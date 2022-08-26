/**
 * @module Routes
 */
import express from 'express';

import { Status }       from '../types/Status';
import { respondError } from '../util/Responses';

const defaultRouter = express.Router();


defaultRouter.use('*', (req, res)=>{
  respondError(Status.NOT_FOUND, 'No Route', `There is no route at: ${req.originalUrl}`, res);
});


export {
  defaultRouter,
};