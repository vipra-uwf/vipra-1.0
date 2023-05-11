/**
 * @module VipraLauncher
 */

import express                            from 'express';
import cors                               from 'cors';

import 'reflect-metadata';
import { container }                      from 'tsyringe';

import { config }                         from './configuration/config';
import { initialSetup, setupHTTPSServer } from './configuration/setup';
import { Logger }                         from './logging/Logging';
import { getCommandLineArguments }        from './util/Util';
import { defaultRouter }                  from './routes/defaultRoutes';
import { moduleRouter }                   from './routes/moduleRoutes';
import { simConfigRouter }                from './routes/simConfigRoutes';
import { simulationRouter }               from './routes/simulationRoutes';
import { Status }                         from './types/Status';
import { FuncResult }                     from './types/typeDefs';
import { ISimBuilder }                    from './controllers/simulation/interfaces/SimBuilder.interface';
import { ISimManager }                    from './controllers/simulation/interfaces/SimManager.interface';
import { IModuleController }              from './controllers/module/interfaces/ModuleController.interface';
import { IConfigManager }                 from './controllers/simconfig/interfaces/ConfigManager.interface';
import { setupDI }                        from './configuration/DepInj';
import { IChainManager }                  from './controllers/chainbuilder/interfaces/ChainManager.interface';

const argv : Map<string, string> = getCommandLineArguments();

setupDI();

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

const simBuilder        : ISimBuilder       = container.resolve('SimBuilder');
const modulesController : IModuleController = container.resolve('ModuleController');
const configManager     : IConfigManager    = container.resolve('ConfigManager');
const simManager        : ISimManager       = container.resolve('SimManager');
const chainManager      : IChainManager     = container.resolve('ChainManager');

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


app.use('/chainbuilder',  simulationRouter(chainManager));
app.use('/module',        moduleRouter(argv, modulesController));
app.use('/simconfig',     simConfigRouter(configManager));
app.use('*',              defaultRouter);

httpsServer.listen(config.app.port);