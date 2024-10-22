/**
 * @module Responses
 */

import express from 'express';
import { Link } from './internalTypes';
import { CbParameters, CbResponses, CbReturnValue, CbServiceInfo } from './Types';

/**
 * @description Sends a Response with {@link Link}s from an {@link Endpoint}
 * @param {Link[]} links - Array of {@link Link}s 
 * @param {express.Response} res - Client Response Object
 */
const cbLinksRespond = (links : Link[], res : express.Response) : void =>{
  res.setHeader('Content-Type', 'text/json;charset=UTF-8');
  res.status(200).json({
    links,
    status: 'success',
  });
};

/**
 * @description Sends a Response with URL to the results of a Service Run
 * @param {string} resultName - Name of the result
 * @param {string} result - The URL to the result
 * @param {express.Response} response - Client Response Object
 */
const cbResultRespond = (resultName : string, result : string, response : express.Response) : void => {
  response.status(200).json({
    data: {
      [resultName]: {
        'href': result,
      },
    },
    status: 'success',
  });
};

/**
 * @description Responds to ChainBuidler with the result
 * @param {string} result - plain string of result
 * @param {express.Response} response - Client Response Object
 */
const cbRawRespond = (result : string, response : express.Response) : void => {
  response.status(200).send(result);
};

/**
 * @description Responds to ChainBuilder with the formats a result is available in
 * @param {string} resultName - name of result
 * @param {string} baseHref - Base URL of the {@link ResultStore} where the result is stored
 * @param {string} resultHash - Location of result in the {@link ResultStore}
 * @param {string[]} formats - The formats available
 * @param {express.Response} response - Client Response Object
 */
const cbFormatRespond = (baseHref : string, resultHash : string, formats : string[], response : express.Response) : void => {
  response.status(200).json({
    methods:['DELETE'],
    links: formats.map((format)=>{
      return { 'href': `${baseHref}/${resultHash}/${format}` };
    }),
    status: 'success',
  });
};

/**
 * @description Responds to Chainbuilder that there was an error
 * @param {string} message - Error message
 * @param {express.Response} response - Client Response Object
 */
const cbErrorRespond = (message : string, response : express.Response) : void => {
  response.statusCode = 200;
  response.json({
    'status': 'error',
    message,
  });
};

/**
 * @description Responds with a {@link Service}'s info
 * @param {CbServiceInfo} info - Service information
 * @param {CbParameter} parameters - Parameters the {@link Service} takes
 * @param {CbResponse} response - Result Response information
 * @param {CbServerOptions[]} server - Server options
 * @param {express.Response} res - Client Response Object
 */
const cbServiceInfoRespond = (info : CbServiceInfo, parameters : CbParameters, response : CbReturnValue[], res : express.Response) : void => {

  const responses : CbResponses = {};

  response.forEach((resp)=>{
    responses[resp.name] = {
      description: resp.description,
      type: resp.type,
    };
  });

  res.send(JSON.stringify({
    info,
    methods:['GET', 'POST'],
    status: 'success',
    parameters,
    responses,
  }));
};

export {
  cbErrorRespond,
  cbLinksRespond,
  cbServiceInfoRespond,
  cbResultRespond,
  cbFormatRespond,
  cbRawRespond,
};