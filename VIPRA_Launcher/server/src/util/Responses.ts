/**
 * @module Responses
 */

import express from 'express';
import { Status } from '../types/Status';
/**
 * @description Responds to client that an unknown error has occured
 * Status: 500
 *
 * @param  {express.Response} response - client response object
 */
const respondUnknownError = (response : express.Response) : void => {
  response.status(Status.INTERNAL_ERROR).json({ error: 'Unknown Error', detail: 'An Unknown error occured, Action may not have completed successfully' });
};

/**
 * @description Responds to client that an error has occured, specified with code, error, and detail
 *
 * @param  {Status} code - Status of response
 * @param  {string} error - short error
 * @param  {string} detail - long error detail
 * @param  {express.Response} response - client response object
 */
const respondError = (code : Status, error : string, detail : string, response : express.Response) : void => {
  response.status(code).json({
    error,
    detail,
  });
};

/**
 * @description Responds with status 401, that the resource was created
 *
 * @param  {express.Response} response - client response object
 */
const respondCreated = (response : express.Response) : void => {
  response.status(Status.CONFLICT).json({});
};

/**
 * @description Responds that the action was successful, with optional message
 * Status: 200
 *
 * @param  {express.Response} response - client response obejct
 * @param  {string?} message - optional message to be sent to client
 */
const respondSuccess = (response : express.Response, message? : string) : void => {
  if (message) {
    response.status(Status.SUCCESS).json({});
  } else {
    response.status(Status.SUCCESS).json({ message });
  }
};

// this works for now, need to change later -RG
/**
 * @description Responds status 200 with data in body
 *
 * @param  {any} data - data obejct to be place in response
 * @param  {express.Response} response - client response object
 */
const respondData = (data : any, response : express.Response) : void => {
  // eslint-disable-next-line @typescript-eslint/no-unsafe-assignment
  response.status(Status.SUCCESS).json({ data });
};

export {
  respondUnknownError,
  respondError,
  respondSuccess,
  respondCreated,
  respondData,
};