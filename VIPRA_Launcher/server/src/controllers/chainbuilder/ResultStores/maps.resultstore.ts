/**
 * @module ResultStores
 */
import { EventSystem } from '../../../controllers/events/eventSystem';
import { OMap } from '../../../types/maps/map.types';
import { CbResult, ResultStore } from 'typechain';
import { RequestType } from '../../../controllers/events/eventTypes';
import { Nullable } from 'typechain/dist/typedefs';

/**
 * @description Result Store for the Maps service
 */
export class MapsResultStore extends ResultStore {
  
  private evsys : EventSystem;
  
  constructor(name :string, evsys : EventSystem) {
    super(name);
    this.evsys = evsys;
  }

  /**
   * @description Returns the result at location
   * @param  {string} locationID - location of result
   * @returns CbResult
   */
  async getResult(): Promise<CbResult> {
    const maps : Nullable<OMap[]> = await this.evsys.request<OMap[]>(RequestType.DATA, 'OMap', {});
    if (maps) {
      return { error: false, result: JSON.stringify(maps) };
    } else {
      return { error: true, result: 'No Map Installed' };
    }
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