import { config } from '../configuration/config';
import { Nullable } from './typeDefs';

interface OMap {
  name : string;
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
    name : map.name,
  };
};

/**
 * @description Creates an OMap from a partial mapinfo
 * @param  {Partial<MapInfo>} map - mapinfo to turn into a map
 * @returns Nullable<OMap> created OMap, null if the mapinfo was incorrect
 */
const completeMap = (map : Partial<MapInfo>) : Nullable<OMap> => {
  if (map.name) {
    const id = crypto.randomUUID();
    const newMap : OMap = {
      name: map.name,
      filepath: `${config.map.mapsDir}/obstacleMaps/${id}.omap`,
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