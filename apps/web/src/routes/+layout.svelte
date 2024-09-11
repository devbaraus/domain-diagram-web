<script>
	import { browser } from '$app/environment';
	import { queryClient } from '$lib/client';
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
</svelte:head>

<QueryClientProvider client={$queryClient}>
	<slot></slot>
</QueryClientProvider>
