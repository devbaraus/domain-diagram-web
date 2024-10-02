<script lang="ts">
	import { page } from '$app/stores';
	import Parser from '$lib/components/parser-embed.svelte';
	import type { PageData } from './$types';
</script>

<svelte:head>
	<title>{$page.data.item?.name} | Domain Driven Diagram</title>
</svelte:head>

{#key $page.params.id}
	<Parser id={$page.params.id} />
{/key}
