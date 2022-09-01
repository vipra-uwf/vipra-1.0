import { ChildProcess } from 'child_process';
import { Nullable } from '../../../types/typeDefs';


export interface ISimRunner {
  runSim(configID : string, mapFile : string, pedestrianFile : string, paramsFile : string, outputFile : string) : Nullable<ChildProcess>
}