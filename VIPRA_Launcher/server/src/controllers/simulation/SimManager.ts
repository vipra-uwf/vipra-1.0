import crypto from 'crypto';
import { ChildProcess } from 'child_process';

import { config } from '../../configuration/config';
import { runSim } from "../../util/Processes";
import { Status } from "../../data_models/Status.e";
import { Logger } from "../../logging/Logging";
import { ConfigManager } from "../simconfig/ConfigManager";

export class SimManager{

    private static instance : SimManager;
    private processMap      : Map<string, ChildProcess>;

    // eslint-disable-next-line @typescript-eslint/no-empty-function
    private constructor(){
    }

    public static getInstance() : SimManager{
        if(SimManager.instance){
            return SimManager.instance;
        }else{
            return new SimManager();
        }
    }

    // TODO change names here, it is confusing -RG
    public async runSim(args : {[key: string] : string[]}) : Promise<string>{
        if(!args.configid){
            return null;
        }
        return new Promise((resolve, reject)=>{
            const configId = args.configid.at(0);
            const outputID : string = crypto.randomUUID();
            const outputPath : string = `${config.vipra.outputDir}/${configId}/${outputID}`;
            const ps : ChildProcess = runSim(configId, outputPath, `TODO`, `TODO`);
            this.processMap.set(configId, ps);

            ps.on('close', (code : number, signal : NodeJS.Signals) =>{
                this.processMap.delete(configId);
                if(code !== 0){
                    reject(signal);
                }else{
                    resolve(outputPath);
                }
            });
        });
    }
}