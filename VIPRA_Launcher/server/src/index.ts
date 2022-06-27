import express from 'express';
import { config } from './configuration/config';
import { defaultRouter } from './routes/defaultRoutes';
import { moduleRouter } from './routes/moduleRoutes';
import { simConfigRouter } from './routes/simConfigRoutes';
import { simulationRouter } from './routes/simulationRoutes';

const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.json());

app.use('/simulation', simulationRouter);
app.use('/module', moduleRouter);
app.use('/simconfig', simConfigRouter);
app.use('*', defaultRouter);

app.listen(config.app.port);