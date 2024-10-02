import { createProject, listProjects } from "$lib/services/project-service.svelte"
import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals, parent }) => {
    const data = await parent()

    let res = data.projects

    if (!res.length) {
        res = await createProject(locals.user.name + '\'s project', locals.session)
        res = [res]
    }

    throw redirect(302, `/p/${res[0].id}`)
}
