import { directusClient } from "$lib/client";
import { createItem, readItem, updateItem } from "@directus/sdk";

export async function createProject(name: string, token: string) {
    await directusClient.setToken(token)

    const project = await directusClient.request(createItem("projects", { name }));

    return project;
}

export async function updateProject(id: string | number, params: {
    name?: string;
    markup?: string;
}, token: string) {
    await directusClient.setToken(token)

    const project = await directusClient.request(updateItem("projects", id, params));

    return project;
}

export async function getProject(id: string | number, token: string) {
    await directusClient.setToken(token)

    const project = await directusClient.request(readItem("projects", id));

    return project;
}