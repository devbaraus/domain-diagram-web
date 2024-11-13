<script lang="ts">
	import { page } from '$app/stores';
	import Parser from '$lib/components/parser-edit.svelte';
</script>

<svelte:head>
	<title>{$page.data.item?.name} | Domain Driven Diagram</title>
</svelte:head>

<Parser id={$page.params.id} />
