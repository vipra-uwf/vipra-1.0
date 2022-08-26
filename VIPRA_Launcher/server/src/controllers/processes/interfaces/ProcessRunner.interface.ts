/**
 * @module Controller.Interfaces
 */

import { Module } from '../../../types/module';
import { Status } from '../../../types/Status';


export interface IProcessRunner {
  buildModule(module : Module, debug : boolean) : Promise<Status>;
  compileHumanBehavior(debug : boolean) : Promise<Status>;
  compileGenMain(buildID : string, debug : boolean) : Promise<Status>;
  compileMain(buildID : string, debug : boolean) : Promise<Status>;
  compileSim(buildID : string, debug : boolean) : Promise<Status>;
  precompileHeaders() : Promise<Status>;
}