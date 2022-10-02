
import express from 'express';
import { Logger } from '../controllers/logging/logger';
import { BaseController } from '../controllers/base.controller';
import { respondUnknownError, switchCreateResponse, switchDataResponse, switchDeleteResponse } from '../util/responses';
import { OperationResult } from 'src/types/typeDefs';


/**
 * @description Creates a router that handles Operations on a DataType
 * @param {BaseController} controller - Controller for datatype
 * @param {BaseService} service - Service for datatype
 * @param {BaseRepo} repo - repo for datatype
 * @param {Logger} logger - logger
 */
const createRouter = <DataType>(logger : Logger, controller : BaseController<DataType>) : express.Router => {

  /**
   * @description Logs an error for a given route
   * @param {string} route - route error occured
   * @param {unknown} error - error
   */
  const logRouteError = (route : string, error : unknown) : void => {
    logger.error(`${route} ERROR: ${error as string}`);
  };

  const router = express.Router();

  router.get('/', (req : express.Request, res : express.Response) => {
    controller.getAll()
      .then((result)=>{
        switchDataResponse(result, res);
      })
      .catch((error : unknown)=>{
        logRouteError(`${typeof controller}::getall()`, error);
        respondUnknownError(res);
      });
  });
  
  router.get('/:id', (req : express.Request, res : express.Response) => {
    controller.get(req)
      .then((result)=>{
        switchDataResponse(result, res);
      })
      .catch((error : unknown) => {
        logRouteError(`${typeof controller}::get()`, error);
        respondUnknownError(res);
      });  
  });
  
  router.post('/', (req : express.Request, res : express.Response) => {
    controller.create(req)
      .then((result : OperationResult<DataType>) => {
        switchCreateResponse(result, res);
      })
      .catch((error : unknown) => {
        logRouteError(`${typeof controller}::create()`, error);
        respondUnknownError(res);
      });  
  });
  
  router.put('/:id', (req : express.Request, res : express.Response) => {
    controller.update(req)
      .then((result)=>{
        switchCreateResponse(result, res);
      })
      .catch((error : unknown) =>{
        logRouteError(`${typeof controller}::update()`, error);
        respondUnknownError(res);
      });
  });
  
  router.delete('/:id', (req : express.Request, res : express.Response) => {
    controller.delete(req)
      .then((result)=>{
        switchDeleteResponse(result, res);
      })
      .catch((error : unknown) =>{
        logRouteError(`${typeof controller}::delete()`, error);
        respondUnknownError(res);
      });
  });


  return router;
};


export {
  createRouter,
};