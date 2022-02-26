

class UpdateManager_SSE{
    constructor(SimManager){
        this.simManager = SimManager;
        this.SSE_RETRY_INTERVAL = 100000;
    }

    // TODO Provide proper updates to client, currently just taking output and piping it straight to client
    // TODO if finished return results
    // TODO doesn't properly close connection
    async ProvideUpdates(configID, response){
        this._SET_SSE_HEADERS(response);

        const ps = this.simManager.GetProcess(configID);

        console.log("CALLED");

        if(ps){
            ps.stdout.on('data', (data)=>{
                console.log("SENDING");
                response.write('data: ' + data + '\n\n');
            });
            ps.stderr.on('data', (data)=>{
                console.log("SENDING");
                response.write('data: ' + data + '\n\n');
            });
            ps.on('close', ()=>{
                response.end();
            });
        }else{
            response.end();
            throw Error("No simulation with configID: " + configID);
        }
    }

    _SET_SSE_HEADERS(response){
        console.log("Setting SSE Headers");
        response.set({
            'Cache-Control': 'no-cache',
            'Content-Type': 'text/event-stream',
            'Connection': 'keep-alive'
          });
          response.flushHeaders();
    }
}

module.exports = UpdateManager_SSE