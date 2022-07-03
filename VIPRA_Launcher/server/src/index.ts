import express from 'express';
import https from 'https';
import cors from 'cors';

import { config } from './configuration/config';
import { initialSetup } from './configuration/setup';
import { defaultRouter } from './routes/defaultRoutes';
import { moduleRouter } from './routes/moduleRoutes';
import { simConfigRouter } from './routes/simConfigRoutes';
import { simulationRouter } from './routes/simulationRoutes';
import { compileGenMain } from './util/Processes';


const app = express();
const httpsServer = https.createServer(config.app.https, app);

initialSetup();

compileGenMain()
.catch((error : string) => {
    throw new Error(`Unable to compile generate_main : ${error}`);
});

app.use(express.urlencoded({extended: true}));
app.use(express.json());

app.use('/chainbuilder', simulationRouter());
app.use('/module', moduleRouter());
app.use('/simconfig', simConfigRouter());
app.use('*', defaultRouter);

httpsServer.listen(config.app.port);
