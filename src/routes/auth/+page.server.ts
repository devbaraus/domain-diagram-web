import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "../$types"
import { Routes } from "$lib"

export const load: PageServerLoad = async ({ locals, url, parent }) => {
    await parent()

    if (locals.user) {
        throw redirect(302, '/p')
    }

    throw redirect(302, Routes.LOGIN)
}

