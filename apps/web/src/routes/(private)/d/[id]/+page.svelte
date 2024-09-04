<script lang="ts">
	import { page } from '$app/stores';
	import { grammar as defaultGrammar } from '$lib';
	import Parser from '$lib/components/parser.svelte';
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();

	let markup = $state<string>(data.item?.markup || defaultGrammar);
</script>

<svelte:head>
	<title>Domain Driven Diagram - {data.item?.name}</title>
</svelte:head>

<Parser {markup} id={$page.params.id} />
