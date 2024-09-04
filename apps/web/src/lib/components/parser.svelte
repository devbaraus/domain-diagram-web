<script lang="ts">
	import { page } from '$app/stores';
	import { grammar as defaultGrammar } from '$lib';
	import Diagram from '$lib/components/diagram.svelte';
	import Editor from '$lib/components/editor.svelte';
	import { updateProject } from '$lib/services/project-service.svelte';
	import _ from 'lodash';
	import { onMount } from 'svelte';
	import TreeSitter, { type Tree } from 'web-tree-sitter';

	type Props = {
		markup: string;
		id: string;
	};
	let props: Props = $props();

	let parser: TreeSitter | undefined;
	let tree = $state<Tree>();
	let markup = $state<string>(props.markup || defaultGrammar);

	const markupUpdate = async () => {
		return updateProject(props.id, { markup }, $page.data.session);
	};

	const debouncedTreeUpdate = _.debounce(() => {
		tree = parser?.parse(markup);
	}, 500);

	const debouncedMarkupUpdate = _.debounce(markupUpdate, 1500);

	async function initializeParser() {
		await TreeSitter.init();
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/parser.wasm');
		parser.setLanguage(dslLang);
	}

	onMount(async () => {
		await initializeParser();

		tree = parser?.parse(markup);

		debouncedTreeUpdate();
	});

	function handleChange(event: CustomEvent<string>) {
		markup = event.detail;
		debouncedTreeUpdate();
		debouncedMarkupUpdate();
	}

	function handleCtrlSave(event: KeyboardEvent) {
		if (event.ctrlKey && event.key === 's') {
			event.preventDefault();
			markupUpdate();
		}
	}
</script>

<div class="flex">
	<Editor class="w-[40dvw]" value={markup} onkeydown={handleCtrlSave} onchange={handleChange} />
	<Diagram {tree} />
</div>
