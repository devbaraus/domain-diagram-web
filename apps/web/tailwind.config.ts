import type { Config } from 'tailwindcss';

export default {
	content: ['./src/**/*.{html,js,svelte,ts}'],

	theme: {
		extend: {
			fontFamily: {
				"poppins": ["Poppins", "sans-serif"]
			}
		}
	},

	daisyui: {
		themes: [
			'bumblebee'
		]
	},
	plugins: [require('daisyui')]
} as Config;
