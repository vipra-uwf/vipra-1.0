import { Full, Nullable } from '../types/typeDefs';
import { OperationResult } from '../types/typeDefs';


export interface BaseRepo<UploadObj, DataObj> {
  getAll() : Promise<DataObj[]>;
  get(id : string) : Promise<Nullable<DataObj>>;
  create(upObj : Full<UploadObj>) : Promise<OperationResult<DataObj>>;
  delete(id : string) : Promise<OperationResult<DataObj>>;
  update(id : string, object : Partial<UploadObj>) : Promise<OperationResult<DataObj>>;
  stage(id : string) : Promise<OperationResult<string>>;
}