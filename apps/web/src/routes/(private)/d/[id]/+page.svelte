<script lang="ts">
	import { onDestroy, onMount } from 'svelte';
	import Diagram from '$lib/components/diagram.svelte';
	import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';
	import TreeSitter, { type Tree } from 'web-tree-sitter';
	import { grammar as defaultGrammar } from '$lib';
	import _ from 'lodash';
	import { directusClient } from '$lib/client.js';
	import { updateItem } from '@directus/sdk';
	import { page } from '$app/stores';
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();
	let id = $page.params.id;

	let editor: Monaco.editor.IStandaloneCodeEditor;
	let monaco: typeof Monaco;
	let parser: TreeSitter | undefined;
	let editorContainer: HTMLElement;
	let tree = $state<Tree>();
	let markup = $state<string>(data.item.markup || defaultGrammar);

	const debouncedTreeUpdate = _.debounce(() => {
		tree = parser?.parse(markup);
	}, 500);

	const debouncedMarkupUpdate = _.debounce(async () => {
		if (markup == data.item.markup) return;

		await directusClient.setToken(data.session);

		await directusClient.request(
			updateItem('projects', id, {
				markup
			})
		);
	}, 1500);

	async function initializeParser() {
		await TreeSitter.init();
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/parser.wasm');
		parser.setLanguage(dslLang);
	}

	onMount(async () => {
		// grammar = window.localStorage.getItem('grammar') || grammar;

		await initializeParser();

		// Import our 'monaco.ts' file here
		// (onMount() will only be executed in the browser, which is what we want)
		monaco = (await import('$lib/monaco')).default;

		// Your monaco instance is ready, let's display some code!
		const editor = monaco.editor.create(editorContainer, {
			theme: 'default'
		});
		const model = monaco.editor.createModel(markup, 'ddd');
		editor.setModel(model);

		tree = parser?.parse(model?.getValue());

		model.onDidChangeContent(() => {
			markup = model.getValue();
			debouncedTreeUpdate();
			debouncedMarkupUpdate();
		});
	});

	onDestroy(() => {
		monaco?.editor.getModels().forEach((model) => model.dispose());
		editor?.dispose();
	});
</script>

<svelte:head>
	<title>Domain Driven Diagram - {data.item.name}</title>
</svelte:head>

<div id="wrapper">
	<div id="code" bind:this={editorContainer}></div>
	<Diagram {tree} />
</div>

<style>
	#wrapper {
		display: flex;
	}
	#code {
		width: 50vw;
		height: 100dvh;
	}
</style>
