import child_process, { ChildProcess } from 'child_process';
import { Logger } from '../../controllers/logging/logger';
import { fileExists } from '../../util/fileOperations';
import { Config } from '../../configuration/config';
import { Nullable } from '../../types/typeDefs';
import { ISimRunner } from './simulation.runner.interface';


/**
 * @description Handles Running Simulation Processes
 */
export class SimRunner implements ISimRunner {

  private config : Config;

  constructor(config : Config) {
    this.config = config;
  }


  /**
   * @description Starts a simulation run with the provdied files
   * @param {string} runID - id of the sim config
   * @param {string} configID - id of the sim config
   * @param {string} mapFile - absolute path to obstacle map
   * @param {string} pedestrianFile - absolute path to pedestrian file
   * @param {string} paramsFile - absolute path to parameters file
   * @param {string} outputFile - absolute path to output file
   */
  runSim(runID : string, configID : string, mapFile : string, pedestrianFile : string, paramsFile : string, outputFile : string) : Nullable<ChildProcess> {
    const configDir = `${this.config.simconfig.simconfigDir}/${configID}`;
    if (!fileExists(configDir)) {
      return null;
    }
  
    const command : string = `${this.config.vipra.vipraDir}/${this.config.vipra.exeName}`;
    const args : string[] =  [`${configDir}/sim.config`, paramsFile, pedestrianFile, mapFile, outputFile];
    const ps = child_process.spawn(command, args);
  
    ps.stderr.on('data', (data : string) => {
      Logger.error(`runSim: runID: ${runID} ; configID: ${configID} ; ${data}`);
    });
    ps.stdout.on('data', (data : string) => {
      Logger.debug(`runSim: runID: ${runID} ; configID: ${configID} ; ${data}`);
    });
    ps.on('error', ()=>{
      Logger.error(`Sim Run: ${runID} ; Unable to start simulation`);
    });
    
    return ps;
  }
}