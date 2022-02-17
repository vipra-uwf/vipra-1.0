const url           = require('url');

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

const redirectToUpdates = (response, pid) => {
    console.log("Redirecting To Updates");
    response.redirect(url.format({
        pathname:'/api/sim/updates',
        query: {
            "PID": pid
        }
    }));
}

// TODO provide updates through SSE for the simulation process on simpid -RG
const provideUpdates = (response, simpid) =>{
    setSSEHeaders(response);
    console.log("Providing Updates");

}

module.exports = 
{
    redirectToUpdates,
    provideUpdates
}