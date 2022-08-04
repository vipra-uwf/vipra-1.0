<script>
    import { onMount } from "svelte";
    import { apiData, simconfigs } from "../../components/configuration/apiData";
    import { Button,Card,CardBody,CardFooter,CardText,CardSubtitle, CardTitle, CardHeader } from 'sveltestrap';
    import { TYPES } from '../../definitions/types';


    onMount(() =>{
        fetch('https://192.168.1.120:3001/simconfig')
        .then(response=>response.json())
        .then((data)=>{
            apiData.set(data);
            console.log($simconfigs);
        })
        .catch((error)=>{
            console.log(error);
        });
    });

</script>

<h1>Simulation Configurations</h1>

{#each Object.keys($simconfigs) as config}
    <Card>
        <CardHeader>
        <CardTitle>{$simconfigs[config].name}</CardTitle>
        </CardHeader>
        <CardBody>
            <CardText>Description: {$simconfigs[config].description}</CardText>
        </CardBody>
        {#each Object.keys(TYPES) as type}
            <p>{TYPES[type]}: {$simconfigs[config][type].name}</p>
        {/each}
    </Card>
{/each}

<a class="btn" href="#/configuration/new">Add New Configuration</a>