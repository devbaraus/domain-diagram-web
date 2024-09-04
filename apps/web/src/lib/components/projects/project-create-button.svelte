<script lang="ts">
	import { goto, invalidate, invalidateAll } from '$app/navigation';
	import { page } from '$app/stores';
	import { createProject } from '$lib/services/project-service.svelte';
	import { PlusIcon } from 'lucide-svelte';

	let modal: HTMLDialogElement;
	// let name = '';

	// async function handleSubmit() {
	// 	const res = await createProject(name, $page.data.session);

	// 	modal?.close();
	// 	name = '';

	// 	goto(`/d/${res.id}`);
	// }
</script>

<div class="tooltip tooltip-right" data-tip="New project">
	<button onclick={() => modal.showModal()} class="mask mask-circle btn size-16">
		<PlusIcon class="w-16" />
	</button>
</div>

<dialog bind:this={modal} class="modal">
	<div class="modal-box">
		<h3 class="mb-2 text-lg font-bold">Create a new project</h3>
		<form method="POST">
			<label class="input input-bordered flex items-center gap-2">
				Name
				<input name="name" type="text" class="grow" placeholder="Daisy" />
			</label>

			<div class="modal-action">
				<button class="btn" type="button">Close</button>
				<button class="btn btn-primary">Create</button>
			</div>
		</form>
	</div>
</dialog>
