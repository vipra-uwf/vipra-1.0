import { isMapFull, OMap } from '../../types/maps/map.types';
import { Status } from '../../types/status';
import { Full, OperationResult } from '../../types/typeDefs';
import { UploadType } from '../../types/uploading.types';
import { BaseService } from '../base.service';


/**
 * @description Service for Maps
 */
export class MapService extends BaseService<OMap> {

  /**
   * @description Checks that an upload has all required properties/files
   * @param {Partial<UploadType<OMap>>} upload - uploaded object
   */
  checkUpload(upload: Partial<UploadType<OMap>>): OperationResult<Full<UploadType<OMap>>> {  
    if (upload.files) {
      if (upload.files.map) {
        if (upload.object) {
          if (isMapFull(upload.object)) {
            return { status: Status.SUCCESS, object: upload as Full<UploadType<OMap>> };
          }
        }
      }
    }

    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Checks that an update doesn't have any restricted properties/files
   * @param {Partial<UploadType<OMap>>} upload - uploaded object
   */
  checkUpdate(upload: Partial<UploadType<OMap>>): OperationResult<UploadType<OMap>> {
    if (upload.object?.id || upload.object?.name) {
      return { status: Status.BAD_REQUEST, object: null };
    }
    return { status: Status.SUCCESS, object: upload as UploadType<OMap> };
  }
}