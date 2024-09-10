import { writable, type Writable } from "svelte/store";

export const editorInstance: Writable<Monaco.editor.IStandaloneCodeEditor> = writable(null);