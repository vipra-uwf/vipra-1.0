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
    if (upload.object?.id || upload.object?.name || upload.object?.type) {
      return { status: Status.BAD_REQUEST, object: null };
    }
    return { status: Status.SUCCESS, object: upload as UploadType<Module> };
  }

}