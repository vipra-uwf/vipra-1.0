import express from 'express';

import { Logger } from './controllers/logging/logger';
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

const app = express();

const config : Config = {
  modules: {
    modulesURL: '',
  },
  simconfig: {
    simconfigURL: '',
  },
};

const evSys = new EventSystem();
const logger = new Logger();

const moduleRepo : LocalModuleRepo = new LocalModuleRepo(config);
const moduleService : ModuleService = new ModuleService(moduleRepo);
const moduleController : ModuleController = new ModuleController(evSys, logger, moduleService);

const simconfigRepo : LocalSimConfigRepo = new LocalSimConfigRepo(config);
const simconfigService : SimConfigService = new SimConfigService(simconfigRepo);
const simconfigController : SimConfigController = new SimConfigController(evSys, logger, simconfigService);

const moduleRoutes = createRouter<Module>(logger, moduleController);
const simconfigRoutes = createRouter<SimConfig>(logger, simconfigController);

app.use('/module', moduleRoutes);
app.use('/simconfig', simconfigRoutes);