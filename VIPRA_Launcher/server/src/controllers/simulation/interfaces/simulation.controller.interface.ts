import { Nullable } from '../../../types/typeDefs';
import { CbArgs } from 'typechain';



export interface ISimController {
  startSim(configID : string, mapFile : string, pedestrianFile : string, params : CbArgs): Promise<Nullable<string>>;
}