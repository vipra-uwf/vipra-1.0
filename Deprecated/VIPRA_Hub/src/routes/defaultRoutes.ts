import express from 'express';
import { Status } from '../data_models/Status';
import { RespondError } from '../util/Responses';


const defaultRouter = express.Router();

defaultRouter.use('*', (req, res) =>{
    RespondError(Status.NOT_FOUND, 'No Route', `There is no route at: ${req.method} ${req.originalUrl}`, res);
});

export {
    defaultRouter
};