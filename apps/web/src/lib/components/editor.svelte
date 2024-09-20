<script lang="ts">
	import { page } from '$app/stores';
	import { PUBLIC_WS_URL } from '$env/static/public';
	import { editor, model, monaco } from '$lib/store';
	import _ from 'lodash';
	import * as Y from 'yjs';
	import { onMount } from 'svelte';

	let el: HTMLDivElement;

	let data: {
		value: string;
		class?: string;
		onchange?: (value: string) => void;
		onkeydown?: (e: KeyboardEvent) => void;
	} = $props();

	onMount(async () => {
		const { WebsocketProvider } = await import('y-websocket');
		const { MonacoBinding } = await import('y-monaco');
		$monaco = (await import('$lib/monaco')).default;

		// Your monaco instance is ready, let's display some code!
		$editor = $monaco.editor.create(el, {
			theme: 'default',
			wordWrap: 'wordWrapColumn',
			wordWrapColumn: 60,
			wrappingIndent: 'indent',
			lineNumbers: 'on',
			fontFamily: 'Fira Code',
			fontSize: 14,
			tabSize: 2,
			fontLigatures: "'zero', 'ss02', 'ss03', 'ss04', 'ss05', 'calt'",
			scrollBeyondLastLine: false,
			minimap: { enabled: false }
		});

		$model = $monaco.editor.createModel(data.value, 'ddd');
		$editor.setModel($model);

		const doc = new Y.Doc();
		const provider = new WebsocketProvider(`${PUBLIC_WS_URL}`, $page.params.id, doc, {
			params: {
				access_token: $page.data.session
			}
		});
		const type = doc.getText('monaco');
		const binding = new MonacoBinding(type, $editor?.getModel()!, new Set([$editor]));

		$model.onDidChangeContent((e) => {
			data.onchange?.($model.getValue());
		});

		data.onchange?.($model.getValue());

		return () => {
			$monaco?.editor.getModels().forEach((model) => model.dispose());
			$editor?.dispose();
		};
	});

	$effect(() => {
		if (_.isEqual($model?.getValue(), data.value)) {
			return;
		}

		$model?.setValue(data.value);
	});
</script>

<div
	id="editor"
	bind:this={el}
	class={data.class}
	onkeydown={data.onkeydown}
	role="textbox"
	aria-label="Code editor"
	aria-multiline="true"
	tabindex="0"
></div>

<style>
	#editor {
		width: calc((100vw * 0.3) - 48px);
	}
</style>
