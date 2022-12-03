/**
 * @module ResultStores
 */
import crypto from 'crypto';
import { CbArgs, CbResult, ResultStore } from 'typechain';
import { Nullable } from 'typechain/dist/typedefs';
import { fileExists, readFile } from '../../../util/fileOperations';



/**
 * @description {@link ResultStore} That holds results from simulation runs
 */
export class SimResultStore extends ResultStore {
  
  private resultMap : Map<string, string>;

  public constructor(name : string) {
    super(name);
    this.resultMap = new Map();
  }

  /**
   * @description Returns a result at the given location
   * @param {string} hash - result location hash
   */
  public getResult(hash: string): CbResult {
    const location : Nullable<string> = this.resultMap.get(hash) || null;
    if (location) {
      if (fileExists(location)) {
        const result = readFile(location);
        if (result) {
          return { error: false, result: result };
        } else {
          return { error: true, result: 'Unable to Properly Read Result' };
        }
      }
    }
    return { error: true, result: 'No Result with the Provided ID' };
  }

  /**
   * @description Saves the results from a simulation run
   * @note Hashes the arguments passed in to get the location
   * @param {CbArgs} args - arguments that were used to run the simulation
   * @param {string} result - file location of the results
   */
  public storeResult(args: CbArgs, result: string): CbResult {
    const hash = crypto.createHash('sha256').update(JSON.stringify(args)).digest('hex').toString();
    this.resultMap.set(hash, result);
    return { error: false, result: hash };
  }

}