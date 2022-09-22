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

interface CbParameters {
  arguments: { [key : string] : CbArgument };
  server: CbServerOptions[];
}

interface CbArgument {
  chain_name: string; 
  type: string; 
  description: string;
  repeatable: boolean;
  sample?: string;
}

interface CbReturnValue {
  name : string;
  type : string;
  description : string;
}

interface CbServiceOptions {
  info: CbServiceInfo;
  arguments: CbArgument[];
  returnValue: CbReturnValue;
  resultStore: ResultStore;
  method: CbMethod;
  server: CbServerOptions[];
}

export {
  CbRootOptions,
  CbServiceInfo,
  CbParameters,
  CbArgument,
  CbMethod,
  CbResult,
  CbReturnValue,
  CbArgs,
  CbServiceOptions,
  CbServerOptions,
};
