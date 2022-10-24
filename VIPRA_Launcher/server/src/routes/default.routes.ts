
import express from 'express';
import { respondFail } from 'src/util/responses';

/**
 * @description Creates a router for default routes
 */
export const createDefaultRouter = () : express.Router => {

  const router = express.Router();


  router.use('/', (req, res)=>{
    respondFail('No Route', null, res);
  });

  return router;
};