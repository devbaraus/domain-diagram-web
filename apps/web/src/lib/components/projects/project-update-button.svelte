<script lang="ts">
	import { goto } from '$app/navigation';
	import { page } from '$app/stores';
	import { queryClient } from '$lib/client';
	import { updateProject } from '$lib/services/project-service.svelte';
	import { project } from '$lib/store';
	import { cn } from '$lib/utils';
	import { createMutation } from '@tanstack/svelte-query';
	import { Share2Icon } from 'lucide-svelte';
	import { toast } from 'svelte-sonner';

	let shareModal: HTMLDialogElement | undefined;

	let members = $state([]);

	$effect(() => {
		members = $project?.members.map((i) => ({ email: i.user.email, role: i.role }));
	});

	const update = createMutation({
		mutationFn: async (data) => await updateProject($page.params.id, data, $page.data.session),
		onSuccess: () => {
			shareModal?.close();
			toast.success('Project shared successfully');
			$queryClient.invalidateQueries({ queryKey: ['list-projects'] });
			goto('/d');
		},
		onError: () => {
			shareModal?.close();
			toast.error('Failed to share project');
		}
	});
</script>

<dialog bind:this={shareModal} class="modal">
	<div class="modal-box space-y-2">
		<p>Update who can see this project</p>

		<div class="grid border-collapse grid-cols-2 gap-2">
			{#if members}
				{#each members as member}
					<input
						class={cn('input input-sm input-bordered', member.role === 'OWNER' && 'col-span-2')}
						type="text"
						disabled={member.role === 'OWNER'}
						value={member.email}
					/>
					<button
						class={cn('btn btn-sm', member.role === 'OWNER' && 'hidden')}
						onclick={() => (members = members.filter((i) => i.email !== member.email))}
						>Remove
					</button>
				{/each}
			{/if}
		</div>
		<div>
			<form
				onsubmit={(e) => {
					e.preventDefault();
					const email = e.target.email.value;
					e.target.reset();
					if (members.find((i) => i.email === email)) return;
					members.push({ email: email, role: 'MEMBER' });
				}}
			>
				<input class="input input-bordered input-sm w-full" type="email" name="email" />
			</form>
		</div>

		<div class="modal-action">
			<button class="btn" onclick={() => shareModal?.close()}>Cancel</button>
			<button class="btn btn-primary" onclick={() => $update.mutate({ members })}>Add</button>
		</div>
	</div>
</dialog>

<button class="btn btn-primary mask mask-squircle" onclick={() => shareModal?.showModal()}>
	<Share2Icon class="size-5" />
</button>
