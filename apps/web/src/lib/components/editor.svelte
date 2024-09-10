<script lang="ts">
	import { editor } from '$lib/actions/editor.svelte';

	let data: {
		id?: string;
		value: string;
		class?: string;
		onkeydown?: (e: KeyboardEvent) => void;
		onchange?: (e: CustomEvent<string>) => void;
	} = $props();
</script>

<div
	id="editor"
	use:editor={data.value}
	onkeydown={data.onkeydown}
	oncontentchange={data.onchange}
	class={data.class}
	role="textbox"
	aria-label="Code editor"
	aria-multiline="true"
	tabindex="0"
></div>

<style>
	#editor {
		width: calc((100vw * 0.3) - 48px);
	}
</style>
