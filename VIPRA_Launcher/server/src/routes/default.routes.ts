
import express from 'express';
import { Status } from '../types/status';

/**
 * @description Creates a router for default routes
 */
export const createDefaultRouter = () : express.Router => {

  const router = express.Router();


  router.use('/', (req, res)=>{
    res.status(Status.NOT_FOUND).send('No Route');
  });

  return router;
};