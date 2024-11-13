import { embedProject, getProject } from "$lib/services/project-service.svelte"
import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals, params, parent, url }) => {
    const token = url.searchParams.get('token')

    try {
        const res = await embedProject(params.id, token)

        return { ...locals, item: res }
    } catch (error) {
        throw redirect(302, '/p')
    }
}


