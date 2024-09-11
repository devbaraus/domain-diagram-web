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
