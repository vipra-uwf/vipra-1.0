import { Status } from '../../types/status';
import { Full, OperationResult } from '../../types/typeDefs';
import { RepoType, UploadType } from '../../types/uploading.types';
import { Files } from '../../util/filestore';
import { Behavior } from '../../types/behavior/behavior.types';
import { BaseLocalRepo } from '../base.local.repo';


/**
 * @description Local Repo for behaviors
 */
export class BehaviorRepo extends BaseLocalRepo<Behavior> {
  /**
   *
   */
  loadInstalledObjects(): Map<string, RepoType<Behavior>> {
    throw new Error('Method not implemented.');
  }

  /**
   *
   * @param data
   */
  onNew(data: Full<UploadType<Behavior>>): Promise<OperationResult<RepoType<Behavior>>> {
    throw new Error('Method not implemented.');
  }

  /**
   *
   * @param object
   * @param files
   */
  onUpdated(object: RepoType<Behavior>, files: Partial<Files>): Promise<Status> {
    throw new Error('Method not implemented.');
  }
  
  /**
   *
   */
  postCreate(): void {}

  /**
   *
   */
  postUpdate(): void {}
  
}