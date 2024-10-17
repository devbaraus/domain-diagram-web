<script lang="ts">
	import { page } from '$app/stores';
	import Diagram from '$lib/components/diagram.svelte';
	import Editor from '$lib/components/editor.svelte';
	import { diagram as diagramStore, model, monaco } from '$lib/store';
	import { cn } from '$lib/utils';
	import { extractDiagram } from '$lib/utils/diagram-extractor';
	import {
		checkForSyntaxErrors,
		linter,
		updateDefinitionMarkers,
		updateModelMarkers
	} from '$lib/utils/editor-utils';
	import _ from 'lodash';
	import { Pane, PaneGroup, PaneResizer } from 'paneforge';
	import { onMount } from 'svelte';
	import TreeSitter, { type Tree } from 'web-tree-sitter';

	let parser: TreeSitter | undefined;
	let tree = $state<Tree>();
	let diagram = $state<Diagram>();
	let editorPane = $state(40);
	let diagramPane = $state(60);

	const updateTree = (value: string) => {
		tree = parser?.parse(value);

		const errors = checkForSyntaxErrors(tree?.rootNode);

		if (errors.length) {
			$monaco?.editor.setModelMarkers($model, 'ddd', errors);
			return;
		}

		let diagram = extractDiagram(tree?.rootNode);

		diagramStore.set(diagram);
		const diagnostic = linter(tree, diagram);

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

<!-- <Editor
			class={cn(
				!$mobSwitch ? 'left-0 top-0' : '-left-[calc(100%_+_1px)] top-0',
				'absolute  h-full w-full overflow-hidden transition-all lg:static lg:w-[calc(100vw_*_0.3_-_48px)]'
			)}
			onchange={handleChange}
			onkeydown={handleCtrlSave}
		/> -->

<PaneGroup direction="horizontal">
	<Pane defaultSize={editorPane}>
		<Editor class={cn('h-full w-full')} onchange={handleChange} onkeydown={handleCtrlSave} />
	</Pane>
	<PaneResizer class="border border-dashed" />
	<Pane defaultSize={diagramPane}>
		<Diagram class={cn('h-full w-full flex-1 select-none')} diagram={$diagramStore} />
	</Pane>
</PaneGroup>
