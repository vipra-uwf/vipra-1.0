import { EventSystem }            from '../controllers/events/eventSystem';
import { SimConfigController }    from '../controllers/simconfig/simconfig.controller';
import { SimulationBuilder }      from '../controllers/simulation/simulation.builder';
import { LocalModuleRepo }        from '../repos/module/module.local.repo';
import { LocalSimConfigRepo }     from '../repos/simconfig/simconfig.local.repo';
import { ModuleService }          from '../services/module/module.service';
import { SimConfigService }       from '../services/simconfig/simconfig.service';
import { ModuleController }       from '../controllers/module/module.controller';
import { Config }                 from './config';


export interface Controllers {
  ModuleController       : ModuleController,
  SimConfigController    : SimConfigController,
  SimulationBuilder             : SimulationBuilder,
}



/**
 * @description Creates required controllers
 * @param {Config} config - configuration object to pass to controllers
 * @param {EventSystem} eventSys - event system to pass to controllers
 */
export const getControllers = (config : Config, eventSys : EventSystem) : Controllers => {
  const moduleRepo : LocalModuleRepo = new LocalModuleRepo(config);
  const moduleService : ModuleService = new ModuleService(moduleRepo);
  const moduleController : ModuleController = new ModuleController(eventSys, moduleService);

  const simconfigRepo : LocalSimConfigRepo = new LocalSimConfigRepo(config);
  const simconfigService : SimConfigService = new SimConfigService(eventSys, simconfigRepo);
  const simconfigController : SimConfigController = new SimConfigController(eventSys, simconfigService);

  const simbuilder : SimulationBuilder = new SimulationBuilder(config, eventSys);

  return {
    ModuleController: moduleController,
    SimConfigController: simconfigController,
    SimulationBuilder: simbuilder,
  };
};