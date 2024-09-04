<script lang="ts">
	type Props = {
		id: number;
		label: string;
	};
	let props: Props = $props();
</script>

<a href={`/d/${props.id}`}>{props.label}</a>
