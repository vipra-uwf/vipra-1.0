/**
 * @module Controllers
 */

import crypto from 'crypto';
import child_process, { ChildProcess } from 'child_process';

import { inject, singleton } from 'tsyringe';

import { config } from '../../configuration/config';
import { Logger } from '../../logging/Logging';
import { CbResult } from 'typechain';
import { FLAGS } from '../../types/flags';
import { FilesController } from '../files/FilesController';
import { FlagMap, Nullable } from '../../types/typeDefs';
import { ISimManager } from './interfaces/SimManager.interface';
import { ISimBuilder } from './interfaces/SimBuilder.interface';
import { IConfigManager } from '../simconfig/interfaces/ConfigManager.interface';

// TODO NEXT check simbuilder for simulation build status before attempting to run -RG

/**
 * @description Handles Running Simulations
 *
 */
@singleton()
export class SimManager implements ISimManager {

  private processMap      : Map<string, ChildProcess>;

  private configManager   : IConfigManager;

  private simBuilder      : ISimBuilder;

  private fc              : FilesController;

  private quicksim        : boolean;

  private defaultMap      : string;

  private defaultPeds     : string;

  private defaultParams   : string;

  public constructor(@inject('ConfigManager') configManager : IConfigManager, @inject('SimBuilder') simBuilder : ISimBuilder, @inject('FilesController') fileController : FilesController) {
    this.processMap = new Map();
    this.fc = fileController;
    this.configManager = configManager;
    this.simBuilder = simBuilder;
  }

  /**
   * @description Sets the applicable flags for SimManager
   *
   * FLAGS:
   * DEFAULT_MAP
   * DEFAULT_PEDS
   * DEFAULT_PARAMS
   * QUICK_SIM
   *
   * @param  {FlagMap} flags - Map of command line flags and their values
   */
  public setFlags(flags : FlagMap) {
    this.quicksim = flags.has(FLAGS.QUICK_SIM);
    if (flags.has(FLAGS.DEFAULT_MAP)) {
      Logger.info(`Setting Sim Default Map: ${flags.get(FLAGS.DEFAULT_MAP) || ''}`);
      this.defaultMap = flags.get(FLAGS.DEFAULT_MAP) || '';
    }
    if (flags.has(FLAGS.DEFAULT_PEDS)) {
      Logger.info(`Setting Sim Default Pedestrians: ${flags.get(FLAGS.DEFAULT_PEDS) || ''}`);
      this.defaultPeds = flags.get(FLAGS.DEFAULT_PEDS) || '';
    }
    if (flags.has(FLAGS.DEFAULT_PARAMS)) {
      Logger.info(`Setting Sim Default Parameters: ${flags.get(FLAGS.DEFAULT_PARAMS) || ''}`);
      this.defaultParams = flags.get(FLAGS.DEFAULT_PARAMS) || '';
    }
  }

  /**
   * @description TypeChain Method used for running the simulation
   *
   * @param  {{[key:string]:string[]}} args - TypeChain arguments
   */
  public async startSim(args : { [key: string] : string[] }) : Promise<CbResult> {

    if (this.quicksim) {
      return { error: false, result: `${config.vipra.outputDir}/debug/quick.json` };
    }

    const simready = this.simBuilder.getSimState();
    if (simready.ready) {
      const configId : string = this.normalizeConfigId(args.configid[0]);
      const map : string = `${this.defaultMap !== undefined ? this.defaultMap : this.getMap(args.map[0])}`;
      const peds: string = `${this.defaultPeds !== undefined ? this.defaultPeds : this.getPeds(args.peds[0])}`;
      const params: string = `${this.defaultParams !== undefined ? this.defaultParams : args.params[0]}`;

      if (configId && map && peds && params) {
        const outputID : string = crypto.randomUUID();
        this.fc.makeDir(`${config.vipra.outputDir}/${configId}/`);
        return new Promise((resolve)=>{
          
          const outputPath : string = `${config.vipra.outputDir}/${configId}/${outputID}`;
          
          /**
           * @description callback function for simulation execution
           * @param {number} code - exit code of simulation process
           */
          const onExit = (code : number) => {
            this.processMap.delete(configId);
            if (code !== 0) {
              Logger.error('Error Running Simulation');
              resolve({ error: true, result: 'Error Running Simulation' });
            } else {
              Logger.info(`Successfully Finished Simulation: ID: ${configId}`);
              resolve({ error: false, result: outputPath });
            }
          };

          Logger.info(`Starting Simulation: ConfigID: ${configId}`);
          const ps : Nullable<ChildProcess> = this.runSim(configId, map, peds, params, outputPath, onExit);

          if (ps) {
            this.processMap.set(configId, ps);
          } else {
            return { error: true, result: 'Unable to start the Simulation' };
          }
        });
      }
    }
    return { error: true, result: `Simulation is not ready to run: ${simready.reason || 'Unknown'}` };
  }

  /**
   * @deprecated
   *
   *
   * @description TypeChain Method that provided the parameters required for a given configid
   *
   * @param  {{[key:string]:string[]}} args - TypeChain arguments
   */
  // NOTE: typechain requires this be async,
  // eslint-disable-next-line @typescript-eslint/require-await
  public async getParams(args : { [key: string] : string[] }) : Promise<CbResult> {
    const configID = args.configid[0].replace(/"/g, '');
    const params = this.configManager.getParams(configID);
    if (params) {
      return {
        error: false,
        result: `${JSON.stringify({ configID, params })}`,
      };
    } else {
      return {
        error: true,
        result: `No Configuration With ID: ${configID}`,
      };
    }
  }

  /**
   * @description Makes sure that the configid is in the expected format for {@link runSim}
   *
   * @param  {string} configid - string to be fixed
   */
  private normalizeConfigId(configid : string) : string {
    return configid.replace(/"/g, '');
  }

  /**
   * @notimplemented
   * @description Returns the path to the map file with id
   * @param  {string} id - id of map file to get
   */
  private getMap(id : string) : string {
    return id;
  }

  /**
   * @notimplemented
   * @description Returns the path to the pedestrian set file with id
   * @param  {string} id - id of pedestrian set to get
   */
  private getPeds(id : string) : string {
    return id;
  }


  /**
   * @description Runs the VIPRA Simulation with the given parameters
   *
   *
   * @private
   * @param  {string} configID - id of sim.config to use
   * @param  {string} mapFile - path to obstacle_set file
   * @param  {string} pedestrianFile - path to pedestrian_set file
   * @param  {string} paramsFile - path to sim_params.json to use
   * @param  {string} outputFile - path of output file
   * @param  {(code:number,signal:NodeJS.Signals)=>void} onExit - callback function for when simulation completes
   */
  private runSim(configID : string, mapFile : string, pedestrianFile : string, paramsFile : string, outputFile : string, onExit : (code : number, signal : NodeJS.Signals)=>void) : Nullable<ChildProcess> {
    const configDir = `${config.vipra.simsDir}/${configID}`;
    if (!this.fc.fileExists(configDir)) {
      return null;
    }

    const command : string = `${config.vipra.simsDir}/VIPRA`;
    const args : string[] =  [`${configDir}/sim.config`, paramsFile, pedestrianFile, mapFile, outputFile];
    const ps = child_process.spawn(command, args);

    ps.stderr.on('data', (data : string) => {
      Logger.error(`runSim: ID: ${configID} : ${data}`);
    });
    ps.stdout.on('data', (data : string) => {
      Logger.debug(`runSim: ID: ${configID} : ${data}`);
    });
    ps.on('close', (code : number, signal : NodeJS.Signals) =>{
      onExit(code, signal);
    });
    return ps;
  }
}


