import { grammar } from "$lib";
import { client } from "$lib/client";

export async function createProject(name: string, token: string) {
    await client.setToken(token)

    const { data } = await client.post("/projects", { name, markup: grammar });

    return data
}

export async function updateProject(id: string | number, params: {
    name?: string;
    markup?: string;
    diagram?: object
}, token: string) {
    await client.setToken(token)

    const { data } = await client.put(`/projects/${id}`, params);
    return data
}

export async function getProject(id: string | number, token: string) {
    await client.setToken(token)

    const { data } = await client.get(`/projects/${id}`);
    return data
}


export async function listProjects(token: string) {
    await client.setToken(token)

    const { data } = await client.get("/projects");
    return data
}

export async function deleteProject(id: string | number, token: string) {
    await client.setToken(token)

    const { data } = await client.delete(`/projects/${id}`);
    return data
}