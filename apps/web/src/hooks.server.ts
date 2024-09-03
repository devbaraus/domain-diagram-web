import { directusClient } from "$lib/client"
import { readUser } from "@directus/sdk"
import type { Handle } from "@sveltejs/kit"

export const handle: Handle = async ({ event, resolve }) => {
    // get cookies from browser
    const session = event.cookies.get('session')

    if (!session) {
        // if there is no session load page as normal
        return await resolve(event)
    }

    try {
        await directusClient.setToken(session)

        const data = await directusClient.request(readUser('me'))

        if (data) {
            event.locals.user = data as any
            event.locals.session = session
        }
    } catch (error) {
        console.error(error)
    } finally {
        return await resolve(event)
    }
}