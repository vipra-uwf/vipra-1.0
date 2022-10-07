
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

  private logger : Logger;

  constructor(config : Config, logger : Logger) {
    this.config = config;
    this.logger = logger;
  }

  /**
   * @description Compiles a Single Module
   * @param {Module} module - module to be compiled
   * @param {boolean} debug - whether to compile in debug mode
   */
  public async buildModule(module : Module, debug : boolean) : Promise<Status> {
    return new Promise(resolve=>{
      const moduleDirPath : string = `${this.config.modules.modulesURL}/${module.type}/${module.name}`;
      if (fileExists(moduleDirPath)) {

        const command = `make module -C ${this.config.vipra.vipraDir} MODULEPATH=${moduleDirPath} MODULEID=${module.id} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            this.logger.error(`buildModule: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            this.logger.debug(`buildModule: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            this.logger.debug(`buildModule: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              this.logger.error(`Build Module ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              this.logger.info(`Module Build Successful: ${module.name}:${module.id}`);
              resolve(Status.SUCCESS);
            }
          });
        } else {
          this.logger.error(`Attempt tob build Module that doesn't exist: ${module.name}:${module.id} ; Path: ${moduleDirPath}`);
          resolve(Status.NOT_FOUND);
        }
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
        const command : string = `make compile -C ${this.config.vipra.behaviorDir} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            this.logger.error(`compileHumanBehavior: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            this.logger.debug(`compileHumanBehavior: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            this.logger.debug(`compileHumanBehavior: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              this.logger.error(`Compile Human Behavior ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              this.logger.info('Human Behavior Compiled Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          this.logger.error('Compile Human Behavior Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        this.logger.error(`Compile Human Behavior: Caught: ${e as string}`);
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
        this.logger.info('Compiling Generate Main');
        const command : string = `make generate_main -C ${this.config.vipra.vipraDir} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            this.logger.error(`compileGenMain: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            this.logger.debug(`compileGenMain: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            this.logger.debug(`compileGenMain: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              this.logger.error(`Compile Generate Main ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              this.logger.info('Generate Main Compiled Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          this.logger.error('Compile Generate Main Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        this.logger.error(`Compile Generate Main: Caught: ${e as string}`);
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
        this.logger.info('Compiling Main');
        const command : string = `make compileMain -C ${this.config.vipra.vipraDir} BID=${buildID} MODULEFILE=${this.config.modules.modulesFilePath} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            this.logger.error(`compileMain: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            this.logger.debug(`compileMain: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            this.logger.debug(`compileMain: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              this.logger.error(`Compile Main ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              this.logger.info('Main Compiled Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          this.logger.error('Compile Main Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        this.logger.error(`Compile Headers: Caught: ${e as string}`);
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
        this.logger.info('Compiling Simulation');
        const command : string = `make simulation -C ${this.config.vipra.vipraDir} BID=${buildID} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            this.logger.error(`compileSim: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            this.logger.debug(`compileSim: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            this.logger.debug(`compileSim: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              resolve(Status.INTERNAL_ERROR);
            } else {
              this.logger.info('Simulation Generated Successfully');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          this.logger.error('Compile Simulation Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        this.logger.error(`Compile Simulation: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
      }
    });
  }

}