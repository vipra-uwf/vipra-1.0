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

/**
 * @description Protect<T> makes an object directly immutable, however it is still in-directly mutable (through passing to other functions)
 * @note Use this to mark an object as not supposed to be mutated
 * @note ! This does NOT guarantee an object is not mutated, it provides surface level checks for mutations !
 */
type Protect<T> = { readonly [K in keyof T]: Protect<T[K]> };

export {
  Nullable,
  FuncResult,
  SimState,
  FlagMap,
  Protect,
};