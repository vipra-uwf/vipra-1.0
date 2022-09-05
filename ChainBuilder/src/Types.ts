/**
 * @module Types
 */
import { ResultStore } from './ResultStore';

enum CbResultOptions {
  TRANSIENT = 'transient',
  CACHABLE = 'cachable',
}


type CbResult = { error : boolean; result : string };
type CbMethod = (args : { [key: string] : string[] }) => Promise<CbResult> | CbResult;
type CbArgs = { [key: string] : string[] };

interface CbResponse {
  [key : string]:
  {
    description     : string;
    type            : string;
    sample?         : string | number;
    sample_href?    : string;
  };
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

interface Link {
  name: string;
  href: string;
}

interface CbParametersInfo {
  arguments : {
    [key: string] : {
      chain_name: string;
      description: string;
      type: string;
      sample?: string | number;
    };
  };
  server:[];
}

interface CbParameter {
  name: string; type: string; 
  description: string; 
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
  server: CbResultOptions[];
}

export {
  Link,
  CbServiceInfo,
  CbParametersInfo,
  CbParameter,
  CbMethod,
  CbResult,
  CbReturnType,
  CbArgs,
  CbServiceOptions,
  CbResponse,
  CbResultOptions,
};
