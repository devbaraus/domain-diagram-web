import { redirect } from "@sveltejs/kit"
import type { LayoutServerLoad } from "./$types"

export const load: LayoutServerLoad = async ({ locals, url, parent }) => {
    await parent()

    if (!locals.session && url.pathname !== '/login') {
        throw redirect(302, '/login')
    }

    return {
        user: locals.user,
    }
}
