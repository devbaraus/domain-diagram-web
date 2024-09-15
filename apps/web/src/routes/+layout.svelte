<script>
	import { browser } from '$app/environment';
	import { queryClient } from '$lib/client';
	import { NODE_ENV } from '$env/static/private';
	import '../app.css';

	import { QueryClient, QueryClientProvider } from '@tanstack/svelte-query';

	queryClient.set(
		new QueryClient({
			defaultOptions: {
				queries: {
					enabled: browser
				}
			}
		})
	);
</script>

<svelte:head>
	<title>Domain Driven Diagram</title>
	{#if NODE_ENV === 'production'}
		<script
			defer
			data-domain="dddiagram.baraus.dev"
			src="https://plausible.lab.baraus.dev/js/script.js"
		></script>
	{/if}
</svelte:head>

<QueryClientProvider client={$queryClient}>
	<slot></slot>
</QueryClientProvider>
