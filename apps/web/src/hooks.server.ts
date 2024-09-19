import { client } from "$lib/client"
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
        await client.setToken(session)

        const { data } = await client.get("/users/me")

        console.log('data', data)

        if (data) {
            event.locals.user = data as any
            event.locals.session = session
        }
    } catch (error) {
        event.cookies.delete('session', {
            path: '/',
        })
    } finally {
        return await resolve(event)
    }
}