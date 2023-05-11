
import child_process, { ChildProcess } from 'child_process';

import { ISimRunner } from './interfaces/SimRunner.interface';
import { IFilesController } from '../files/interfaces/FilesController.interface';
import { inject, injectable } from 'tsyringe';
import { config } from '../../configuration/config';
import { Logger } from '../../logging/Logging';
import { Nullable } from '../../types/typeDefs';

/**
 * @description Handles Creating Simulation Processes
 */
@injectable()
export class SimRunner implements ISimRunner {

  private fc : IFilesController;

  public constructor(@inject('FilesController') filescontroller : IFilesController) {
    this.fc = filescontroller;
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
   */
  public runSim(configID : string, mapFile : string, pedestrianFile : string, paramsFile : string, outputFile : string) : Nullable<ChildProcess> {
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
    
    return ps;
  }
}


// /**
//            * @description callback function for simulation execution
//            * @param {number} code - exit code of simulation process
//            */
//  const onExit = (code : number) : void => {
//   this.processMap.delete(configId);
//   if (code !== 0) {
//     Logger.error('Error Running Simulation');
//     resolve({ error: true, result: 'Error Running Simulation' });
//   } else {
//     Logger.info(`Successfully Finished Simulation: ID: ${configId}`);
//     resolve({ error: false, result: outputPath });
//   }
// };