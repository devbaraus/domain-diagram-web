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

    for (let child of node.children) {
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
        default: ''
    }

    for (let child of node.children) {
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
    }


    return data
}

export function extractGenericType(node: SyntaxNode | undefined): string {
    if (!node) {
        return '';
    }

    for (let child of node.children) {
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

    for (let child of node.children) {
        if (child.type == "field") {
            const param = extractField(child);

            if (param) {
                data.push(param);
            }
        }
    }

    return data;
}

export function extractMethod(node: SyntaxNode | undefined): Method | undefined {
    if (!node) {
        return;
    }

    const data: Method = {
        name: '',
        parameters: [],
        return: {
            type: '',
            kind: 'primitive',
            array: false,
            nullable: false
        }
    }

    for (let child of node.children) {
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

export function extractAggregate(node: SyntaxNode | undefined): Aggregate | undefined {
    if (!node) {
        return;
    }

    const data: Aggregate = {
        ids: [],
        name: '',
        properties: [],
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    for (let child of node.children) {
        if (child.type === 'generic_type') {
            data.ids.push(extractGenericType(child));
        }

        if (child.type === 'identifier') {
            data.name = child.text;
            data.ids.push(child.text);
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.properties.push(field);
            }
        }

        if (child.type === 'method') {
            const method = extractMethod(child);

            if (method) {
                data.methods.push(method);
            }
        }
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
        properties: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    for (let child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
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
        properties: [],
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    for (let child of node.children) {
        if (child.type === 'generic_type') {
            data.ids.push(extractGenericType(child));
        }

        if (child.type === 'identifier') {
            data.name = child.text;
            data.ids.push(child.text);
        }

        if (child.type === 'field') {
            const field = extractField(child);

            if (field) {
                data.properties.push(field);
            }
        }

        if (child.type === 'method') {
            const method = extractMethod(child);

            if (method) {
                data.methods.push(method);
            }
        }
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
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    for (let child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
        }


        if (child.type === 'method') {
            const method = extractMethod(child);

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
        methods: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    for (let child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
        }


        if (child.type === 'method') {
            const method = extractMethod(child);

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
        values: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    for (let child of node.children) {
        if (child.type === 'identifier') {
            data.name = child.text;
            data.id = child.text;
        }


        if (child.type === 'enum_value') {
            data.values.push(child.text);
        }
    }

    return data
}

export function extractDiagram(node: SyntaxNode | undefined, context: string = 'DEFAULT', passDiagram: Diagram): Diagram {
    const diagram: Diagram = passDiagram || {
        aggregates: [],
        entities: [],
        enums: [],
        repositories: [],
        services: [],
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
        aggregates: [],
        entities: [],
        valueObjects: [],
        enums: [],
        services: [],
        repositories: [],
        position: {
            fixed: false,
            hidden: false,
            x: 0,
            y: 0
        }
    }

    diagram.contexts.push(contextData);

    for (let child of node.children) {
        if (child.type === 'aggregate') {
            const aggregate = extractAggregate(child);

            if (aggregate) {
                diagram.aggregates.push(aggregate);
                diagram.contexts.find(c => c.name === context)?.aggregates.push(aggregate.name);
            }
        }
        if (child.type === 'entity') {
            const entity = extractEntity(child);

            if (entity) {
                diagram.entities.push(entity);
                diagram.contexts.find(c => c.name === context)?.entities.push(entity.name);
            }
        }
        if (child.type === 'enum') {
            const enumData = extractEnum(child);

            if (enumData) {
                diagram.enums.push(enumData);
                diagram.contexts.find(c => c.name === context)?.enums.push(enumData.name);
            }

        }
        if (child.type === 'value_object') {
            const valueObject = extractValueObject(child);

            if (valueObject) {
                diagram.valueObjects.push(valueObject);
                diagram.contexts.find(c => c.name === context)?.valueObjects.push(valueObject.name);
            }
        }
        if (child.type === 'repository') {
            const repository = extractRepository(child);

            if (repository) {
                diagram.repositories.push(repository);
                diagram.contexts.find(c => c.name === context)?.repositories.push(repository.name);
            }
        }
        if (child.type === 'service') {
            const service = extractService(child);

            if (service) {
                diagram.services.push(service);
                diagram.contexts.find(c => c.name === context)?.services.push(service.name);
            }
        }
        if (child.type === 'context') {
            let name = ''

            for (let children of child.children) {
                if (children.type === 'identifier') {
                    name = children.text;
                }
            }


            extractDiagram(child, name, diagram);
        }
    }

    return diagram;
}