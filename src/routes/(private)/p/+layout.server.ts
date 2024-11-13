import { listProjects } from "$lib/services/project-service.svelte"
import { redirect } from "@sveltejs/kit"
import type { LayoutServerLoad } from "./$types"

export const load: LayoutServerLoad = async ({ locals }) => {
    try {
        const res = await listProjects(locals.session)

        return { projects: res }
    } catch (error) {
        throw redirect(302, '/p')
    }
}
