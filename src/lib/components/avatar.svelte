<script lang="ts">
	import { getAvatarName } from '$lib';
	import { cn } from '$lib/utils';

	type Props = {
		class?: string;
		borderColor?: string;
		name: string;
	};

	let { borderColor, class: className, name, ...rest }: Props = $props();
</script>

<div class="avatar placeholder select-none">
	<div
		style="--border-color: {borderColor};"
		class={cn(
			'mask mask-squircle bg-base-200 text-base-200-content flex size-12 items-center justify-center uppercase',
			className
		)}
		{...rest}
	>
		{getAvatarName(name)}
	</div>
</div>

<style>
	.ddd-avatar {
		border-color: var(--border-color);
	}
</style>
