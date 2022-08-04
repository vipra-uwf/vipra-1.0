<script>
    import axios from 'axios';

    import "./../../styles/main.css";
    import 'bootstrap/dist/css/bootstrap.min.css';
    import { onMount } from "svelte";
    import { apiData, modules } from "../../components/configuration/apiData";
    import { Dropdown, DropdownItem, DropdownMenu, DropdownToggle, Form, FormGroup, FormText, Input, Label} from 'sveltestrap';
    import { TYPES } from '../../definitions/types';

    let simconfig = {};
    let createError;
    let createResponse;


    onMount(async () => {
        console.log("fetching");
        fetch('https://192.168.1.120:3001/module/')
        .then(response => response.json())
        .then(data => {
            apiData.set(data);
            simconfig.configuration_reader = $modules["configuration_reader"][0].id;
            simconfig.clock = $modules["clock"][0].id;
            simconfig.data = $modules["data"][0].id;
            simconfig.simulation = $modules["simulation"][0].id;
        }).catch(error => {
            console.log(error);
        });
    });

    async function sendNewConfig() {
        createError = null;
        createResponse = null;
        if(checkConfig()){
            axios({
                method: 'post',
                url: 'https://192.168.1.120:3001/simconfig',
                data: {
                    simconfig
                }
            })
            .then((response)=>{
                
            })
            .catch((error)=>{
                createError = error.response.data.error;
                createResponse = error.response.data.detail;
                console.log(error);
            });
        }
    }

    function checkConfig(){
        return true;
    }

</script>


{#if Object.keys($modules).length > 0}
    <Form>
        <FormGroup>
            <Label for="Name">Configuration Name</Label>
            <Input style="margin: auto; width: 25%" type="text" bind:value={simconfig.name}/>
        </FormGroup>
        <FormGroup>
            <Label for="Description">Configuration Description</Label>
            <Input style="margin: auto; width: 25%" type="textarea" bind:value={simconfig.description}  />
        </FormGroup>
    </Form>
    {#each Object.keys(TYPES) as type}
        <Label>{TYPES[type]}</Label>
        {#if $modules[type]}
        <Dropdown >
            <DropdownToggle caret>
            {#if simconfig[type]}
                {simconfig[type]}
            {:else}
                {TYPES[type]}
            {/if}
            </DropdownToggle>
            <DropdownMenu end>
            {#each $modules[type] as module}
                <DropdownItem id={type} on:click={()=>{simconfig[type]= {id: module.id}; }}>{module.name}</DropdownItem>
            {/each}
            </DropdownMenu>
        </Dropdown>
        {:else}
            <p style="margin: auto; width: 50%; text-align:center">No Installed "{TYPES[type]}" Modules</p>
            <a href="https://vrs.chain-builder.net">Download More From Here</a>
        {/if}
    {/each}
    <div>
        <br/>
        <br/>
        <button on:click={sendNewConfig}>Create Configuration</button>
        <br/>
        {#if createError}
            <p>ERROR: {createError}</p>
        {/if}
        {#if createResponse}
            <p>{createResponse}</p>
        {/if}
    </div>
{:else}
    <p>Loading... </p>
{/if}