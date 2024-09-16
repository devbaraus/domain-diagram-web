<script lang="ts">
	import { page } from '$app/stores';
	import Diagram from '$lib/components/diagram.svelte';
	import Editor from '$lib/components/editor.svelte';
	import { updateProject } from '$lib/services/project-service.svelte';
	import { extractDiagram } from '$lib/utils/diagram-extractor';
	import {
		checkForSyntaxErrors,
		lintAST,
		updateDefinitionMarkers,
		updateModelMarkers
	} from '$lib/utils/editor-utils';
	import { model, monaco } from '$lib/store';
	import _ from 'lodash';
	import { onMount } from 'svelte';
	import TreeSitter, { type Tree } from 'web-tree-sitter';

	type Props = {
		diagram: Diagram;
		markup: string;
		id: string;
	};
	let props: Props = $props();

	let parser: TreeSitter | undefined;
	let tree = $state<Tree>();
	let diagram = $state<Diagram>(props.diagram);

	const updateMarkup = async (markup: string, diagram: Diagram) => {
		return updateProject(props.id, { markup, diagram }, $page.data.session);
	};

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

		debouncedMarkupUpdate(value, diagram);
	}, 1500);

	const debouncedMarkupUpdate = _.debounce(
		(markup: string, diagram: Diagram) => updateMarkup(markup, diagram),
		500
	);

	async function initializeParser() {
		await TreeSitter.init();
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/tree-sitter-ddd.wasm');
		parser.setLanguage(dslLang);
	}

	onMount(async () => {
		await initializeParser();
		updateTree(props.markup);
	});

	function handleChange(value: string) {
		debouncedTreeUpdate(value);
	}

	function handleCtrlSave(event: KeyboardEvent) {
		if (event.ctrlKey && event.key === 's') {
			event.preventDefault();
		}
	}
</script>

<Editor value={props.markup} onchange={handleChange} onkeydown={handleCtrlSave} />
<!-- <span class="w-96">{tree?.rootNode?.toString()}</span> -->
<Diagram class="font-fira w-full flex-1 select-none" {diagram} />
