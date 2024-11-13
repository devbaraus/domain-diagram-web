<script lang="ts">
	import { enhance } from '$app/forms';
	import { goto } from '$app/navigation';
	import { Routes } from '$lib';
	import AuthLayout from '$lib/components/layouts/auth-layout.svelte';
	import { toast } from 'svelte-sonner';
</script>

<AuthLayout tab="register">
	<form
		method="post"
		use:enhance={() => {
			return async ({ result }) => {
				if (result.status === 302 || result.status === 200) {
					toast.success('Registered successfully');
					goto(Routes.LOGIN);
				} else {
					toast.error('Invalid data');
				}
			};
		}}
		class="mt-6 w-96 md:mt-10"
	>
		<div class="space-y-3">
			<div class="form-control">
				<label for="name" class="label"><span class="label-text cursor-pointer">Name</span></label>
				<div class="form-control rounded-box border-base-content/20 border ps-3">
					<input
						id="name"
						placeholder="Name"
						class="input input-sm w-full transition-all focus:border-transparent focus:outline-0 focus:outline-offset-0"
						name="name"
					/>
				</div>
			</div>
			<div class="form-control">
				<label for="email" class="label"><span class="label-text cursor-pointer">Email</span></label
				>
				<div class="form-control rounded-box border-base-content/20 border ps-3">
					<input
						id="email"
						placeholder="example@dddiagram.com"
						type="email"
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
						placeholder="Password"
						class="input input-sm w-full transition-all focus:border-transparent focus:outline-0 focus:outline-offset-0"
						type="password"
						name="password"
					/>
				</div>
			</div>
		</div>
		<div class="mt-4 md:mt-6">
			<button class="btn btn-primary btn-block gap-2 text-base"> <span>Register</span></button>
		</div>
	</form>
</AuthLayout>
