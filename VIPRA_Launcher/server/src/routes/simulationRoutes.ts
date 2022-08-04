import express from 'express';
import { setupCB } from '../chainbuilder/cbSetup';
import { CBServer } from 'typechain';
import { FLAGS } from '../data_models/flags';

const simulationRouter = (argv: Map<string, string>) : express.Router => {
    const simRoutes = express.Router();

    const cbServer : CBServer = setupCB(argv.has(FLAGS.DEBUG_RESULTS), argv.has(FLAGS.DEBUG_PARAMS));

    simRoutes.use('/', (req : express.Request, res : express.Response)=>{
        req.originalUrl = req.url;
        cbServer.handleChainBuilderRequest(req, res);
    });

    return simRoutes;
};


export {
    simulationRouter
};