import type { Config } from 'tailwindcss';

export default {
	content: ['./src/**/*.{html,js,svelte,ts,svx,md}'],

	theme: {
		extend: {
			fontFamily: {
				"poppins": ["Inter", "sans-serif"],
				"fira": ["Fira Code", "monospace"]
			}
		}
	},
	daisyui: {
		themes: [
			'bumblebee',
			// 'dracula',
			// 'light',
			// 'corporate',
		]
	},
	plugins: [require('@tailwindcss/typography'), require('daisyui')]
} as Config;
