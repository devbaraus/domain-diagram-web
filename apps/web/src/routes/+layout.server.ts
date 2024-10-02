import { redirect } from "@sveltejs/kit"
import type { LayoutServerLoad } from "./$types"
import { Routes } from "$lib"

const pubMatcher = /^\/(docs|e\/\d+)/

export const load: LayoutServerLoad = async ({ locals, url, parent }) => {
    await parent()

    if (pubMatcher.test(url.pathname)) {
        return {}
    }

    if (!locals.session && ![Routes.LOGIN, Routes.REGISTER].includes(url.pathname)) {
        throw redirect(302, Routes.LOGIN)
    }

    return {
        user: locals.user,
    }
}
