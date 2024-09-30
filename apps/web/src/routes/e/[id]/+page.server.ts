import { getProject } from "$lib/services/project-service.svelte"
import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals, params, parent }) => {
    await parent()

    try {
        const res = await getProject(params.id, locals.session)

        return { ...locals, item: res }
    } catch (error) {
        throw redirect(302, '/d')
    }
}


