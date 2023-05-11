/**
 * @module Types
 */

import { Status } from './status';

/**
 * @description Allows the object to be null
 */
type Nullable<T> = T | null;


type OperationResult<DataType> = { status: Status; object: Nullable<DataType> };

type DeepPartial<T> = { [K in keyof T]?: DeepPartial<T[K]> };

type Full<T> = {
  [P in keyof T]-?: Full<T[P]>;
};

type StringLiteral<T> = T extends string ? string extends T ? never : T : never;

/**
 * @description Map meant for holding command line arguments
 */
type FlagMap = Map<string, string>;

export {
  Nullable,
  OperationResult,
  FlagMap,
  DeepPartial,
  StringLiteral,
  Full,
};