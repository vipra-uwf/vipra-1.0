/**
 * @module VipraLauncher
 */

import express from 'express';
import cors from 'cors';

import 'reflect-metadata';
import { container } from 'tsyringe';

import { config } from './configuration/config';
import { initialSetup, setupHTTPSServer } from './configuration/setup';
import { Logger } from './logging/Logging';
import { getCommandLineArguments } from './util/Util';
import { ModuleController } from './controllers/module/moduleController';
import { SimManager } from './controllers/simulation/SimManager';
import { ConfigManager } from './controllers/simconfig/ConfigManager';

import { defaultRouter } from './routes/defaultRoutes';
import { moduleRouter } from './routes/moduleRoutes';
import { simConfigRouter } from './routes/simConfigRoutes';
import { simulationRouter } from './routes/simulationRoutes';
import { SimBuilder } from './controllers/simulation/SimBuilder';
import { Status } from './types/Status';
import { FuncResult } from './types/typeDefs';
import { FilesController } from './controllers/files/FilesController';
import { ProcessRunner } from './controllers/processes/ProcessRunner';

const argv : Map<string, string> = getCommandLineArguments();

try {
  initialSetup(argv);
} catch (error) {
  Logger.error(`Unable to complete initial setup: ${error as string}`);
  process.exit(1);
}

const app = express();
const httpsServer = setupHTTPSServer(app);

app.use(express.urlencoded({ extended: true }));
app.use(express.json());
app.use(cors());

container.register('FilesController', FilesController);
container.register('SimBuilder', SimBuilder);
container.register('ProcessRunner', ProcessRunner);
container.register('ModuleController', ModuleController);
container.register('ConfigManager', ConfigManager);
container.register('SimManager', SimManager);

const simBuilder : SimBuilder               = container.resolve(SimBuilder);
const modulesController : ModuleController  = container.resolve(ModuleController);
const configManager : ConfigManager         = container.resolve(ConfigManager);
const simManager : SimManager               = container.resolve(SimManager);

simManager.setFlags(argv);
simBuilder.setFlags(argv);

simBuilder.startup(modulesController.getModules())
  .then((result : FuncResult)=>{
    if (result.status !== Status.SUCCESS) {
      Logger.info(`Unable to compile Simulation in Startup, reason: ${result.message || 'Unknown'}`);
    }
  })
  .catch((err : string)=>{
    Logger.error(`SimBuilder Startup : ${err}`);
  })
  .finally(()=>{
    modulesController.writeModulesFile();
  });


app.use('/chainbuilder', simulationRouter(argv));
app.use('/module', moduleRouter(argv, modulesController));
app.use('/simconfig', simConfigRouter(configManager));
app.use('*', defaultRouter);

httpsServer.listen(config.app.port);