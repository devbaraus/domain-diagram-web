import { writable, type Writable } from "svelte/store";
import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';

export const editor: Writable<Monaco.editor.IStandaloneCodeEditor> = writable(null);
export const monaco: Writable<typeof Monaco> = writable(null);
export const model: Writable<Monaco.editor.ITextModel> = writable(null);
export const project: Writable<any> = writable(null);
export const session: Writable<string> = writable(null);
export const user: Writable<any> = writable(null);

export type DiagramStore = {
    fixed: boolean,
    nodeLayout: Layout
}

export type Layout = 'minheight' | 'nextindex'

export const diagramStore: Writable<DiagramStore> = writable({
    fixed: false,
    nodeLayout: 'minheight',
})