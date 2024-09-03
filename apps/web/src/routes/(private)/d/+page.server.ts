import { directusClient } from "$lib/client"
import { createItem, readItems } from "@directus/sdk"
import { fail, redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"
import { goto } from "$app/navigation"

export const load: PageServerLoad = async ({ locals, parent }) => {
    await parent()

    await directusClient.setToken(locals.session)

    const res = await directusClient.request(readItems('projects'))

    return { ...locals, items: res }
}

export const actions = {
    default: async ({ request, locals }) => {
        const formData = await request.formData()
        const name = formData.get('name')
        const markup = formData.get('markup')

        if (typeof name !== 'string' || typeof markup !== 'string' || !name || !markup) {
            return fail(400, { invalid: true })
        }

        if (!locals.session) {
            return fail(401, { invalid: true })
        }

        await directusClient.setToken(locals.session)

        const res = await directusClient.request(createItem('projects', {
            name, markup
        }))

        goto(`/d/${res.id}`)

        throw redirect(302, `/d/${res.id}`)
    },
}