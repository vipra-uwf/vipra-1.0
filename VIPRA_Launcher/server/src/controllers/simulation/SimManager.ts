import crypto from 'crypto';
import { ChildProcess } from 'child_process';

import { config } from '../../configuration/config';
import { runSim } from "../../util/Processes";
import { Logger } from "../../logging/Logging";
import { ConfigManager } from "../simconfig/ConfigManager";
import { CbResult } from 'typechain';
import { FLAGS } from '../../data_models/flags';
import { makeDir } from '../../util/FileOperations';

export class SimManager{

    private static instance : SimManager;
    private processMap      : Map<string, ChildProcess>;
    private configManager   : ConfigManager;

    private quicksim        : boolean;

    private defaultMap      : string;
    private defaultPeds     : string;
    private defaultParams   : string;

    private constructor(configManager : ConfigManager){
        this.processMap = new Map();
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

    public setFlags(flags : Map<string, string>){
        this.quicksim = flags.has(FLAGS.QUICK_SIM);
        if(flags.has(FLAGS.DEFAULT_MAP)){
            Logger.info(`Setting Sim Default Map: ${flags.get(FLAGS.DEFAULT_MAP)}`);
            this.defaultMap = flags.get(FLAGS.DEFAULT_MAP);
        }
        if(flags.has(FLAGS.DEFAULT_PEDS)){
            Logger.info(`Setting Sim Default Pedestrians: ${flags.get(FLAGS.DEFAULT_PEDS)}`);
            this.defaultPeds = flags.get(FLAGS.DEFAULT_PEDS);
        }
        if(flags.has(FLAGS.DEFAULT_PARAMS)){
            Logger.info(`Setting Sim Default Parameters: ${flags.get(FLAGS.DEFAULT_PARAMS)}`);
            this.defaultParams = flags.get(FLAGS.DEFAULT_PARAMS);
        }
    }

    public async runSim(args : {[key: string] : string[]}) : Promise<CbResult>{

        if(this.quicksim){
            return {error: false, result: `${config.vipra.outputDir}/debug/quick.json`};
        }

        const configId : string = this.normalizeConfigId(args.configid[0]);
        const map : string = `${this.defaultMap !== undefined ? this.defaultMap : this.getMap(args.map[0])}`;
        const peds: string = `${this.defaultPeds !== undefined ? this.defaultPeds : this.getPeds(args.peds[0])}`;
        const params: string = `${this.defaultParams !== undefined ? this.defaultParams : args.params[0]}`;

        if(configId && map && peds && params){
            const outputID : string = crypto.randomUUID();
            makeDir(`${config.vipra.outputDir}/${configId}/`);
            return new Promise((resolve)=>{

                const onExit = (code : number) => {
                    this.processMap.delete(configId);
                    if(code !== 0){
                        Logger.error(`Error Running Simulation`);
                        resolve({error: true, result: 'Error Running Simulation'});
                    }else{
                        Logger.info(`Successfully Finished Simulation: ID: ${configId}`);
                        resolve({error: false, result: outputPath});
                    }
                };

                const outputPath : string = `${config.vipra.outputDir}/${configId}/${outputID}`;
                Logger.info(`Starting Simulation: ConfigID: ${configId}`);
                const ps : ChildProcess = runSim(configId, map, peds, params, outputPath, onExit);
                this.processMap.set(configId, ps);
            });
        }
    }

    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    public async getParams(args : {[key: string] : string[]}) : Promise<CbResult>{
        const configID = args.configid[0].replace(/"/g,'');
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

    private normalizeConfigId(configid : string) : string {
        return configid.replace(/"/g, '');
    }

    // TODO NEXT add loading maps and pedestrian files -RG
    private getMap(id : string) : string {
        return id;
    }

    private getPeds(id : string) : string {
        return id;
    }
}