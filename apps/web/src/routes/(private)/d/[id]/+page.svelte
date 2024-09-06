<script lang="ts">
	import { page } from '$app/stores';
	import Parser from '$lib/components/parser.svelte';
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();
</script>

<svelte:head>
	<title>Domain Driven Diagram - {data.item?.name}</title>
</svelte:head>

<Parser markup={data.item?.markup} diagram={data.item?.diagram} id={$page.params.id} />
