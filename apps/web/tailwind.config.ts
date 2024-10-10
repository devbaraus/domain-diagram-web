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
			{
				mindark: {
					"primary": "#1976D2", // Same primary color (can be kept the same in dark mode)
					"primary-focus": "#1565C0", // Darker shade for hover
					"primary-content": "#ffffff", // White text on primary elements

					"secondary": "#6f42c1", // Secondary color for method names, etc.
					"secondary-focus": "#5a34a5", // Darker secondary color for hover
					"secondary-content": "#ffffff", // White text on secondary elements

					"accent": "#D32F2F", // Accent color for errors and highlights
					"accent-focus": "#C62828", // Darker accent for hover
					"accent-content": "#ffffff", // White text on accent elements

					"neutral": "#f5f5f5", // Light neutral text for the dark background
					"neutral-focus": "#e0e0e0", // Slightly darker for focus states
					"neutral-content": "#333333", // Darker content on neutral elements

					"base-100": "#212121", // Dark background
					"base-200": "#333333", // Slightly lighter background for containers
					"base-300": "#424242", // Even lighter background for borders or highlights
					"base-content": "#E0E0E0", // Light text on the dark background

					"info": "#4dbf99", // Cyan for info states
					"success": "#77cc00", // Green for success states
					"warning": "#FF9800", // Orange for warnings
					"error": "#D32F2F", // Red for error states

					"--rounded-box": "0.25rem", // Rounded corners for boxes
					"--rounded-btn": "0.25rem", // Rounded buttons
					"--rounded-badge": "0.25rem", // Rounded badges

					"--animation-btn": "0.2s", // Button animation speed
					"--animation-input": "0.2s", // Input animation speed

					"--btn-text-case": "uppercase", // Uppercase button text
					"--navbar-padding": "0.5rem", // Navbar padding
					"--border-btn": "1px", // Button border width
				},
				minlight: {
					"primary": "#1976D2", // Highlight color for links, buttons, etc.
					"primary-focus": "#1565C0", // Darker shade for hover states
					"primary-content": "#ffffff", // Text color on primary elements

					"secondary": "#6f42c1", // For secondary UI elements
					"secondary-focus": "#5a34a5", // Darker secondary for hover states
					"secondary-content": "#ffffff", // Text color on secondary elements

					"accent": "#D32F2F", // Accent color for highlights (e.g., tags, error states)
					"accent-focus": "#C62828", // Darker accent shade for hover
					"accent-content": "#ffffff", // Text color on accent elements

					"neutral": "#212121", // Default text color
					"neutral-focus": "#333333", // Focused/hover neutral color
					"neutral-content": "#ffffff", // Text color on neutral elements

					"base-100": "#ffffff", // Background color
					"base-200": "#f6f6f6", // Light background, e.g., sidebar background
					"base-300": "#e0e0e0", // Even lighter background, e.g., for borders
					"base-content": "#757575", // Default text on the base background

					"info": "#22863a", // For informational messages
					"success": "#77cc00", // Success states
					"warning": "#FF9800", // Warnings (parameter colors, etc.)
					"error": "#D32F2F", // Error states

					"--rounded-box": "0.25rem", // Rounded corners for cards/containers
					"--rounded-btn": "0.25rem", // Rounded buttons
					"--rounded-badge": "0.25rem", // Rounded badges

					"--animation-btn": "0.2s", // Button animations
					"--animation-input": "0.2s", // Input animations

					"--btn-text-case": "uppercase", // Text case for buttons
					"--navbar-padding": "0.5rem", // Padding in the navbar
					"--border-btn": "1px", // Button border width
				},
			}
		]
	},
	plugins: [require('@tailwindcss/typography'), require('daisyui')]
} as Config;
