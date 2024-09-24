<script>
	import { browser } from '$app/environment';
	import { queryClient } from '$lib/client';
	import { Toaster } from 'svelte-sonner';
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
	{#if process.env.NODE_ENV === 'production'}
		<script
			defer
			data-domain="dddiagram.baraus.dev"
			src="https://plausible.lab.baraus.dev/js/script.js"
		></script>
	{/if}
</svelte:head>

<QueryClientProvider client={$queryClient}>
	<Toaster expand={true} richColors />
	<slot></slot>
</QueryClientProvider>
