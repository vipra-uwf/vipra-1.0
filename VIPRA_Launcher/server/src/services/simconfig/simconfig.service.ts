import { BaseRepo } from '../../repos/base.repo';
import { Nullable, OperationResult, Full } from '../../types/typeDefs';
import { SimConfig, SimConfigUpload } from '../../types/simconfig/simconfig.types';
import { BaseService } from '../base.service';
import { Status } from '../../types/status';
import { ModuleType } from '../../types/module/module.types';


/**
 * @description Service for SimConfigs
 */
export class SimConfigService implements BaseService<SimConfigUpload, SimConfig> {

  private repo : BaseRepo<SimConfigUpload, SimConfig>;

  constructor(repo : BaseRepo<SimConfigUpload, SimConfig>) {
    this.repo = repo;
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
    
    const simconfig : Nullable<Full<SimConfigUpload>> = this.completeConfig(object);

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
  private completeConfig(simconfig : Partial<SimConfigUpload>) : Nullable<Full<SimConfigUpload>> {
    if (simconfig.id && simconfig.description && simconfig.modules && simconfig.name) {
      if (simconfig.modules) {
        for (const type of Object.values(ModuleType)) {
          if (!simconfig.modules[type as keyof Record<ModuleType, string>]) {
            return null;
          }
        }
        return simconfig as Full<SimConfigUpload>;
      }
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
}