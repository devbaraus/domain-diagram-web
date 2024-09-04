import { createProject, listProjects } from "$lib/services/project-service.svelte"
import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals, parent }) => {
    await parent()

    console.log("locals", locals)

    let res = await listProjects(locals.session, { limit: 1 })

    if (!res.length) {
        res = await createProject(locals.user.first_name + '\'s project', locals.session)
        res = [res]
    }

    throw redirect(302, `/d/${res[0].id}`)
}
