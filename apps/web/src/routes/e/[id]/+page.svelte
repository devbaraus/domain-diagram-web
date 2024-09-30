<script lang="ts">
	import { page } from '$app/stores';
	import Parser from '$lib/components/parser-embed.svelte';
	import type { PageData } from './$types';
	import { project } from '$lib/store';

	let { data }: { data: PageData } = $props();

	$effect(() => {
		project.set(data.item);
	});
</script>

<svelte:head>
	<title>Domain Driven Diagram - {data.item?.name}</title>
</svelte:head>

{#key $page.params.id}
	<Parser id={$page.params.id} />
{/key}
