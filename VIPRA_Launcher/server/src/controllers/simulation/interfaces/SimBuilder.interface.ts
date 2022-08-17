/**
 * @module SimBuilder.Interface
 */
import { Module, ModulesFile } from "../../../types/module";
import { FuncResult, SimState } from "../../../types/typeDefs";


export interface ISimBuilder{
    setFlags            (argv : Map<string, string>)    : void;
    isSimReady          ()                              : SimState;
    compileSimulation   ()                              : Promise<FuncResult>;
    addModule           (module : Module)               : Promise<FuncResult>;
    startup             (modules : ModulesFile)         : Promise<FuncResult>;
}

