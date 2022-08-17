/**
 * @module SimManager.Interface
 */
import { CbArgs, CbResult } from "typechain";


export interface ISimManager{
    setFlags(flags : Map<string, string>) : void;
    startSim(args : CbArgs) : Promise<CbResult>;
}