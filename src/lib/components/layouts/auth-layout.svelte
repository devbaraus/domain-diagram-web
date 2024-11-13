<script lang="ts">
	import { Routes } from '$lib';
	import { cn } from '$lib/utils';

	type Props = {
		tab: 'register' | 'login';
		children: () => any;
	};
	let props: Props = $props();
</script>

<div class="flex min-h-screen items-center justify-center self-center">
	<div class="flex flex-col items-stretch p-6 shadow md:p-8 lg:p-16">
		<div role="tablist" class="tabs tabs-bordered">
			<a
				href={Routes.LOGIN}
				class={cn('tab text-center text-xl font-semibold', props.tab === 'login' && 'tab-active')}
			>
				Login
			</a>
			<a
				href={Routes.REGISTER}
				class={cn(
					'tab text-center text-xl font-semibold',
					props.tab === 'register' && 'tab-active'
				)}
			>
				Register
			</a>
		</div>
		{@render props.children()}
	</div>
</div>
