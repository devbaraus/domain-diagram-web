<script lang="ts">
    import { onDestroy, onMount } from 'svelte';
    import Diagram from '$lib/components/diagram.svelte';
    import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';
    import TreeSitter, {type Tree} from 'web-tree-sitter';
    import {grammar as defaultGrammar} from '$lib';

    let editor: Monaco.editor.IStandaloneCodeEditor;
    let monaco: typeof Monaco;
    let parser: TreeSitter | undefined;
    let editorContainer: HTMLElement;
    let tree = $state<Tree>();
    let grammar = $state(defaultGrammar);

    async function initializeParser() {
        await TreeSitter.init();
        parser = new TreeSitter();

        const dslLang = await TreeSitter.Language.load('/parser.wasm');
        parser.setLanguage(dslLang);
    }

    onMount(async () => {
        grammar = window.localStorage.getItem('grammar') || grammar;

        await initializeParser();

        // Import our 'monaco.ts' file here
        // (onMount() will only be executed in the browser, which is what we want)
        monaco = (await import('$lib/monaco')).default;

        // Your monaco instance is ready, let's display some code!
        const editor = monaco.editor.create(editorContainer);
        const model = monaco.editor.createModel(grammar, "ddd");
        editor.setModel(model);

        tree = parser?.parse(model?.getValue());

        model.onDidChangeContent(() => {
            grammar = model.getValue();
        });
    });

    $effect(() => {
        window.localStorage.setItem('grammar', grammar);
        tree = parser?.parse(grammar);
    })

    onDestroy(() => {
        monaco?.editor.getModels().forEach((model) => model.dispose());
        editor?.dispose();
    });
</script>

<div id="wrapper">
    <div id="code" bind:this={editorContainer}></div>
    <Diagram {tree}/>
</div>

<style>
    #wrapper {
        display: flex;
    }
    #code {
        width: 50vw;
        height: 100dvh;
    }

</style>s