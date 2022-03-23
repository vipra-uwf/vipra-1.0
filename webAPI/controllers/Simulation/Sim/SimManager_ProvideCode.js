

const { SIM_OPTIONS_PATH, SIM_GEN_PATH, INPUT_DATA_PATH }    = require('../../../configurations/File_Paths');
const randomUUID                            = require('crypto').randomUUID;
const execSync                              = require('child_process').execSync;
const fs		                            = require('fs');

class SimManager_API{

    #configManager;
    #behaviorManager;

    constructor(ConfigManager, BehaviorManager){
       this.#configManager = ConfigManager;
       this.#behaviorManager = BehaviorManager;
    }

    async HandleSimRequest(reqBody, auth, response){
        if(auth){
            if(this.#CheckSimRequest(reqBody)){
                const simID = await this.#SetupSim(reqBody.sim_config, reqBody.sim_params);
                const genereated = await this.#GenerateSim(simID);
                if(genereated){
                    this.#SendGenerated(response, simID);
                }else{
                    res.status(500).json({error: "Unknown Error", detail: "The Simulation Generation has failed"});
                }
            }else{
                response.status(400).json({error: "Bad Request", detail: "Request is Missing Simulation Configuration Information"});
            }
        }else{
            response.status(401).json({error: "Not Authorized", detail: "Not Authorized to access this resource"});
        }
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

    // TODO doesn't check if something errored -RG
    // TODO only loads one behavior -RG
    async #SetupSim(sim_config, sim_params){
        const simID = await this.#configManager.CreateConfig(sim_config, sim_params);
        await this.#configManager.StageConfig(simID);
        const behaviorName = await this.#GetBehaviorName(sim_config);
        await this.#behaviorManager.StageBehavior(behaviorName);
        return simID;
    }

    // TODO currently only sends generatedmain, will need other parts as well -RG
    #SendGenerated(response, simID){
        const filepath = INPUT_DATA_PATH.concat('/', simID, '/generatedmain.cpp');
        response.status(200).download(filepath);
    }

    #GetBehaviorName(configJSON){
        const name = configJSON.human_behavior_model.configuration["behavior#"];
        return name;
    }

    async #GenerateSim(simID){
        try{
            console.log("MAKING CODE");
            execSync('sh', [SIM_GEN_PATH, simID], {stdio: 'inherit'});
            console.log("MADE CODE");
            return true;
        }catch (err){
            return false;
        }
    }

    #CheckSimRequest(reqBody){
        if(!(reqBody.sim_config && reqBody.sim_params)){
            return false;
        }
        return true;
    }
}


module.exports = SimManager_API
