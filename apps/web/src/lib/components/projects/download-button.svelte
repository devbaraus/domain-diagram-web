<script lang="ts">
	import { page } from '$app/stores';
	import { DownloadIcon, ChevronDownIcon } from 'lucide-svelte';
	import { diagram } from '$lib/store';

	let processing = false;
	let modal: HTMLDialogElement;
	let widthPerContext = 1200;
	let imageformat = 'image/png';

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
			`-40 -40 ${group?.getBBox().width + 20} ${group?.getBBox().height}`
		);

		const contexts = Math.ceil(Math.sqrt($diagram.contexts.length));
		const contextWidth = contexts * widthPerContext;
		const scale = contextWidth / svg?.getBBox().width;

		svgToCanvasAndDownload(svg, 'diagram.png', scale, () => {
			group?.setAttribute('transform', transform);
			svg?.setAttribute('width', width);
			svg?.setAttribute('height', height);
			svg?.setAttribute('viewBox', viewBox);
			processing = false;
			modal.close();
		});
	}

	function svgToCanvasAndDownload(
		svgElement,
		filename = 'image.png',
		scale: number,
		callback: Function
	) {
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
			a.href = canvas.toDataURL(imageformat);

			const ext = imageformat.split('/')[1];
			a.download = $page.data.item?.name ? `${$page.data.item.name}.${ext}` : filename;
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
	<button
		disabled={processing}
		class="btn btn-info mask mask-squircle"
		onclick={() => modal.showModal()}
	>
		<span class="sr-only">download</span>
		<DownloadIcon class="size-5" />
	</button>
</div>

<dialog bind:this={modal} class="modal">
	<div class="modal-box max-w-3xl">
		<h3 class="mb-2 text-lg font-bold">Configure download</h3>
		<label class="label gap-2">
			<span class="label-text">Context Width</span>
			<input class="input input-bordered flex-1" inputmode="numeric" bind:value={widthPerContext} />
		</label>
		<label class="label gap-2">
			<span class="label-text"> Image Format </span>
			<select class="select select-bordered flex-1" bind:value={imageformat}>
				<option value="image/png">PNG</option>
				<option value="image/jpeg">JPEG</option>
				<option value="image/webp">WebP</option>
			</select>
		</label>
		<div class="modal-action">
			<form method="dialog">
				<!-- if there is a button in form, it will close the modal -->
				<button class="btn">Close</button>
				<button class="btn btn-primary" disabled={processing} onclick={downloadPng}>Download</button
				>
			</form>
		</div>
	</div>

	<form method="dialog" class="modal-backdrop">
		<button>close</button>
	</form>
</dialog>
