import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals, url, ...event }) => {
    return {
        user: locals.user,
    }
}

