/**
 * @module Routes
 */
import express           from 'express';
import { IChainManager } from '../controllers/chainbuilder/interfaces/ChainManager.interface';

/**
 * @description Creates the router that handles routes pertaining to the VIPRA simulation
 *
 * @note router factory functions are used to ensure that the objects are made at the correct time -RG
 *
 * @param  {IChainManager} chainManager - ChainBuilder manager implementation
 */
const simulationRouter = (chainManager : IChainManager) : express.Router => {
  const simRoutes = express.Router();

  simRoutes.use('/', (req : express.Request, res : express.Response)=>{
    chainManager.handleChainBuilderRequest(req, res);
  }); 

  return simRoutes;
};


export {
  simulationRouter,
};