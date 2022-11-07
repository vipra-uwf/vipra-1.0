import { Nullable } from '../../types/typeDefs';

export type EventHandler = (data : unknown) => void | Promise<void>;
export type RequestHandler = (select : unknown) => Nullable<unknown[]> | Promise<Nullable<unknown[]>>;

export enum EventType {
  NEW,
  UPDATE,
  DELETE,
  FAIL,
  SUCCESS,
}

export type EventData = 'SimConfig' | 'Module' | 'Map' | 'Build' | 'SimRun';

export enum RequestType {
  SIM_STATE,
  SIM_BUILD,
  MODULE,
  MODULE_REPO,
  MAP,
  SIM_CONFIG,
  SIM_CONFIG_PARAMS,
}
