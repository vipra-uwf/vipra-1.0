import { Nullable, Full, OperationResult } from 'src/types/typeDefs';
import { SimConfig, SimConfigUpload } from '../../types/simconfig/simconfig.types';
import { BaseRepo } from '../base.repo';

/**
 * @description SimConfig Repo that keeps configs on the local filesystem
 */
export class LocalSimConfigRepo implements BaseRepo<SimConfigUpload, SimConfig> {
  getAll(): Promise<SimConfig[]> {
    throw new Error('Method not implemented.');
  }
  get(id: string): Promise<Nullable<SimConfig>> {
    throw new Error('Method not implemented.');
  }
  create(upObj: Full<Partial<SimConfig>>): Promise<OperationResult<SimConfig>> {
    throw new Error('Method not implemented.');
  }
  delete(id: string): Promise<OperationResult<SimConfig>> {
    throw new Error('Method not implemented.');
  }
  update(id: string, object: Partial<Partial<SimConfig>>): Promise<OperationResult<SimConfig>> {
    throw new Error('Method not implemented.');
  }
  stage(id: string): Promise<OperationResult<string>> {
    throw new Error('Method not implemented.');
  }
  
}