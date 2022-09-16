/**
 * @module Controllers
 */

import crypto                   from 'crypto';

import { config }               from '../../configuration/config';
import { SimConfig, complete }  from '../../types/simconfig';
import { FuncResult, Nullable } from '../../types/typeDefs';
import { inject, injectable }   from 'tsyringe';
import { IFilesController }     from '../files/interfaces/FilesController.interface';
import { IModuleController }    from '../module/interfaces/ModuleController.interface';
import { IConfigManager }       from './interfaces/ConfigManager.interface';
import { IChainManager }        from '../chainbuilder/interfaces/ChainManager.interface';
import { Status }               from '../../types/Status';
import { Logger }               from '../../logging/Logging';
import { ModuleType }           from '../../types/module';


// TODO when creating a new sim config, create new service for ChainBuilder -RG

/**
 * @description Handles creation and tracking of simulation configurations
 */
@injectable()
export class ConfigManager implements IConfigManager {

  private configsMap : Map<string, SimConfig>;

  private moduleController : IModuleController;

  private fc : IFilesController;

  private cm : IChainManager;

  public constructor(@inject('ModuleController') moduleController : IModuleController, @inject('FilesController') fileController : IFilesController, @inject('ChainManager') chainManager : IChainManager) {
    this.configsMap = new Map();
    this.moduleController = moduleController;
    this.fc = fileController;
    this.cm = chainManager;
    this.loadConfigs(config.vipra.vipraDir);
  }
  
  /**
   * @description Returns the simulation config with the provided id, null if no config exists
   * @param  {string} id - id of config to get
   */
  getConfig(id: string): Nullable<SimConfig> {
    return this.configsMap.get(id) || null;
  }

  /**
   * @description Returns all of the current simulation configurations
   */
  public getConfigs(): SimConfig[] {
    const configs : SimConfig[] = [];
    for (const value of this.configsMap) {
      configs.push(value[1]);
    }
    return configs;
  }

  /**
   * @description Creates a new simulation configuration
   * @param  {SimConfig} simConfig - simulation config to create
   */
  public addConfig(simConfig: Partial<SimConfig>) : FuncResult {
    const configID = crypto.randomUUID();
    const simconf : Nullable<SimConfig> = complete(configID, simConfig);

    if (simconf) {
      
      const duplicate : Nullable<string> = this.checkDuplicate(simconf);
      if (duplicate) {
        return { status: Status.CONFLICT, message: duplicate };
      }

      const modulesCheck = this.checkModules(simconf.moduleIDs);
      if (modulesCheck.status !== Status.SUCCESS) {
        return modulesCheck;
      }

      this.configsMap.set(configID, simconf);
      this.saveConfig(simconf);
      
      const serviceCreated : FuncResult = this.cm.addService(simconf);
      if (serviceCreated.status !== Status.SUCCESS) {
        return serviceCreated;
      }

      return { status:Status.SUCCESS, message: configID };
    } else {
      return { status: Status.BAD_REQUEST, message: 'Simulation Config Missing Properties' };
    }
  }

  /**
   * @description Updates the config with id: configID, with the new simConfig
   * @param  {string} configID - id of simulation configuartion to update
   * @param  {SimConfig} simConfig - new values for the simulation configuration
   */
  public updateConfig(configID: string, simConfig: Partial<SimConfig>) : FuncResult {
    
    const simconf : Nullable<SimConfig> = this.configsMap.get(configID) || null;
    if (simconf) {
      const modulesCheck = this.checkModules(simconf.moduleIDs);
      if (modulesCheck.status !== Status.SUCCESS) {
        return { status: Status.NOT_FOUND, message: `Module Not Found: ${modulesCheck.message || 'null'}` };
      }

      if (simConfig.description) {
        simconf.description = simConfig.description;
      }
      if (simConfig.moduleIDs) {
        simconf.moduleIDs = simConfig.moduleIDs;
      }

      this.saveConfig(simconf);
      return { status: Status.SUCCESS, message: null };
    } else {
      return { status: Status.NOT_FOUND, message: null };
    }
  }

  
  /**
   * @description Removes a simulation configuration, making it unusable
   * @param  {string} configID - id of configuration to delete
   */
  public removeConfig(configID: string) : FuncResult {
    
    if (this.configsMap.has(configID)) {
      const dirpath = `${config.vipra.simsDir}/${configID}`;
      this.fc.deleteDir(dirpath, true);
      this.configsMap.delete(configID);
      return this.cm.removeService(configID);      
    } else {
      return { status: Status.NOT_FOUND, message: null };
    }
  }
  
  /**
   * @description Checks for configurations that have the same modules, returns the id of the duplicate config if one is found
   * @param  {SimConfig} simconfig - the config to check for duplicates of
   */
  private checkDuplicate(simconfig : SimConfig) : Nullable<string> {
    for (const [key, value] of this.configsMap) {
      if (Object.values(ModuleType).every((type)=>{
        return (value[type as unknown as keyof SimConfig] === simconfig[type as unknown as keyof SimConfig]);
      })) {
        return key;
      }
    }
    return null;
  }

  /**
   * @description Saves the provided config to disk
   * @param  {SimConfig} simconfig - config to save
   */
  private saveConfig(simconfig : SimConfig) : void {
    const dirPath = `${config.vipra.simsDir}/${simconfig.id}/`;
    const filepath = `${dirPath}/sim.config`;
    this.fc.makeDir(dirPath);
    this.fc.writeFile(filepath, JSON.stringify(simconfig));
  }

  /**
   * @description Saves all of the simulation configs to their respective places
   * @returns void
   */
  private saveAllConfigs() : void {
    for (const value of this.configsMap) {
      this.saveConfig(value[1]);
    }
  }

  /**
   * @description Loads all sim.config files under baseDirPath
   * @param  {string} baseDirPath - root directory to start looking for sim.config files
   */
  public loadConfigs(baseDirPath : string) : void {
    this.fc.forAllFilesThatMatchDo(/sim\.config/, baseDirPath, (filePath : string) => {
      const simconfig = this.fc.readJsonFile<SimConfig>(filePath, { error:false });
      if (simconfig) {
        if (simconfig) {
          Logger.info(`Found Simulation Configuration at: ${filePath}`);
          this.configsMap.set(simconfig.id, simconfig);
          const addService = this.cm.addService(simconfig);
          if (addService.status !== Status.SUCCESS) {
            Logger.error(`Unable To Create Service for SimConfig: ${simconfig.name} : ${simconfig.id}`);
            this.configsMap.delete(simconfig.id);
          }
        }
      }
    });
    Logger.info('Finished Loading Simulation Configurations');
  }

  /**
   * @description Checks that all modules are installed and correct
   * @param  {Record<ModuleType, string>} modules - modules to check for correctness
   */
  private checkModules(modules : Record<ModuleType, string>) : FuncResult {
    for (const id in modules) {
      const check = this.moduleController.checkModule(modules[id as ModuleType]);
      if (check.status !== Status.SUCCESS) {
        return { status: check.status, message: `Module ${check.status === Status.NOT_FOUND ? 'Not Found' : 'Failed Compilation'}: ${modules[id as ModuleType]}` };
      }
    }
    return { status: Status.SUCCESS, message: null };
  }
}