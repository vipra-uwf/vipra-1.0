import { CbResult, CbArgs } from "../../src/Types";
import { ResultStore } from "../../src/ResultStore";


class TestResultStore extends ResultStore {
  constructor(name : string){
    super(name);
  }
  getResult(hash: string): CbResult {
    if (hash === 'good') {
      return { error : false, result : 'good' };
    } else {
      return { error : true, result : 'bad' };
    }
  }
  storeResult(args: CbArgs, result: string): CbResult {
    if (result === 'good') {
      return { error : false, result : 'good' };
    } else {
      return { error : true, result : 'bad' };
    }
  }
}



export {
  TestResultStore
}