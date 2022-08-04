<script>
	import Router from "svelte-spa-router";
	import routes from './routes';
	import './styles/main.css';
</script>

<main>
	<Router {routes}/>
</main>

<style>


	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>