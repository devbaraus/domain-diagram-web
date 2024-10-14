import type { SyntaxNode } from "web-tree-sitter";

export function extractType(node: SyntaxNode | undefined): Type | undefined {
    if (!node) {
        return;
    }

    let data: Type = {
        type: '',
        kind: 'primitive',
        array: false,
        nullable: false
    }

    for (const child of node.children) {
        if (child.type === 'primitive_type') {
            data = {
                type: child.text,
                kind: 'primitive',
                array: false,
                nullable: false
            }
        }

        if (child.type === 'reference_type') {
            data = {
                type: child.text,
                kind: 'reference',
                array: false,
                nullable: false
            }
        }

        if (child.type === 'array_type') {
            const arrayData = extractType(child);


            if (!arrayData) {
                return;
            }

            data = {
                type: arrayData.type,
                kind: arrayData.kind,
                array: true,
                nullable: false
            }
        }

        if (child.type === 'nullable_type') {
            const nullableData = extractType(child);

            if (!nullableData) {
                return;
            }

            data = {
                type: nullableData.type,
                kind: nullableData.kind,
                array: false,
                nullable: true
            }
        }
    }

    return data
}

export function extractField(node: SyntaxNode | undefined): Property | undefined {
    if (!node) {
        return;
    }

    const data: Property = {
        name: '',
        type: '',
        array: false,
        kind: 'primitive',
        nullable: false,
        default: '',
        note: {
            text: '',
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        },
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
        }

        if (child.type === 'type') {
            const typeData = extractType(child);

            data.type = typeData?.type || data.type;
            data.kind = typeData?.kind || data.kind;
            data.array = typeData?.array || data.array;
            data.nullable = typeData?.nullable || data.nullable;
        }

        if (child.type === 'value') {
            data.default = child.text;
        }


        data.markup = {
            start: {
                row: child.startPosition.row,
                column: child.startPosition.column
            },
            end: {
                row: child.endPosition.row,
                column: child.endPosition.column
            }
        }
    }


    return data
}

export function extractGenericType(node: SyntaxNode | undefined): string {
    if (!node) {
        return '';
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            return child.text;
        }
    }

    return '';
}



export function extractParamsList(node: SyntaxNode | undefined): Parameter[] | undefined {
    if (!node) {
        return;
    }

    const data: Parameter[] = []

    for (const child of node.children) {
        if (child.type == "field") {
            const param = extractField(child);

            if (param) {
                data.push(param);
            }
        }
    }

    return data;
}

export function extractEmitter(node: SyntaxNode | undefined): Emitter {
    if (!node) {
        return {
            events: [],
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        }
    }

    const data: Emitter = {
        events: [],
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type == "identifier") {
            data.events.push(child.text);
        }
    }

    data.markup = {
        start: {
            row: node.startPosition.row,
            column: node.startPosition.column
        },
        end: {
            row: node.endPosition.row,
            column: node.endPosition.column
        }
    }

    return data;
}

export function extractNote(node: SyntaxNode | undefined): Note {
    if (!node) {
        return {
            text: '',
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        }
    }

    const data = {
        text: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        }
    }


    for (const child of node.children) {
        if (child.type == "string") {
            data.text = child.text.replaceAll('"', '');
        }
    }

    data.markup = {
        start: {
            row: node.startPosition.row,
            column: node.startPosition.column
        },
        end: {
            row: node.endPosition.row,
            column: node.endPosition.column
        }
    }

    return data
}

export function extractMethod(node: SyntaxNode | undefined): Omit<Method, 'note' | 'emits' | 'markup'> | undefined {
    if (!node) {
        return;
    }

    const data: Omit<Method, 'note' | 'emits'> = {
        name: '',
        parameters: [],
        return: {
            type: '',
            kind: 'primitive',
            array: false,
            nullable: false,
        },
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.parameters.push(field);
            }
        }

        if (child.type === 'type') {
            const returnType = extractType(child);

            if (returnType) {
                data.return = returnType;
            }
        }
    }

    return data;
}

export function extractMethodWithAnnotations(node: SyntaxNode | undefined): Method | undefined {
    if (!node) {
        return;
    }

    const data: Method = {
        name: '',
        parameters: [],
        note: {
            text: '',
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        },
        emits: {
            events: [],
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        },
        return: {
            type: '',
            kind: 'primitive',
            array: false,
            nullable: false,
        },
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'method') {
            const method = extractMethod(child);
            data.name = method?.name || '';
            data.parameters = method?.parameters || [];
            data.return = method?.return || data.return;
        }


        if (child.type === 'annotation_emitter') {
            const emitter = extractEmitter(child);

            if (emitter) {
                data.emits = emitter;
            }
        }

        if (child.type === 'annotation_note') {
            data.note = extractNote(child)
        }

        data.markup = {
            start: {
                row: child.startPosition.row,
                column: child.startPosition.column
            },
            end: {
                row: child.endPosition.row,
                column: child.endPosition.column
            }
        }
    }

    return data;
}

export function extractAggregate(node: SyntaxNode | undefined): Aggregate | undefined {
    if (!node) {
        return;
    }

    const data: Aggregate = {
        ids: [],
        name: '',
        type: 'aggregate',
        context: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        properties: [],
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    let hasGeneric = false

    for (const child of node.children) {
        if (child.type === 'generic_type') {
            hasGeneric = true;
            const genericType = extractGenericType(child);

            data.ids.push(genericType);
            data.properties.push({
                name: 'id',
                type: genericType,
                array: false,
                kind: 'reference',
                nullable: false,
                default: '',
                note: {
                    text: '',
                    markup: {
                        start: {
                            row: 0,
                            column: 0
                        },
                        end: {
                            row: 0,
                            column: 0
                        }
                    }
                },
                markup: {
                    start: {
                        row: 0,
                        column: 0
                    },
                    end: {
                        row: 0,
                        column: 0
                    }
                }
            })
        }

        if (child.type === 'identifier') {
            data.name = child.text;
            data.ids.push(child.text);
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.properties.push(field);
            }
        }

        if (child.type === 'method_emitter') {
            const method = extractMethodWithAnnotations(child);

            if (method) {
                data.methods.push(method);
            }
        }
    }

    if (!hasGeneric) {
        const genericType = data.name + "ID";
        data.ids.push(genericType);
        data.properties.unshift({
            name: 'id',
            type: genericType,
            array: false,
            kind: 'reference',
            nullable: false,
            default: '',
            note: {
                text: '',
                markup: {
                    start: {
                        row: 0,
                        column: 0
                    },
                    end: {
                        row: 0,
                        column: 0
                    }
                }
            },
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        })
    }

    return data
}

export function extractValueObject(node: SyntaxNode | undefined): ValueObject | undefined {
    if (!node) {
        return;
    }

    const data: ValueObject = {
        id: '',
        name: '',
        type: 'value_object',
        context: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        properties: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.properties.push(field);
            }
        }
    }

    return data
}

export function extractEvent(node: SyntaxNode | undefined): DomainEvent | undefined {
    if (!node) {
        return;
    }

    const data: DomainEvent = {
        id: '',
        name: '',
        type: 'event',
        context: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        properties: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.properties.push(field);
            }
        }
    }

    return data
}

export function extractEntity(node: SyntaxNode | undefined): Entity | undefined {
    if (!node) {
        return;
    }

    const data: Entity = {
        ids: [],
        name: '',
        type: 'entity',
        context: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        properties: [],
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    let hasGeneric = false

    for (const child of node.children) {
        if (child.type === 'generic_type') {
            hasGeneric = true;
            const genericType = extractGenericType(child);

            data.ids.push(genericType);
            data.properties.push({
                name: 'id',
                type: genericType,
                array: false,
                kind: 'reference',
                nullable: false,
                default: '',
                note: {
                    text: '',
                    markup: {
                        start: {
                            row: 0,
                            column: 0
                        },
                        end: {
                            row: 0,
                            column: 0
                        }
                    }
                },
                markup: {
                    start: {
                        row: 0,
                        column: 0
                    },
                    end: {
                        row: 0,
                        column: 0
                    }
                }
            })
        }

        if (child.type === 'identifier') {
            data.name = child.text;
            data.ids.push(child.text);
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.properties.push(field);
            }
        }

        if (child.type === 'method_note') {
            const method = extractMethodWithAnnotations(child);

            if (method) {
                data.methods.push(method);
            }
        }
    }

    if (!hasGeneric) {
        const genericType = data.name + "ID";
        data.ids.push(genericType);
        data.properties.unshift({
            name: 'id',
            type: genericType,
            array: false,
            kind: 'reference',
            nullable: false,
            default: '',
            note: {
                text: '',
                markup: {
                    start: {
                        row: 0,
                        column: 0
                    },
                    end: {
                        row: 0,
                        column: 0
                    }
                }
            },
            markup: {
                start: {
                    row: 0,
                    column: 0
                },
                end: {
                    row: 0,
                    column: 0
                }
            }
        })
    }

    return data
}

export function extractRepository(node: SyntaxNode | undefined): Repository | undefined {
    if (!node) {
        return;
    }

    const data: Repository = {
        id: '',
        name: '',
        type: 'repository',
        context: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }


        if (child.type === 'method_note') {
            const method = extractMethodWithAnnotations(child);

            if (method) {
                data.methods.push(method);
            }
        }
    }

    return data
}

export function extractService(node: SyntaxNode | undefined): Service | undefined {
    if (!node) {
        return;
    }

    const data: Service = {
        id: '',
        name: '',
        type: 'service',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        context: '',
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }

        if (child.type === 'method_note') {
            const method = extractMethodWithAnnotations(child);

            if (method) {
                data.methods.push(method);
            }
        }
    }

    return data
}

export function extractEnum(node: SyntaxNode | undefined): Enum | undefined {
    if (!node) {
        return;
    }

    const data: Enum = {
        id: '',
        name: '',
        type: 'enum',
        context: '',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        values: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    for (const child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
            data.markup = {
                start: {
                    row: child.startPosition.row,
                    column: child.startPosition.column
                },
                end: {
                    row: child.endPosition.row,
                    column: child.endPosition.column
                }
            }
        }


        if (child.type === 'enum_value') {
            data.values.push(child.text);
        }
    }

    return data
}

export function extractDiagram(node: SyntaxNode | undefined, context: string = 'DEFAULT', passDiagram: Diagram | undefined = undefined): Diagram {
    const diagram: Diagram = passDiagram || {
        aggregates: [],
        entities: [],
        enums: [],
        repositories: [],
        services: [],
        events: [],
        valueObjects: [],
        contexts: [],
        columns: 4
    };

    if (!node) {
        return diagram;
    }

    const contextData: Context = {
        id: context,
        name: context,
        type: 'context',
        markup: {
            start: {
                row: 0,
                column: 0
            },
            end: {
                row: 0,
                column: 0
            }
        },
        aggregates: [],
        entities: [],
        valueObjects: [],
        enums: [],
        services: [],
        events: [],
        repositories: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        },
        ports: {
            top: {
                x: 0,
                y: 0
            },
            right: {
                x: 0,
                y: 0
            },
            bottom: {
                x: 0,
                y: 0
            },
            left: {
                x: 0,
                y: 0
            }
        }
    }

    diagram.contexts.push(contextData);

    for (const child of node.children) {
        if (child.type === 'aggregate') {
            const aggregate = extractAggregate(child);

            if (aggregate) {
                aggregate.context = context;
                diagram.aggregates.push(aggregate);
                diagram.contexts.find(c => c.name === context)?.aggregates.push(aggregate.name);
            }
        }
        if (child.type === 'entity') {
            const entity = extractEntity(child);

            if (entity) {
                entity.context = context;
                diagram.entities.push(entity);
                diagram.contexts.find(c => c.name === context)?.entities.push(entity.name);
            }
        }
        if (child.type === 'enum') {
            const enumData = extractEnum(child);

            if (enumData) {
                enumData.context = context;
                diagram.enums.push(enumData);
                diagram.contexts.find(c => c.name === context)?.enums.push(enumData.name);
            }
        }
        if (child.type === 'event') {
            const event = extractEvent(child);

            if (event) {
                event.context = context;
                diagram.events.push(event);
                diagram.contexts.find(c => c.name === context)?.events.push(event.name);
            }
        }
        if (child.type === 'value_object') {
            const valueObject = extractValueObject(child);

            if (valueObject) {
                valueObject.context = context;
                diagram.valueObjects.push(valueObject);
                diagram.contexts.find(c => c.name === context)?.valueObjects.push(valueObject.name);
            }
        }
        if (child.type === 'repository') {
            const repository = extractRepository(child);

            if (repository) {
                repository.context = context;
                diagram.repositories.push(repository);
                diagram.contexts.find(c => c.name === context)?.repositories.push(repository.name);
            }
        }
        if (child.type === 'service') {
            const service = extractService(child);

            if (service) {
                service.context = context
                diagram.services.push(service);
                diagram.contexts.find(c => c.name === context)?.services.push(service.name);
            }
        }
        if (child.type === 'context') {
            let name = ''

            for (const children of child.children) {
                if (children.type === 'identifier') {
                    name = children.text;
                }
            }

            extractDiagram(child, name, diagram);
        }
    }

    return diagram;
}