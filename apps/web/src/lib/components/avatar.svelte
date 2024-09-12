<script lang="ts">
	import { getAvatarName } from '$lib';
	import { cn } from '$lib/utils';

	type Props = {
		class?: string;
		name: string;
	};

	let props: Props = $props();
</script>

<div class="avatar placeholder">
	<div
		class={cn(
			'mask mask-squircle bg-base-200 text-base-200-content flex size-12 items-center justify-center uppercase ',
			props.class
		)}
	>
		{getAvatarName(props.name)}
	</div>
</div>
