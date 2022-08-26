/**
 * @module Routes
 */
import express from 'express';
import { setupCB } from '../chainbuilder/cbSetup';
import { CBServer } from 'typechain';
import { FLAGS } from '../types/flags';
/**
 * @description Creates the router that handles routes pertaining to the VIPRA simulation
 *
 * @note router factory functions are used to ensure that the objects are made at the correct time -RG
 *
 * @param  {Map<string, string>} argv - Map containing the commandline flags and their values
 */
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
  simulationRouter,
};