<script lang="ts">
	import { page } from '$app/stores';
	import Diagram from '$lib/components/diagram.svelte';
	import Editor from '$lib/components/editor.svelte';
	import { PUBLIC_WS_URL } from '$env/static/public';
	import { mobSwitch, model, monaco } from '$lib/store';
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
	import { cn } from '$lib/utils';
	import { diagram as diagramStore } from '$lib/store';

	let parser: TreeSitter | undefined;
	let tree = $state<Tree>();
	let diagram = $state<Diagram>();

	const updateTree = (value: string) => {
		tree = parser?.parse(value);

		const errors = checkForSyntaxErrors(tree?.rootNode);

		if (errors.length) {
			$monaco?.editor.setModelMarkers($model, 'ddd', errors);
			return;
		}

		diagram = extractDiagram(tree?.rootNode);
		diagramStore.set(diagram);
		const diagnostic = lintAST(tree);

		updateDefinitionMarkers($monaco, diagram);
		updateModelMarkers($monaco, $model, diagnostic);
	};

	const debouncedTreeUpdate = _.debounce((value: string) => {
		updateTree(value);
	}, 300);

	async function initializeParser() {
		await TreeSitter.init({
			locateFile(scriptName: string, scriptDirectory: string) {
				return `${$page.url.origin}/${scriptName}`;
			}
		});
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/tree-sitter-ddd.wasm');
		parser.setLanguage(dslLang);
	}

	onMount(async () => {
		await initializeParser();
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

<Editor
	class={cn(
		!$mobSwitch ? 'left-0 top-0' : '-left-[calc(100%_+_1px)] top-0',
		'absolute  h-full w-full overflow-hidden transition-all lg:static lg:w-[calc(100vw_*_0.3_-_48px)]'
	)}
	onchange={handleChange}
	onkeydown={handleCtrlSave}
/>
<!-- <span class="w-96">{tree?.rootNode?.toString()}</span> -->
<Diagram class={cn('font-fira w-full flex-1 select-none overflow-hidden')} {diagram} />
