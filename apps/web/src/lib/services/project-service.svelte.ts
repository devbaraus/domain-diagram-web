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
    return client(token).put(`/projects/${id}`, params);
}

export async function getProject(id: string | number, token: string) {
    return client(token).get(`/projects/${id}`);

}

export async function embedProject(id: string | number, token: string | null) {
    return client().get(`/projects/${id}` + (token ? `?embed_token=${token}` : ""));
}


export async function listProjects(token: string) {
    return client(token).get("/projects");
}

export async function deleteProject(id: string | number, token: string) {
    return client(token).delete(`/projects/${id}`);
}