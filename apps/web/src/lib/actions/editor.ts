import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';
import { onMount } from 'svelte';

export function editor(el: HTMLElement, value: string) {
    let editor: Monaco.editor.IStandaloneCodeEditor;
    let monaco: typeof Monaco;

    onMount(async () => {
        monaco = (await import('$lib/monaco')).default;

        // Your monaco instance is ready, let's display some code!
        const editor = monaco.editor.create(el, {
            theme: 'default'
        });

        const model = monaco.editor.createModel(value, 'ddd');

        editor.setModel(model);

        model.onDidChangeContent((e) => {
            el.dispatchEvent(new CustomEvent<string>('contentchange',
                { detail: model.getValue() }));
        });
    });

    return {
        destroy() {
            monaco?.editor.getModels().forEach((model) => model.dispose());
            editor?.dispose();
        }
    }
}