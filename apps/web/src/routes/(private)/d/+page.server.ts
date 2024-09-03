import { fail } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"
import { directusClient } from "$lib/client"
import { readItem, readItems, updateItem } from "@directus/sdk"

export const load: PageServerLoad = async ({ locals }) => {
    if (!locals.session) {
        return fail(401)
    }

    try {
        await directusClient.setToken(locals.session)

        const res = await directusClient.request(readItems('projects'))

        return { ...locals, items: res }
    } catch (error) {
        return fail(401)
    }
}