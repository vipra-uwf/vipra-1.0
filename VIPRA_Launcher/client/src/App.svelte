<script>
	export const port = 3000;
	export let debug;
	export let res;

	function recompile(){
		fetch(`https://localhost:${port}/configuration/`)
		.then((response)=>{
			res = response;
		})
		.catch((error)=>{
			res = `ERROR: ${error}`;
		});
	}
</script>

<main>
	<label>
		DEBUG
		<input type=checkbox bind:checked={debug}>
	</label>
	<button on:click={recompile}>Recompile</button>
	<h1>Response: {res}</h1>
</main>

<style>
	main {
		text-align: center;
		padding: 1em;
		max-width: 240px;
		margin: 0 auto;
	}

	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>