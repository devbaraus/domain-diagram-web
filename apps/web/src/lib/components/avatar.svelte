<script lang="ts">
	import { getAvatarName } from '$lib';

	type Props = {
		name: string;
	};

	let props: Props = $props();
</script>

<div class="avatar placeholder">
	<div
		class="mask mask-squircle bg-neutral text-neutral-content flex size-12 items-center justify-center uppercase"
	>
		{getAvatarName(props.name)}
	</div>
</div>
