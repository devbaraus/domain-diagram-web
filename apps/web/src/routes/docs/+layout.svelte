<script>
	const links = [
		{
			name: 'Introduction',
			href: '/docs'
		},
		{
			name: 'Installation',
			href: '#installation'
		},
		{
			name: 'Usage',
			href: '#usage'
		},
		{
			name: 'Examples',
			href: '#examples'
		},
		{
			name: 'API',
			href: '#api'
		},
		{
			name: 'Contributing',
			href: '#contributing'
		}
	];
</script>

<div class="flex">
	<div class="bg-primary sticky h-[100dvh] w-24">
		<ul>
			{#each links as link}
				<li><a href={link.href}>{link.name}</a></li>
			{/each}
		</ul>
	</div>

	<div class="prose flex-1 px-8 py-4">
		<slot />
	</div>
</div>
