import { BaseRepo } from '../../repos/base.repo';
import { Nullable, OperationResult, Full } from '../../types/typeDefs';
import { SimConfig, SimConfigUpload } from '../../types/simconfig/simconfig.types';
import { BaseService } from '../base.service';
import { Status } from '../../types/status';
import { Module, ModuleType } from '../../types/module/module.types';
import { EventSystem } from '../../controllers/events/eventSystem';
import { RequestType } from '../../controllers/events/eventTypes';


/**
 * @description Service for SimConfigs
 */
export class SimConfigService implements BaseService<SimConfigUpload, SimConfig> {

  private repo : BaseRepo<SimConfigUpload, SimConfig>;

  private evSys : EventSystem;

  constructor(evSys : EventSystem, repo : BaseRepo<SimConfigUpload, SimConfig>) {
    this.repo = repo;
    this.evSys = evSys;
  }

  /**
   * @description Returns all Simconfigs in an array
   */
  public async getAll(): Promise<SimConfig[]> {
    return this.repo.getAll();
  }

  /**
   * @description Returns the simconfig with id
   * @param {string} id - id of simconfig to get
   */
  public async get(id: string): Promise<Nullable<SimConfig>> {
    return this.repo.get(id);
  }

  /**
   * @description Creates a new simconfig
   * @param {Partial<SimConfigUpload>} object - Simconfig to create
   */
  public async create(object: Partial<SimConfigUpload>): Promise<OperationResult<SimConfig>> {
    
    const simconfig : Nullable<Full<SimConfig>> = await this.completeConfig(object);

    if (simconfig) {
      return this.repo.create(simconfig);
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Updates the simconfig with id
   * @param {string} id - id of simconfig to update
   * @param {Partial<SimConfigUpload>} object - properties to update
   */
  public async update(id: string, object: Partial<SimConfigUpload>): Promise<OperationResult<SimConfig>> {
    if (this.checkSimConfigUpdate(object)) {
      return this.repo.update(id, object);
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Deletes the simconfig with id
   * @param {string} id - id of simconfig to delete
   */
  public async delete(id: string): Promise<OperationResult<SimConfig>> {
    return this.repo.delete(id);
  }
  
  /**
   * @description may not be needed?
   * @param {string} id - id of simconfig to stage
   */
  public async stage(id: string): Promise<OperationResult<string>> {
    return this.repo.stage(id);
  }

  /**
   * @description Makes sure the a simconfig upload is complete
   * @param {Partial<SimConfigUpload>} simconfig - simconfig to check
   */
  private async completeConfig(simconfig : Partial<SimConfigUpload>) : Promise<Nullable<Full<SimConfig>>> {
    if (simconfig.id && simconfig.description && simconfig.modules && simconfig.name) {
      for (const type of Object.values(ModuleType)) {
        const moduleID = simconfig.modules[type as keyof Record<ModuleType, string>];
        if (moduleID) {
          if (! await this.checkModule(moduleID, type)) {
            return null;
          }
        } else {
          return null;
        }
      }
      return simconfig as Full<SimConfigUpload>;
    }
    return null;
  }

  /**
   * @description Checks that a simconfig is proper
   * @param {Partial<SimConfigUpload>} simconfig - simconfig to check
   */
  private checkSimConfigUpdate(simconfig : Partial<SimConfigUpload>) : boolean {
    if (simconfig.id || simconfig.name) {
      return false;
    }
    if (simconfig.description || simconfig.modules) {
      return true;
    }
    return false;
  }

  /**
   * @description Checks that a module exists and is the expected type
   * @param {string} moduleID - id of module to check
   * @param {ModuleType} type - type module should be
   */
  private async checkModule(moduleID : string, type : ModuleType) : Promise<boolean> {
    const module = await this.evSys.request<Module>(RequestType.MODULE, { id: moduleID, type });
    if (module) {
      if (module.type !== type) {
        return false;
      }
    } else {
      return false;
    }
    return true;
  }
}