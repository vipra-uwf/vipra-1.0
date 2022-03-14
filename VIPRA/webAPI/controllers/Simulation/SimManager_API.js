

const { SIM_OPTIONS_PATH, SIM_RUN_PATH }    = require('./../../configurations/File_Paths');
const spawnSync                             = require('child_process').spawn;
const fs		                            = require('fs');

// TODO switch this from using configIDs to simIDs

class SimManager_API{
    constructor(){
        this.cID_Process_Map = new Map();    
    }

    GetProcess(configID){
        return this.cID_Process_Map.get(configID);
    }

    SendSimOptions(response){
        fs.readFile(SIM_OPTIONS_PATH, (err, data)=>{
            if(err){
                response.send("Error Reading From Options File");
            }else{
                response.send(data);
            }
        });
    }

    async StartSim(configID){
        await this._START_SIM(configID);
    }

    _START_SIM(configID){
        const ps = spawnSync('sh', [SIM_RUN_PATH, configID])

        this.cID_Process_Map.set(configID, ps);

        ps.stdout.on('data', (data)=>{console.log(data.toString())})
        ps.stderr.on('data', (data)=>{console.log(data.toString());})
        ps.on('close', (data)=>{
            console.log("CLOSING SIM");
            this.cID_Process_Map.delete(configID);
        });
    }
}


module.exports = SimManager_API
