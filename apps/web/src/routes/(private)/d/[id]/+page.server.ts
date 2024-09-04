import { createProject, getProject } from "$lib/services/project-service.svelte"
import { fail, redirect } from "@sveltejs/kit"
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


export const actions = {
    default: async ({ request, locals }) => {
        if (!locals.session) {
            return fail(401, { invalid: true })
        }

        const formData = await request.formData()
        const name = formData.get('name')

        if (typeof name !== 'string' || !name) {
            return fail(400, { invalid: true })
        }

        const res = await createProject(name, locals.session)

        return {
            item: res
        }
    },
}