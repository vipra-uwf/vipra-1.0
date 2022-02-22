

class UpdateManager_SSE{
    constructor(SimManager){
        this.simManager = SimManager;
        this.SSE_RETRY_INTERVAL = 10000;
    }

    // TODO Provide proper updates to client, currently just taking output and piping it straight to client
    // TODO if finished return results
    async ProvideUpdates(configID, response){

        const ps = this.simManager.GetProcess(configID);
        if(ps){
            this._SET_SSE_HEADERS(response);
            ps.stdout.on('data', (data)=>{
                response.write(data.toString());
            });
            ps.stderr.on('data', (data)=>{
                response.write(data.toString());
            })
            ps.on('close', ()=>{
                response.end();
            });
        }else{
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
        response.write('retry: ' + this.SSE_RETRY_INTERVAL);
    }
}

module.exports = UpdateManager_SSE