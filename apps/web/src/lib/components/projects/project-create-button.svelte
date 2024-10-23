<script lang="ts">
	import { enhance } from '$app/forms';
	import { goto } from '$app/navigation';
	import { PlusIcon } from 'lucide-svelte';
	import { createQuery, QueryClient } from '@tanstack/svelte-query';
	import { queryClient } from '$lib/client';

	let loading = $state(false);
	let modal: HTMLDialogElement = $state();
</script>

<div class="tooltip tooltip-right" data-tip="New project">
	<button onclick={() => modal.showModal()} class="mask mask-squircle btn size-12">
		<PlusIcon class="w-16" />
	</button>
</div>

<dialog bind:this={modal} class="modal">
	<div class="modal-box">
		<h3 class="mb-2 text-lg font-bold">Create a new project</h3>
		<form
			method="POST"
			onsubmit={() => {
				loading = true;
			}}
			use:enhance={() => {
				return async ({ result }) => {
					if (result.status === 200) {
						loading = false;
						modal.close();
						await $queryClient.invalidateQueries({
							queryKey: ['list-projects']
						});
						window.location.href = `/p/${result.data.item.id}`;
					}
				};
			}}
		>
			<label class="input input-bordered flex items-center gap-2">
				Name
				<input name="name" minlength="3" type="text" class="grow" placeholder="Daisy" />
			</label>

			<div class="modal-action">
				<button class="btn" onclick={() => modal.close()} type="button">Close</button>
				<button class="btn btn-primary" disabled={loading}>Create</button>
			</div>
		</form>
	</div>
</dialog>
