import { fail } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"
import { directusClient } from "$lib/client"
import { readItem, updateItem } from "@directus/sdk"

export const load: PageServerLoad = async ({ locals, params, parent }) => {
    await parent()

    if (!locals.session) {
        return fail(401, {
            unauthorized: true,
        })
    }

    try {
        await directusClient.setToken(locals.session)

        const res = await directusClient.request(readItem('projects', params.id))

        return { ...locals, project: res }
    } catch (error) {
        return fail(401, {
            unauthorized: true,
        })
    }
}