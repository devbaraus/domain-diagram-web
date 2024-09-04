<script lang="ts">
	import { editor } from '$lib/actions/editor';

	let data: {
		value: string;
		class?: string;
		onkeydown?: (e: KeyboardEvent) => void;
		onchange?: (e: CustomEvent<string>) => void;
	} = $props();
</script>

<div
	use:editor={data.value}
	onkeydown={data.onkeydown}
	oncontentchange={data.onchange}
	class={data.class}
	role="textbox"
	aria-label="Code editor"
	aria-multiline="true"
	tabindex="0"
></div>
