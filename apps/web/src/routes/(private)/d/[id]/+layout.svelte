<script lang="ts">
	import { page } from '$app/stores';
	import ProjectCreateButton from '$lib/components/projects/project-create-button.svelte';
	import { deleteProject, listProjects } from '$lib/services/project-service.svelte';
	import { createMutation, createQuery } from '@tanstack/svelte-query';
	import { getAvatarColor, getAvatarName } from '$lib';
	import { project } from '$lib/store';
	import { goto } from '$app/navigation';
	import { TrashIcon } from 'lucide-svelte';
	import Avatar from '$lib/components/avatar.svelte';

	let modal;

	const query = createQuery({
		queryKey: ['list-projects'],
		queryFn: async () =>
			await listProjects($page.data.session, { filter: { user_created: $page.data.user.id } }),
		initialData: $page.data.items
	});

	const deletion = createMutation({
		mutationFn: async () => await deleteProject($page.params.id, $page.data.session),
		onSuccess: () => {
			modal?.close();
			$query.refetch();
			goto('/d');
		}
	});
</script>

<svelte:head>
	<title>Domain Driven Diagram</title>
</svelte:head>

<div class="flex max-w-[100dvw] divide-x">
	<aside class="h-screen w-16 space-y-2 p-2">
		<ProjectCreateButton />

		{#each $query.data as project}
			<div class="tooltip tooltip-right z-20" data-tip={project.name}>
				<a href={`/d/${project.id}`}>
					<Avatar name={project.name} />
				</a>
			</div>
		{/each}
	</aside>
	<div class="w-full">
		<div class="navbar bg-base-100 h-12 border-b">
			<div class="flex-1 space-x-2 px-2">
				<button onclick={() => modal?.showModal()}>
					<TrashIcon class="text-error size-5" />
				</button>
				<span class="text-xl">{$project?.name}</span>

				<dialog bind:this={modal} class="modal">
					<div class="modal-box">
						<p>Are you sure you want to delete this project?</p>
						<div class="modal-action">
							<button class="btn" onclick={() => modal?.close()}> No </button>
							<button class="btn btn-error" onclick={() => $deletion.mutate()}> Yes </button>
						</div>
					</div>
				</dialog>
			</div>
			<div class="flex-none items-center">
				<div class="dropdown dropdown-end">
					<div tabindex="0" role="button" class="avatar">
						<Avatar name={`${$page.data.user?.first_name} ${$page.data.user?.last_name}`} />
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
		<div class="flex h-[calc(100dvh_-_64px)] max-h-[calc(100dvh_-_64px)] flex-1">
			<slot></slot>
		</div>
	</div>
</div>
