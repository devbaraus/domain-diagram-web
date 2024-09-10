import { editorInstance } from '$lib/store';
import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';
import { getContext, onMount, setContext } from 'svelte';

export function editor(el: HTMLElement, value: string) {
    let editor: Monaco.editor.IStandaloneCodeEditor = $state(null);
    let monaco: typeof Monaco = $state(null);
    let model: Monaco.editor.ITextModel = $state(null)


    onMount(async () => {
        monaco = (await import('$lib/monaco')).default;

        // Your monaco instance is ready, let's display some code!
        editor = monaco.editor.create(el, {
            theme: 'default',
            wordWrap: 'on',
            scrollBeyondLastLine: false,
            minimap: { enabled: false },
        });

        model = monaco.editor.createModel(value, 'ddd');

        editor.setModel(model);

        model.onDidChangeContent((e) => {
            el.dispatchEvent(new CustomEvent<string>('contentchange',
                { detail: model.getValue() }));
        });

        editorInstance.set(editor);
    });

    return {
        update(value: string) {
            model.setValue(value);
        },
        destroy() {
            monaco?.editor.getModels().forEach((model) => model.dispose());
            editor?.dispose();
        }
    }
}