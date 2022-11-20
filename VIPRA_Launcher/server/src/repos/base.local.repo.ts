
import { Identifiable, RepoType, UploadType } from '../types/uploading.types';
import { Full, Nullable, OperationResult } from '../types/typeDefs';
import { Status } from '../types/status';
import { deleteDir, readMap, writeMap } from '../util/fileOperations';
import { Config } from '../configuration/config';
import { Files } from '../util/filestore';



/**
 * @description Base Repo for objects that are saved in the local filesystem
 */
export abstract class BaseLocalRepo<DataType extends Identifiable> {

  abstract postCreate(object : RepoType<DataType>) : void;
  abstract postUpdate(object : RepoType<DataType>) : void;
  abstract postFound(object : RepoType<DataType>) : void;
  abstract postDelete(objects : DataType[]) : void;

  abstract saveFiles(object : Full<UploadType<DataType>>) : Promise<Nullable<string>>;
  abstract updateFiles(object : RepoType<DataType>, files : Files) : Promise<Nullable<string>>;

  protected config : Config;

  protected objects : Map<string, RepoType<DataType>>;

  protected repoFile : string;

  constructor(typeName : string, config : Config) {
    this.config = config;
    this.repoFile = `${this.config.launcher.repoDir}/${typeName}.json`;
    this.readRepoFile();
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
   * @description Adds an object that was found on start
   * @param {DataType} object - object that was found
   * @param {string} dirPath - directory object was found in
   */
  found(object : DataType, dirPath : string) : Promise<OperationResult<DataType>> {
    const duplicate = this.objects.get(object.id as unknown as string);
    if (duplicate) {
      return Promise.resolve({ status: Status.CONFLICT, object: duplicate.object });
    }
    const obj = { object, dirPath };
    this.objects.set(object.id, obj);
    this.updateRepoFile();
    this.postFound(obj);
    return Promise.resolve({ status: Status.SUCCESS, object: object });
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

    // save the files
    const saved = await this.saveFiles(upObj);
    if (saved) {
      // add object to map
      this.objects.set(upObj.object.id as unknown as string, {
        object: upObj.object as unknown as DataType,
        dirPath: saved,
      });
      this.updateRepoFile();
      return { status: Status.CREATED, object: upObj.object as unknown as DataType };
    }

    return { status: Status.INTERNAL_ERROR, object: null };
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
          this.objects.delete(value[1].object.id);
          ret.push(value[1].object);
        }
      }
    }
    this.postDelete(ret);
    return { status: Status.SUCCESS, object: ret };
  }

  /**
   * @uses updateFiles
   * @description Updates an object with the provided properties
   * @param {string} id - id of object to update
   * @param {Partial<UploadType<DataType>>} object - properties/files to update
   */
  async update(id : string, object : UploadType<DataType>) : Promise<OperationResult<DataType>> {

    const repoObj : Nullable<RepoType<DataType>> = this.objects.get(id) || null;
    
    if (repoObj) {
      repoObj.object = { ...repoObj.object, ...object.object };
      const updatedFiles = await this.updateFiles(repoObj, object.files);
      if (!updatedFiles) {
        return { status: Status.INTERNAL_ERROR, object: null };
      }

      this.postUpdate(repoObj);
      return { status: Status.SUCCESS, object: repoObj.object };      
    }
    return { status: Status.BAD_REQUEST, object: null };   
  }

  /**
   * @description Updates the repo file with all of the current objects
   */
  private updateRepoFile() : void {
    writeMap<Map<string, RepoType<DataType>>>(this.repoFile, this.objects);
  }

  /**
   * @description Reads the saved objects from the repo file
   */
  private readRepoFile() : void {
    const temp = readMap<RepoType<DataType>>(this.repoFile);
    if (temp) {
      this.objects = temp;
    } else {
      this.objects = new Map<string, RepoType<DataType>>();
    }
  }
}