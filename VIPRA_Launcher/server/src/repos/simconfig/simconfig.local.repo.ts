import { Config } from '../../configuration/config';
import { Full, Nullable, OperationResult } from '../../types/typeDefs';
import { SimConfig, SimConfigUpload } from '../../types/simconfig/simconfig.types';
import { BaseRepo } from '../base.repo';
import { Status } from 'src/types/status';
import { deleteDir, writeFile } from '../../util/fileOperations';

/**
 * @description SimConfig Repo that keeps configs on the local filesystem
 */
export class LocalSimConfigRepo implements BaseRepo<SimConfigUpload, SimConfig> {


  private configMap : Map<string, SimConfig>;

  private configDir : string;

  constructor(config? : Config) {
    if (config) {
      this.configDir = config.simconfig.simconfigURL;
    } else {
      throw new Error('Attempt to create Local SimConfig Repo without a Config');
    }
  }

  /**
   * @description Returns all SimConfigs
   */
  public getAll(): SimConfig[] {
    const retVal : SimConfig[] = [];
    for (const key in this.configMap) {
      const value = this.configMap.get(key);
      if (value) {
        retVal.push(value);
      }
    }
    return retVal;
  }

  /**
   * @description Returns the simconfig with id
   * @param {string} id - id of simconfig to get
   */
  public get(id: string): Nullable<SimConfig> {
    const config = this.configMap.get(id);
    if (config) {
      return config;
    } else {
      return null;
    }
  }

  /**
   * @description Creates a new simconfig
   * @param {Full<SimConfig>} upObj - simconfig to adds
   */
  public create(upObj: Full<SimConfig>): OperationResult<SimConfig> {
    if (this.configMap.has(upObj.id)) {
      return { status: Status.CONFLICT, object: this.configMap.get(upObj.id) || null };
    }

    this.saveConfig(upObj);
    this.configMap.set(upObj.id, upObj);

    return { status: Status.CREATED, object: upObj };
  }

  /**
   * @description Deletes a simconfig
   * @param {string} id - id of simconfig to deletes
   */
  public async delete(id: string): Promise<OperationResult<SimConfig>> {
    const config = this.configMap.get(id);
    if (config) {
      const dirPath = `${this.configDir}/${config.id}`;
      await deleteDir(dirPath, true);
      this.configMap.delete(id);
      return { status: Status.SUCCESS, object: config };
    } else {
      return { status: Status.NOT_FOUND, object: null };
    }
  }

  /**
   * @description Updates a simconfig with provided properties
   * @param {string} id - id of config to update
   * @param {Partial<SimConfig>} object - properties to update
   */
  public update(id: string, object: Partial<SimConfig>): OperationResult<SimConfig> {
    let config = this.configMap.get(id);
    if (config) {
      config = { ...config, ...object };
      this.saveConfig(config);
      return { status: Status.SUCCESS, object: config };
    } else {
      return { status:Status.NOT_FOUND, object:null };
    }
  }

  /**
   * @description Makes sure the simconfig is staged, ready for use
   * @param {string} id - id of config to stage
   */
  public stage(id: string): OperationResult<string> {
    const config = this.configMap.get(id);
    if (config) {
      const filePath = `${this.configDir}/${config.id}/sim.config`;
      return { status: Status.SUCCESS, object: filePath };
    }

    return { status: Status.NOT_FOUND, object: null };
  }

  /**
   * @description Saves the SimConfig file to the local filesystem
   * @param {SimConfig} config - config to save
   */
  private saveConfig(config : SimConfig) : void {
    const filePath = `${this.configDir}/${config.id}/sim.config`;
    writeFile(filePath, JSON.stringify(config));
  } 
}