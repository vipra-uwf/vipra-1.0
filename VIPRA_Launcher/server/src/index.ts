import express from 'express';
import https from 'https';
import cors from 'cors';

import { config } from './configuration/config';
import { FLAGS } from './data_models/flags';
import { startup, initialSetup, debugSetup } from './configuration/setup';
import { Logger } from './logging/Logging';
import { defaultRouter } from './routes/defaultRoutes';
import { moduleRouter } from './routes/moduleRoutes';
import { simConfigRouter } from './routes/simConfigRoutes';
import { simulationRouter } from './routes/simulationRoutes';
import { readFile } from './util/FileOperations';
import { getCommandLineArguments } from './util/Util';
import { ModuleController } from './controllers/module/moduleController';
import { SimManager } from './controllers/simulation/SimManager';
import { ConfigManager } from './controllers/simconfig/ConfigManager';



const argv : Map<string, string> = getCommandLineArguments();

if(argv.has(FLAGS.DEBUG_SETUP)){
    debugSetup();
}else{
    try{
        initialSetup(argv);
    }catch(error){
        Logger.error(`Unable to complete initial setup: ${error as string}`);
        process.exit(1);
    }
}

const app = express();
const httpsServer = https.createServer({
    key: readFile(config.app.https.key),
    cert: readFile(config.app.https.cert),
    passphrase: config.app.https.passphrase
}, app);


startup(argv).then(()=>{
    app.use(express.urlencoded({extended: true}));
    app.use(express.json());
    app.use(cors());

    const modulesController = new ModuleController();
    const configManager = new ConfigManager();
    const simManager = SimManager.getInstance(configManager);
    simManager.setFlags(argv);


    app.use('/chainbuilder', simulationRouter(argv));
    app.use('/module', moduleRouter(argv, modulesController));
    app.use('/simconfig', simConfigRouter(argv, configManager));
    app.use('*', defaultRouter);

    httpsServer.listen(config.app.port);
})
.catch((error : string)=>{
    Logger.error(`Error in startup: ${error}`);
});