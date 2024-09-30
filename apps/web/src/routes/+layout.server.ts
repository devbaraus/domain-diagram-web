import { redirect } from "@sveltejs/kit"
import type { LayoutServerLoad } from "./$types"

const pubMatcher = /^\/(docs|embeds\/\d+)/

export const load: LayoutServerLoad = async ({ locals, url, parent }) => {
    await parent()

    console.log('layout load', url.pathname, pubMatcher.test(url.pathname))


    if (pubMatcher.test(url.pathname)) {
        return {}
    }

    if (!locals.session && url.pathname !== '/login') {
        throw redirect(302, '/login')
    }

    return {
        user: locals.user,
    }
}
