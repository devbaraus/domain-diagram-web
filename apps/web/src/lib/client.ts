import { authentication, createDirectus, rest } from '@directus/sdk';
import { PUBLIC_API_URL } from '$env/static/public'

export const directusClient = createDirectus(PUBLIC_API_URL).with(authentication()).with(rest())