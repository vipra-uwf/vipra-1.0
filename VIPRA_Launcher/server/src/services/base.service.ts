import { Nullable } from '../types/typeDefs';
import { OperationResult } from '../types/typeDefs';


/**
 * @description Base Class for services
 */
export interface BaseService<UploadType, DataType> {
  getAll() : Promise<DataType[]>;
  get(id : string) : Promise<Nullable<DataType>>;
  create(object : Partial<UploadType>) : Promise<OperationResult<DataType>>;
  update(id : string, object : Partial<UploadType>) : Promise<OperationResult<DataType>>;
  delete(id : string) : Promise<OperationResult<DataType>>;
  stage(id : string) : Promise<OperationResult<string>>;
}