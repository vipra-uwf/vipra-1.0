/**
 * @module Controllers
 */
import  child_process  from 'child_process';
import { Status } from '../../types/Status';
import { Module } from '../../types/module';
import { IFilesController } from '../files/interfaces/FilesController.interface';
import { inject, singleton } from 'tsyringe';
import { Logger } from '../../logging/Logging';
import { config } from '../../configuration/config';
import { IProcessRunner } from './interfaces/ProcessRunner.interface';

/**
 * @description Handles starting and maintaining external processes
 */
@singleton()
export class ProcessRunner implements IProcessRunner {

  private fc : IFilesController;

  constructor(@inject('FilesController') filesController : IFilesController) {
    this.fc = filesController;
  }

  /**
   * @description Creates Precompiled headers for faster build times
   * @returns Promise
   */
  public async precompileHeaders(): Promise<Status> {
    return new Promise((resolve)=>{
      try {
        this.fc.makeDir(`${config.vipra.vipraDir}/build`);
        const command : string = `make -C ${config.vipra.simsDir} precompileHeaders`;
        const ps = child_process.exec(command, (error : child_process.ExecException) => {
          if (error) {
            Logger.error(`precompileHeaders: ${error.message}`);
            resolve(Status.INTERNAL_ERROR);
          }
        });
        if (ps && ps.stderr && ps.stdout) {
          ps.stderr.on('data', (data : string) => {
            Logger.debug(`precompileHeaders: ${data}`);
          });
          ps.stdout.on('data', (data : string) => {
            Logger.debug(`precompileHeaders: ${data}`);
          });
          ps.on('close', (code : number) => {
            if (code !== 0) {
              Logger.error(`Precompile Headers ended with code: ${code}`);
              resolve(Status.INTERNAL_ERROR);
            } else {
              Logger.info('Headers Compiled Successful');
              resolve(Status.SUCCESS);
            }
          });
        } else {
          Logger.error('Precompile Headers Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        Logger.error(`Compile Headers: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
      }
    });
  }

  /**
   * @description Builds the object file for the provided module
   *
   *
   * @async
   * @param  {Module} module - the module to be compiled
   * @param  {boolean} debug - if true: defines DEBUG_OUTPUT and compiles with -g -O0
   */
  public async buildModule(module : Module, debug : boolean) : Promise<Status> {
    return new Promise((resolve)=>{
      try {
        if (!this.fc.fileExists(`${module.includePath}`)) {
          Logger.error(`Attempt to build module that doesn't exist: ${module.name}:${module.id}, path: ${module.dirPath}`);
          resolve(Status.NOT_FOUND);
        }
        this.fc.makeDir(`${config.vipra.vipraDir}/build`);
        const command : string = `make module -C ${config.vipra.simsDir} MODULEPATH=${module.dirPath}/${module.name} MODULEID=${module.id} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
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
        } else {
          Logger.error('Build Module Process is null');
          resolve(Status.INTERNAL_ERROR);
        }
      } catch (e : unknown) {
        Logger.error(`Build Module: Caught: ${e as string}`);
        resolve(Status.INTERNAL_ERROR);
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
        const command : string = `make compile -C ${config.vipra.behaviorDir} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
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
        const command : string = `make generate_main -C ${config.vipra.simsDir} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
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
        const command : string = `make compileMain -C ${config.vipra.simsDir} BID=${buildID} MODULEFILE=${config.module.modulesFile} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
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
        const command : string = `make simulation -C ${config.vipra.simsDir} BID=${buildID} ${debug ? 'DEBUG_OUTPUT=1' : ''}`;
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