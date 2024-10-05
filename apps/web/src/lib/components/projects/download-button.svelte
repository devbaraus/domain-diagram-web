<script lang="ts">
	import { DownloadIcon } from 'lucide-svelte';
	import * as donwloader from 'save-svg-as-png';

	function downloadPng() {
		const group = document.querySelector('#diagram > g');
		const transform = group?.getAttribute('transform');

		group?.setAttribute('transform', 'translate(0,0)');

		const svg = document.querySelector('#diagram');
		const width = svg?.getAttribute('width');
		const height = svg?.getAttribute('height');
		const viewBox = svg?.getAttribute('viewBox');

		svg?.setAttribute('width', '100%');
		svg?.setAttribute('height', '100%');
		svg?.setAttribute(
			'viewBox',
			`0 0 ${group?.getBoundingClientRect().width} ${group?.getBoundingClientRect().height + 20}`
		);

		donwloader
			.saveSvgAsPng(svg, 'diagram.png', {
				scale: 2,
				top: -40
			})
			.then(() => {
				group?.setAttribute('transform', transform);
				svg?.setAttribute('width', width);
				svg?.setAttribute('height', height);
				svg?.setAttribute('viewBox', viewBox);
			});
	}
</script>

<div class="tooltip tooltip-right" data-tip="Download">
	<button class="btn btn-info mask mask-squircle" onclick={downloadPng}>
		<span class="sr-only">download</span>
		<DownloadIcon class="size-5" />
	</button>
</div>
