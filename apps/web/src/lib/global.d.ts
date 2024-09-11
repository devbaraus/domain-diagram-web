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

declare type Parameter = Property

declare type Method = {
    name: string;
    parameters: Parameter[];
    return: Type;
}

declare type Position = {
    hidden: boolean;
    fixed: boolean;
    x: number;
    y: number;
}

declare type Aggregate = {
    ids: string[],
    name: string;
    type: string;
    line: number;
    properties: Property[];
    methods: Method[];
    position: Position
};

declare type Entity = {
    ids: string[],
    name: string;
    type: string;
    line: number;
    properties: Property[];
    methods: Method[];
    position: Position
}

declare type ValueObject = {
    id: string,
    name: string;
    type: string;
    line: number;
    properties: Property[];
    position: Position
}

declare type Enum = {
    id: string,
    name: string;
    type: string;
    line: number;
    values: string[];
    position: Position
}

declare type Service = {
    id: string,
    name: string;
    type: string;
    line: number;
    methods: Method[];
    position: Position
}

declare type DomainEvent = {
    id: string,
    name: string;
    type: string;
    line: number;
    properties: Property[];
    position: Position
}

declare type Repository = {
    id: string,
    name: string;
    type: string;
    line: number;
    methods: Method[];
    position: Position
}

declare type Context = {
    id: string,
    name: string;
    type: string;
    line: number;
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