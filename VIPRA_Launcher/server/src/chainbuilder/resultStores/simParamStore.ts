/**
 * @module TypeChain
 */

import { CbResult, ResultStore } from 'typechain';

/* eslint-disable */

export class SimParamStore extends ResultStore{
    private paramsMap : Map<string, string> = new Map();

    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    async getResult(hash: string): Promise<CbResult> {
        if(this.paramsMap.has(hash)){
            return {error: false, result: this.paramsMap.get(hash) || ''};
        }else{
            return {error: true, result:`Invalid Result Location`};
        }
    }


    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    async storeResult(result: string): Promise<CbResult> {
        const parsed = JSON.parse(result);
        if(parsed.configID && parsed.params){
            const id = parsed.configID;
            const params = parsed.params;
            this.paramsMap.set(id, JSON.stringify(params));
            return {error: false, result: id};
        }else{
            return {error: true, result:`TODO`};
        }
    }
}





