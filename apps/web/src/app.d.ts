type User = {
	id: string,
	first_name: string,
	last_name: string,
	email: string,
}

// See https://kit.svelte.dev/docs/types#app
// for information about these interfaces
declare global {
	namespace App {
		// interface Error {}
		interface Locals {
			user: User | null
			session?: string
		}
		// interface PageData {}
		// interface PageState {}
		// interface Platform {}
	}
}

export { };
