<script lang="ts">
	import { page } from '$app/stores';
	import { DownloadIcon } from 'lucide-svelte';
	import { diagram } from '$lib/store';

	let processing = false;

	function downloadPng() {
		processing = true;
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
			`-40 -40 ${group?.getBoundingClientRect().width} ${group?.getBoundingClientRect().height}`
		);

		svgToCanvasAndDownload(svg, 'diagram.png', () => {
			group?.setAttribute('transform', transform);
			svg?.setAttribute('width', width);
			svg?.setAttribute('height', height);
			svg?.setAttribute('viewBox', viewBox);
			processing = false;
		});
	}

	function svgToCanvasAndDownload(svgElement, filename = 'image.png', callback: Function) {
		const contexts = Math.ceil(Math.sqrt($diagram.contexts.length));
		const widthPerContext = 1200;
		const width = contexts * widthPerContext;
		const scale = width / svgElement.getBBox().width;

		const svgData = new XMLSerializer().serializeToString(svgElement); // Convert SVG to XML string
		const svgBlob = new Blob([svgData], { type: 'image/svg+xml;charset=utf-8' }); // Create a Blob from the SVG
		const url = URL.createObjectURL(svgBlob); // Create a URL for the Blob

		const img = new Image(); // Create a new image element
		img.onload = function () {
			const canvas = document.createElement('canvas');
			const context = canvas.getContext('2d');

			// Set canvas dimensions based on the SVG size and scale factor
			canvas.width = svgElement.getBBox().width * scale;
			canvas.height = svgElement.getBBox().height * scale;

			// Draw the image on the canvas with scaling
			context.drawImage(img, 0, 0, canvas.width, canvas.height);

			// Create the download link
			const a = document.createElement('a');
			a.href = canvas.toDataURL('image/png');
			a.download = $page.data.item?.name ? `${$page.data.item.name}.png` : filename;
			document.body.appendChild(a);
			a.click();

			// Cleanup: remove the Blob URL and download link
			URL.revokeObjectURL(url);
			document.body.removeChild(a);
			callback();
		};

		img.src = url; // Set the SVG URL as the image source
	}
</script>

<div class="tooltip tooltip-right" data-tip="Download">
	<button disabled={processing} class="btn btn-info mask mask-squircle" onclick={downloadPng}>
		<span class="sr-only">download</span>
		<DownloadIcon class="size-5" />
	</button>
</div>
