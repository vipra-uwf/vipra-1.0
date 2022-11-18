import { Status } from 'src/types/status';
import { OperationResult, Full } from 'src/types/typeDefs';
import { UploadType } from 'src/types/uploading.types';
import { Behavior } from '../../types/behavior/behavior.types';
import { BaseService } from '../base.service';


/**
 * @description Service 
 */
export class BehaviorController extends BaseService<Behavior> {
  
  
  /**
   * @description Checks that an upload has all of the required properties
   * @param {Partial<UploadType<Behavior>>} upload - uploaded object
   */
  checkUpload(upload: Partial<UploadType<Behavior>>): OperationResult<Full<UploadType<Behavior>>> {
    if (upload.object && upload.files) {
      if (upload.object.description && upload.object.id && upload.object.name && upload.files.behavior) {
        return { status: Status.SUCCESS, object: upload as Full<UploadType<Behavior>> };
      }
    }
    return { status: Status.BAD_REQUEST, object: null };
  }
  
  /**
   * @description Checks that an update doesn't have any restricted properties
   * @param {Partial<UploadType<Behavior>>} upload - uploaded object
   */
  checkUpdate(upload: Partial<UploadType<Behavior>>): OperationResult<UploadType<Behavior>> {
    if (upload.object) {
      if (upload.object.id) {
        return { status: Status.BAD_REQUEST, object: null };
      }
    }

    return { status: Status.SUCCESS, object: upload as UploadType<Behavior> };
  }
}