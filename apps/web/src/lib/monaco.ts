import * as monaco from 'monaco-editor';
import { findDefinition } from './utils/editor-utils';

monaco.languages.register({ id: 'ddd' });

monaco.languages.setMonarchTokensProvider('ddd', {
  tokenizer: {
    root: [
      [/\b(Context|BoundedContext|Aggregate|AggregateRoot|Entity|ValueObject|DomainEvent|Event|DomainService|Service|Enum)\b/, 'keyword'],
      [/\/\/.*/, 'comment'],
      [/\{/, 'delimiter.bracket'],
      [/\}/, 'delimiter.bracket'],
      [/[a-zA-Z_]\w*/, 'identifier'],
      [/\b(String|Int|UUID|Boolean|Float|Date|Null|true|false|null)\b/, 'type'],
      [/"[^"]*"/, 'string'],
      [/(\d+(\.\d+)?)/, 'number'],
      [/\[|\]/, 'delimiter.array'],
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


monaco.editor.defineTheme('dark', {
  base: 'vs-dark', // Use dark base theme
  inherit: true,   // Inherit other default Monaco settings
  rules: [
    // Token rules for syntax highlighting
    { token: '', foreground: '888888' }, // Default foreground
    { token: 'support.function', foreground: 'b392f0' },
    { token: 'keyword.operator.accessor', foreground: 'b392f0' },
    { token: 'meta.group.braces.round.function.arguments', foreground: 'b392f0' },
    { token: 'meta.template.expression', foreground: 'b392f0' },
    { token: 'markup.fenced_code meta.embedded.block', foreground: 'b392f0' },
    { token: 'emphasis', fontStyle: 'italic' },
    { token: 'strong', foreground: 'FF7A84', fontStyle: 'bold' },
    { token: 'markup.heading.markdown', foreground: 'FF7A84', fontStyle: 'bold' },
    { token: 'markup.bold.markdown', foreground: 'FF7A84', fontStyle: 'bold' },
    { token: 'markup.italic.markdown', fontStyle: 'italic' },
    { token: 'meta.link.inline.markdown', foreground: '1976D2', fontStyle: 'underline' },
    { token: 'string', foreground: '9db1c5' },
    { token: 'markup.fenced_code', foreground: '9db1c5' },
    { token: 'markup.inline', foreground: '9db1c5' },
    { token: 'comment', foreground: '6b737c' },
    { token: 'string.quoted.docstring.multi', foreground: '6b737c' },
    { token: 'constant.language', foreground: '79b8ff' },
    { token: 'variable.language.this', foreground: '79b8ff' },
    { token: 'variable.other.object', foreground: '79b8ff' },
    { token: 'variable.other.class', foreground: '79b8ff' },
    { token: 'meta.property-name', foreground: '79b8ff' },
    { token: 'constant.numeric', foreground: 'f8f8f8' },
    { token: 'constant.other.placeholder', foreground: 'f8f8f8' },
    { token: 'meta.property-value', foreground: 'f8f8f8' },
    { token: 'keyword', foreground: 'f97583' },
    { token: 'variable.parameter.function', foreground: 'FF9800' },
    { token: 'entity.name.type', foreground: 'b392f0' },
    { token: 'entity.name.tag', foreground: 'ffab70' },
    { token: 'string.quoted', foreground: 'ffab70' },
    { token: 'constant.language', foreground: '79b8ff' },
    { token: 'entity.name.function', foreground: 'b392f0' },
    { token: 'entity.other.attribute-name', foreground: 'b392f0' },
    { token: 'punctuation.definition.metadata.markdown', foreground: 'ffab70' },
    { token: 'token.info-token', foreground: '316bcd' },
    { token: 'token.warn-token', foreground: 'cd9731' },
    { token: 'token.error-token', foreground: 'cd3131' },
    { token: 'token.debug-token', foreground: '800080' },
    { token: 'punctuation.definition.arguments', foreground: 'bbbbbb' },
    { token: 'markup.underline.link', foreground: 'ffab70' },
    { token: 'beginning.punctuation.definition.list.markdown', foreground: 'FF7A84' }
  ],
  colors: {
    // Editor and UI Colors
    'editor.background': '#1f1f1f',
    'editor.foreground': '#888888',
    'editor.lineHighlightBackground': '#303030',
    'editorLineNumber.foreground': '#727272',
    'editorIndentGuide.activeBackground': '#383838',
    'editorIndentGuide.background': '#2A2A2A',
    'editorRuler.foreground': '#2A2A2A',
    'activityBar.background': '#1A1A1A',
    'activityBar.foreground': '#7D7D7D',
    'activityBarBadge.background': '#383838',
    'badge.background': '#383838',
    'badge.foreground': '#C1C1C1',
    'button.background': '#333',
    'editor.lineHighlightBorder': '#303030',
    'editorGroupHeader.tabsBackground': '#1A1A1A',
    'editorGroupHeader.tabsBorder': '#1A1A1A',
    'editorSuggestWidget.background': '#1A1A1A',
    'focusBorder': '#444',
    'gitDecoration.ignoredResourceForeground': '#444444',
    'input.background': '#2A2A2A',
    'input.foreground': '#E0E0E0',
    'list.activeSelectionBackground': '#212121',
    'list.activeSelectionForeground': '#F5F5F5',
    'list.focusBackground': '#292929',
    'list.highlightForeground': '#EAEAEA',
    'list.hoverBackground': '#262626',
    'list.hoverForeground': '#9E9E9E',
    'list.inactiveSelectionBackground': '#212121',
    'list.inactiveSelectionForeground': '#F5F5F5',
    'panelTitle.activeForeground': '#FAFAFA',
    'panelTitle.inactiveForeground': '#484848',
    'peekView.border': '#444',
    'peekViewEditor.background': '#242424',
    'pickerGroup.border': '#363636',
    'pickerGroup.foreground': '#EAEAEA',
    'progressBar.background': '#FAFAFA',
    'scrollbar.shadow': '#1f1f1f',
    'sideBar.background': '#1A1A1A',
    'sideBarSectionHeader.background': '#202020',
    'statusBar.background': '#1A1A1A',
    'statusBar.foreground': '#7E7E7E',
    'statusBarItem.remoteForeground': '#7E7E7E',
    'statusBarItem.prominentBackground': '#fafafa1a',
    'tab.activeForeground': '#FAFAFA',
    'tab.inactiveBackground': '#1A1A1A',
    'tab.inactiveForeground': '#727272',
    'terminal.ansiBrightBlack': '#5c5c5c',
    'titleBar.activeBackground': '#1A1A1A',
    'titleBar.border': '#00000000'
  }
});

monaco.editor.defineTheme('light', {
  base: 'vs', // 'vs' is the light theme base
  inherit: true, // Inherit default settings from the base
  rules: [
    { token: '', foreground: '24292e' }, // Default text color

    // Token colors
    { token: 'keyword.operator.accessor', foreground: '24292e' },
    { token: 'meta.group.braces.round.function.arguments', foreground: '24292e' },
    { token: 'meta.template.expression', foreground: '24292e' },
    { token: 'markup.fenced_code meta.embedded.block', foreground: '24292e' },
    { token: 'emphasis', fontStyle: 'italic' },
    { token: 'strong', fontStyle: 'bold' },
    { token: 'markup.italic.markdown', fontStyle: 'italic' },
    { token: 'meta.link.inline.markdown', fontStyle: 'underline', foreground: '1976D2' },
    { token: 'string', foreground: '2b5581' },
    { token: 'comment', foreground: 'c2c3c5' },
    { token: 'constant.numeric', foreground: '1976D2' },
    { token: 'constant.language', foreground: '1976D2' },
    { token: 'keyword', foreground: 'D32F2F' },
    { token: 'variable.parameter.function', foreground: 'FF9800' },
    { token: 'support.function', foreground: '6f42c1' },
    { token: 'entity.name.tag', foreground: '22863a' },
    { token: 'token.info-token', foreground: '316bcd' },
    { token: 'token.warn-token', foreground: 'cd9731' },
    { token: 'token.error-token', foreground: 'cd3131' },
    { token: 'token.debug-token', foreground: '800080' },
    { token: 'punctuation.definition.arguments', foreground: '212121' }
  ],
  colors: {
    'editor.background': '#ffffff', // White background
    'editor.foreground': '#212121', // Text color
    'editor.lineHighlightBackground': '#f2f2f2', // Line highlight background
    'editorCursor.foreground': '#000000', // Cursor color
    'editorIndentGuide.background': '#EEE', // Indent guide color
    'editorLineNumber.foreground': '#CCC', // Line number color
    'editorLineNumber.activeForeground': '#757575', // Active line number color
    'editorSuggestWidget.background': '#F3F3F3', // Suggest widget background
    'editorBracketMatch.background': '#E7F3FF', // Bracket match background
    'editorBracketMatch.border': '#c8e1ff', // Bracket match border
    'scrollbarSlider.background': '#AAA', // Scrollbar color
    'input.border': '#E9E9E9', // Input border color
    'panel.background': '#FFFFFF', // Panel background
    'statusBar.background': '#f6f6f6', // Status bar background
    'statusBar.foreground': '#7E7E7E', // Status bar text color
    'tab.activeForeground': '#424242', // Active tab text color
    'tab.inactiveForeground': '#BDBDBD', // Inactive tab text color
    'tab.border': '#f6f6f6', // Tab border color
    'terminal.ansiBlack': '#333', // Terminal black
    'terminal.ansiRed': '#D32F2F', // Terminal red
    'terminal.ansiGreen': '#77cc00', // Terminal green
    'terminal.ansiYellow': '#f29718', // Terminal yellow
    'terminal.ansiBlue': '#6871ff', // Terminal blue
    'terminal.ansiMagenta': '#9966cc', // Terminal magenta
    'terminal.ansiCyan': '#4dbf99', // Terminal cyan
    'terminal.ansiWhite': '#c7c7c7', // Terminal white
    'terminal.background': '#fff', // Terminal background
  }
});


export default monaco;