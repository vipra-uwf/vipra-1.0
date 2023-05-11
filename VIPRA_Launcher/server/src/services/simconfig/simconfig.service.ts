import { SimConfig } from '../../types/simconfig/simconfig.types';
import { Status } from '../../types/status';
import { OperationResult, Full } from '../../types/typeDefs';
import { UploadType } from '../../types/uploading.types';
import { BaseService } from '../base.service';



/**
 * @description Service for SimConfigs
 */
export class SimConfigService extends BaseService<SimConfig> {
  /**
   * @note in this case the upload is already checked in the controller, so it is returned as full
   * @description Checks that an upload has all necessary properties
   * @param {Partial<UploadType<SimConfig>>} upload - uploaded object
   */
  checkUpload(upload: Partial<UploadType<SimConfig>>): OperationResult<Full<UploadType<SimConfig>>> {
    return { status: Status.SUCCESS, object: upload as Full<UploadType<SimConfig>> };
  }

  /**
   * @description Checks that an update doesn't have any restricted properties
   * @param {Partial<UploadType<SimConfig>>} upload - properties to update
   */
  checkUpdate(upload: Partial<UploadType<SimConfig>>): OperationResult<UploadType<SimConfig>> {
    
    if ( upload.object?.id || upload.object?.name ) {
      return { status: Status.BAD_REQUEST, object: null };
    }

    return { status: Status.SUCCESS, object: upload as UploadType<SimConfig> };
  }
  
}