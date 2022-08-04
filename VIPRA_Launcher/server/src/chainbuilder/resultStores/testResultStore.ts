import { CbResult, ResultStore } from 'typechain';


export class TestResultStore extends ResultStore{

    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    async getResult(hash: string): Promise<CbResult> {
        return {error: false, result: hash};
    }

    // NOTE: typechain requires this be async,
    // eslint-disable-next-line @typescript-eslint/require-await
    async storeResult(result: string): Promise<CbResult> {
        return {error: false, result};
    }
}