/**
 * @module ResultStores
 */
import { CbResult, ResultStore } from 'typechain';

/**
 * @description Result Store for the Maps service
 */
export class MapsResultStore extends ResultStore {
  
  /**
   * @description Returns the result at location
   * @param  {string} locationID - location of result
   * @returns CbResult
   */
  getResult(): CbResult {
    // const maps : string[] = this.mc.getAllMaps().map((map)=>{return map.name;});
    // if (maps) {
    //   return { error: false, result: JSON.stringify(maps) };
    // } else {
    //   return { error: true, result: 'No Map Installed' };
    // }
    throw new Error('not implemented');
  }

  
  /**
   * @description Stores the Result of a Service Run
   * @param  {CbArgs} args - arguments passed into the service
   * @param  {string} result - result of the service run
   * @returns CbResult
   */
  storeResult(): CbResult {
    return { error: false, result: 'MAPS' };
  }
  
}