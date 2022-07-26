

import { ResultStore } from 'typechain';


export class SimResultStore extends ResultStore{
    getResult(hash: string): Promise<string> {
        throw new Error("Method not implemented.");
    }
    hashResult(result: string): Promise<string> {
        throw new Error("Method not implemented.");
    }
    storeResult(result: string): Promise<string> {
        throw new Error("Method not implemented.");
    }
}