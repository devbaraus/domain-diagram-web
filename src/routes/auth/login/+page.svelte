<script lang="ts">
	import { enhance } from '$app/forms';
	import { goto } from '$app/navigation';
	import { Routes } from '$lib';
	import { queryClient } from '$lib/client';
	import AuthLayout from '$lib/components/layouts/auth-layout.svelte';
	import { LogInIcon } from 'lucide-svelte';
	import { toast } from 'svelte-sonner';
</script>

<AuthLayout tab="login">
	<form
		method="post"
		use:enhance={() => {
			return async ({ result }) => {
				if (result.status === 302 || result.status === 200) {
					await $queryClient.invalidateQueries({
						queryKey: ['list-projects']
					});
					goto('/p');
				} else {
					toast.error('Invalid credentials');
				}
			};
		}}
		class="mt-6 w-96 md:mt-10"
	>
		<div class="space-y-3">
			<div class="form-control">
				<label for="email" class="label"><span class="label-text cursor-pointer">Email</span></label
				>
				<div class="form-control rounded-box border-base-content/20 border ps-3">
					<input
						id="email"
						placeholder="demo@dddiagram.com"
						class="input input-sm w-full transition-all focus:border-transparent focus:outline-0 focus:outline-offset-0"
						name="email"
					/>
				</div>
			</div>
			<div class="form-control">
				<label for="password" class="label"
					><span class="label-text cursor-pointer">Password</span></label
				>
				<div class="form-control rounded-box border-base-content/20 border">
					<input
						id="password"
						placeholder="ddDemo1234)"
						class="input input-sm w-full transition-all focus:border-transparent focus:outline-0 focus:outline-offset-0"
						type="password"
						name="password"
					/>
				</div>
			</div>
		</div>
		<div class="mt-4 md:mt-6">
			<button class="btn btn-primary btn-block gap-2 text-base">
				<LogInIcon class="size-4" />
				<span>Login</span>
			</button>
		</div>
	</form>
</AuthLayout>
