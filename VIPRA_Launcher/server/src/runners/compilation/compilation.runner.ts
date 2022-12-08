
import child_process from 'child_process';

import { Config } from '../../configuration/config';
import { Status } from '../../types/status';
import { Module } from '../../types/module/module.types';
import { fileExists } from '../../util/fileOperations';
import { Logger } from '../../controllers/logging/logger';

/**
 * @description Handles Running 
 */
export class CompilationRunner {

  private config : Config;

  constructor(config : Config) { 
    this.config = config;
  }

  /**
   * @description Compiles a Single Module
   * @param {Module} module - module to be compiled
   * @param {string} dirPath - directory the module is in
   * @param {boolean} debug - whether to compile in debug mode
   */
  public async buildModule(module : Module, dirPath : string, debug : boolean) : Promise<Status> {
    return new Promise(resolve=>{
      if (fileExists(dirPath)) {
        const command = `make module -B -C ${this.config.vipra.vipraDir} MODULEPATH=${dirPath}/${module.name} MODULEID=${module.id} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            Logger.error(`buildModule: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            Logger.debug(`buildModule: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            Logger.debug(`buildModule: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              Logger.error(`Build Module ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              Logger.info(`Module Build Successful: ${module.name}:${module.id}`);
              resolve(Status.SUCCESS);
            }
          });
        }
      } else {
        Logger.error(`Attempt to build Module that doesn't exist: ${module.name}:${module.id} ; Path: ${dirPath}`);
        resolve(Status.NOT_FOUND);
      }
    });
  }


  /**
   * @description Compiles the entirety of the Human Behavior Model
   *
   *
   * @async
   * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
   */
  public async compileHumanBehavior(debug : boolean) : Promise<Status> {
    return new Promise((resolve) => {
      try {
        const command : string = `make compile -B -C ${this.config.vipra.behaviorDir} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            Logger.error(`compileHumanBehavior: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            Logger.debug(`compileHumanBehavior: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            Logger.debug(`compileHumanBehavior: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              Logger.error(`Compile Human Behavior ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              Logger.info('Human Behavior Compiled Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          Logger.error('Compile Human Behavior Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        Logger.error(`Compile Human Behavior: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
      }
    });
  }

  /**
   * @description Compiles generate_main
   *
   * @async
   * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
   */
  public async compileGenMain(debug : boolean) : Promise<Status> {
    return new Promise((resolve) =>{
      try {
        Logger.info('Compiling Generate Main');
        const command : string = `make generate_main -B -C ${this.config.vipra.vipraDir} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            Logger.error(`compileGenMain: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            Logger.debug(`compileGenMain: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            Logger.debug(`compileGenMain: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              Logger.error(`Compile Generate Main ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              Logger.info('Generate Main Compiled Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          Logger.error('Compile Generate Main Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        Logger.error(`Compile Generate Main: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
      }
    });
  }

  /**
   * @description Calls generate_main then compiles the resulting main.cpp
   *
   *
   * @async
   * @param  {string} buildID - id for current build
   * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
   */
  public async compileMain(buildID : string, debug : boolean) : Promise<Status> {
    return new Promise((resolve) =>{
      try {
        Logger.info('Compiling Main');
        const command : string = `make compileMain -B -C ${this.config.vipra.vipraDir} BID=${buildID} MODULEFILE=${this.config.modules.modulesFilePath} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            Logger.error(`compileMain: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            Logger.debug(`compileMain: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            Logger.debug(`compileMain: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              Logger.error(`Compile Main ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              Logger.info('Main Compiled Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          Logger.error('Compile Main Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        Logger.error(`Compile Headers: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
      }
    });
  }

  /**
   * @description Compiles the simulation, resulting in the executable VIPRA
   *
   *
   * @param  {string} buildID - id for current build
   * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
   */
  public compileSim(buildID : string, debug : boolean) : Promise<Status> {
    return new Promise((resolve) =>{
      try {
        Logger.info('Compiling Simulation');
        const command : string = `make simulation -B -C ${this.config.vipra.vipraDir} BID=${buildID} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            Logger.error(`compileSim: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            Logger.debug(`compileSim: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            Logger.debug(`compileSim: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              resolve(Status.INTERNAL_ERROR);
            } else {
              Logger.info('Simulation Generated Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          Logger.error('Compile Simulation Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        Logger.error(`Compile Simulation: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
      }
    });
  }

}