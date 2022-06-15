import { ResultStore } from "./Types/ResultStore";



export class  EchoResultStore extends ResultStore{
    async storeResult(result: string): Promise<string> {
        return result;
    }
    async getResult(hash: string): Promise<string> {
        return hash;
    }
    async hashResult(result: string): Promise<string> {
        return result;
    }
}