import express from 'express';
import https from 'https';

import { config } from './configuration/config';
import { initialSetup } from './configuration/setup';
import { Logger } from './logging/Logging';
import { defaultRouter } from './routes/defaultRoutes';
import { moduleRouter } from './routes/moduleRoutes';
import { simConfigRouter } from './routes/simConfigRoutes';
import { simulationRouter } from './routes/simulationRoutes';


// TODO add installing map files -RG

// TODO !!! add initial installation that finds vipra folder -RG

const app = express();
const httpsServer = https.createServer(config.app.https, app);

initialSetup()
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
    Logger.error(`Error in initialSetup: ${error}`);
});