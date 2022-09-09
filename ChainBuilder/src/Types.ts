/**
 * @module Types
 */
import { ResultStore } from './ResultStore';

type CbServerOptions = 'transient' | 'cachable';
type CbResult = { error : boolean; result : string };
type CbMethod = (args : { [key: string] : string[] }) => Promise<CbResult> | CbResult;
type CbArgs = { [key: string] : string[] };


interface CbRootOptions {
  allowStoreSharing? : boolean
}

interface CbServiceInfo {
  name            : string;
  description     : string;
  key             : string;
  version         : string;
  author          : string;
  email           : string;
  doc_href        : string;
}

interface CbParameter {
  name: string; 
  type: string; 
  description: string;
  repeatable: boolean;
  sample?: string;
}

interface CbReturnType {
  name : string;
  type : string;
}

interface CbServiceOptions {
  info: CbServiceInfo;
  parameters: CbParameter[];
  returnValue: CbReturnType;
  resultStore: ResultStore;
  method: CbMethod;
  server: CbServerOptions[];
}

export {
  CbRootOptions,
  CbServiceInfo,
  CbParameter,
  CbMethod,
  CbResult,
  CbReturnType,
  CbArgs,
  CbServiceOptions,
  CbServerOptions,
};
