<script lang="ts">
	import { editor, model, monaco } from '$lib/store';
	import { onMount } from 'svelte';

	let el: HTMLDivElement;

	let data: {
		value: string;
		class?: string;
		onchange?: (value: string) => void;
		onkeydown?: (e: KeyboardEvent) => void;
	} = $props();

	onMount(async () => {
		$monaco = (await import('$lib/monaco')).default;

		// Your monaco instance is ready, let's display some code!
		$editor = $monaco.editor.create(el, {
			theme: 'default',
			wordWrap: 'on',
			fontFamily: 'Fira Code',
			fontSize: 14,
			fontLigatures: "'zero', 'ss02', 'ss03', 'ss04', 'ss05', 'calt'",
			scrollBeyondLastLine: false,
			minimap: { enabled: false }
		});

		$model = $monaco.editor.createModel(data.value, 'ddd');

		$editor.setModel($model);

		$model.onDidChangeContent((e) => {
			data.onchange?.($model.getValue());
		});

		data.onchange?.($model.getValue());

		return () => {
			$monaco?.editor.getModels().forEach((model) => model.dispose());
			$editor?.dispose();
		};
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
