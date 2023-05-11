import { Status } from '../../types/status';
import { PedMap } from '../../types/pedestrian/pedestrian.types';
import { OperationResult, Full } from '../../types/typeDefs';
import { UploadType } from '../../types/uploading.types';
import { BaseService } from '../base.service';


/**
 * @description Service for pedestrian maps
 */
export class PedestrianService extends BaseService<PedMap> {
  /**
   * @description Checks that a create upload has all of the necessary properties
   * @param {Partial<UploadType<PedMap>>} upload - uploaded object
   */
  checkUpload(upload: Partial<UploadType<PedMap>>): OperationResult<Full<UploadType<PedMap>>> {
    if (upload.object?.id && upload.object?.description && upload.object?.mapRef && upload.object?.name) {
      if (upload.files?.pedmap) {
        return { status: Status.SUCCESS, object: upload as Full<UploadType<PedMap>> };
      }
    }
    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @description Checks that an update upload doesn't have any restricted properties
   * @param {Partial<UploadType<PedMap>>} upload - Uploaded object
   */
  checkUpdate(upload: Partial<UploadType<PedMap>>): OperationResult<UploadType<PedMap>> {
    if (upload.object?.id || upload.object?.name) {
      return { status: Status.BAD_REQUEST, object: null };
    }

    return { status: Status.SUCCESS, object: upload as UploadType<PedMap> };
  }
}