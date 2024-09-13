<script>
	import { browser } from '$app/environment';
	import { queryClient } from '$lib/client';

	import { QueryClient, QueryClientProvider } from '@tanstack/svelte-query';

	queryClient.set(
		new QueryClient({
			defaultOptions: {
				queries: {
					enabled: browser,
					refetchOnWindowFocus: false
				}
			}
		})
	);
</script>

<QueryClientProvider client={$queryClient}>
	<slot></slot>
</QueryClientProvider>
