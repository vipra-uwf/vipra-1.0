import { Nullable } from '../../types/typeDefs';

export type EventHandler = (data : unknown, source : unknown) => void | Promise<void>;
export type RequestHandler = (select : unknown) => Nullable<unknown> | Promise<Nullable<unknown>>;


export enum EventType {
  NEW_MODULE,
  UPDATE_MODULE,
  DELETE_MODULE,
  FAIL_MODULE,
  BUILT_MODULE,
  NEW_SIMCONFIG,
  UPDATE_SIMCONFIG,
  DELETE_SIMCONFIG,
  NEW_MAP,
  UPDATE_MAP,
  DELETE_MAP,
  NEW_SIMULATION_BUILD,
  FAIL_SIMULATION_BUILD,
  SUCCESS_SIMULATION_BUILD,
}

export enum RequestType {
  SIM_STATE,
  SIM_BUILD,
  ALL_MODULE,
  MODULE,
  MAP,
  SIM_CONFIG,
  SIM_CONFIG_PARAMS,
}
