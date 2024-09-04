<script>
	import { page } from '$app/stores';
	import ProjectCreateButton from '$lib/components/projects/project-create-button.svelte';

	let projects = $page.data.items;
</script>

<svelte:head>
	<title>Domain Driven Diagram</title>
</svelte:head>

<div class="navbar bg-base-100 h-12 border-b">
	<div class="flex-1">
		<a class="text-xl" href="/d">Domain Driven Diagram</a>
	</div>
	<div class="flex-none items-center">
		<div class="dropdown dropdown-end">
			<div tabindex="0" role="button" class="avatar">
				<div class="w-12 rounded-full">
					<img alt="Random Avatar" src="https://avatar.iran.liara.run/public" />
				</div>
			</div>
			<ul class="menu menu-sm dropdown-content bg-base-100 rounded-box z-[1] w-52 p-2 shadow">
				<li>
					<form action="/api/auth/logout" class="flex w-full" method="get">
						<button class="w-full text-start">logout</button>
					</form>
				</li>
			</ul>
		</div>
	</div>
</div>

<div class="flex max-w-[100dvw]">
	<aside class="h-[calc(100dvh_-_64px)] max-h-[calc(100dvh_-_64px)] w-24 space-y-2 p-2">
		<ProjectCreateButton />

		{#each projects as project}
			<div class="tooltip tooltip-right z-20" data-tip={project.name}>
				<a href={`/d/${project.id}`}>
					<img
						class="mask mask-circle w-12"
						alt={`Project Avatar: ${project.name}`}
						src={`https://avatar.iran.liara.run/username?username=${project.name}`}
					/>
				</a>
			</div>
		{/each}
	</aside>
	<div class="z-0 flex flex-1">
		<slot></slot>
	</div>
</div>
