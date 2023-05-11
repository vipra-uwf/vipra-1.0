import { MapController }          from '../controllers/map/map.controller';
import { MapRepo }                from '../repos/map/map.repo';
import { MapService }             from '../services/map/map.service';
import { EventSystem }            from '../controllers/events/eventSystem';
import { SimConfigController }    from '../controllers/simconfig/simconfig.controller';
import { SimulationBuilder }      from '../controllers/simulation/simulation.builder';
import { ModuleRepo }             from '../repos/module/module.repo';
import { SimConfigRepo }          from '../repos/simconfig/simconfig.repo';
import { ModuleService }          from '../services/module/module.service';
import { SimConfigService }       from '../services/simconfig/simconfig.service';
import { ModuleController }       from '../controllers/module/module.controller';
import { Config }                 from './config';
import { ChainBuilderController } from '../controllers/chainbuilder/chainbuilder.controller';
import { SimController }          from '../controllers/simulation/simulation.controller';
import { SimRunner }              from '../runners/simulation/simulation.runner';
import { BehaviorController }     from '../controllers/behavior/behavior.controller';
import { BehaviorRepo }           from '../repos/behavior/behavior.repo';
import { BehaviorService }        from '../services/behavior/behavior.service';
import { PedestrianController }   from '../controllers/pedestrian/pedestrian.controller';
import { PedestrianRepo }         from '../repos/pedestrian/pedestrian.repo';
import { PedestrianService }      from '../services/pedestrian/pedestrian.service';


export interface Controllers {
  ModuleController       : ModuleController,
  SimConfigController    : SimConfigController,
  SimulationBuilder      : SimulationBuilder,
  BehaviorController     : BehaviorController
  MapController          : MapController,
  ChainBuilderController : ChainBuilderController,
  SimController          : SimController,
  PedestrianController   : PedestrianController,
}

/**
 * @description Runs start on all Controllers that have it
 * @param {Controllers} controllers - Controllers to start
 */
export const startControllers = (controllers : Controllers) : void => {
  controllers.ModuleController.start();
  controllers.MapController.start();
  controllers.SimConfigController.start();
  controllers.BehaviorController.start();
  controllers.PedestrianController.start();
};

/**
 * @description Creates required controllers
 * @param {Config} config - configuration object to pass to controllers
 * @param {EventSystem} eventSys - event system to pass to controllers
 */
export const getControllers = (config : Config, eventSys : EventSystem) : Controllers => {
  
  
  const mapRepo             : MapRepo             = new MapRepo('Map', config);
  const mapService          : MapService          = new MapService(config, mapRepo);
  const mapController       : MapController       = new MapController('OMap', eventSys, mapService, config);

  const moduleRepo          : ModuleRepo          = new ModuleRepo('Module', config);
  const moduleService       : ModuleService       = new ModuleService(config, moduleRepo);
  const moduleController    : ModuleController    = new ModuleController('Module', eventSys, moduleService, config);

  const simconfigRepo       : SimConfigRepo       = new SimConfigRepo('SimConfig', config);
  const simconfigService    : SimConfigService    = new SimConfigService(config, simconfigRepo);
  const simconfigController : SimConfigController = new SimConfigController('SimConfig', eventSys, simconfigService, config);

  const behaviorRepo        : BehaviorRepo         = new BehaviorRepo('Behavior', config);
  const behaviorService     : BehaviorService      = new BehaviorService(config, behaviorRepo);
  const behaviorController  : BehaviorController   = new BehaviorController('Behavior', eventSys, behaviorService, config);

  const pedRepo             : PedestrianRepo       = new PedestrianRepo('PedMap', config);
  const pedService          : PedestrianService    = new PedestrianService(config, pedRepo);
  const pedController       : PedestrianController = new PedestrianController('PedMap', eventSys, pedService, config);
  
  const simbuilder          : SimulationBuilder         = new SimulationBuilder(config, eventSys);
  const simRunner           : SimRunner                 = new SimRunner(config);
  const simController       : SimController             = new SimController(simRunner, config, eventSys);
  const cbController        : ChainBuilderController    = new ChainBuilderController(config, simController, eventSys);

  return {
    ModuleController: moduleController,
    SimConfigController: simconfigController,
    SimulationBuilder: simbuilder,
    MapController : mapController,
    ChainBuilderController : cbController,
    BehaviorController: behaviorController,
    SimController : simController,
    PedestrianController : pedController,
  };
};