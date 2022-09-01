/**
 * @module Controllers
 */

import crypto from 'crypto';
import { ChildProcess } from 'child_process';

import { inject, singleton } from 'tsyringe';

import { config } from '../../configuration/config';
import { Logger } from '../../logging/Logging';
import { CbResult } from 'typechain';
import { FLAGS } from '../../types/flags';
import { IFilesController } from '../files/interfaces/FilesController.interface';
import { FlagMap, Nullable } from '../../types/typeDefs';
import { ISimManager } from './interfaces/SimManager.interface';
import { ISimBuilder } from './interfaces/SimBuilder.interface';
import { IConfigManager } from '../simconfig/interfaces/ConfigManager.interface';
import { ISimRunner } from './interfaces/SimRunner.interface';

// TODO NEXT check simbuilder for simulation build status before attempting to run -RG

/**
 * @description Handles Running Simulations
 *
 */
@singleton()
export class SimManager implements ISimManager {

  private processMap      : Map<string, ChildProcess>;

  private simRunner       : ISimRunner;

  private configManager   : IConfigManager;

  private simBuilder      : ISimBuilder;

  private fc              : IFilesController;

  private quicksim        : boolean;

  private defaultMap      : string;

  private defaultPeds     : string;

  private defaultParams   : string;

  public constructor(@inject('ConfigManager') configManager : IConfigManager, @inject('SimBuilder') simBuilder : ISimBuilder, @inject('FilesController') fileController : IFilesController, @inject('SimRunner') simrunner : ISimRunner) {
    this.processMap = new Map();
    this.fc = fileController;
    this.configManager = configManager;
    this.simRunner = simrunner;
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
  public setFlags(flags : FlagMap) : void {
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
        

          Logger.info(`Starting Simulation: ConfigID: ${configId}`);
          const ps : Nullable<ChildProcess> = this.simRunner.runSim(configId, map, peds, params, outputPath);
          if (ps) {
            ps.on('close', ()=>{
              resolve({ error: false, result: outputPath });
            });
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
}


