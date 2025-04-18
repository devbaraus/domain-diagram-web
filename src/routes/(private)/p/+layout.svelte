<script lang="ts">
	import { page } from '$app/stores';
	import Avatar from '$lib/components/avatar.svelte';
	import DownloadButton from '$lib/components/projects/download-button.svelte';
	import ProjectCreateButton from '$lib/components/projects/project-create-button.svelte';
	import ProjectDeleteButton from '$lib/components/projects/project-delete-button.svelte';
	import ProjectUpdateButton from '$lib/components/projects/project-update-button.svelte';
	import { listProjects } from '$lib/services/project-service.svelte';
	import { connections, mobSwitch } from '$lib/store';
	import { createQuery } from '@tanstack/svelte-query';
	import { LetterTextIcon, WorkflowIcon } from 'lucide-svelte';
	interface Props {
		children?: import('svelte').Snippet;
	}

	let { children }: Props = $props();

	const query = createQuery({
		queryKey: ['list-projects'],
		queryFn: async () => await listProjects($page.data.session),
		initialData: $page.data.projects
	});
</script>

<div class="z-10 flex max-h-dvh divide-x">
	<aside class="bg-base-100 z-10 flex h-dvh w-16 flex-col justify-between p-2">
		<div class="space-y-2">
			<ProjectCreateButton />

			{#each $query.data as project}
				<div class="tooltip tooltip-right z-20" data-tip={project.name}>
					<a href={`/p/${project.id}`} data-sveltekit-reload>
						<Avatar
							class={project.id == $page.params.id ? 'bg-neutral text-neutral-content' : ''}
							name={project.name}
						/>
					</a>
				</div>
			{/each}
		</div>

		<div class="space-y-2">
			<DownloadButton />
			{#if $page.data.item?.members.find((i) => i.role === 'OWNER' && i.user.id === $page.data.user.id)}
				<ProjectUpdateButton />
				<ProjectDeleteButton />
			{/if}
		</div>
	</aside>
	<div class="max-h-dvh w-full">
		<div class="bg-base-100 flex h-10 border-b p-2">
			<div class="flex flex-1 space-x-2 px-2">
				<span class="text line-clamp-1 w-24 lg:w-64">{$page.data.item?.name}</span>
			</div>
			<div class="flex flex-none items-center gap-2 lg:gap-2">
				<ul class="space-x-2">
					{#each $connections.filter((i) => 'user' in i && $page.data.user.id !== i.user.id) as { user }}
						<li class="tooltip tooltip-bottom" data-tip={user.name}>
							<Avatar
								name={user.name}
								class="ddd-avatar size-6 rounded-full border-2"
								borderColor={user.color}
							/>
						</li>
					{/each}
				</ul>
				<button
					class="btn btn-info btn-xs mask mask-squircle lg:hidden"
					onclick={() => ($mobSwitch = !$mobSwitch)}
				>
					{#if !$mobSwitch}
						<LetterTextIcon class="size-4" />
					{:else}
						<WorkflowIcon class="size-4" />
					{/if}
				</button>
				<div class="dropdown dropdown-end">
					<div tabindex="0" role="button" class="avatar">
						<Avatar class="size-6" name={$page.data.user?.name} />
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
		<div class="h-[calc(100vh_-_2.5rem)]">
			{@render children?.()}
		</div>
	</div>
</div>
