import { MapController }       from '../controllers/map/map.controller';
import { MapRepo }             from '../repos/map/map.repo';
import { MapService }          from '../services/map/map.service';
import { EventSystem }         from '../controllers/events/eventSystem';
import { SimConfigController } from '../controllers/simconfig/simconfig.controller';
import { SimulationBuilder }   from '../controllers/simulation/simulation.builder';
import { ModuleRepo }          from '../repos/module/module.repo';
import { SimConfigRepo }       from '../repos/simconfig/simconfig.repo';
import { ModuleService }       from '../services/module/module.service';
import { SimConfigService }    from '../services/simconfig/simconfig.service';
import { ModuleController }    from '../controllers/module/module.controller';
import { Config }              from './config';
import { ChainBuilderController } from 'src/controllers/chainbuilder/chainbuilder.controller';
import { SimController } from 'src/controllers/simulation/simulation.controller';
import { SimRunner } from 'src/runners/simulation/simulation.runner';


export interface Controllers {
  ModuleController       : ModuleController,
  SimConfigController    : SimConfigController,
  SimulationBuilder      : SimulationBuilder,
  MapController : MapController,
  ChainBuilderController : ChainBuilderController,

}



/**
 * @description Creates required controllers
 * @param {Config} config - configuration object to pass to controllers
 * @param {EventSystem} eventSys - event system to pass to controllers
 */
export const getControllers = (config : Config, eventSys : EventSystem) : Controllers => {

  const mapRepo             : MapRepo             = new MapRepo(config);
  const mapService          : MapService          = new MapService(config, mapRepo);
  const mapController       : MapController       = new MapController('Map', eventSys, mapService);

  const moduleRepo          : ModuleRepo          = new ModuleRepo(config);
  const moduleService       : ModuleService       = new ModuleService(config, moduleRepo);
  const moduleController    : ModuleController    = new ModuleController('Module', eventSys, moduleService);

  const simconfigRepo       : SimConfigRepo       = new SimConfigRepo(config);
  const simconfigService    : SimConfigService    = new SimConfigService(config, simconfigRepo);
  const simconfigController : SimConfigController = new SimConfigController('SimConfig', eventSys, simconfigService);

  const simbuilder : SimulationBuilder = new SimulationBuilder(config, eventSys);
  const simRunner : SimRunner = new SimRunner(config);
  const simController : SimController = new SimController(simRunner, config, eventSys);
  const cbController : ChainBuilderController = new ChainBuilderController(config, simController, eventSys);

  return {
    ModuleController: moduleController,
    SimConfigController: simconfigController,
    SimulationBuilder: simbuilder,
    MapController : mapController,
    ChainBuilderController : cbController,
  };
};