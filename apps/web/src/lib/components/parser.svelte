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
	let markup = $state(props.markup);
	let diagram = $state(props.diagram);

	const markupUpdate = async (markup: string, diagram: Diagram) => {
		return updateProject(props.id, { markup, diagram }, $page.data.session);
	};

	const debouncedTreeUpdate = _.debounce((value: string) => {
		tree = parser?.parse(value);
		diagram = extractDiagram(tree?.rootNode);

		debouncedMarkupUpdate(value, diagram);
	}, 1500);

	const debouncedMarkupUpdate = _.debounce(
		(markup: string, diagram: Diagram) => markupUpdate(markup, diagram),
		1500
	);

	async function initializeParser() {
		await TreeSitter.init();
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/tree-sitter-ddd.wasm');
		parser.setLanguage(dslLang);
	}

	onMount(async () => {
		await initializeParser();

		tree = parser?.parse(props.markup);
		diagram = extractDiagram(tree?.rootNode);
	});

	function handleChange(event: CustomEvent<string>) {
		debouncedTreeUpdate(event.detail);
	}

	function handleCtrlSave(event: KeyboardEvent) {
		if (event.ctrlKey && event.key === 's') {
			event.preventDefault();
			// markupUpdate(event);
		}
	}
</script>

<Editor value={props.markup} onkeydown={handleCtrlSave} onchange={handleChange} />
<!-- <span class="w-96">{tree?.rootNode?.toString()}</span> -->
<Diagram class="w-full flex-1" {diagram} />
