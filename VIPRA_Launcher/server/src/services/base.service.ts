

import { Identifiable, UploadType } from '../types/uploading.types';
import { BaseLocalRepo } from '../repos/base.local.repo';
import { Status } from '../types/status';
import { Full, Nullable, OperationResult } from '../types/typeDefs';
import { Config } from '../configuration/config';


/**
 * @description Base Service Class
 */
export abstract class BaseService<DataType extends Identifiable> {

  abstract checkUpload(upload : Partial<UploadType<DataType>>) : OperationResult<Full<UploadType<DataType>>>;
  abstract checkUpdate(upload : Partial<UploadType<DataType>>) : OperationResult<UploadType<DataType>>;

  protected config : Config;

  private repo : BaseLocalRepo<DataType>;

  constructor(config : Config, repo : BaseLocalRepo<DataType>) {
    this.config = config;
    this.repo = repo;
  }

  /**
   * @description Returns an array of all installed Objects of type DataType
   */
  getAll() : DataType[] {
    return this.repo.getAll();
  }
  
  /**
   * @description Returns the object that matches select
   * @param {Partial<DataType>} select - properties to match
   */
  get(select : Partial<DataType>) : Promise<Nullable<DataType[]>> {
    return Promise.resolve(this.repo.get(select));
  }

  /**
   * @uses checkUpload
   * @description Creates a new object on the Repo
   * @param {Partial<UploadType<DataType>>} object - Uploaded Object to create
   */
  create(object : Partial<UploadType<DataType>>) : Promise<OperationResult<DataType>> {
    const upload : OperationResult<Full<UploadType<DataType>>> = this.checkUpload(object);
    if (upload.status === Status.SUCCESS) {
      if (upload.object) {
        return this.repo.create(upload.object);
      }
    }
    return Promise.resolve({ status: Status.BAD_REQUEST, object: null });
  }
  
  /**
   * @uses checkUpdate
   * @description Updates the object with id, with the provided properties
   * @param {string} id - id of object to update
   * @param {Partial<UploadType<DataType>>} object - properties to update
   */
  update(id : string, object : Partial<UploadType<DataType>>) : Promise<OperationResult<DataType>> {
    const upload = this.checkUpdate(object);
    if (upload.status === Status.SUCCESS) {
      if (upload.object) {
        return this.repo.update(id, upload.object);
      }
    }
    return Promise.resolve({ status: Status.BAD_REQUEST, object: null });
  }
  
  /**
   * @description Deletes the objects that match the provided properties
   * @param {Partial<DataType>} select - properties to match
   */
  delete(select : Partial<DataType>) : Promise<OperationResult<DataType[]>> {
    return this.repo.delete(select);
  }
}
