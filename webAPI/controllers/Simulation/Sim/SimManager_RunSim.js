

const { SIM_OPTIONS_PATH, SIM_RUN_PATH }    = require('../../../configurations/File_Paths');
const spawnSync                             = require('child_process').spawn;
const fs		                            = require('fs');

// TODO This needs to be updated to use HandleSimRequest and cleaned up -RG

class SimManager_RunSim{

    #configManager;
    #behaviorManager;

    constructor(ConfigManager, BehaviorManager){
        throw(`SimManager_RunSim is not properly Implemented`);
        this.cID_Process_Map = new Map();
        this.#configManager = ConfigManager;
        this.#behaviorManager = BehaviorManager; 
    }

    GetProcess(configID){
        return this.cID_Process_Map.get(configID);
    }

    SendSimOptions(response){
        fs.readFile(SIM_OPTIONS_PATH, (err, data)=>{
            if(err){
                response.status(500).json({error: "Unknown Error", detail: "Unable to read Config Options File"});
            }else{
                response.status(200).json({message: 'SUCCESS', data: JSON.parse(data)});
            }
        });
    }

    async HandleSimRequest(reqBody, auth, response){
        if(auth){
            if(this.#CheckSimRequest(reqBody)){
                const simID = await this.#SetupSim(reqBody.sim_config, reqBody.sim_params);
                const started = await this.#StartSim(simID);
                response.status(200).json({message:"started"});
            }else{
                response.status(400).json({error: "Bad Request", detail: "Request is Missing Simulation Configuration Information"});
            }
        }else{
            response.status(401).json({error: "Not Authorized", detail: "Not Authorized to access this resource"});
        }
    }

    async #SetupSim(sim_config, sim_params){
        const simID = await this.#configManager.CreateConfig(sim_config, sim_params);
        await this.#configManager.StageConfig(simID);
        const behaviorName = await this.#GetBehaviorName(sim_config);
        await this.#behaviorManager.StageBehavior(behaviorName);
        return simID;
    }

    #GetBehaviorName(configJSON){
        const name = configJSON.human_behavior_model.configuration["behavior#"];
        return name;
    }

    #CheckSimRequest(reqBody){
        if(!(reqBody.sim_config && reqBody.sim_params)){
            return false;
        }
        return true;
    }

    #StartSim(configID){
        const ps = spawnSync('sh', [SIM_RUN_PATH, configID]);

        this.cID_Process_Map.set(configID, ps);

        ps.stdout.on('data', (data)=>{console.log(data.toString())})
        ps.stderr.on('data', (data)=>{console.log(data.toString());})
        ps.on('close', (data)=>{
            console.log("CLOSING SIM");
            this.cID_Process_Map.delete(configID);
        });
    }
}


module.exports = SimManager_RunSim;
