import { PUBLIC_API_URL } from '$env/static/public'
import { QueryClient } from '@tanstack/svelte-query';
import { writable } from 'svelte/store';
import axios from 'axios';

// export const client = createDirectus(PUBLIC_API_URL).with(authentication()).with(rest())

export const queryClient = writable<QueryClient>();

class Client {
    private token: string | null = null
    private http = fetch

    constructor(
        token?: string,
        http?: any
    ) {
        if (token) {
            this.token = token
        }

        if (http) {
            this.http = http
        }
    }

    async get(resource: string) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
        }).then(r => r.json())
    }

    async post(resource: string, data: any) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            method: 'POST',
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
            body: JSON.stringify(data),
        }).then(r => r.json())
    }

    async put(resource: string, data: any) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            method: 'PUT',
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
            body: JSON.stringify(data),
        }).then(r => r.json())
    }

    async delete(resource: string) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            method: 'DELETE',
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
        }).then(r => r.json())
    }
}

export const client = (token?: string, http?: any) => new Client(token, http)
