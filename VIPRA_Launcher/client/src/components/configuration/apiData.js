import { writable, derived } from 'svelte/store';

export const apiData = writable([]);

export const modules = derived(apiData, ($apiData)=> {
    if($apiData.data){
        let ret = {};
        $apiData.data.forEach(element => {
            ret[element.type] = element.modules
        });
        return ret;
    }
    return {};
});

export const simconfigs = derived(apiData, ($apiData)=>{
    if($apiData.data){
        let ret = {};
        $apiData.data.forEach(element => {
            ret[element.id] = element;
        });
        return ret;
    }
    return {};
});