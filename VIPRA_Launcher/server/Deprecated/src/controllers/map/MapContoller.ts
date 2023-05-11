/**
 * @module MapController
 */

import { Status } from '../../types/Status';
import { inject, singleton } from 'tsyringe';
import { OMap, MapInfo, completeMap, OMapFile } from '../../types/map';
import { FuncResult, Nullable } from '../../types/typeDefs';
import { IFilesController } from '../files/interfaces/FilesController.interface';
import { IMapController } from './interfaces/MapController.interface';
import { config } from '../../configuration/config';


/**
 * @description Handles Adding/Removing/Updating Maps
 */
@singleton()
export class MapController implements IMapController {
  
  private mapMap : Map<string, OMap>;

  private mapFile : OMapFile;

  private fc : IFilesController;

  constructor(@inject('FilesController') fileContoller : IFilesController) {
    this.fc = fileContoller;
    this.loadMaps();
  }

  /**
   * @description Returns all loaded Maps
   * @returns {OMap[]} Array of all loaded Maps
   */
  getAllMaps(): OMap[] {
    return Array.from(this.mapMap.values());
  }

  /**
   * @description Gets the map with the given ID
   * @param  {string} id - ID of map to get
   * @returns {Nullable<Map>} Map with id
   */
  getMap(id: string): Nullable<OMap> {
    return this.mapMap.get(id) || null;
  }
  
  /**
   * @description Adds a new Map
   * @param {Partial<MapInfo>} newMap - Mapinfo for the new map
   * @param {Buffer} mapBuffer - buffer of map file contents
   * @returns {FuncResult} result of adding the map
   */
  public addMap(newMap : Partial<MapInfo>, mapBuffer : Buffer) : FuncResult {
    const map : Nullable<OMap> = completeMap(newMap);
    if (map) {
      this.saveMap(map, mapBuffer);
      return { status: Status.CREATED, message: map.name };
    } else {
      return { status: Status.BAD_REQUEST, message: 'Missing Properties' };
    }
  }

  
  /**
   * @description Removes Map with id
   * @param {string} id - id of Map to remove
   * @returns FuncResult
   */
  public removeMap(id : string) : FuncResult {
    const map : Nullable<OMap> = this.mapMap.get(id) || null;
    if (map) {
      this.fc.deleteDir(map.filepath, false);
      this.mapMap.delete(id);
      return { status: Status.SUCCESS, message: null };
    } else {
      return { status: Status.NOT_FOUND, message: null };
    }
  }

  
  /**
   * @description Saves the map and updates the mapfile
   * @param  {OMap} map - map being save
   * @param  {Buffer} mapBuffer - map content to save
   */
  private saveMap(map : OMap, mapBuffer : Buffer) : void {
    this.fc.writeFileFromBuffer(map.filepath, mapBuffer);
    this.mapMap.set(map.name, map);
    this.mapFile.maps.push(map);
    this.fc.writeFile(config.map.mapsFile, JSON.stringify(this.mapFile));
  }

  /**
   * @description Finds all installed maps and loads them into the controller
   */
  private loadMaps() : void {
    this.fc.forAllFilesThatMatchDo(/\*\.map/, config.map.mapsDir, (filePath : string)=>{
      const map : Nullable<OMap> = this.fc.readJsonFile<OMap>(filePath, { error: true });
      if (map) {
        this.mapMap.set(map.name, map);
      }
    });
  }
}