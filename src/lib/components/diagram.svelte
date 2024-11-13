<script lang="ts">
	import { diagram } from '$lib/actions/diagram.svelte';

	type Props = {
		class?: string;
		diagram: Diagram;
	};

	let props: Props = $props();
</script>

<div class={props.class} use:diagram={props.diagram}></div>
