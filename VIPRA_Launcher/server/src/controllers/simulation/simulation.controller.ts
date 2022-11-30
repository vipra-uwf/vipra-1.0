import crypto from 'crypto';
import { ISimRunner } from '../../runners/simulation/simulation.runner.interface';
import { Nullable } from '../../types/typeDefs';
import { CbArgs } from 'typechain';
import { EventSystem } from '../events/eventSystem';
import { EventHandler, EventType, RequestType } from '../events/eventTypes';
import { ISimController } from './interfaces/simulation.controller.interface';
import { Config } from '../../configuration/config';
import { deleteDir, fileExists, makeDir } from '../../util/fileOperations';
import { OMap } from '../../types/maps/map.types';
import { RepoType } from '../../types/uploading.types';
import { FLAGS } from '../../types/flags/flags.types';
import { Logger } from '../logging/logger';
import { errorExit } from '../../util/utilMethods';

interface SimInputs {
  mapPath : string;
  pedPath : string;
  paramFile : string;
}

/**
 * @description Controller Class for simulations
 */
export class SimController implements ISimController {
  
  private evSys : EventSystem;

  private simRunner : ISimRunner;

  private config : Config;

  constructor(simRunner : ISimRunner, config : Config, evSys : EventSystem) {
    this.evSys = evSys;
    this.simRunner = simRunner;
    this.config = config;
    this.setupHandlers();
  }

  /**
   * @description Starts a new simulation
   * @param {string} configID - simconfig id
   * @param {string} mapID - obstacle map id
   * @param {string} pedsID - pedestrian set id
   * @param {CbArgs} params - parameters for simulation
   */
  public async startSim(configID : string, mapID : string, pedsID : string, params : CbArgs): Promise<Nullable<string>> {

    const runID : string = crypto.randomUUID();
    const runDir = `${this.config.vipra.outputDir}/${runID}`;
    const outputPath = `${runDir}/output.file`;
    makeDir(runDir);
    
    const inputs = await this.getInputs(mapID, pedsID, params, runDir);
    
    if (inputs) {
      configID = this.config.flags.get(FLAGS.DEBUG_CONFIG) || configID;
      const simPS = this.simRunner.runSim(runID, configID, inputs.mapPath, inputs.pedPath, inputs.paramFile, outputPath);
      if (simPS) {
        void this.evSys.emit<string>(EventType.NEW, 'SimRun', runID);
        return new Promise(resolve=>{
          simPS.on('close', (code, signal)=>{
            if (errorExit(code, signal)) {
              void deleteDir(runDir, true);
              void this.evSys.emit<string>(EventType.FAIL, 'SimRun', runID);
              resolve(null);
            } else {
              void this.evSys.emit<string>(EventType.SUCCESS, 'SimRun', runID);
              resolve(outputPath);
            }
          });
        });
      } else {
        void deleteDir(runDir, true);
        void this.evSys.emit<string>(EventType.FAIL, 'SimRun', runID);
      }
    }

    void deleteDir(runDir, true);
    return Promise.resolve(null);
  }

  /**
   * @description Sets up the event handlers for SimController
   */
  private setupHandlers() : void {
    this.evSys.subscribe(EventType.SUCCESS, 'SimBuild', this.handleNewBuild);
  }

  /**
   * @description Event handler for successful simulation builds
   * @param {string} buildID - id of build that completed
   */
  private handleNewBuild : EventHandler = () : void => {
    if (this.config.flags.has(FLAGS.DEBUG_RUN)) {
      this.startSim('', '', '', {})
        .catch((error : string)=>{
          Logger.error(`Debug Simulation Run Failed: ${error}`);
        });
    }
  };

  /**
   * @description Gets the paths to the input files from their IDs
   * @param {string} mapID - id of map
   * @param {string} pedsID - id of pedestrians
   * @param {string} params - parameters passed in from ChainBuilder
   * @param {string} runDir - directory for the simulation run
   */
  private async getInputs(mapID : string, pedsID : string, params : CbArgs, runDir : string) : Promise<Nullable<SimInputs>> {
    const mapPath = await this.getMap(mapID);
    if (mapPath) {
      const pedPath = this.getPeds(pedsID);
      if (pedPath) {
        const paramFile = this.writeParams(params, runDir);
        if (paramFile) {
          return {
            mapPath,
            pedPath,
            paramFile,
          };
        }
      }
    }
    return null;
  }

  /**
   * @description Takes chainbuilder params and writes them to a file in the proper format
   * @param {CbArgs} params - chainbuilder parameters
   * @param {string} runDir - directory to place file
   */
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  private writeParams(params : CbArgs, runDir : string) : Nullable<string> {
    if (this.config.flags.has(FLAGS.DEBUG_PARAMS)) {
      return this.config.flags.get(FLAGS.DEBUG_PARAMS) || null;
    }
    return null;
  }

  /**
   * @description Gets the path to the map file for the map with id mapID, null if no map with id
   * @param {string} mapID - id of map to get path of
   */
  private async getMap(mapID : string) : Promise<Nullable<string>> {
    if (this.config.flags.has(FLAGS.DEBUG_MAP)) {
      return this.config.flags.get(FLAGS.DEBUG_MAP) || null;
    }
    const map = await this.evSys.request<RepoType<OMap>>(RequestType.DATA_W_PATH, 'OMap', { id: mapID });
    if (map) {
      const mapPath = `${map.dirPath}/${map.object.name}.omap`;
      if (fileExists(mapPath)) {
        return mapPath;
      }
    }
    return null;
  }

  /**
   * @description Gets the path to the map file for the map with id mapID, null if no map with id
   * @param {string} pedsID - id of pedestrian file to get
   */
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  private getPeds(pedsID : string) : Nullable<string> {
    if (this.config.flags.has(FLAGS.DEBUG_PEDS)) {
      return this.config.flags.get(FLAGS.DEBUG_PEDS) || null;
    }
    return null;
  }
}