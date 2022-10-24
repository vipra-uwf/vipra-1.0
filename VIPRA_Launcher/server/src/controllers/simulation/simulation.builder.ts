
import crypto from 'crypto';

import { CompilationRunner } from '../../runners/compilation/compilation.runner';
import { Config } from '../../configuration/config';
import { EventSystem } from '../events/eventSystem';
import { EventHandler, EventType, RequestType } from '../events/eventTypes';
import { Module, ModuleType } from '../../types/module/module.types';
import { Status } from '../../types/status';
import { SimState } from '../../types/simulation/simulation.types';
import { Nullable } from 'typechain/dist/typedefs';


/**
 * @description Handles building the simulation
 */
export class SimulationBuilder {

  private isBuilt : { genMain: boolean; humanBehavior : boolean; };

  private simState : SimState;

  private evSys : EventSystem;

  private config : Config;

  private buildMap : Map<string, SimState>;

  private compilationRunner : CompilationRunner;

  private moduleTypes : Record<ModuleType, number>;

  constructor(config : Config, evSys : EventSystem) {
    this.evSys = evSys;
    this.config = config;
    this.buildMap = new Map();
    this.compilationRunner = new CompilationRunner(config);
    this.setupHandlers();
  }

  /**
   * @description Request handler for the current simulation state
   */
  public getSimState = () : SimState[] => {
    return [this.simState];
  };

  /**
   * @description Request handler for build status
   * @param {{id? : string}} select - select object for builds
   * @param {string} select.id - id of build
   */
  public getBuildStatus = (select : { id? : string }) : Nullable<SimState[]> => {
    if (select.id) {
      const build = this.buildMap.get(select.id);
      if (build) {
        return [build];
      }
    }
    return null;
  };

  /**
   * @description Sets up the event handlers for Simulation Building
   */
  private setupHandlers() : void {
    this.evSys.subscribe(EventType.NEW, 'Module', this.compileModule);
    this.evSys.setRequestHandler(RequestType.SIM_BUILD, this.getBuildStatus);
    this.evSys.setRequestHandler(RequestType.SIM_STATE, this.getSimState);
  }

  /**
   * @description Runs initial build of simulation, sets up sim state
   */
  public startup() : void {
    this.setSimState({ ready : false, reason: 'Initial Startup Running' });
    this.isBuilt = { genMain: false, humanBehavior: false };
    this.compileSimulation();
  }

  /**
   * @description Compiles a provided module
   * @param {Module} module - module to compile
   * @param {ModuleController} source - source of module
   */
  private compileModule : EventHandler = async (module : Module) : Promise<void> => {
    
    const compiled = await this.compilationRunner.buildModule(module, false);

    if (compiled === Status.SUCCESS) {
      void this.evSys.emit<Module>(EventType.SUCCESS, 'Module', module);
      this.compileSimulation();
    } else {
      void this.evSys.emit<Module>(EventType.FAIL, 'Module', module);
    }
  };

  /**
   * @description Compiles the Simulation
   * @emits NEW_SIMULATION_BUILD
   */
  private compileSimulation = () : string => {

    const buildID = crypto.randomUUID();
    this.setBuildState(buildID, { ready: false, reason: 'Build Starting' });
    void this.evSys.emit<string>(EventType.NEW, 'Build', buildID);
    
    void Promise.all([this.compileGenMain(buildID), this.compileBehavior(buildID)])
      .then((result)=>{
        if (result.every((val)=> {return val === Status.SUCCESS;})) {
          void this.compileAllModules()
            .then(()=>{
              if (this.reqsMet()) {
                void this.compileMain(buildID)
                  .then((mainReady)=>{
                    if (mainReady) {
                      void this.compileSim(buildID);
                    }
                  });
              }
            });
        }
      })
      .catch(()=>{
        this.buildFailed(buildID, 'Unknown Error');
      });

    return buildID;
  };

  /**
   * @description Compiles Main
   * @emits FAIL_SIMULATION_BUILD
   * @param {string} buildID - id of current build
   */
  private compileMain(buildID : string) : Promise<Status> {
    return this.compilationRunner.compileMain(buildID, this.config.simulation.debugMode)
      .then((result)=>{
        if (result !== Status.SUCCESS) {
          this.buildFailed(buildID, 'Unable To Compile Main');
        }
        return result;
      })
      .catch(()=>{
        this.buildFailed(buildID, 'Unable To Compile Main');
        return Status.INTERNAL_ERROR;
      });
  }

  /**
   * @description Compiles The full simulation executable
   * @emits SUCCESS_SIMULATION_BUILD, FAIL_SIMULATION_BUILD
   * @param {string} buildID - id of current build
   */
  private compileSim(buildID : string) : Promise<Status> {
    return this.compilationRunner.compileSim(buildID, this.config.simulation.debugMode)
      .then((result)=>{
        if (result === Status.SUCCESS) {
          this.buildSuccess(buildID);
        } else {
          this.buildFailed(buildID, 'Unable To Compile Simulation');
        }
        return result;
      })
      .catch(()=>{
        this.buildFailed(buildID, 'Unable To Compile Simulation');
        return Status.INTERNAL_ERROR;
      });
  }

  /**
   * @description Compiles generate_main, if it hasn't already been compiled
   * @emits FAIL_SIMULATION_BUILD
   * @param {string} buildID - id of current build
   */
  private compileGenMain(buildID : string) : Promise<Status> {
    let genMain : Promise<Status> = new Promise(resolve=>resolve(Status.SUCCESS));
    if (!this.isBuilt.genMain) {
      genMain = this.compilationRunner.compileGenMain(this.config.simulation.debugMode)
        .then((result)=>{
          if (result === Status.SUCCESS) {
            this.isBuilt.genMain = true;
          } else {
            this.isBuilt.genMain = false;
            this.buildFailed(buildID, 'Unable To Compile Generate Main');
          }
          return result;
        })
        .catch(()=>{
          this.buildFailed(buildID, 'Unable To Compile Generate Main');
          return Status.INTERNAL_ERROR;
        });
    }
    return genMain;
  }

  /**
   * @description Compiles the Human Behavior Module, if it hasn't already been compiled
   * @emits FAIL_SIMULATION_BUILD
   * @param {string} buildID - id of current build
   */
  private compileBehavior(buildID : string) : Promise<Status> {
    let genBehavior : Promise<Status> = new Promise(resolve=>resolve(Status.SUCCESS));
    if (!this.isBuilt.humanBehavior) {
      genBehavior  = this.compilationRunner.compileHumanBehavior(this.config.simulation.debugMode)
        .then((result)=>{
          if (result === Status.SUCCESS) {
            this.isBuilt.humanBehavior = true;
          } else {
            this.isBuilt.humanBehavior = false;
            this.buildFailed(buildID, 'Unable To Compile Human Behavior');
          }
          return result;
        })
        .catch(()=>{
          this.buildFailed(buildID, 'Unable To Compile Human Behavior');
          return Status.INTERNAL_ERROR;
        });
    }
    return genBehavior;
  }

  /**
   * @description Builds all installed modules
   * @emits BUILT_MODULE, FAIL_MODULE
   */
  private async compileAllModules() : Promise<void> {
    const modules : Nullable<Module[]> = await this.evSys.request(RequestType.MODULE, {});    

    if (modules) {
      let builds : Promise<Status>[] = [];
      let curr = 0;
      for (const module of modules) {
        if (curr >= this.config.simulation.maxConcurComps) {
          await Promise.all(builds);
          curr = 0;
          builds = [];
        }
        builds.push(
          this.compilationRunner.buildModule(module, this.config.simulation.debugMode)
            .then((result)=>{
              if (result === Status.SUCCESS) {
                this.addedModuleType(module.type);
                void this.evSys.emit<Module>(EventType.SUCCESS, 'Module', module);
              } else {
                void this.evSys.emit<Module>(EventType.FAIL, 'Module', module);
              }
              return result;
            }),
        );
        curr++;
      }
    }
  }

  /**
   * @description Sets build state / sim state, emits the SUCCESS_SIMULATION_BUILD event
   * @emits SUCCESS_SIMULATION_BUILD
   * @param {string} buildID -id of build that completed
   */
  private buildSuccess(buildID : string) : void {
    this.setBuildState(buildID, { ready:true, reason:'Successful Build' });
    this.setSimState({ ready: true, reason: 'Successful Build' });
    void this.evSys.emit<string>(EventType.SUCCESS, 'Build', buildID);
  }

  /**
   * @description Sets the build state, and emits a FAIL_SIMULATION_BUILD event
   * @emits FAIL_SIMULATION_BUILD
   * @param {string} buildID - id of build that failed
   * @param {string} reason - reason for failure
   */
  private buildFailed(buildID : string, reason : string) : void {
    this.setBuildState(buildID, { ready: false, reason });
    void this.evSys.emit<string>(EventType.FAIL, 'Build', buildID);
  }

  /**
   * @description Checks that the simulation requirements have been met to build
   */
  private reqsMet() : boolean {
    for (const key of Object.keys(this.moduleTypes)) {
      if (this.moduleTypes[key as ModuleType] < 1) {
        return false;
      }
    }
    if (!this.isBuilt.genMain || !this.isBuilt.humanBehavior) {
      return false;
    }
    return true;
  }

  /**
   * @description Increments count of module type, to keep track of whether the simulation has all necessary types
   * @param {ModuleType} type - module type removed
   */
  private addedModuleType(type : ModuleType) : void {
    this.moduleTypes[type]++;
  }

  /**
   * @description Decrements count of module type, to keep track of whether the simulation has all necessary types
   * @param {ModuleType} type - module type removed
   */
  private removedModuleType(type : ModuleType) : void {
    this.moduleTypes[type]--;
  }

  /**
   * @description Sets the state of the current simulation
   * @param {SimState} state - state to set simulation as
   */
  private setSimState(state : SimState) : void {
    this.simState = state;
  }

  /**
   * @description Sets the State of a build
   * @param {string} buildID - id of build
   * @param {SimState} state - state to set build
   */
  private setBuildState(buildID : string, state : SimState) : void {
    this.buildMap.set(buildID, state);
  }
}