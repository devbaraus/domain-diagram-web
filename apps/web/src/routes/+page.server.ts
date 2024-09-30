import { redirect } from "@sveltejs/kit"
import type { PageServerLoad } from "./$types"

export const load: PageServerLoad = async ({ locals, url, parent }) => {
    await parent()

    throw redirect(302, '/p')
}

