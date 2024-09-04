<script lang="ts">
</script>

<div class="flex min-h-screen items-center justify-center self-center">
	<div class="flexflex-col items-stretch p-6 shadow md:p-8 lg:p-16">
		<h3 class="text-center text-xl font-semibold">Login</h3>
		<!-- <h3 class="text-base-content/70 mt-2 text-center text-sm">
			Seamless Access, Secure Connection: Your Gateway to a Personalized Experience.
		</h3> -->
		<form method="post" class="mt-6 w-96 md:mt-10">
			<div>
				<div class="form-control">
					<label for="email" class="label"
						><span class="label-text cursor-pointer">Email Address</span></label
					>
					<div class="form-control rounded-box border-base-content/20 border ps-3">
						<input
							id="email"
							placeholder="Email Address"
							class="input input-sm w-full transition-all focus:border-transparent focus:outline-0 focus:outline-offset-0"
							name="email"
						/>
					</div>
				</div>
				<div class="form-control mt-3">
					<label for="password" class="label"
						><span class="label-text cursor-pointer">Password</span></label
					>
					<div class="form-control rounded-box border-base-content/20 border">
						<input
							id="password"
							placeholder="Password"
							class="input input-sm w-full transition-all focus:border-transparent focus:outline-0 focus:outline-offset-0"
							type="password"
							name="password"
						/>
					</div>
				</div>
			</div>
			<div class="mt-4 md:mt-6">
				<button class="btn btn-primary btn-block gap-2 text-base"
					><svg
						xmlns="http://www.w3.org/2000/svg"
						xmlns:xlink="http://www.w3.org/1999/xlink"
						aria-hidden="true"
						role="img"
						font-size="16"
						width="1em"
						height="1em"
						viewBox="0 0 24 24"
						><path
							fill="none"
							stroke="currentColor"
							stroke-linecap="round"
							stroke-linejoin="round"
							stroke-width="2"
							d="M15 3h4a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2h-4m-5-4l5-5l-5-5m5 5H3"
						></path></svg
					>Login</button
				>
			</div>

			<!-- <p class="text-base-content/80 mt-4 text-center text-sm md:mt-6">
				Haven't account <a class="text-primary hover:underline" href="/auth/register">Create One</a>
			</p> -->
		</form>
	</div>
</div>
