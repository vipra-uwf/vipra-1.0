import { Nullable } from '../../types/typeDefs';

export type EventHandler = (data : any, source : any)=>void;
export type RequestHandler = (data : any)=>Promise<Nullable<unknown>>;


export enum EventType {
  NEW_MODULE,
  UPDATE_MODULE,
  DELETE_MODULE,
  NEW_SIMCONFIG,
  UPDATE_SIMCONFIG,
  DELETE_SIMCONFIG,
  NEW_MAP,
  UPDATE_MAP,
  DELETE_MAP,
}

export enum RequestType {
  MODULE,
  MAP,
  SIM_CONFIG,
}
