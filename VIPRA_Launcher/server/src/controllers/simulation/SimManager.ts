import crypto from 'crypto';
import { ChildProcess } from 'child_process';

import { config } from '../../configuration/config';
import { runSim } from "../../util/Processes";
import { Status } from "../../data_models/Status.e";
import { Logger } from "../../logging/Logging";
import { ConfigManager } from "../simconfig/ConfigManager";
import { CbResult } from 'typechain';

export class SimManager{

    private static instance : SimManager;
    private processMap      : Map<string, ChildProcess>;
    private configManager   : ConfigManager;

    private quicksim        : boolean;

    private constructor(configManager : ConfigManager){
        this.configManager = configManager;
    }

    public static getInstance(configManager? : ConfigManager) : SimManager{
        if(SimManager.instance){
            return SimManager.instance;
        }else{
            if(configManager){
                this.instance = new SimManager(configManager);
                return this.instance;
            }else{
                Logger.error('Attempt to create SimManager without a ConfigManager');
                throw new Error('Attempt to create SimManager without a ConfigManager');
            }
        }
    }

    public setQuickSim(quicksim : boolean){
        this.quicksim = quicksim;
    }

    // TODO
    public async runSim(args : {[key: string] : string[]}) : Promise<CbResult>{

        if(this.quicksim){
            return {error: false, result: `${config.vipra.outputDir}/debug/quick.json`};
        }

        if(args.configid && args.map && args.pedestrians && args.params){
            return new Promise((resolve, reject)=>{
                const configId = args.configid.at(0);
                const outputID : string = crypto.randomUUID();
                const outputPath : string = `${config.vipra.outputDir}/${configId}/${outputID}`;
                const ps : ChildProcess = runSim(configId, args.map[0], args.pedestrians[0], outputPath);
                this.processMap.set(configId, ps);

                Logger.info(`Starting Simulation: ConfigID: ${configId}`);

                ps.on('close', (code : number, signal : NodeJS.Signals) =>{
                    this.processMap.delete(configId);
                    if(code !== 0){
                        Logger.error(`Error Running Simulation`);
                        resolve({error: true, result: 'Error Running Simulation'});
                    }else{
                        Logger.info(`Successfully Finished Simulation: ID: ${configId}`);
                        resolve({error: false, result: outputPath});
                    }
                });
            });
        }else{
            return {
                error: true,
                result: `Missing Parameters: ${args.configid ? "" : "configid, "}${args.map ? "" : "map, "}${args.pedestrians ? "" : "pedestrians, "}${args.params ? "" : "params"}`
            };
        }
    }

    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    public async getParams(args : {[key: string] : string[]}) : Promise<CbResult>{
        const configID = args['configid'][0].replace(/"/g,'');
        const params = this.configManager.getParams(configID);
        if(params){
            return {
                error: false,
                result: JSON.stringify({configID, params})
            };
        }else{
            return {
                error: true,
                result: `No Configuration With ID: ${configID}`
            };
        }
    }
}