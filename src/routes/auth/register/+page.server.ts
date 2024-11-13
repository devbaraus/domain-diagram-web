import { fail, redirect } from "@sveltejs/kit"
import type { Actions, PageServerLoad } from "../$types"
import { client } from "$lib/client"
import { Routes } from "$lib"
import { goto } from "$app/navigation"

export const load: PageServerLoad = async ({ locals, url, parent }) => {
    await parent()

    if (locals.user) {
        throw redirect(302, '/p')
    }
}

export const actions: Actions = {
    default: async ({ request, cookies, fetch }) => {
        const formData = await request.formData()
        const email = formData.get('email')
        const name = formData.get('name')
        const password = formData.get('password')

        if (typeof email !== 'string' || typeof password !== 'string' || !email || !password || !name || typeof name !== 'string') { 
            return fail(400, { invalid: true })
        }

        try {
            await client().post('/auth/register', { email, password, name })
        } catch (error) {
            return fail(400, { invalid: true })
        }
        

        throw redirect(302, Routes.LOGIN)
    },
}