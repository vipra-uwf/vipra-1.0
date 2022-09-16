import { OMap, MapInfo } from '../../../types/map';
import { FuncResult, Nullable } from '../../../types/typeDefs';



export interface IMapController {
  getAllMaps() : OMap[];
  getMap(id : string) : Nullable<OMap>;
  addMap(newMap : Partial<MapInfo>, mapFile : Buffer) : FuncResult;
  removeMap(id : string) : FuncResult;
}