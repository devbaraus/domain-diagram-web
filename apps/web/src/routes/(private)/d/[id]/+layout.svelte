<script lang="ts">
	import { goto } from '$app/navigation';
	import { page } from '$app/stores';
	import Avatar from '$lib/components/avatar.svelte';
	import ProjectCreateButton from '$lib/components/projects/project-create-button.svelte';
	import { deleteProject, listProjects, updateProject } from '$lib/services/project-service.svelte';
	import { project, connections, mobSwitch } from '$lib/store';
	import { cn } from '$lib/utils';
	import { createMutation, createQuery } from '@tanstack/svelte-query';
	import { TrashIcon, Share2Icon, LetterTextIcon, WorkflowIcon } from 'lucide-svelte';
	import { toast } from 'svelte-sonner';

	let deleteModal;
	let shareModal;
	let members = $state([]);

	$effect(() => {
		members = $project?.members.map((i) => ({ email: i.user.email, role: i.role }));
	});

	const query = createQuery({
		queryKey: ['list-projects'],
		queryFn: async () => await listProjects($page.data.session),
		initialData: []
	});

	const deletion = createMutation({
		mutationFn: async () => await deleteProject($page.params.id, $page.data.session),
		onSuccess: () => {
			deleteModal?.close();
			$query.refetch();
			goto('/d');
		}
	});

	const update = createMutation({
		mutationFn: async (data) => await updateProject($page.params.id, data, $page.data.session),
		onSuccess: () => {
			shareModal?.close();
			toast.success('Project shared successfully');
			$query.refetch();
			goto('/d');
		},
		onError: () => {
			shareModal?.close();
			toast.error('Failed to share project');
		}
	});

	function handleKeyDown(e) {
		if (e.key === 'Enter') {
			e.preventDefault();
			e.target.blur();
		}
	}
</script>

<svelte:head>
	<title>Domain Driven Diagram</title>
</svelte:head>

<div class="z-10 flex max-w-[100dvw] divide-x">
	<aside class="bg-base-100 z-10 flex h-[100dvh] w-16 flex-col justify-between p-2">
		<div class="space-y-2">
			<ProjectCreateButton />

			{#each $query.data as project}
				<div class="tooltip tooltip-right z-20" data-tip={project.name}>
					<a href={`/d/${project.id}`}>
						<Avatar
							class={project.id == $page.params.id ? 'bg-neutral text-neutral-content' : ''}
							name={project.name}
						/>
					</a>
				</div>
			{/each}
		</div>

		<div class="space-y-2">
			{#if $project?.members.find((i) => i.role === 'OWNER' && i.user.id === $page.data.user.id)}
				<button class="btn btn-primary mask mask-squircle" onclick={() => shareModal?.showModal()}>
					<Share2Icon class="size-5" />
				</button>

				<button class="btn btn-error mask mask-squircle" onclick={() => deleteModal?.showModal()}>
					<TrashIcon class="size-5" />
				</button>
			{/if}
		</div>
	</aside>
	<div class="w-full">
		<dialog bind:this={deleteModal} class="modal">
			<div class="modal-box">
				<p>Are you sure you want to delete this project?</p>
				<div class="modal-action">
					<button class="btn" onclick={() => deleteModal?.close()}>Cancel</button>
					<button class="btn btn-error" onclick={() => $deletion.mutate()}>Delete</button>
				</div>
			</div>
		</dialog>

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
		<div class="navbar bg-base-100 h-12 border-b">
			<div class="flex-1 space-x-2 px-2">
				<span
					class="text-xl"
					contenteditable
					onkeydown={handleKeyDown}
					onblur={(e) => $update.mutate({ name: e.currentTarget.innerText })}>{$project?.name}</span
				>
				<ul>
					{#each $connections.filter((i) => $page.data.user.id !== i.user.id) as { user }}
						<li class="tooltip tooltip-bottom" data-tip={user.name}>
							<Avatar
								name={user.name}
								class="ddd-avatar size-8 rounded-full border-2"
								borderColor={user.color}
							/>
						</li>
					{/each}
				</ul>
			</div>
			<div class="flex-none items-center gap-2">
				<button
					class="btn btn-info mask mask-squircle lg:hidden"
					onclick={() => ($mobSwitch = !$mobSwitch)}
				>
					{#if !$mobSwitch}
						<LetterTextIcon class="size-8" />
					{:else}
						<WorkflowIcon class="size-8" />
					{/if}
				</button>
				<div class="dropdown dropdown-end">
					<div tabindex="0" role="button" class="avatar">
						<Avatar name={$page.data.user?.name} />
					</div>
					<ul class="menu menu-sm dropdown-content bg-base-100 rounded-box z-[1] w-52 p-2 shadow">
						<li>
							<form action="/api/auth/logout" class="flex w-full" method="get">
								<button class="w-full text-start">LOGOUT</button>
							</form>
						</li>
					</ul>
				</div>
			</div>
		</div>
		<div
			class="relative z-0 flex h-[calc(100dvh_-_64px)] max-h-[calc(100dvh_-_64px)] flex-1 bg-white"
		>
			<slot></slot>
		</div>
	</div>
</div>
