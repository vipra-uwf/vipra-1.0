
interface OMap {
  id : string;
  name : string;
  description : string;
}

interface OMapUpload {
  map : Partial<OMap>;
  file : Partial<File>;  
}

/**
 * @description Returns true if the map has all properties, false if not
 * @param {Partial<OMap>} map - map to check
 */
const isMapFull = (map:Partial<OMap>) : boolean => {
  return (map.id !== undefined && 
    map.name !== undefined &&
    map.description !== undefined
  );
};

export {
  OMap,
  OMapUpload,
  isMapFull,
};