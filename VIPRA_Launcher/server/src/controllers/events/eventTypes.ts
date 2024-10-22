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

export type EventData = 'SimConfig' | 'SimConfigParams' | 'Module' | 'OMap' | 'SimBuild' | 'SimRun' | 'SimState' | 'Behavior' | 'PedMap';

export enum RequestType {
  DATA,
  DATA_W_PATH,
}
