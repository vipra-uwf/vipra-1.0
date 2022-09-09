/**
 * @module Types
 */

import { Status } from './Status';

/**
 * @description Allows the object to be null
 */
type Nullable<T> = T | null;


type FuncResult = { status : Status; message : Nullable<string> };


type SimState = { ready : boolean; reason : Nullable<string> };

/**
 * @description Map meant for holding command line arguments
 */
type FlagMap = Map<string, string>;

export {
  Nullable,
  FuncResult,
  SimState,
  FlagMap,
};