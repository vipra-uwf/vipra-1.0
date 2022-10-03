import { ModuleType } from '../module/module.types';
import { DeepPartial } from '../typeDefs';

interface SimConfig {
  id : string;
  name : string;
  description : string;
  modules : Record<ModuleType, string>;
}

type SimConfigUpload = DeepPartial<SimConfig>;

export {
  SimConfig,
  SimConfigUpload,
};