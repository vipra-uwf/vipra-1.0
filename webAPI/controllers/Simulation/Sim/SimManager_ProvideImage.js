

const { SIM_OPTIONS_PATH, SIM_GEN_PATH, INPUT_DATA_PATH, DOCKER_GEN_PATH }    = require('../../../configurations/File_Paths');
const { spawnSync }                         = require('child_process');
const fs		                            = require('fs');

class SimManager_ProvideImage{

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
                const generated = await this.#GenerateDocker(simID);
                if(generated){
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
                response.status(500).json({error: "Unknown Error", detail: "Unable to read Config Options File"});
            }else{
                response.status(200).json({message: 'SUCCESS', data: JSON.parse(data)});
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

    // TODO change this to download docker image
    #SendGenerated(response, simID, behaviorName){
        const filepath = INPUT_DATA_PATH.concat('/', simID, '/generated_main.cpp');
        response.status(200).download(filepath);
        // TODO remove config / behavior and generated code
        this.#configManager.UnStage(simID);
        this.#behaviorManager.UnStage(behaviorName);
    }

    #GetBehaviorName(configJSON){
        const name = configJSON.human_behavior_model.configuration["behavior#"];
        return name;
    }

    async #GenerateDocker(simID){
        const generated = await this.#GenerateSim(simID);
        if(generated){
            console.log(
                spawnSync('sh', [DOCKER_GEN_PATH, simID], {
                cwd: process.cwd(),
                env: process.env,
                stdio: 'pipe',
                encoding: 'utf-8'
            }).output);
            return true;
        }else{
            return false;
        }
    }

    async #GenerateSim(simID){
        try{
            console.log(
                spawnSync('sh', [SIM_GEN_PATH, simID], {
                cwd: process.cwd(),
                env: process.env,
                stdio: 'pipe',
                encoding: 'utf-8'
            }).output);
            return true;
        }catch (err){
            console.log(err);
            console.log(err.stderr.toString());
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


module.exports = SimManager_ProvideImage
