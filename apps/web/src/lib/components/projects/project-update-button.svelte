<script lang="ts">
	import { page } from '$app/stores';
	import { queryClient } from '$lib/client';
	import { updateProject } from '$lib/services/project-service.svelte';
	import { cn } from '$lib/utils';
	import { createMutation } from '@tanstack/svelte-query';
	import { PenIcon } from 'lucide-svelte';
	import { toast } from 'svelte-sonner';

	let modal: HTMLDialogElement | undefined;

	let members = $state([]);
	let name = $state($page.data.item.name);
	let pub = $state($page.data.item.public);
	let realtime = $state($page.data.item.realtime);

	$effect(() => {
		members = $page.data.item?.members.map((i) => ({ email: i.user.email, role: i.role }));
	});

	const update = createMutation({
		mutationFn: async (data) => await updateProject($page.params.id, data, $page.data.session),
		onSuccess: () => {
			modal?.close();
			toast.success('Project shared successfully');
			$queryClient.invalidateQueries({ queryKey: ['list-projects'] });
			// window.location.reload();
		},
		onError: () => {
			modal?.close();
			toast.error('Failed to share project');
		}
	});

	function handleSubmit() {
		$update.mutate({
			name: name,
			public: pub,
			realtime: realtime,
			members: members
		});
	}
</script>

<dialog bind:this={modal} class="modal">
	<div class="modal-box max-w-3xl space-y-2">
		<p>Update the settings this project</p>

		<label class="label cursor-pointer justify-start gap-2">
			<span class="label-text">Name</span>
			<input
				class="input input-sm input-bordered flex w-full items-center gap-2"
				name="name"
				minlength="3"
				type="text"
				placeholder="Daisy"
				value={$page.data.item.name}
			/>
		</label>

		<label class="label cursor-pointer justify-start gap-2">
			<span class="label-text">Public</span>
			<input name="public" type="checkbox" class="toggle" bind:checked={pub} />
		</label>

		<label class="label cursor-pointer justify-start gap-2">
			<span class="label-text">Realtime</span>
			<input name="public" type="checkbox" class="toggle" bind:checked={realtime} />
		</label>

		<div class="space-y-1">
			{#if members}
				{#each members as member, index}
					<div class="grid border-collapse grid-cols-5 gap-2">
						<input
							bind:value={member.email}
							class={'input input-sm input-bordered col-span-3'}
							type="text"
							disabled={member.role === 'OWNER'}
						/>

						<select
							bind:value={member.role}
							class="select select-bordered select-sm col-span-1"
							disabled={member.role === 'OWNER'}
						>
							<option value="OWNER">OWNER</option>
							<option value="VIEWER">VIEWER</option>
							<option value="EDITOR">EDITOR</option>
						</select>

						<button
							type="button"
							class={cn('btn btn-sm')}
							disabled={member.role === 'OWNER'}
							onclick={() => (members = members.filter((i) => i.email !== member.email))}
							>Remove
						</button>
					</div>
				{/each}
			{/if}
		</div>
		<div class="label mt-2">
			<form
				class="grid w-full grid-cols-5 gap-2"
				onsubmit={(e) => {
					e.preventDefault();

					const email = e.target[0].value;
					const role = e.target[1].value;

					if (members.find((i) => i.email === email)) return;

					members.push({ email: email, role: role });

					e.target[0].value = '';
					e.target[1].value = 'VIEWER';
				}}
			>
				<input
					id="member"
					class="input input-bordered input-sm col-span-3 w-full"
					type="email"
					placeholder="Add member by email"
				/>
				<select class="select select-bordered select-sm" name="role">
					<option value="VIEWER">VIEWER</option>
					<option value="EDITOR">EDITOR</option>
				</select>
				<button class={'btn btn-sm'}>Add</button>
			</form>
		</div>

		<div class="modal-action">
			<button
				type="button"
				class="btn mr-auto"
				onclick={() => {
					navigator.clipboard.writeText(
						`${$page.url.protocol}//${$page.url.host}/e/${$page.params.id}?token=${$page.data.item.embed}`
					);
					modal?.close();
					toast.success('Embed code copied to clipboard');
				}}>Embed</button
			>
			<button type="button" class="btn" onclick={() => modal?.close()}>Cancel</button>
			<button class="btn btn-primary" onclick={handleSubmit}>Save</button>
		</div>
	</div>
</dialog>

<div class="tooltip tooltip-right" data-tip="Update">
	<button class="btn btn-primary mask mask-squircle" onclick={() => modal?.showModal()}>
		<span class="sr-only">update</span>
		<PenIcon class="size-5" />
	</button>
</div>
