<script>
	const links = [
		{
			topic: 'Introduction',
			name: 'Introduction',
			children: []
		},
		{
			topic: 'Domain Driven Design',
			children: [
				{
					name: 'Context',
					href: '/docs/ddd/context'
				},
				{
					name: 'Aggregate',
					href: '/docs/ddd/aggregate'
				},
				{
					name: 'Entity',
					href: '/docs/ddd/entity'
				},
				{
					name: 'Value Object',
					href: '/docs/ddd/value-object'
				}
				// {
				// 	name: 'Contributing',
				// 	href: '/docs/ddd/entity'
				// }
			]
		}
	];
</script>

<div class="flex">
	<div class="bg-primary sticky h-[100dvh] space-y-4 px-4">
		<h2 class="text-xl font-bold opacity-80">Documentation</h2>
		<aside class="space-y-4">
			{#each links as link}
				<div>
					<div class="text- font-semibold opacity-80">
						{link.topic}
					</div>
					<ul class="mt-2 space-y-2">
						{#each link.children as child}
							<li><a href={child.href}>{child.name}</a></li>
						{/each}
					</ul>
				</div>
			{/each}
		</aside>
	</div>

	<article class="prose prose-neutral flex-1 px-8 py-4">
		<slot />
	</article>
</div>
