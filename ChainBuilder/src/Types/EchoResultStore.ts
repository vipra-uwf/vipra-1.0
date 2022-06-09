import { ResultStore } from "./ResultStore.interface";


export class EchoResultStore implements ResultStore{
    async storeResult(result: string): Promise<string> {
        return result;
    }
    async getResult(hash: string): Promise<string> {
        return hash;
    }
}