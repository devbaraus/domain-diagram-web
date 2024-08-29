import * as monaco from 'monaco-editor';

// Import the workers in a production-safe way.
// This is different than in Monaco's documentation for Vite,
// but avoids a weird error ("Unexpected usage") at runtime
// import editorWorker from 'monaco-editor/esm/vs/editor/editor.worker?worker';
// import cssWorker from 'monaco-editor/esm/vs/language/css/css.worker?worker';
// import htmlWorker from 'monaco-editor/esm/vs/language/html/html.worker?worker';
// import jsonWorker from 'monaco-editor/esm/vs/language/json/json.worker?worker';
// import tsWorker from 'monaco-editor/esm/vs/language/typescript/ts.worker?worker';

// self.MonacoEnvironment = {
//     getWorker: function (_: string, label: string) {
//         switch (label) {
//             case 'json':
//                 return new jsonWorker();
//             case 'css':
//             case 'scss':
//             case 'less':
//                 return new cssWorker();
//             case 'html':
//             case 'handlebars':
//             case 'razor':
//                 return new htmlWorker();
//             case 'typescript':
//             case 'javascript':
//                 return new tsWorker();
//             default:
//                 return new editorWorker();
//         }
//     }
// };

monaco.languages.register({ id: 'ddd' });

monaco.editor.defineTheme('default', {
  "base": "vs-dark",
  "inherit": true,
  "rules": [
    {
      "background": "272822",
      "token": ""
    },
    {
      "foreground": "75715e",
      "token": "comment"
    },
    {
      "foreground": "e6db74",
      "token": "string"
    },
    {
      "foreground": "ae81ff",
      "token": "constant.numeric"
    },
    {
      "foreground": "ae81ff",
      "token": "constant.language"
    },
    {
      "foreground": "ae81ff",
      "token": "constant.character"
    },
    {
      "foreground": "ae81ff",
      "token": "constant.other"
    },
    {
      "foreground": "f92672",
      "token": "keyword"
    },
    {
      "foreground": "f92672",
      "token": "variable.other.dollar.only.js"
    },
    {
      "foreground": "f92672",
      "token": "storage"
    },
    {
      "foreground": "66d9ef",
      "fontStyle": "italic",
      "token": "storage.type"
    },
    {
      "foreground": "a6e22e",
      "fontStyle": "underline",
      "token": "entity.name.class"
    },
    {
      "foreground": "a6e22e",
      "fontStyle": "italic underline",
      "token": "entity.other.inherited-class"
    },
    {
      "foreground": "a6e22e",
      "token": "entity.name.function"
    },
    {
      "foreground": "fd971f",
      "fontStyle": "italic",
      "token": "variable.parameter"
    },
    {
      "foreground": "f92672",
      "token": "entity.name.tag"
    },
    {
      "foreground": "a6e22e",
      "token": "entity.other.attribute-name"
    },
    {
      "foreground": "66d9ef",
      "token": "support.function"
    },
    {
      "foreground": "66d9ef",
      "token": "support.constant"
    },
    {
      "foreground": "66d9ef",
      "fontStyle": "italic",
      "token": "support.type"
    },
    {
      "foreground": "66d9ef",
      "fontStyle": "italic",
      "token": "support.class"
    },
    {
      "foreground": "f8f8f0",
      "background": "f92672",
      "token": "invalid"
    },
    {
      "foreground": "f8f8f0",
      "background": "ae81ff",
      "token": "invalid.deprecated"
    },
    {
      "foreground": "cfcfc2",
      "token": "meta.structure.dictionary.json string.quoted.double.json"
    },
    {
      "foreground": "75715e",
      "token": "meta.diff"
    },
    {
      "foreground": "75715e",
      "token": "meta.diff.header"
    },
    {
      "foreground": "f92672",
      "token": "markup.deleted"
    },
    {
      "foreground": "a6e22e",
      "token": "markup.inserted"
    },
    {
      "foreground": "e6db74",
      "token": "markup.changed"
    },
    {
      "foreground": "ae81ffa0",
      "token": "constant.numeric.line-number.find-in-files - match"
    },
    {
      "foreground": "e6db74",
      "token": "entity.name.filename.find-in-files"
    }
  ],
  "colors": {
    "editor.foreground": "#F8F8F2",
    "editor.background": "#272822",
    "editor.selectionBackground": "#9D550F",
    "editor.inactiveSelectionBackground": "#bbbbbb",
    "editor.lineHighlightBackground": "#3E3D32",
    "editorCursor.foreground": "#F8F8F0",
    "editorWhitespace.foreground": "#3B3A32",
    "editorIndentGuide.activeBackground": "#9D550FB0"
  }
})

monaco.languages.setMonarchTokensProvider('ddd', {
  tokenizer: {
    root: [
      [/\b(aggregate|entity|value_object|enum|identifier)\b/, 'keyword'],
      [/\b(UUID|String|Boolean|Float|Int|Date)\b/, 'type'],
      [/\b[a-zA-Z_][a-zA-Z0-9_]*\b/, 'identifier'],
      [/{|}/, 'delimiter.bracket'],
      [/:/, 'delimiter'],
      [/\[|\]/, 'delimiter.square'],
    ],
  },
});

export default monaco;