import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';
import { onMount } from 'svelte';
import { ModuleCacheMap } from 'vite/runtime';

export function editor(el: HTMLElement, value: string) {
    let editor: Monaco.editor.IStandaloneCodeEditor;
    let monaco: typeof Monaco;
    let model: Monaco.editor.ITextModel;

    onMount(async () => {
        monaco = (await import('$lib/monaco')).default;

        // Your monaco instance is ready, let's display some code!
        editor = monaco.editor.create(el, {
            theme: 'default',
            minimap: { enabled: false },
        });

        model = monaco.editor.createModel(value, 'ddd');

        editor.setModel(model);

        model.onDidChangeContent((e) => {
            el.dispatchEvent(new CustomEvent<string>('contentchange',
                { detail: model.getValue() }));
        });
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