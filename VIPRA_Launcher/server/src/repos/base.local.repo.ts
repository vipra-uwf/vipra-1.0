
import { Identifiable, RepoType, UploadType } from '../types/uploading.types';
import { Full, Nullable, OperationResult } from '../types/typeDefs';
import { Status } from '../types/status';
import { deleteDir } from '../util/fileOperations';
import { Files } from '../util/filestore';
import { Config } from '../configuration/config';



/**
 * @description Base Repo for objects that are saved in the local filesystem
 */
export abstract class BaseLocalRepo<DataType extends Identifiable> {

  abstract loadInstalledObjects() : Map<string, RepoType<DataType>>;
  abstract onNew(data : Full<UploadType<DataType>>) : Promise<OperationResult<RepoType<DataType>>>;
  abstract onUpdated(object : RepoType<DataType>, files : Partial<Files>) : Promise<Status>;
  abstract postCreate() : void;
  abstract postUpdate() : void;

  protected config : Config;

  protected objects : Map<string, RepoType<DataType>>;

  constructor(config : Config) {
    this.config = config;
    this.objects = this.loadInstalledObjects();
  }

  /**
   * @description Returns all installed objects as an array
   */
  getAll() : DataType[] {
    const ret : DataType[] = [];
    for (const value of this.objects) {
      ret.push(value[1].object);
    }
    return ret;
  }

  /**
   * @description Returns all objects whose properties match the provided select
   * @param {Partial<DataType>} select - properties to match
   */
  get(select : Partial<DataType>) : DataType[] {
    const ret : DataType[] = [];
    for (const value of this.objects) {
      if (Object.keys(select).every((key)=>{
        return select[key as keyof Partial<DataType>] === value[1].object[key as keyof DataType];
      })) {
        ret.push(value[1].object);
      }
    }
    return ret;
  }

  /**
   * @description Returns all objects whose properties match the provided select
   * @param {Partial<DataType>} select - properties to match
   */
  getRepo(select : Partial<DataType>) : RepoType<DataType>[] {
    const ret : RepoType<DataType>[] = [];
    for (const value of this.objects) {
      if (Object.keys(select).every((key)=>{
        return select[key as keyof Partial<DataType>] === value[1].object[key as keyof DataType];
      })) {
        ret.push(value[1]);
      }
    }
    return ret;
  }

  /**
   * @uses saveFiles
   * @description Creates a new object on the repo
   * @param {Full<UploadType<DataType>>} upObj - uploaded object
   */
  async create(upObj : Full<UploadType<DataType>>) : Promise<OperationResult<DataType>> {
    const duplicate = this.objects.get(upObj.object.id as unknown as string);
    if (duplicate) {
      return { status: Status.CONFLICT, object: duplicate.object };
    }
    const saved = await this.onNew(upObj);
    if (saved) {
      if (saved.object) {
        this.objects.set(upObj.object.id as unknown as string, saved.object);
        this.postCreate();
        return { status: Status.CREATED, object: saved.object.object };    
      }
    }
    return { status: saved.status, object: null };
  }

  /**
   * @description Removes all objects matching the provided properties, returning all objects that were deleted
   * @param {Partial<DataType>} select - properties to match
   */
  async delete(select : Partial<DataType>) : Promise<OperationResult<DataType[]>> { 
    const ret : DataType[] = [];
    for (const value of this.objects) {
      if (Object.keys(select).every((key)=>{
        return select[key as keyof Partial<DataType>] === value[1].object[key as keyof DataType];
      })) {
        if (await deleteDir(value[1].dirPath, true) === Status.SUCCESS) {
          ret.push(value[1].object);
        }
      }
    }
    return { status: Status.SUCCESS, object: ret };
  }

  /**
   * @uses updateFiles
   * @description Updates an object with the provided properties
   * @param {string} id - id of object to update
   * @param {Partial<UploadType<DataType>>} object - properties/files to update
   */
  async update(id : string, object : UploadType<DataType>) : Promise<OperationResult<DataType>> {

    let repoObj : Nullable<RepoType<DataType>> = this.objects.get(id) || null;
    
    if (repoObj) {
      repoObj = { ...repoObj, ...object.object };
      const updatedFiles = await this.onUpdated(repoObj, object.files);
      if (updatedFiles !== Status.SUCCESS) {
        return { status: updatedFiles, object: null };
      }

      this.postUpdate();
      return { status: Status.SUCCESS, object: repoObj.object };      
    }
    return { status: Status.BAD_REQUEST, object: null };      
  }
}