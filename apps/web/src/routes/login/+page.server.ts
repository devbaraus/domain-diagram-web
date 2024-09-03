import { fail, redirect } from "@sveltejs/kit"
import type { Actions, PageServerLoad } from "./$types"
import { directusClient } from "$lib/client"

export const load: PageServerLoad = async ({ locals, url, ...event }) => {
    if (locals.user) {
        redirect(302, '/')
    }
}

export const actions: Actions = {
    login: async ({ request, cookies, fetch }) => {
        const formData = await request.formData()
        const email = formData.get('email')
        const password = formData.get('password')

        if (typeof email !== 'string' || typeof password !== 'string' || !email || !password) {
            return fail(400, { invalid: true })
        }

        try {
            const data = await directusClient.login(email, password)

            if (!data.access_token || !data.expires) {
                return fail(401, { invalid: true })
            }

            cookies.set("session", data.access_token, {
                path: "/",
                httpOnly: true,
                sameSite: "strict",
                secure: process.env.NODE_ENV === "production",
                maxAge: data.expires * 1000
            })

            redirect(303, "/d")
        } catch (error) {
            return fail(401, { invalid: true })
        }
    },
}