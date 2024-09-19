import { PUBLIC_API_URL } from '$env/static/public'
import { QueryClient } from '@tanstack/svelte-query';
import { writable } from 'svelte/store';
import axios from 'axios';

// export const client = createDirectus(PUBLIC_API_URL).with(authentication()).with(rest())

export const queryClient = writable<QueryClient>();

class Client {
    private _client = axios.create({
        baseURL: PUBLIC_API_URL,
        withCredentials: true
    })


    async setToken(token: string) {
        this._client.defaults.headers.common['Authorization'] = `Bearer ${token}`
    }

    async get(url: string) {
        return this._client.get(url)
    }

    async post(url: string, data: any) {
        return this._client.post(url, data)
    }

    async put(url: string, data: any) {
        return this._client.put(url, data)
    }

    async delete(url: string) {
        return this._client.delete(url)
    }
}

export const client = new Client()
