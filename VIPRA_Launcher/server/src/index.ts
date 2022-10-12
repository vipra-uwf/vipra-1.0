import express from 'express';

import { Config } from './configuration/config';
import { EventSystem } from './controllers/events/eventSystem';
import { createRouter } from './routes/base.routes';
import { Module } from './types/module/module.types';
import { SimConfig } from './types/simconfig/simconfig.types';
import { initialSetup } from './configuration/setup';
import { createDefaultRouter } from './routes/default.routes';
import { getControllers } from './configuration/DepInj';
import { OMap } from './types/maps/map.types';

const app = express();
const config : Config = initialSetup();
const evSys = new EventSystem();

const controllers = getControllers(config, evSys);

const mapRoutes = createRouter<OMap>('Map', controllers.MapController);
const moduleRoutes = createRouter<Module>('Module', controllers.ModuleController);
const simconfigRoutes = createRouter<SimConfig>('SimConfig', controllers.SimConfigController);

app.use('/map', mapRoutes);
app.use('/module', moduleRoutes);
app.use('/simconfig', simconfigRoutes);
app.use('*', createDefaultRouter());

// controllers.SimulationBuilder.startup();

app.listen(3000, ()=>{
  console.log('listening');
});