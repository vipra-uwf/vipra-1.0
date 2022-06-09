

export interface ResultStore{
    storeResult(result : string)     : Promise<string>;
    getResult(hash : string)    : Promise<string>;
}