/**
 * @module InternalTypes
 * @description These Types aren't of use for the end user, as such they are only used internally
 */

import { CbServerOptions } from './Types';

interface CbParametersInfo {
  arguments : {
    [key: string] : {
      chain_name: string;
      description: string;
      type: string;
      repeatable?: boolean;
      sample?: string | number;
    };
  };
  server: CbServerOptions[];
}

interface CbResponses {
  [key : string]:
  {
    description     : string;
    type            : string;
    sample?         : string | number;
    sample_href?    : string;
  };
}

interface Link {
  name: string;
  href: string;
}


export {
  CbParametersInfo,
  CbResponses,
  Link,
};