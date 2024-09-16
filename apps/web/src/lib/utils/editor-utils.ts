import _ from 'lodash';
import * as TreeSitter from 'web-tree-sitter';
import type * as Monaco from 'monaco-editor/esm/vs/editor/editor.api';

enum MarkerSeverity {
    Hint = 1,
    Info = 2,
    Warning = 4,
    Error = 8
}

export function lintAST(ast) {
    const diagnostics = [];

    ast.rootNode.children.forEach((node) => {
        if (node.type === 'context') {
            const hasAggregateOrEntity = node.children.some(child =>
                ['aggregate', 'entity'].includes(child.type)
            );
            if (!hasAggregateOrEntity) {
                diagnostics.push({
                    message: 'A context must contain at least one aggregate or entity.',
                    severity: MarkerSeverity.Error,
                    startLineNumber: node.startPosition.row + 1,
                    startColumn: node.startPosition.column + 1,
                    endLineNumber: node.endPosition.row + 1,
                    endColumn: node.endPosition.column + 1,
                });
            }
        }

        if (node.type === 'aggregate') {
            const hasIdentifierField = node.children.some(
                (child) => child.type === 'field' && child.text.includes('id:')
            );
            if (hasIdentifierField) {
                diagnostics.push({
                    message: 'The aggregate identifier is automatically generated and cannot be defined.',
                    severity: MarkerSeverity.Warning,
                    startLineNumber: node.startPosition.row + 1,
                    startColumn: node.startPosition.column + 1,
                    endLineNumber: node.endPosition.row + 1,
                    endColumn: node.endPosition.column + 1,
                });
            }
        }
    });
    return diagnostics;
}

export function checkForSyntaxErrors(ast) {
    const errors = [];

    // Recursively check the tree for error nodes
    function walk(node) {
        if (node.type === 'ERROR') {
            errors.push({
                message: 'Syntax error found',
                startLineNumber: node.startPosition.row + 1,
                startColumn: node.startPosition.column + 1,
                endLineNumber: node.endPosition.row + 1,
                endColumn: node.endPosition.column + 1,
            });
        } else if (node.hasError) {
            // hasError() will return true if there are errors anywhere within this node's subtree
            node.children.forEach(walk);
        }
    }

    walk(ast);

    return errors;
}

export function updateDefinitionMarkers(monaco, diagram: Diagram) {
    monaco?.languages.registerDefinitionProvider('ddd', {
        provideDefinition: function (model, position) {
            const word = model.getWordAtPosition(position);

            if (!word || !diagram) return;

            const definitionPosition = findDefinition(word.word, diagram);

            if (!definitionPosition) return;

            return {
                uri: model.uri,
                range: new monaco.Range(
                    definitionPosition.start.row + 1,
                    definitionPosition.start.column + 1,
                    definitionPosition.end.row + 1,
                    definitionPosition.end.column + 1
                )
            };
        }
    });
}

export function updateModelMarkers(monaco, model, markers) {
    monaco?.editor.setModelMarkers(model, 'ddd', markers);
}

export function findDefinition(word, diagram: Diagram) {
    const items = [diagram.aggregates, diagram.entities, diagram.valueObjects, diagram.enums, diagram.services, diagram.events, diagram.repositories].flat();

    let definitionNode = null;

    for (const item of items) {
        if ('id' in item && item.id === word) {
            definitionNode = item;
            break;
        }

        if ('ids' in item && item.ids.includes(word)) {
            definitionNode = item;
            break;
        }
    }

    console.log('Definition node:', definitionNode);

    return definitionNode ? {
        start: definitionNode.markup.start,
        end: definitionNode.markup.start
    } : null;
}
