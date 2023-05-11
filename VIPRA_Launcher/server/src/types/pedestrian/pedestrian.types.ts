
import { Identifiable } from '../uploading.types';

interface PedMap extends Identifiable {
  id : string;
  name : string;
  description: string;
  mapRef : string;
}


export {
  PedMap,
};