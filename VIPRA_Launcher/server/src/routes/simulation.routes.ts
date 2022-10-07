import express from 'express';
import { ChainBuilderController } from '../controllers/chainbuilder/chainbuilder.controller';


/**
 * @description Sets up routes for simulations
 * @param {ChainBuilderController} cbController - ChainBuilder Controller
 */
export const createSimRouter = (cbController : ChainBuilderController) : express.Router => {
  const router = express.Router();

  router.use('/chainbuilder', (req, res)=>{
    cbController.handleChainBuilderRequest(req, res);
  });

  return router;
};