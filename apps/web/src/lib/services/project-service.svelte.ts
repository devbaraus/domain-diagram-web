import { grammar } from "$lib";
import { directusClient } from "$lib/client";
import { createItem, readItem, readItems, updateItem, type Query } from "@directus/sdk";

export async function createProject(name: string, token: string) {
    await directusClient.setToken(token)

    return directusClient.request(createItem("projects", { name, markup: grammar }));
}

export async function updateProject(id: string | number, params: {
    name?: string;
    markup?: string;
}, token: string) {
    await directusClient.setToken(token)

    return await directusClient.request(updateItem("projects", id, params));
}

export async function getProject(id: string | number, token: string) {
    await directusClient.setToken(token)

    return directusClient.request(readItem("projects", id));
}


export async function listProjects(token: string, query?: Query<any, any>) {
    await directusClient.setToken(token)

    return directusClient.request(readItems("projects", {
        fields: "id,name,date_created,date_updated",
        sort: ["-date_updated"],
        ...query
    }));
}