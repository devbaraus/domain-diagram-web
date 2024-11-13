import * as monaco from 'monaco-editor';
import { findDefinition } from './utils/editor-utils';

monaco.languages.register({ id: 'ddd' });

monaco.languages.setMonarchTokensProvider('ddd', {
  tokenizer: {
    root: [
      [/\b(Context|BoundedContext|Aggregate|AggregateRoot|Entity|ValueObject|DomainEvent|Event|DomainService|Service|Enum|Repository)\b/, 'keyword'],
      [/\/\/.*/, 'comment'],
      [/\{/, 'delimiter.bracket'],
      [/\}/, 'delimiter.bracket'],
      [/[a-zA-Z_]\w*/, 'identifier'],
      [/\b(String|Int|UUID|Boolean|Float|Date|Null|true|false|null)\b/, 'type'],
      [/"[^"]*"/, 'string'],
      [/(\d+(\.\d+)?)/, 'number'],
      [/\[|\]/, 'delimiter.array'],
      [/@(emits|note)\w*/, 'annotation'],
    ],
  },
});

monaco.languages.setLanguageConfiguration('ddd', {
  comments: {
    lineComment: '//',
  },
  brackets: [
    ['{', '}'],
    ['[', ']'],
  ],
  autoClosingPairs: [
    { open: '{', close: '}' },
    { open: '[', close: ']' },
    { open: '"', close: '"' },
  ],
  surroundingPairs: [
    { open: '{', close: '}' },
    { open: '[', close: ']' },
    { open: '"', close: '"' },
  ],
  indentationRules: {
    increaseIndentPattern: /{\s*$/,
    decreaseIndentPattern: /^\s*}/,
  },
});

monaco.languages.registerDocumentFormattingEditProvider('ddd', {
  provideDocumentFormattingEdits: function (model, options, token) {
    const text = model.getValue();
    const formatted = formatDDDCode(text);
    return [
      {
        range: model.getFullModelRange(),
        text: formatted
      }
    ];
  }
});

function formatDDDCode(text) {
  const lines = text.split('\n');
  let indentLevel = 0;
  const indentString = '  '; // Two spaces indentation

  const formattedLines = lines.map((line) => {
    const trimmedLine = line.trim();

    if (trimmedLine.endsWith('}')) {
      indentLevel--;
    }

    const indentedLine = indentString.repeat(indentLevel) + trimmedLine;

    if (trimmedLine.endsWith('{')) {
      indentLevel++;
    }

    return indentedLine;
  });

  return formattedLines.join('\n');
}


monaco.languages.registerCompletionItemProvider("ddd", {
  provideCompletionItems: () => {
    const suggestions = [
      // Keywords
      {
        label: 'Context',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Context ${1:ContextName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new context',
      },
      {
        label: 'Aggregate',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Aggregate ${1:AggregateName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new aggregate',
      },
      {
        label: 'Entity',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Entity ${1:EntityName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new entity',
      },
      {
        label: 'ValueObject',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'ValueObject ${1:ValueObjectName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new value object',
      },
      {
        label: 'Enum',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Enum ${1:EnumName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new enum',
      },
      {
        label: 'Event',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Event ${1:EventName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new domain event',
      },
      {
        label: 'Service',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Service ${1:ServiceName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new service',
      },
      {
        label: 'Repository',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: 'Repository ${1:RepositoryName} {\n\t$0\n}',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Defines a new repository',
      },
      {
        label: 'emits',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: '@emits(${1:EventName})',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,

        documentation: 'Annotation for domain events',
      },
      {
        label: 'note',
        kind: monaco.languages.CompletionItemKind.Keyword,
        insertText: '@note("${1:Note}")',
        insertTextRules: monaco.languages.CompletionItemInsertTextRule.InsertAsSnippet,
        documentation: 'Annotation for notes',
      },
      // Primitive types
      {
        label: 'String',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'String',
        documentation: 'Primitive type: String',
      },
      {
        label: 'Int',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'Int',
        documentation: 'Primitive type: Int',
      },
      {
        label: 'UUID',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'UUID',
        documentation: 'Primitive type: UUID',
      },
      {
        label: 'Boolean',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'Boolean',
        documentation: 'Primitive type: Boolean',
      },
      {
        label: 'Float',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'Float',
        documentation: 'Primitive type: Float',
      },
      {
        label: 'Date',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'Date',
        documentation: 'Primitive type: Date',
      },
      {
        label: 'Null',
        kind: monaco.languages.CompletionItemKind.TypeParameter,
        insertText: 'Null',
        documentation: 'Primitive type: Null',
      },
      // Additional elements like methods, fields, and more can be added here...
    ];

    return { suggestions: suggestions };
  },
});

monaco.languages.registerHoverProvider("ddd", {
  provideHover: function (model, position) {
    const word = model.getWordAtPosition(position);

    // Define hover content for domain-specific keywords
    const hoverContent = {
      Context: {
        contents: [
          { value: "**Context**" },
          { value: "Defines a bounded context where aggregates, entities, value objects, etc. reside." },
          { value: "`Context ContextName { ... }`" }
        ],
      },
      Aggregate: {
        contents: [
          { value: "**Aggregate**" },
          { value: "Represents a cluster of associated objects treated as a unit." },
          { value: "`Aggregate AggregateName { ... }`" }
        ],
      },
      Entity: {
        contents: [
          { value: "**Entity**" },
          { value: "An object with identity that persists over time." },
          { value: "`Entity EntityName { ... }`" }
        ],
      },
      ValueObject: {
        contents: [
          { value: "**ValueObject**" },
          { value: "An object that has no identity but represents a conceptual value." },
          { value: "`ValueObject ValueObjectName { ... }`" }
        ],
      },
      Enum: {
        contents: [
          { value: "**Enum**" },
          { value: "Defines an enumeration, a fixed set of constant values." },
          { value: "`Enum EnumName { Value1, Value2, ... }`" }
        ],
      },
      Event: {
        contents: [
          { value: "**Event**" },
          { value: "Represents a domain event, something that happened in the domain." },
          { value: "`Event EventName { ... }`" }
        ],
      },
      Service: {
        contents: [
          { value: "**Service**" },
          { value: "Defines a domain service that handles business logic." },
          { value: "`Service ServiceName { ... }`" }
        ],
      },
      String: {
        contents: [
          { value: "**String**" },
          { value: "A primitive data type representing textual data." }
        ],
      },
      Int: {
        contents: [
          { value: "**Int**" },
          { value: "A primitive data type representing an integer number." }
        ],
      },
      UUID: {
        contents: [
          { value: "**UUID**" },
          { value: "A universally unique identifier, commonly used for identifying entities." }
        ],
      },
      Boolean: {
        contents: [
          { value: "**Boolean**" },
          { value: "A primitive data type representing true/false values." }
        ],
      },
      Float: {
        contents: [
          { value: "**Float**" },
          { value: "A primitive data type representing a floating-point number." }
        ],
      },
      Date: {
        contents: [
          { value: "**Date**" },
          { value: "A primitive data type representing a calendar date." }
        ],
      },
      Null: {
        contents: [
          { value: "**Null**" },
          { value: "Represents a null or undefined value." }
        ],
      },
    };

    // Return the hover content for the word if it exists
    if (word && hoverContent[word.word]) {
      return {
        range: new monaco.Range(
          position.lineNumber,
          word.startColumn,
          position.lineNumber,
          word.endColumn
        ),
        contents: hoverContent[word.word].contents,
      };
    }
    return null;
  },
});


const dracula = {
  "base": "vs-dark",
  "inherit": true,
  "rules": [
    {
      "background": "282a36",
      "token": ""
    },
    {
      "foreground": "6272a4",
      "token": "comment"
    },
    {
      "foreground": "f1fa8c",
      "token": "string"
    },
    {
      "foreground": "bd93f9",
      "token": "constant.numeric"
    },
    {
      "foreground": "bd93f9",
      "token": "constant.language"
    },
    {
      "foreground": "bd93f9",
      "token": "constant.character"
    },
    {
      "foreground": "bd93f9",
      "token": "constant.other"
    },
    {
      "foreground": "ffb86c",
      "token": "variable.other.readwrite.instance"
    },
    {
      "foreground": "ff79c6",
      "token": "constant.character.escaped"
    },
    {
      "foreground": "ff79c6",
      "token": "constant.character.escape"
    },
    {
      "foreground": "ff79c6",
      "token": "string source"
    },
    {
      "foreground": "ff79c6",
      "token": "string source.ruby"
    },
    {
      "foreground": "ff79c6",
      "token": "keyword"
    },
    {
      "foreground": "ff79c6",
      "token": "storage"
    },
    {
      "foreground": "8be9fd",
      "fontStyle": "italic",
      "token": "storage.type"
    },
    {
      "foreground": "50fa7b",
      "fontStyle": "underline",
      "token": "entity.name.class"
    },
    {
      "foreground": "50fa7b",
      "fontStyle": "italic underline",
      "token": "entity.other.inherited-class"
    },
    {
      "foreground": "50fa7b",
      "token": "entity.name.function"
    },
    {
      "foreground": "ffb86c",
      "fontStyle": "italic",
      "token": "variable.parameter"
    },
    {
      "foreground": "ff79c6",
      "token": "entity.name.tag"
    },
    {
      "foreground": "50fa7b",
      "token": "entity.other.attribute-name"
    },
    {
      "foreground": "8be9fd",
      "token": "support.function"
    },
    {
      "foreground": "6be5fd",
      "token": "support.constant"
    },
    {
      "foreground": "66d9ef",
      "fontStyle": " italic",
      "token": "support.type"
    },
    {
      "foreground": "66d9ef",
      "fontStyle": " italic",
      "token": "support.class"
    },
    {
      "foreground": "f8f8f0",
      "background": "ff79c6",
      "token": "invalid"
    },
    {
      "foreground": "f8f8f0",
      "background": "bd93f9",
      "token": "invalid.deprecated"
    },
    {
      "foreground": "cfcfc2",
      "token": "meta.structure.dictionary.json string.quoted.double.json"
    },
    {
      "foreground": "6272a4",
      "token": "meta.diff"
    },
    {
      "foreground": "6272a4",
      "token": "meta.diff.header"
    },
    {
      "foreground": "ff79c6",
      "token": "markup.deleted"
    },
    {
      "foreground": "50fa7b",
      "token": "markup.inserted"
    },
    {
      "foreground": "e6db74",
      "token": "markup.changed"
    },
    {
      "foreground": "bd93f9",
      "token": "constant.numeric.line-number.find-in-files - match"
    },
    {
      "foreground": "e6db74",
      "token": "entity.name.filename"
    },
    {
      "foreground": "f83333",
      "token": "message.error"
    },
    {
      "foreground": "eeeeee",
      "token": "punctuation.definition.string.begin.json - meta.structure.dictionary.value.json"
    },
    {
      "foreground": "eeeeee",
      "token": "punctuation.definition.string.end.json - meta.structure.dictionary.value.json"
    },
    {
      "foreground": "8be9fd",
      "token": "meta.structure.dictionary.json string.quoted.double.json"
    },
    {
      "foreground": "f1fa8c",
      "token": "meta.structure.dictionary.value.json string.quoted.double.json"
    },
    {
      "foreground": "50fa7b",
      "token": "meta meta meta meta meta meta meta.structure.dictionary.value string"
    },
    {
      "foreground": "ffb86c",
      "token": "meta meta meta meta meta meta.structure.dictionary.value string"
    },
    {
      "foreground": "ff79c6",
      "token": "meta meta meta meta meta.structure.dictionary.value string"
    },
    {
      "foreground": "bd93f9",
      "token": "meta meta meta meta.structure.dictionary.value string"
    },
    {
      "foreground": "50fa7b",
      "token": "meta meta meta.structure.dictionary.value string"
    },
    {
      "foreground": "ffb86c",
      "token": "meta meta.structure.dictionary.value string"
    }
  ],
  "colors": {
    "editor.foreground": "#f8f8f2",
    "editor.background": "#282a36",
    "editor.selectionBackground": "#44475a",
    "editor.lineHighlightBackground": "#44475a",
    "editorCursor.foreground": "#f8f8f0",
    "editorWhitespace.foreground": "#3B3A32",
    "editorIndentGuide.activeBackground": "#9D550FB0",
    "editor.selectionHighlightBorder": "#222218"
  }
}


monaco.editor.defineTheme('dracula', dracula)

export default monaco;