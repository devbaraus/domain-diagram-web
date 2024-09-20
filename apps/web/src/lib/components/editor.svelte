<script lang="ts">
	import { page } from '$app/stores';
	import { PUBLIC_WS_URL } from '$env/static/public';
	import { editor, model, monaco } from '$lib/store';
	import _ from 'lodash';
	import * as Y from 'yjs';
	import { onDestroy, onMount } from 'svelte';

	let el: HTMLDivElement;
	let provider;
	let type;
	let doc;
	let binding;

	let props: {
		value: string;
		class?: string;
		onchange?: (value: string) => void;
		onkeydown?: (e: KeyboardEvent) => void;
	} = $props();

	async function setup() {
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

		$model = $monaco.editor.createModel('', 'ddd');
		$editor.setModel($model);

		doc = new Y.Doc();
		provider = new WebsocketProvider(`${PUBLIC_WS_URL}`, $page.params.id, doc, {
			params: {
				access_token: $page.data.session
			}
		});

		type = doc.getText('monaco');
		binding = new MonacoBinding(type, $editor?.getModel()!, new Set([$editor]), provider.awareness);

		provider.awareness.setLocalStateField('user', {
			name: $page.data.user.name,
			color: '#f3c2d8'
		});

		// provider.awareness.on('change', () => {
		// 	// Map each awareness state to a dom-string
		// 	const strings = [];
		// 	provider.awareness.getStates().forEach((state) => {
		// 		console.log(state);
		// 		if (state.user) {
		// 			strings.push(`<div style="color:${state.user.color};">• ${state.user.name}</div>`);
		// 		}
		// 		document.querySelector('#users').innerHTML = strings.join('');
		// 	});
		// });

		$model.onDidChangeContent((e) => {
			props.onchange?.($model.getValue());
		});

		props.onchange?.($model.getValue());
	}

	function dispose() {
		provider?.disconnect();
		binding?.destroy();
		doc?.destroy();

		$model?.dispose();
		$editor?.dispose();
	}

	onMount(() => {
		setup();

		return dispose;
	});

	onDestroy(() => {
		dispose();
	});

	$effect(() => {
		if (!$model || $model?.isDisposed() || _.isEqual($model?.getValue(), props.value)) {
			return;
		}

		$model?.setValue(props.value);
	});
</script>

<div
	id="editor"
	bind:this={el}
	class={props.class}
	onkeydown={props.onkeydown}
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
