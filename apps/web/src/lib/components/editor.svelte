<script lang="ts">
	import { page } from '$app/stores';
	import { PUBLIC_WS_URL } from '$env/static/public';
	import { getAvatarColor } from '$lib';
	import { editor, model, monaco } from '$lib/store';
	import { color } from 'd3';
	import _ from 'lodash';
	import { onDestroy, onMount } from 'svelte';
	import * as Y from 'yjs';

	const backgrounds = [
		'bg-red-500',
		'bg-blue-500',
		'bg-green-500',
		'bg-yellow-500',
		'bg-indigo-500',
		'bg-purple-500',
		'bg-pink-500',
		'bg-gray-500'
	];

	const borders = [
		'border-l-red-500',
		'border-l-blue-500',
		'border-l-green-500',
		'border-l-yellow-500',
		'border-l-indigo-500',
		'border-l-purple-500',
		'border-l-pink-500',
		'border-l-gray-500'
	];

	let el: HTMLDivElement;
	let provider;
	let type;
	let doc;
	let binding;
	let awareness;
	let decorations;

	interface CursorsType {
		lineNumber: number;
		column: number;
	}
	interface SelectionsType {
		startLineNumber: number;
		startColumn: number;
		endLineNumber: number;
		endColumn: number;
	}

	let props: {
		value: string;
		class?: string;
		onchange?: (value: string) => void;
		onkeydown?: (e: KeyboardEvent) => void;
	} = $props();

	async function setup() {
		const { WebsocketProvider } = await import('y-websocket');
		const { MonacoBinding } = await import('y-monaco');
		$monaco = (await import('$lib/monaco')).default;

		// Your monaco instance is ready, let's display some code!
		$editor = $monaco.editor.create(el, {
			theme: 'default',
			wordWrap: 'wordWrapColumn',
			wordWrapColumn: 60,
			wrappingIndent: 'indent',
			lineNumbers: 'on',
			fontFamily: 'Fira Code',
			fontSize: 14,
			tabSize: 2,
			fontLigatures: "'zero', 'ss02', 'ss03', 'ss04', 'ss05', 'calt'",
			scrollBeyondLastLine: false,
			minimap: { enabled: false }
		});

		$model = $monaco.editor.createModel('', 'ddd');
		$editor.setModel($model);

		doc = new Y.Doc();
		provider = new WebsocketProvider(`${PUBLIC_WS_URL}`, $page.params.id, doc, {
			params: {
				access_token: $page.data.session
			}
		});

		type = doc.getText('monaco');
		binding = new MonacoBinding(type, $editor?.getModel()!, new Set([$editor]), provider.awareness);

		awareness = provider.awareness;
		awareness.setLocalState({
			user: {
				id: $page.data.user.id,
				name: $page.data.user.name
			}
		});

		// Update cursor positions for each user
		$editor.onDidChangeCursorPosition((e: any) => {
			decorations?.clear();
			const cursor = e.position;
			const localState = awareness?.getLocalState();
			awareness?.setLocalState({
				...localState,
				cursor
			});
		});

		$editor.onDidChangeCursorSelection((e: any) => {
			decorations?.clear();
			const selection = e.selection;
			let localState = awareness?.getLocalState();
			awareness?.setLocalState({
				...localState,
				selection
			});
		});

		awareness.on('change', () => {
			decorations?.clear();

			decorateCursors();
		});

		function decorateCursors() {
			const r: any = [];

			for (const deco of Array.from(
				awareness
					.getStates()
					.values()
					.filter((s) => s.user.id !== $page.data.user.id)
			)) {
				const user = deco.user;
				const cursor = deco.cursor;
				const selection = deco.selection;
				console.log('cursor', user);

				if (cursor) {
					r.push({
						range: new $monaco.Range(
							cursor.lineNumber,
							cursor.column,
							cursor.lineNumber,
							cursor.column + 1
						),
						options: {
							className: `${borders[user.id % borders.length]} opacity-50 rounded border-l-solid border-l-4 animate-pulse`,
							hoverMessage: {
								value: user.name,
								isTrusted: true
							}
						}
					});
				}

				if (selection) {
					r.push({
						range: new $monaco.Range(
							selection.startLineNumber,
							selection.startColumn,
							selection.endLineNumber,
							selection.endColumn
						),
						options: {
							className: `${backgrounds[user.id % backgrounds.length]} opacity-50 rounded`,
							hoverMessage: {
								value: user.name,
								isTrusted: true
							}
						}
					});
				}
			}

			decorations?.clear();
			decorations = $editor?.createDecorationsCollection(r);
		}

		$model.onDidChangeContent((e) => {
			props.onchange?.($model.getValue());
		});

		props.onchange?.($model.getValue());
	}

	function dispose() {
		provider?.disconnect();
		binding?.destroy();
		doc?.destroy();

		$model?.dispose();
		$editor?.dispose();
	}

	onMount(() => {
		setup();

		return dispose;
	});

	onDestroy(() => {
		dispose();
	});
</script>

<div
	id="editor"
	bind:this={el}
	class={props.class}
	onkeydown={props.onkeydown}
	role="textbox"
	aria-label="Code editor"
	aria-multiline="true"
	tabindex="0"
></div>

<style>
	#editor {
		width: calc((100vw * 0.3) - 48px);
	}

	/* Add color per user */
</style>
