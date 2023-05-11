/**
 * @module Types
 */

/**
 * @description Allows for an Object to be null
 */
type Nullable<T> = T | null;

/**
 * @description Protect<T> makes an object directly immutable, however it is still in-directly mutable (through passing to other functions)
 * @note Use this to mark an object as not supposed to be mutated
 * @note ! This does NOT guarantee an object is not mutated, it provides surface level checks for mutations !
 */
type Protect<T> = { readonly [K in keyof T]: Protect<T[K]> };

export {
  Protect,
  Nullable,
};