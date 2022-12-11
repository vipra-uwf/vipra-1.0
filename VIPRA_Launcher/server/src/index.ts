import express from 'express';
import cors from 'cors';

import { Config } from './configuration/config';
import { EventSystem } from './controllers/events/eventSystem';
import { createRouter } from './routes/base.routes';
import { Module } from './types/module/module.types';
import { SimConfig } from './types/simconfig/simconfig.types';
import { initialSetup, setupHTTPS } from './configuration/setup';
import { createDefaultRouter } from './routes/default.routes';
import { getControllers, startControllers } from './configuration/DepInj';
import { OMap } from './types/maps/map.types';
import { Logger } from './controllers/logging/logger';
import { createSimRouter } from './routes/simulation.routes';
import { FLAGS } from './types/flags/flags.types';
import { PedMap } from './types/pedestrian/pedestrian.types';

const app = express();

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(cors());

const config : Config = initialSetup();
const evSys = new EventSystem();

const controllers = getControllers(config, evSys);

const mapRoutes = createRouter<OMap>('Map', controllers.MapController);
const moduleRoutes = createRouter<Module>('Module', controllers.ModuleController);
const simconfigRoutes = createRouter<SimConfig>('SimConfig', controllers.SimConfigController);
const pedMapRoutes = createRouter<PedMap>('PedMap', controllers.PedestrianController);
const simulationRoutes = createSimRouter(controllers.ChainBuilderController);

app.use('/map', mapRoutes);
app.use('/pedmap', pedMapRoutes);
app.use('/module', moduleRoutes);
app.use('/simconfig', simconfigRoutes);
app.use('/simulation', simulationRoutes);
app.use('*', createDefaultRouter());

startControllers(controllers);
controllers.SimulationBuilder.startup();

if (!config.flags.has(FLAGS.NO_SERV)) {
  setupHTTPS(app, config).listen(config.app.port).on('error', (error : Error) => { Logger.error(`HTTPS Server: ${error.message}`); });
}