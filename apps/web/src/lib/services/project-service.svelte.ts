import { grammar } from "$lib";
import { client } from "$lib/client";

export async function createProject(name: string, token: string) {
    const { data } = await client(token).post("/projects", { name, markup: grammar });

    return data
}

export async function updateProject(id: string | number, params: {
    name?: string;
    members?: {
        role: string,
        userId: string
    }[],
    public: boolean,
    embed: boolean,
}, token: string) {
    const { data } = await client(token).put(`/projects/${id}`, params);
    return data
}

export async function getProject(id: string | number, token: string) {
    const { data } = await client(token).get(`/projects/${id}`);
    return data
}

export async function embedProject(id: string | number, token: string | null) {
    const { data } = await client().get(`/projects/${id}` + (token ? `?embed_token=${token}` : ""));
    return data
}


export async function listProjects(token: string) {
    const { data } = await client(token).get("/projects");
    return data
}

export async function deleteProject(id: string | number, token: string) {
    const { data } = await client(token).delete(`/projects/${id}`);
    return data
}