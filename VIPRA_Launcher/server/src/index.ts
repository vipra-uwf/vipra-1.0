import express from 'express';

import { Logger } from './controllers/logging/logger';
import { Config } from './configuration/config';
import { EventSystem } from './controllers/events/eventSystem';
import { createRouter } from './routes/base.routes';
import { ModuleController } from './controllers/module/module.controller';
import { Module } from './types/module/module.types';
import { ModuleService } from './services/module/module.service';
import { LocalModuleRepo } from './repos/module/module.local.repo';

const app = express();

const config : Config = {
  modules: {
    modulesURL: '',
  },
};

const evSys = new EventSystem();
const logger = new Logger();

const moduleRepo : LocalModuleRepo = new LocalModuleRepo(config);
const moduleService : ModuleService = new ModuleService(moduleRepo);
const moduleController : ModuleController = new ModuleController(evSys, logger, moduleService);

const moduleRoutes = createRouter<Module>(logger, moduleController);

app.use('/module', moduleRoutes);