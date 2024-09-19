<script lang="ts">
	import { page } from '$app/stores';
	import Diagram from '$lib/components/diagram.svelte';
	import Editor from '$lib/components/editor.svelte';
	import { updateProject } from '$lib/services/project-service.svelte';
	import { model, monaco } from '$lib/store';
	import { extractDiagram } from '$lib/utils/diagram-extractor';
	import {
		checkForSyntaxErrors,
		lintAST,
		updateDefinitionMarkers,
		updateModelMarkers
	} from '$lib/utils/editor-utils';
	import _ from 'lodash';
	import { onMount } from 'svelte';
	import TreeSitter, { type Tree } from 'web-tree-sitter';

	type Props = {
		// diagram: Diagram;
		// markup: string;
		id: string;
	};
	let props: Props = $props();
	let ws: WebSocket | undefined;

	let parser: TreeSitter | undefined;
	let tree = $state<Tree>();
	let diagram = $state<Diagram>();
	let markup = $state<string>('');

	const updateTree = (value: string) => {
		tree = parser?.parse(value);

		const errors = checkForSyntaxErrors(tree?.rootNode);

		if (errors.length) {
			$monaco?.editor.setModelMarkers($model, 'ddd', errors);
			return;
		}

		diagram = extractDiagram(tree?.rootNode);
		const diagnostic = lintAST(tree);

		updateDefinitionMarkers($monaco, diagram);
		updateModelMarkers($monaco, $model, diagnostic);
	};

	const debouncedTreeUpdate = _.debounce((value: string) => {
		updateTree(value);
	}, 300);

	async function initializeParser() {
		await TreeSitter.init();
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/tree-sitter-ddd.wasm');
		parser.setLanguage(dslLang);
	}

	onMount(async () => {
		await initializeParser();

		ws = new WebSocket(
			`ws://localhost:3000/projects/${$page.params.id}/ws?access_token=${$page.data.session}`
		);
		ws.onmessage = (event) => {
			if (event.data !== $model?.getValue()) {
				markup = event.data;
			}
		};
	});

	function handleChange(value: string) {
		debouncedTreeUpdate(value);
		ws?.send(value);
	}

	function handleCtrlSave(event: KeyboardEvent) {
		if (event.ctrlKey && event.key === 's') {
			event.preventDefault();
		}
	}
</script>

<Editor value={markup} onchange={handleChange} onkeydown={handleCtrlSave} />
<!-- <span class="w-96">{tree?.rootNode?.toString()}</span> -->
<Diagram class="font-fira w-full flex-1 select-none" {diagram} />
