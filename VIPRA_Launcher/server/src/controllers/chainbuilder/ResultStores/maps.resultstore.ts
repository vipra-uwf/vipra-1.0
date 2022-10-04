/**
 * @module ResultStores
 */
import { CbArgs, CbResult, ResultStore } from 'typechain';



/**
 * @description Result Store for the Maps service
 */
export class MapsResultStore extends ResultStore {
  
  /**
   * @description Returns the result at location
   * @param  {string} locationID - location of result
   * @returns CbResult
   */
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  getResult(locationID: string): CbResult {
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
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  storeResult(args: CbArgs, result: string): CbResult {
    return { error: false, result: 'MAPS' };
  }
  
}