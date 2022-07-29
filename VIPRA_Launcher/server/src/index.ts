import express from 'express';
import https from 'https';

import { config } from './configuration/config';
import { startup, initialSetup, debugSetup } from './configuration/setup';
import { Logger } from './logging/Logging';
import { defaultRouter } from './routes/defaultRoutes';
import { moduleRouter } from './routes/moduleRoutes';
import { simConfigRouter } from './routes/simConfigRoutes';
import { simulationRouter } from './routes/simulationRoutes';
import { readFile } from './util/FileOperations';
import { getCommandLineArguments } from './util/Util';

const DEBUG_SETUP_FLAG = "debugsetup";
const DEBUG_BUILD_FLAG = "debugbuild";

const argv : Map<string, string> = getCommandLineArguments();

if(argv.has(DEBUG_SETUP_FLAG)){
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

startup(argv.has(DEBUG_BUILD_FLAG))
.then(()=>{
    app.use(express.urlencoded({extended: true}));
    app.use(express.json());

    app.use('/chainbuilder', simulationRouter());
    app.use('/module', moduleRouter());
    app.use('/simconfig', simConfigRouter());
    app.use('*', defaultRouter);

    httpsServer.listen(config.app.port);
})
.catch((error : string)=>{
    Logger.error(`Error in startup: ${error}`);
});