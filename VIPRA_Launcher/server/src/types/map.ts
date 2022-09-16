import { config } from '../configuration/config';
import { Nullable } from './typeDefs';

interface OMap {
  id : string;
  name : string;
  description : string;
  filepath : string;
}

type MapInfo = Omit<OMap, 'filepath'>;

interface OMapFile {
  maps : OMap[];
}

/**
 * @description Returns a MapInfo taken from a Map, removing filepaths etc
 * @param  {Map} map - map to get info of
 * @returns MapInfo
 */
const mapToInfo = (map : OMap) : MapInfo => {
  return {
    id : map.id,
    name : map.name,
    description : map.description,
  };
};

/**
 * @description Creates an OMap from a partial mapinfo
 * @param  {Partial<MapInfo>} map - mapinfo to turn into a map
 * @returns Nullable<OMap> created OMap, null if the mapinfo was incorrect
 */
const completeMap = (map : Partial<MapInfo>) : Nullable<OMap> => {
  if (map.name && map.description) {
    const id = crypto.randomUUID();
    const newMap : OMap = {
      id,
      name: map.name,
      description: map.description,
      filepath: `${config.vipra.vipraDir}/obstacleMaps/${id}.omap`,
    };
    return newMap;
  } else {
    return null;
  }
};

export {
  OMap,
  MapInfo,
  OMapFile,
  mapToInfo,
  completeMap,
};