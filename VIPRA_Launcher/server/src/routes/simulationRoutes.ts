import express from 'express';
import { SimManager } from '../controllers/simulation/SimManager';

import { ConfigManager } from '../controllers/simconfig/ConfigManager';

const simulationRouter = express.Router();

const configManager = ConfigManager.getInstance();
const simManager = new SimManager(configManager);

// TODO:
// Start Sim


simulationRouter.get('/:id', (req, res)=>{
    simManager.startSimWithConfig(req.params.id);
});


export {
    simulationRouter
};