import { redirect } from "@sveltejs/kit"
import type { LayoutServerLoad } from "./$types"

const pubMatcher = /^\/(docs|e\/\d+)/

export const load: LayoutServerLoad = async ({ locals, url, parent }) => {
    await parent()

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
