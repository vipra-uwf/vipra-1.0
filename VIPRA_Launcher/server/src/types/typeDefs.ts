import { Status } from "./Status";

type Nullable<T> = T | null;
type FuncResult = {status : Status; message : Nullable<string>};


type SimState = {ready : boolean; reason : Nullable<string>};

type FlagMap = Map<string, string>;

export {
    Nullable,
    FuncResult,
    SimState,
    FlagMap
};