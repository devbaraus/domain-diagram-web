import { listProjects } from "$lib/services/project-service.svelte"
import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals }) => {
    try {
        const res = await listProjects(locals.session)

        return { projects: res }
    } catch (error) {
        throw redirect(302, '/p')
    }
}
