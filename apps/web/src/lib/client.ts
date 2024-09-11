import { authentication, createDirectus, rest } from '@directus/sdk';
import { PUBLIC_API_URL } from '$env/static/public'
import { QueryClient } from '@tanstack/svelte-query';
import { writable } from 'svelte/store';

export const directusClient = createDirectus(PUBLIC_API_URL).with(authentication()).with(rest())

export const queryClient = writable<QueryClient>();