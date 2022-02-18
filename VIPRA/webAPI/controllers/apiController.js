const { response } = require('express');
const url           = require('url');

const { cID_Process_Map } = require("./simulationController");

// TODO remove console logging from this file


const SSE_RETRY_INTERVAL = '10000'


const setSSEHeaders = (response) =>{
    console.log("Setting SSE Headers");
    response.set({
        'Cache-Control': 'no-cache',
        'Content-Type': 'text/event-stream',
        'Connection': 'keep-alive'
    });
    response.flushHeaders();
    response.write('retry: ' + SSE_RETRY_INTERVAL);
}

// TODO provide updates through SSE for the simulation process on configID -RG
const provideUpdates = (response, configID) =>{
    setSSEHeaders(response);
    console.log("Providing Updates");
    
    const ps = cID_Process_Map.get(configID);
    ps.stdout.on('data', (data)=>{
        response.write(data);
    });
    ps.stderr.on('data', (data)=>{
        response.write(data);
    })
}

module.exports = 
{
    provideUpdates
}