declare type KindType = "reference" | "primitive";

declare type Type = {
    type: string;
    kind: KindType;
    array: boolean;
    nullable: boolean;
}

declare type Property = {
    name: string;
    type: string;
    kind: KindType;
    array: boolean;
    nullable: boolean;
    default: string;
}

declare type Port = {
    x: number;
    y: number;
}

type Common = {
    id: string;
    name: string;
    type: string;
    context: string;
    markup: MarkupPosition;
    position: Position
    ports: {
        top: Port;
        right: Port;
        bottom: Port;
        left: Port;
    }
}

declare type Parameter = Property

declare type Method = {
    name: string;
    parameters: Parameter[];
    return: Type;
}

declare type Markup = {
    start: {
        row: number;
        column: number;
    };
    end: {
        row: number;
        column: number;
    };
}

declare type Position = {
    hidden: boolean;
    fixed: boolean;
    x: number;
    y: number;
}

declare type Aggregate = Omit<Common, 'id'> & {
    ids: string[],
    properties: Property[];
    methods: Method[];
};

declare type Entity = Omit<Common, 'id'> & {
    ids: string[],
    properties: Property[];
    methods: Method[];
}

declare type ValueObject = Common & {
    properties: Property[];
}

declare type Enum = Common & {
    values: string[];
}

declare type Service = Common & {
    methods: Method[];
}

declare type DomainEvent = Common & {
    properties: Property[];
}

declare type Repository = Common & {
    methods: Method[];
}

declare type Domain = {
    aggregates: Aggregate[];
    entities: Entity[];
    valueObjects: ValueObject[];
    enums: Enum[];
    events: DomainEvent[];
    services: Service[];
    repositories: Repository[];
}

declare type Context = Omit<Common, 'context'> & {
    id: string,
    name: string;
    type: string;
    aggregates: string[];
    entities: string[];
    valueObjects: string[];
    enums: string[];
    services: string[];
    repositories: string[];
    events: string[];
    position: Position
}

declare type Diagram = {
    aggregates: Aggregate[];
    entities: Entity[];
    valueObjects: ValueObject[];
    enums: Enum[];
    events: DomainEvent[];
    services: Service[];
    repositories: Repository[];
    contexts: Context[];
    columns: number;
}