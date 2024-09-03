<script lang="ts">
	import { grammar } from '$lib';
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

<form method="post">
	<label for="name">name:</label>
	<input name="name" required />

	<input type="hidden" name="markup" value={grammar} />

	<button type="submit">Create</button>
</form>
