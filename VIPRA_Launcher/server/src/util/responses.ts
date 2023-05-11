import express from 'express';
import { OperationResult } from '../types/typeDefs';

import { Status } from '../types/status';
import { Logger } from '../controllers/logging/logger';


/**
 * @description Responds with a successful status
 * @param {string} message - message to send with response
 * @param {express.Response} response - client response object
 */
const respondSuccess = (message : string, response : express.Response) : void => {
  response.status(Status.SUCCESS).send(message);
};


/**
 * @description Responds with JSON data
 * @param {unknown} data - data to send to client
 * @param {express.Response} response - client response object
 */
const respondData = (data : unknown, response : express.Response) : void => {
  response.status(Status.SUCCESS).json({
    status: 'success',
    data,
  });
};

/**
 * @description Responds that an unknown error occured
 * @param {express.Response} response - client response object
 */
const respondUnknownError = (response : express.Response) : void => {
  response.status(Status.SUCCESS).json({
    status: 'error',
    message: 'Unknown Error Occurred',
  });
};

/**
 * @description Responds that the operation failed due to user input
 * @param {string} reason - reason for fail
 * @param {unknown} data - any message/data to send to client
 * @param {express.Response} response - client response object
 */
const respondFail = (reason : string, data : unknown, response : express.Response) : void => {
  response.status(Status.SUCCESS).json({
    status: 'fail',
    reason,
    data,
  });
};

/**
 * @description Responds that an error occurred, not due to user input
 * @param {string} message - message describing error
 * @param {express.Response} response - client response object
 */
const respondError = (message : string, response : express.Response) : void => {
  response.status(Status.SUCCESS).json({
    status: 'error',
    message,
  });
};


/**
 * @description Takes an Operation Result For a Data request, responds with the proper response for the status of the Operation Result
 * @param {OperationResult<unknown>} result - Result of a data request
 * @param {express.Response} response - client response object
 */
const switchDataResponse = (result : OperationResult<unknown>, response : express.Response) : void => {
  switch (result.status) {
    case Status.SUCCESS:
      respondData(result.object, response);
      break;
    case Status.FORBIDDEN:
      respondFail('Forbidden', {}, response);
      break;
    case Status.UNAUTHORIZED:
      respondFail('Not Authorized', {}, response);
      break;
    case Status.BAD_REQUEST:
      respondFail('Bad Request', {}, response);
      break;
    case Status.NOT_FOUND:
      respondFail('Not Found', {}, response);
      break;
    case Status.INTERNAL_ERROR:
      respondUnknownError(response);
      break;    
  }
};

/**
 * @description Takes an Operation Result For a Create request, responds with the proper response for the status of the Operation Result
 * @param {OperationResult<unknown>} result - Result of a create request
 * @param {express.Response} response - client response object
 */
const switchCreateResponse = (result : OperationResult<unknown>, response : express.Response) : void => {
  switch (result.status) {
    case Status.SUCCESS:
      Logger.warn('Create Request Resulted in SUCCESS status when CREATED should be used!');
      respondData(result.object, response);
      break;
    case Status.CREATED:
      respondData(result.object, response);
      break;
    case Status.FORBIDDEN:
      respondFail('Forbidden', {}, response);
      break;
    case Status.UNAUTHORIZED:
      respondFail('Not Authorized', {}, response);
      break;
    case Status.BAD_REQUEST:
      respondFail('Bad Request', {}, response);
      break;
    case Status.CONFLICT:
      respondFail('Conflict', { data: result.object }, response);
      break;
    case Status.INTERNAL_ERROR:
      respondUnknownError(response);
      break;
  }
};

/**
 * @description Takes an Operation Result For a Delete request, responds with the proper response for the status of the Operation Result
 * @param {OperationResult<unknown>} result - Result of a delete request
 * @param {express.Response} response - client response object
 */
const switchDeleteResponse = (result : OperationResult<unknown>, response : express.Response) : void => {
  switch (result.status) {
    case Status.SUCCESS:
      respondData(result.object, response);
      break;
    case Status.FORBIDDEN:
      respondFail('Forbidden', {}, response);
      break;
    case Status.UNAUTHORIZED:
      respondFail('Not Authorized', {}, response);
      break;
    case Status.NOT_FOUND:
      respondFail('Not Found', {}, response);
      break;
    case Status.BAD_REQUEST:
      respondFail('Bad Request', {}, response);
      break;
    case Status.CONFLICT:
      respondFail('Conflict', { conflict: result.object }, response);
      break;
    case Status.INTERNAL_ERROR:
      respondUnknownError(response);
      break;    
  }
};

export {
  switchDataResponse,
  switchCreateResponse,
  switchDeleteResponse,
  respondSuccess,
  respondData,
  respondUnknownError,
  respondError,
  respondFail,
};