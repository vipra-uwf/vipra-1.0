import express from 'express';
import { setupCB } from '../chainbuilder/cbSetup';
import { CBServer } from 'typechain';

const simulationRouter = () : express.Router => {
    const simRoutes = express.Router();

    const cbServer : CBServer = setupCB();

    simRoutes.use('/', (req : express.Request, res : express.Response)=>{
        req.originalUrl = req.url;
        // TODO find out why eslint is complaining about this -RG
        // eslint-disable-next-line @typescript-eslint/no-unsafe-call
        cbServer.handleChainBuilderRequest(req, res);
    });

    return simRoutes;
};


export {
    simulationRouter
};