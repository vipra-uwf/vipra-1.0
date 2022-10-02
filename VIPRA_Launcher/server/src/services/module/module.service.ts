import { BaseService } from '../base.service';

import { Module, ModuleUpload } from '../../types/module/module.types';
import { Status } from '../../types/status';
import { Full, Nullable, OperationResult } from 'src/types/typeDefs';
import { BaseRepo } from 'src/repos/base.repo';


/**
 * @description Module Service
 */
export class ModuleService implements BaseService<ModuleUpload, Module> {
  

  private repo : BaseRepo<ModuleUpload, Module>;

  constructor(repo : BaseRepo<ModuleUpload, Module>) {
    this.repo = repo;
  }
  
  /**
   * @description Returns all modules installed
   */
  getAll(): Promise<Module[]> {
    return this.repo.getAll();
  }

  /**
   * @description Returns the module with id, null if not found
   * @param {string} id - id of module to get
   */
  async get(id: string): Promise<Nullable<Module>> {
    return this.repo.get(id);
  }

  /**
   * @description Creates a new module on the service's repository
   * @param {Partial<Module>}module - module to create
   */
  async create(module: Partial<ModuleUpload>): Promise<OperationResult<Module>> {
    const completeModule : Nullable<Full<ModuleUpload>> = this.completeModule(module);
    if (completeModule) {
      return this.repo.create(completeModule);
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Updates an existing module with the provided data
   * @param {string} id - id of module to update
   * @param {Partial<Module>} module - data to update
   */
  async update(id: string, module: Partial<ModuleUpload>): Promise<OperationResult<Module>> {
    if (module.module) {
      if (this.checkModuleUpdate(module.module)) {
        return this.repo.update(id, module);
      }
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Deletes a module from the repo
   * @param {string} id - id of module to delete
   */
  public async delete(id: string): Promise<OperationResult<Module>> {
    return this.repo.delete(id);
  }

  /**
   * @description Stages a Module on the local file system
   * @param {string} id - id of module to stage
   */
  public async stage(id: string): Promise<OperationResult<string>> {
    return this.repo.stage(id);
  }

  /**
   * @description Checks that a module is complete, returning it as a module if it is, null if not
   * @param {Partial<ModuleUpload>} upload - module to check
   */
  private completeModule(upload : Partial<ModuleUpload>) : Nullable<Full<ModuleUpload>> {
    if (
      upload.module?.description &&
      upload.module?.name &&
      upload.module?.params &&
      upload.module?.type &&
      upload.files?.headerFile &&
      upload.files?.srcFile &&
      upload.files?.metaFile
    ) {
      return upload as Full<ModuleUpload>;
    }

    return null;
  }

  /**
   * @description Checks that a Partial<Module> for an update request is correct
   * @param {Partial<Module>} module - update data to check
   */
  private checkModuleUpdate(module : Partial<Module>) : boolean {
    if (module.id || module.name || module.type) {
      return false;
    }

    if (!module.description && !module.params) {
      return false;
    }

    return true;
  }
}