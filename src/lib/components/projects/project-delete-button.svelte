<script lang="ts">
	import { page } from '$app/stores';
	import { queryClient } from '$lib/client';
	import { deleteProject } from '$lib/services/project-service.svelte';
	import { createMutation } from '@tanstack/svelte-query';
	import { TrashIcon } from 'lucide-svelte';

	let deleteModal: HTMLDialogElement | undefined = $state();

	const deletion = createMutation({
		mutationFn: async () => await deleteProject($page.params.id, $page.data.session),
		onSuccess: () => {
			deleteModal?.close();
			$queryClient.invalidateQueries({ queryKey: ['list-projects'] });
			window.location.href = '/p';
		}
	});
</script>

<dialog bind:this={deleteModal} class="modal">
	<div class="modal-box">
		<p>Are you sure you want to delete this project?</p>
		<div class="modal-action">
			<button class="btn" onclick={() => deleteModal?.close()}>Cancel</button>
			<button class="btn btn-error" onclick={() => $deletion.mutate()}>Delete</button>
		</div>
	</div>
</dialog>

<div class="tooltip tooltip-right" data-tip="Delete">
	<button class="btn btn-error mask mask-squircle" onclick={() => deleteModal?.showModal()}>
		<span class="sr-only">delete</span>
		<TrashIcon class="size-5" />
	</button>
</div>
