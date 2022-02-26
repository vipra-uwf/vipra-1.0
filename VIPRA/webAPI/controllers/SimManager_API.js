

const { SIM_OPTIONS_PATH, SIM_RUN_PATH }   = require('../configurations/File_Paths');
const spawn              = require('child_process').spawn;
const fs		 = require('fs');

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

    // TODO this currently compiles and starts the simulation, may want to change
    _START_SIM(configID){
        const ps = spawn('sh', [SIM_RUN_PATH, configID]).on('spawn', ()=>{
            this.cID_Process_Map.set(configID, ps);
        });
        ps.stdout.on('data', (data)=>{console.log(data.toString())})
        ps.stderr.on('data', (data)=>{console.log(data.toString());})
        ps.on('close', (data)=>{
            console.log("CLOSING SIM");
            this.cID_Process_Map.delete(configID);
        });
    }
}


module.exports = SimManager_API
