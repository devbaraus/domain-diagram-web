<script lang="ts">
	type Props = {
		id: number;
		label: string;
	};
	let props: Props = $props();
</script>

<a href={`/p/${props.id}`}>{props.label}</a>
