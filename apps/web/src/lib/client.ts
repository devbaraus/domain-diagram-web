import { PUBLIC_API_URL } from '$env/static/public'
import { QueryClient } from '@tanstack/svelte-query';
import { writable } from 'svelte/store';
import axios from 'axios';

// export const client = createDirectus(PUBLIC_API_URL).with(authentication()).with(rest())

export const queryClient = writable<QueryClient>();

class Client {
    private token: string | null = null
    private http = fetch

    private returnData = (r: Response) => {
        if (r.ok) {
            return r.json()
        }

        if (r.status === 401) {
            throw new Error('Unauthorized')
        }

        if (r.status === 404) {
            throw new Error('Not found')
        }

        if (r.status === 400) {
            throw new Error('Validation failed')
        }

        if (r.status >= 500) {
            throw new Error('Internal server error')
        }

        throw new Error(r.statusText)
    }

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
        }).then(this.returnData)
    }

    async post(resource: string, data: any) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            method: 'POST',
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
            body: JSON.stringify(data),
        }).then(this.returnData)
    }

    async put(resource: string, data: any) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            method: 'PUT',
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
            body: JSON.stringify(data),
        }).then(this.returnData)
    }

    async delete(resource: string) {
        const url = new URL(resource, PUBLIC_API_URL)

        return this.http(url, {
            method: 'DELETE',
            headers: this.token ? {
                Authorization: `Bearer ${this.token}`,
            } : {},
        }).then(this.returnData)
    }
}

export const client = (token?: string, http?: any) => new Client(token, http)
