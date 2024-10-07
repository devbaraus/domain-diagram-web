/** @type {import('tailwindcss').Config} */
module.exports = {
  content: ['./views/**/*.{html,hbs}'],
  theme: {
    extend: {
      fontFamily: {
        poppins: ['Inter', 'sans-serif'],
        fira: ['Fira Code', 'monospace'],
      },
    },
  },
  daisyui: {
    themes: [
      'bumblebee',
      // 'dracula',
      // 'light',
      // 'corporate',
    ],
  },
  plugins: [require('daisyui')],
};
