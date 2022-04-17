

const { SIM_OPTIONS_PATH, SIM_GEN_PATH, INPUT_DATA_PATH, DOCKER_GEN_PATH, BUILD_DIR_PATH }    = require('../../../configurations/File_Paths');
const { spawnSync }                         = require('child_process');
const fs		                            = require('fs');

class SimManager_ProvideImage{

    #configManager;
    #behaviorManager;
    #imageBuilder;

    constructor(ConfigManager, BehaviorManager, ImageBuilder){
        this.#checkParams(ConfigManager, BehaviorManager, ImageBuilder);
        this.#configManager = ConfigManager;
        this.#behaviorManager = BehaviorManager;
        this.#imageBuilder = ImageBuilder;
    }

    async HandleSimRequest(reqBody, auth, response){
        if(auth){
            if(this.#CheckSimRequest(reqBody)){
                const configID = await this.#SetupSim(reqBody);
                const generated = await this.#GenerateSim(configID);
                if(generated){
                    await this.#SendImage(response, reqBody.build_config, configID);
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
    async #SetupSim(configJSON){
        const configID = await this.#configManager.CreateConfig(configJSON);
        this.#imageBuilder.MakeBuildDir(configID);
        const buildPath = BUILD_DIR_PATH.concat('/', configID);
        const behaviorName = await this.#GetBehaviorName(configJSON.sim_config);

        await this.#configManager.StageConfig(configID, buildPath);
        await this.#behaviorManager.StageBehavior(behaviorName, buildPath);

        return configID;
    }

    #checkParams(ConfigManager, BehaviorManager, ImageBuilder){
        if(!ConfigManager){
            throw(`Simulation Manager's Config Manager is NULL`);
        }
        if(!BehaviorManager){
            throw(`Simulation Manager's Behavior Manager is NULL`);
        }
        if(!ImageBuilder){
            throw(`Simulation Manager's ImageBuilder is NULL`);
        }
    }

    // TODO provide more descriptive errors
    async #SendImage(response, build_config, configID, behaviorName){
        this.#imageBuilder.BuildImage(build_config, configID)
        .then((imagePath)=>{
            console.log(imagePath);
            if(imagePath){
                response.download(imagePath);
            }else{
                console.log("[ERROR] Error in SendImage");
                response.status(500).json({error: 'Unknown Error'});
            }
            // TODO remove config / behavior and generated code
            this.#configManager.UnStage(configID, BUILD_DIR_PATH.concat('/', configID));
            this.#behaviorManager.UnStage(behaviorName, BUILD_DIR_PATH.concat('/', configID));
        })
        .catch((err)=>{
            console.log(`[ERROR] Error in SendImage: ${err}`);
            response.status(500).json({error: 'Unknown Error'});
        });
    }

    // TODO this only gets one behavior from the config (will error if more)
    #GetBehaviorName(configJSON){
        const name = configJSON.human_behavior_model.configuration["behavior#"];
        return name;
    }

    async #GenerateSim(configID){
        try{
            const output = spawnSync('sh', [SIM_GEN_PATH, configID], {
                                cwd: process.cwd(),
                                env: process.env,
                                stdio: 'pipe',
                                encoding: 'utf-8'
                            });
            console.log(`STDOUT: ${output.stdout}`);
            console.log(`STDERR: ${output.stderr}`);
            if(output.stderr){
                return false;
            }
            return true;
        }catch (err){
            console.log(err);
            console.log(err.stderr.toString());
            return false;
        }
    }

    #CheckSimRequest(reqBody){
        if(!(reqBody.sim_config && reqBody.sim_params && reqBody.build_config)){
            return false;
        }
        return true;
    }
}


module.exports = SimManager_ProvideImage
