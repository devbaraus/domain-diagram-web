import { listProjects } from "$lib/services/project-service.svelte"
import type { PageServerLoad } from "../$types"

export const load: PageServerLoad = async ({ locals, parent, depends }) => {
    await parent()

    let res = await listProjects(locals.session)


    return {
        items: res,
    }
}