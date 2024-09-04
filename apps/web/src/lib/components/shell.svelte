<script>
	import { page } from '$app/stores';

	// function handleLogout() {
	// 	fetch('/api/auth/logout', {
	// 		method: 'GET',
	// 		headers: {
	// 			'Content-Type': 'application/json'
	// 		},
	// 		credentials: 'include'
	// 	});
	// }
</script>

<div class="navbar bg-base-100 mb-2 border-b">
	<div class="flex-1">
		<a class="text-xl" href="/d">Domain Driven Diagram</a>
	</div>
	<div class="flex-none items-center">
		<div class="dropdown dropdown-end">
			<div tabindex="0" role="button" class="avatar">
				<div class="w-12 rounded-full">
					<img alt="Random Avatar" src="https://avatar.iran.liara.run/public" />
				</div>
			</div>
			<ul class="menu menu-sm dropdown-content bg-base-100 rounded-box z-[1] w-52 p-2 shadow">
				<li>
					<form action="/api/auth/logout" class="flex w-full" method="get">
						<button class="w-full text-start">logout</button>
					</form>
				</li>
			</ul>
		</div>
	</div>
</div>

<slot></slot>
