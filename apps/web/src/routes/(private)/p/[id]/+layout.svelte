<script lang="ts">
	import { page } from '$app/stores';
	import Avatar from '$lib/components/avatar.svelte';
	import ProjectCreateButton from '$lib/components/projects/project-create-button.svelte';
	import ProjectDeleteButton from '$lib/components/projects/project-delete-button.svelte';
	import ProjectUpdateButton from '$lib/components/projects/project-update-button.svelte';
	import { listProjects } from '$lib/services/project-service.svelte';
	import { connections, mobSwitch, project } from '$lib/store';
	import { createQuery } from '@tanstack/svelte-query';
	import { LetterTextIcon, WorkflowIcon } from 'lucide-svelte';

	const query = createQuery({
		queryKey: ['list-projects'],
		queryFn: async () => await listProjects($page.data.session),
		initialData: []
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
					<a href={`/p/${project.id}`}>
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
				<ProjectUpdateButton />
				<ProjectDeleteButton />
			{/if}
		</div>
	</aside>
	<div class="w-full">
		<div class="navbar bg-base-100 h-12 border-b">
			<div class="flex-1 space-x-2 px-2">
				<span class="text-xl">{$project?.name}</span>
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
