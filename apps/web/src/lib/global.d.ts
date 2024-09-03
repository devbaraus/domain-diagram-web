declare type Entity = {
    id: string,
    description?: string | null;
    name?: string | null;
    type?: string | null;
    values: string[];
    properties: {
        name?: string | null;
        type?: string | null;
    }[];
    methods: {
        name?: string | null;
        parameters: {
            name?: string | null;
            type?: string | null;
        }[];
        returnType?: string | null;
    }[];
    position?: {
        x: number;
        y: number;
        width: number;
        height: number;
    };
};
