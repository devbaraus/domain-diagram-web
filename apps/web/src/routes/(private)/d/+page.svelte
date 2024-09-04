<script lang="ts">
	import { grammar } from '$lib';
	import { createRender, createTable } from 'svelte-headless-table';
	import Table from '$lib/components/table.svelte';
	import { writable, type Writable } from 'svelte/store';
	import type { PageData } from './$types';
	import TableLink from '$lib/components/table-link.svelte';

	let { data }: { data: PageData } = $props();

	let items: Writable<{
		id: number;
		name: string;
		createdAt: string;
		updatedAt: string;
	}> = writable(data.items);

	const table = createTable(items);

	const columns = table.createColumns([
		table.column({
			accessor: 'id',
			header: 'Nome',
			cell: (e) => {
				console.log(e);
				return createRender(TableLink, {
					id: e.value,
					label: e.row.original.name
				});
			}
		}),
		table.column({
			accessor: 'date_created',
			header: 'Criado em'
		}),
		table.column({
			accessor: 'date_updated',
			header: 'Atualizado em'
		})
	]);
</script>

<h1 class="text-lg font-bold">Projects</h1>

<Table {table} {columns} />

<form method="post">
	<label for="name">name:</label>
	<input name="name" required />

	<input type="hidden" name="markup" value={grammar} />

	<button type="submit">Create</button>
</form>
