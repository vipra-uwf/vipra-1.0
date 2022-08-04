import Home from './pages/Home.svelte';
import Configuration from './pages/configuration/Configuration.svelte';
import NewConfig from './pages/configuration/NewConfig.svelte';

export default {
    '/': Home,
    '/configuration': Configuration,
    '/configuration/new': NewConfig 
};