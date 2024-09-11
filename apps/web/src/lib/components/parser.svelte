<script lang="ts">
	import { page } from '$app/stores';
	import Diagram from '$lib/components/diagram.svelte';
	import Editor from '$lib/components/editor.svelte';
	import { updateProject } from '$lib/services/project-service.svelte';
	import { extractDiagram } from '$lib/utils/diagram-extractor';
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
	let diagram = $state(props.diagram);

	const updateMarkup = async (markup: string, diagram: Diagram) => {
		return updateProject(props.id, { markup, diagram }, $page.data.session);
	};

	const updateTree = (value: string) => {
		tree = parser?.parse(value);
		diagram = extractDiagram(tree?.rootNode);
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

	function handleChange(event: CustomEvent<string>) {
		debouncedTreeUpdate(event.detail);
	}

	function handleCtrlSave(event: KeyboardEvent) {
		if (event.ctrlKey && event.key === 's') {
			event.preventDefault();
		}
	}
</script>

<Editor value={props.markup} onkeydown={handleCtrlSave} onchange={handleChange} />
<!-- <span class="w-96">{tree?.rootNode?.toString()}</span> -->
<Diagram class="font-fira w-full flex-1 select-none" {diagram} />
