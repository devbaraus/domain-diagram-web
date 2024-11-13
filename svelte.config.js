import adapter from '@sveltejs/adapter-netlify';
import { mdsvex } from 'mdsvex';
import { vitePreprocess } from '@sveltejs/vite-plugin-svelte';
import Prism from 'prismjs';

Prism.languages.ddd = {
	'comment': {
	  pattern: /\/\/.*/,
	  greedy: true
	},
	'keyword': {
	  pattern: /\b(?:Context|BoundedContext|Aggregate|AggregateRoot|Entity|ValueObject|DomainEvent|Event|DomainService|Service|Enum|String|Int|UUID|Boolean|Float|Date|Null|Void)\b/,
	  greedy: true
	},
	'string': {
	  pattern: /"(?:\\.|[^"\\])*"/,
	  greedy: true
	},
	'number': {
	  pattern: /\b-?\d+(?:\.\d+)?\b/,
	},
	'boolean': {
	  pattern: /\b(?:true|false)\b/,
	},
	'null': {
	  pattern: /\bnull\b/,
	},
	'identifier': {
	  pattern: /\b[a-zA-Z_]\w*\b/,
	},
	'operator': {
	  pattern: /=|\?|:/,
	},
	'punctuation': {
	  pattern: /[{}[\](),;]/,
	},
	'generic': {
	  pattern: /<\w+>/,
	},
	'method': {
	  pattern: /\b[a-zA-Z_]\w*\(.*?\): \w+\b/,
	  inside: {
		'function-name': {
		  pattern: /^\w+/,
		  alias: 'function'
		},
		'parameters': {
		  pattern: /\(.*?\)/,
		  inside: {
			'parameter': {
			  pattern: /\b\w+:\s*\w+/,
			  inside: {
				'parameter-name': {
				  pattern: /^\w+/,
				  alias: 'variable'
				},
				'parameter-type': {
				  pattern: /:\s*\w+/,
				  inside: {
					'type': {
					  pattern: /\b\w+\b/,
					  alias: 'class-name'
					}
				  }
				}
			  }
			},
			'punctuation': /[(),]/
		  }
		},
		'return-type': {
		  pattern: /:\s*\w+/,
		  inside: {
			'type': {
			  pattern: /\b\w+\b/,
			  alias: 'class-name'
			}
		  }
		}
	  }
	},
	'field': {
	  pattern: /\b[a-zA-Z_]\w*\s*:\s*\w+\b/,
	  inside: {
		'field-name': {
		  pattern: /^\w+/,
		  alias: 'variable'
		},
		'field-type': {
		  pattern: /:\s*\w+/,
		  inside: {
			'type': {
			  pattern: /\b\w+\b/,
			  alias: 'class-name'
			}
		  }
		}
	  }
	}
  };
  
  

/** @type {import('@sveltejs/kit').Config} */
const config = {
	extensions: ['.svelte', '.svx', '.md'],

	// Consult https://kit.svelte.dev/docs/integrations#preprocessors
	// for more information about preprocessors
	preprocess: [
		mdsvex({
			extensions: ['.md', '.svx'],
		}),
		vitePreprocess()
	],

	kit: {
		// adapter-auto only supports some environments, see https://kit.svelte.dev/docs/adapter-auto for a list.
		// If your environment is not supported, or you settled on a specific environment, switch out the adapter.
		// See https://kit.svelte.dev/docs/adapters for more information about adapters.
		adapter: adapter()
	}
};

export default config;
