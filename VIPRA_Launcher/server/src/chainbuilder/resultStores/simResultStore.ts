import crypto from 'crypto';

import { fileExists, readFile } from '../../util/FileOperations';
import { CbResult, ResultStore } from 'typechain';


export class SimResultStore extends ResultStore{

    private resultMap : Map<string, string> = new Map();


    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    async getResult(hash: string): Promise<CbResult> {
        if(!fileExists(this.resultMap.get(hash))){
            return {error: true, result: `Invalid Result Location`};
        }
        return {error: false, result: readFile(this.resultMap.get(hash))};
    }

    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    async storeResult(result: string): Promise<CbResult> {
        const id = crypto.randomUUID();
        this.resultMap.set(id, result);
        return {error: false, result: id};
    }
}