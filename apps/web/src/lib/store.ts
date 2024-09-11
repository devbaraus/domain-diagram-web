import { writable, type Writable } from "svelte/store";
import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';

export const editor: Writable<Monaco.editor.IStandaloneCodeEditor> = writable(null);
export const monaco: Writable<typeof Monaco> = writable(null);
export const model: Writable<Monaco.editor.ITextModel> = writable(null);