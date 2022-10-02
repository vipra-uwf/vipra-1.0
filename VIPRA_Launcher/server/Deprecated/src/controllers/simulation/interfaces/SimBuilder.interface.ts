/**
 * @module Controller.Interfaces
 */
import { Module, ModulesFile } from '../../../types/module';
import { FuncResult, Nullable, SimState } from '../../../types/typeDefs';


export interface ISimBuilder {
  startup             (modules : ModulesFile)              : Promise<FuncResult>;
  setFlags            (argv : Map<string, string>)         : void;
  getSimState         ()                                   : SimState;
  getBuildStatus      (buildID : string)                   : Nullable<SimState>;
  compileSimulation   (buildID : Nullable<string>)         : FuncResult;
  addedModule           (added : Module)                     : Promise<FuncResult>;
  removedModule        (removed : Module)                   : FuncResult;
}

