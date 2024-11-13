<script lang="ts">
	import { Column, Render, Subscribe, Table } from 'svelte-headless-table';

	export let loading: boolean = false;
	export let table: Table<any, any>;
	export let columns: Column<any, any>[];

	const { headerRows, pageRows, tableAttrs, tableBodyAttrs } = table.createViewModel(columns);
</script>

<div class="overflow-auto">
	<table {...$tableAttrs} class="rounded-box mt-2 table">
		<thead>
			{#each $headerRows as headerRow (headerRow.id)}
				<Subscribe attrs={headerRow.attrs()} let:attrs>
					<tr {...attrs}>
						{#each headerRow.cells as cell (cell.id)}
							<Subscribe attrs={cell.attrs()} let:attrs>
								<th {...attrs}>
									<span class="text-base-content/80 text-sm font-medium">
										<Render of={cell.render()} />
									</span>
								</th>
							</Subscribe>
						{/each}
					</tr>
				</Subscribe>
			{/each}
		</thead>
		<tbody {...$tableBodyAttrs}>
			{#if loading}
				<tr>
					<td colSpan={columns.length} class="h-12 animate-pulse text-center">Loading...</td>
				</tr>
			{:else}
				{#each $pageRows as row (row.id)}
					<Subscribe attrs={row.attrs()} let:attrs>
						<tr {...attrs} class="hover:bg-base-200/40">
							{#each row.cells as cell (cell.id)}
								<Subscribe attrs={cell.attrs()} let:attrs>
									<td {...attrs}>
										<Render of={cell.render()} />
									</td>
								</Subscribe>
							{/each}
						</tr>
					</Subscribe>
				{/each}
			{/if}
		</tbody>
	</table>
</div>
