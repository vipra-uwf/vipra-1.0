import express from 'express';

import { Config } from './configuration/config';
import { EventSystem } from './controllers/events/eventSystem';
import { createRouter } from './routes/base.routes';
import { ModuleController } from './controllers/module/module.controller';
import { Module } from './types/module/module.types';
import { ModuleService } from './services/module/module.service';
import { LocalModuleRepo } from './repos/module/module.local.repo';
import { LocalSimConfigRepo } from './repos/simconfig/simconfig.local.repo';
import { SimConfigService } from './services/simconfig/simconfig.service';
import { SimConfigController } from './controllers/simconfig/simconfig.controller';
import { SimConfig } from './types/simconfig/simconfig.types';
import { initialSetup } from './configuration/setup';
import { createDefaultRouter } from './routes/default.routes';
// import { createSimRouter } from './routes/simulation.routes';
// import { ChainBuilderController } from './controllers/chainbuilder/chainbuilder.controller';

const app = express();
const config : Config = initialSetup();

const evSys = new EventSystem();

const moduleRepo : LocalModuleRepo = new LocalModuleRepo(config);
const moduleService : ModuleService = new ModuleService(moduleRepo);
const moduleController : ModuleController = new ModuleController(evSys, moduleService);

const simconfigRepo : LocalSimConfigRepo = new LocalSimConfigRepo(config);
const simconfigService : SimConfigService = new SimConfigService(evSys, simconfigRepo);
const simconfigController : SimConfigController = new SimConfigController(evSys, simconfigService);

// const chainController : ChainBuilderController = new ChainBuilderController(config, evSys);

const moduleRoutes = createRouter<Module>('Module', moduleController);
const simconfigRoutes = createRouter<SimConfig>('SimConfig', simconfigController);
// const simulationRoutes = createSimRouter(chainController);

app.use('/module', moduleRoutes);
app.use('/simconfig', simconfigRoutes);
// app.use('/simulation', simulationRoutes);
app.use('*', createDefaultRouter());

app.listen(3000, ()=>{
  console.log('listening');
});