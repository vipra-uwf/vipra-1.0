
import crypto from 'crypto';
import { IFilesController } from '../../../controllers/files/interfaces/FilesController.interface';
import { inject } from 'tsyringe';
import { CbArgs, CbResult, ResultStore } from 'typechain';
import { Nullable } from 'typechain/dist/typedefs';



/**
 * @description {@link ResultStore} That holds results from simulation runs
 */
export class SimResultStore extends ResultStore {

  private fc : IFilesController;
  
  private resultMap : Map<string, string>;

  public constructor(name : string, @inject('FilesController') fileController : IFilesController) {
    super(name);
    this.resultMap = new Map();
    this.fc = fileController;
  }

  /**
   * @description Returns a result at the given location
   * @param {string} hash - result location hash
   */
  public getResult(hash: string): CbResult {
    const location : Nullable<string> = this.resultMap.get(hash) || null;
    if (location) {
      if (this.fc.fileExists(location)) {
        const result = this.fc.readFile(location);
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
    const hash : string = crypto.createHash('sha256').update(JSON.stringify(args)).toString();
    this.resultMap.set(hash, result);
    return { error: false, result: hash };
  }

}