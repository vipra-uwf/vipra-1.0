import App from './App.svelte';

const app = new App({
	target: document.body,
	props: {
		debug: false,
		res: "NONE"
	}
});

export default app;