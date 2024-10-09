<script lang="ts">
	import Diagram from '$lib/components/diagram.svelte';
	import { model, monaco } from '$lib/store';
	import { cn } from '$lib/utils';
	import { extractDiagram } from '$lib/utils/diagram-extractor';
	import { checkForSyntaxErrors } from '$lib/utils/editor-utils';
	import _ from 'lodash';
	import { onDestroy, onMount } from 'svelte';
	import TreeSitter, { type Tree } from 'web-tree-sitter';
	import { WebsocketProvider } from 'y-websocket';
	import { PUBLIC_WS_URL } from '$env/static/public';
	import { page } from '$app/stores';
	import * as Y from 'yjs';

	let parser: TreeSitter | undefined;
	let tree = $state<Tree>();
	let diagram = $state<Diagram>();
	let provider;
	let type;
	let doc;

	const updateTree = (value: string) => {
		tree = parser?.parse(value);

		const errors = checkForSyntaxErrors(tree?.rootNode);

		if (errors.length) {
			$monaco?.editor.setModelMarkers($model, 'ddd', errors);
			return;
		}

		diagram = extractDiagram(tree?.rootNode);
	};

	const debouncedTreeUpdate = _.debounce((value: string) => {
		updateTree(value);
	}, 300);

	async function initializeParser() {
		await TreeSitter.init({
			locateFile(scriptName: string, scriptDirectory: string) {
				return `${$page.url.origin}/${scriptName}`;
			}
		});
		parser = new TreeSitter();

		const dslLang = await TreeSitter.Language.load('/tree-sitter-ddd.wasm');
		parser.setLanguage(dslLang);
	}

	function dispose() {
		provider?.destroy();
		doc?.destroy();
	}

	onMount(async () => {
		await initializeParser();

		if ($page.data.item.realtime) {
			doc = new Y.Doc();

			const embedToken = $page.url.searchParams.get('token');
			const accessToken = $page.data.session;

			provider = new WebsocketProvider(`${PUBLIC_WS_URL}`, $page.params.id, doc, {
				params: accessToken
					? {
							access_token: accessToken
						}
					: embedToken
						? {
								embed_token: embedToken
							}
						: undefined
			});

			type = doc.getText('monaco');

			provider.on('status', (event) => {
				if (event.status === 'connected') {
					updateTree(type?.toJSON());

					type?.observe(() => {
						debouncedTreeUpdate(type?.toJSON());
					});
				}
			});
		} else {
			updateTree($page.data.item.markup);
		}

		return dispose;
	});

	onDestroy(() => {
		dispose();
	});
</script>

<Diagram class={cn('font-fira h-screen w-full flex-1 select-none overflow-hidden')} {diagram} />
