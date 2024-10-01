<script lang="ts">
	import { goto } from '$app/navigation';
	import { page } from '$app/stores';
	import { queryClient } from '$lib/client';
	import { updateProject } from '$lib/services/project-service.svelte';
	import { project } from '$lib/store';
	import { cn } from '$lib/utils';
	import { createMutation } from '@tanstack/svelte-query';
	import { PenIcon } from 'lucide-svelte';
	import { toast } from 'svelte-sonner';

	let modal: HTMLDialogElement | undefined;

	let members = $state([]);

	$effect(() => {
		members = $project?.members.map((i) => ({ email: i.user.email, role: i.role }));
	});

	const update = createMutation({
		mutationFn: async (data) => await updateProject($page.params.id, data, $page.data.session),
		onSuccess: () => {
			modal?.close();
			toast.success('Project shared successfully');
			$queryClient.invalidateQueries({ queryKey: ['list-projects'] });
			goto('/p');
		},
		onError: () => {
			modal?.close();
			toast.error('Failed to share project');
		}
	});
</script>

<dialog bind:this={modal} class="modal">
	<div class="modal-box space-y-2">
		<p>Update the settings this project</p>

		<form action="">
			<label class="label cursor-pointer justify-start gap-2">
				<span class="label-text">Name</span>
				<input
					class="input input-sm input-bordered flex w-full items-center gap-2"
					name="name"
					minlength="3"
					type="text"
					placeholder="Daisy"
					value={$project.name}
				/>
			</label>

			<label class="label cursor-pointer justify-start gap-2">
				<span class="label-text">Public</span>
				<input type="checkbox" class="toggle" checked={$project.public} />
			</label>

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
			<div class="mt-2">
				<input
					class="input input-bordered input-sm w-full"
					type="email"
					name="email"
					onkeydown={(e) => {
						if (e.key === 'Enter') {
							e.preventDefault();
							const email = e.currentTarget.value;

							if (/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/.test(email) === false) {
								toast.error('Invalid email address');
								return;
							}

							if (members.find((i) => i.email === email)) return;
							members.push({ email: email, role: 'MEMBER' });

							e.currentTarget.value = '';
						}
					}}
				/>
			</div>
		</form>

		<div class="modal-action">
			<button
				class="btn mr-auto"
				onclick={() => {
					navigator.clipboard.writeText(
						`<iframe src="${$page.url.protocol}://${$page.url.host}/e/${$page.params.id}?token=${$project.embed}" width="100%" height="100%"></iframe>`
					);
					modal?.close();
					toast.success('Embed code copied to clipboard');
				}}>Embed</button
			>
			<button class="btn" onclick={() => modal?.close()}>Cancel</button>
			<button class="btn btn-primary" onclick={() => $update.mutate({ members })}>Add</button>
		</div>
	</div>
</dialog>

<div class="tooltip tooltip-right" data-tip="Update">
	<button class="btn btn-primary mask mask-squircle" onclick={() => modal?.showModal()}>
		<span class="sr-only">update</span>
		<PenIcon class="size-5" />
	</button>
</div>
