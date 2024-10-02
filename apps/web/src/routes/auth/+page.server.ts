import { fail, redirect } from "@sveltejs/kit"
import type { Actions, PageServerLoad } from "../$types"
import { client } from "$lib/client"
import { goto } from "$app/navigation"

export const load: PageServerLoad = async ({ locals, url, parent }) => {
    await parent()

    if (locals.user) {
        throw redirect(302, '/p')
    }

    throw redirect(302, Routes.LOGIN)
}

