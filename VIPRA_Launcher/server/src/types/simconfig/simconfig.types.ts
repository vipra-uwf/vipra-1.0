import { Module, ModuleType } from '../module/module.types';



interface SimConfig {
  id : string;
  name : string;
  description : string;
  modules : Record<ModuleType, Module>;
}

type SimConfigUpload = Partial<SimConfig>;

export {
  SimConfig,
  SimConfigUpload,
};