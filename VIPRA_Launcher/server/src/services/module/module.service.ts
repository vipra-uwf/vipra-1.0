import { isModuleFull, Module } from '../../types/module/module.types';
import { Status } from '../../types/status';
import { OperationResult, Full } from '../../types/typeDefs';
import { UploadType } from '../../types/uploading.types';
import { readJsonBuffer } from '../../util/fileOperations';
import { BaseService } from '../base.service';

/**
 * @description Service for Modules
 */
export class ModuleService extends BaseService<Module> {

  /**
   * @description Checks that an upload is full
   * @param {Partial<UploadType<Module>>)} upload - uploaded object
   */
  checkUpload(upload: Partial<UploadType<Module>>): OperationResult<Full<UploadType<Module>>> {
    if (upload.files) {
      if (upload.files.source && upload.files.header && upload.files.meta) {
        const module = readJsonBuffer<Module>(upload.files?.meta[0]?.buffer);
        if (module) {
          module.compiled = false;
          if (isModuleFull(module)) {
            upload.object = module;
            return { status: Status.SUCCESS, object: upload as Full<UploadType<Module>> };
          }
        }
      }
    }

    return { status: Status.BAD_REQUEST, object: null };
  }
  
  /**
   * @description Checks that an update request doesn't have any restricted properties
   * @param {Partial<UploadType<Module>>} upload - uploaded object
   */
  checkUpdate(upload: Partial<UploadType<Module>>): OperationResult<UploadType<Module>> {
    if (upload.object?.id || upload.object?.name || upload.object?.compiled || upload.object?.type) {
      return { status: Status.BAD_REQUEST, object: null };
    }
    return { status: Status.SUCCESS, object: upload as UploadType<Module> };
  }

}


// import { BaseService } from '../base.service';

// import { isFullModule, Module, ModuleUpload } from '../../types/module/module.types';
// import { Status } from '../../types/status';
// import { Full, Nullable, OperationResult } from '../../types/typeDefs';
// import { BaseRepo } from '../../repos/base.repo';
// import { readJsonBuffer } from '../../util/fileOperations';


// /**
//  * @description Module Service
//  */
// export class ModuleService implements BaseService<ModuleUpload, Module> {
  

//   private repo : BaseRepo<ModuleUpload, Module>;

//   constructor(repo? : BaseRepo<ModuleUpload, Module>) {
//     if (repo) {
//       this.repo = repo;
//     } else { 
//       throw new Error('Attempt to Create Module Service without a Repo');
//     }
//   }
  
//   /**
//    * @description Returns all modules installed
//    */
//   public async getAll(): Promise<Module[]> {
//     return this.repo.getAll();
//   }

//   /**
//    * @description Returns the module with properties that match select, null if not found
//    * @param {Partial<Module>} select - Partial Module with properties to match
//    */
//   async get(select : Partial<Module>): Promise<Nullable<Module>> {
//     return this.repo.get(select);
//   }

//   /**
//    * @description Creates a new module on the service's repository
//    * @param {Partial<Module>}module - module to create
//    */
//   async create(module: Partial<ModuleUpload>): Promise<OperationResult<Module>> {
//     const completeModule : Nullable<Full<ModuleUpload>> = this.completeModule(module);
//     if (completeModule) {
//       return this.repo.create(completeModule);
//     }
//     return { status: Status.BAD_REQUEST, object: null };
//   }

//   /**
//    * @description Updates an existing module with the provided data
//    * @param {string} id - id of module to update
//    * @param {Partial<Module>} module - data to update
//    */
//   async update(id: string, module: Partial<ModuleUpload>): Promise<OperationResult<Module>> {
//     if (module.module || module.files) {
//       if (this.checkModuleUpdate(module)) {
//         return this.repo.update(id, module);
//       }
//     }
//     return { status: Status.BAD_REQUEST, object: null };
//   }

//   /**
//    * @description Deletes a module from the repo
//    * @param {string} id - id of module to delete
//    */
//   public async delete(id: string): Promise<OperationResult<Module>> {
//     return this.repo.delete(id);
//   }

//   /**
//    * @description Checks that a module is complete, returning it as a module if it is, null if not
//    * @param {Partial<ModuleUpload>} upload - module to check
//    */
//   private completeModule(upload : Partial<ModuleUpload>) : Nullable<Full<ModuleUpload>> {
//     if (
//       upload.files?.headerFile &&
//       upload.files?.srcFile &&
//       upload.files?.metaFile
//     ) {
//       const module = readJsonBuffer<Partial<Module>>(upload.files?.metaFile.buffer);
//       if (module) {
//         upload.module = {
//           id: module.id,
//           name: module.name,
//           description: module.description,
//           type: module.type,
//           params: module.params,
//           compiled: false,
//         };
//         if (isFullModule(upload.module)) {
//           return upload as Full<ModuleUpload>;
//         }
//       }
//     }

//     return null;
//   }

//   /**
//    * @description Checks that a Partial<Module> for an update request is correct
//    * @param {Partial<Module>} module - update data to check
//    */
//   private checkModuleUpdate(module : Partial<ModuleUpload>) : boolean {
//     if (module.module?.id || module.module?.name || module.module?.type) {
//       return false;
//     }

//     if (module.module?.description || module.module?.params || module.files?.srcFile || module.files?.headerFile || module.files?.metaFile) {
//       return true;
//     }

//     return false;
//   }
// }