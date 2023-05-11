import { MapInfo } from "../../src/types/map";


const goodMapUpload : Partial<MapInfo> = {
  name: "goodmap",
  description: "this is a good map upload",
};

const goodMapUploadBuffer : Buffer = new Buffer("this is a good map");


const badMapUpload : Partial<MapInfo> = {
  name: "badmap",
}





export {
  goodMapUpload,
  goodMapUploadBuffer,
};