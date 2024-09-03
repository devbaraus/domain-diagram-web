<script lang="ts">
	import type { PageData } from './$types';

	let { data }: { data: PageData } = $props();
</script>

<h1>Projects</h1>
<ul>
	{#each data.items as item}
		<li>
			<a href={`/d/${item.id}`}>{item.name}</a>
		</li>
	{/each}
</ul>
