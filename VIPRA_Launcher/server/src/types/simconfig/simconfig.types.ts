import { ModuleType } from '../module/module.types';

interface SimConfig {
  id : string;
  name : string;
  description : string;
  modules : Record<ModuleType, string>;
}



export {
  SimConfig,
};