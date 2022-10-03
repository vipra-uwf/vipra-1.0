import { Full, Nullable } from '../types/typeDefs';
import { OperationResult } from '../types/typeDefs';


export interface BaseRepo<UploadObj, DataObj> {
  getAll() : DataObj[] | Promise<DataObj[]>;
  get(id : string) : Nullable<DataObj> | Promise<Nullable<DataObj>>;
  create(upObj : Full<UploadObj>) : OperationResult<DataObj> | Promise<OperationResult<DataObj>>;
  delete(id : string) : OperationResult<DataObj> | Promise<OperationResult<DataObj>>;
  update(id : string, object : Partial<UploadObj>) : OperationResult<DataObj> | Promise<OperationResult<DataObj>>;
  stage(id : string) : OperationResult<string> | Promise<OperationResult<string>>;
}