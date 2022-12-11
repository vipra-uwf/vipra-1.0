/**
 * @module ResultStores
 */
import { EventSystem } from '../../../controllers/events/eventSystem';
import { OMap } from '../../../types/maps/map.types';
import { CbResult, ResultStore } from 'typechain';
import { RequestType } from '../../../controllers/events/eventTypes';
import { Nullable } from 'typechain/dist/typedefs';
import { PedMap } from '../../../types/pedestrian/pedestrian.types';

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
    const maps : Nullable<OMap[]> = await this.evsys.request<OMap>(RequestType.DATA, 'OMap', {});
    if (maps) {
      const ret = await Promise.all(maps.map(async (map : OMap) => {
        const pedMaps = await this.evsys.request<PedMap>(RequestType.DATA, 'PedMap', { mapRef:map.id });
        return {
          id: map.id,
          name: map.name,
          description: map.description,
          type: map.type,
          pedestrainsets: pedMaps,
        };
      }));
      return { error: false, result: JSON.stringify(ret) };
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