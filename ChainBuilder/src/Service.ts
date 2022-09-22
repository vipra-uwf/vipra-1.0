/**
 * @modules Service
 */
import express from 'express';
import https from 'https';
import { ResultStore } from './ResultStore';
import { cbErrorRespond, cbResultRespond, cbServiceInfoRespond } from './Responses';
import { CbMethod, CbResult, CbArgs, CbServiceOptions, CbServiceInfo, CbParameters, CbReturnValue, CbArgument } from './Types';

import axios, { AxiosResponse } from 'axios';
import { Nullable, Protect } from './typedefs';

/**
 * @description ChainBuiler Service
 */
export class Service {

  private info            : CbServiceInfo;

  private parameters      : CbParameters;

  private resultStore     : ResultStore;

  private serviceMethod   : CbMethod;
  
  private methodReturn    : CbReturnValue;

  private httpsAgent      : https.Agent;

  constructor(settings : CbServiceOptions) {
    this.httpsAgent = new https.Agent({
      rejectUnauthorized: false,
    });
    this.info = settings.info;
    this.resultStore = settings.resultStore;
    this.methodReturn = settings.returnValue;
    this.parameters = { arguments:{}, server:[] };
    this.parameters.server = settings.server;
    this.setMethod(settings.arguments, settings.method);
  }

  /**
   * @description Handles a ChainBuilder request
   * @param {express.Request} request - Client Request Object
   * @param {express.Response} response - Client Response Object
   */
  public async handleRequest(request : express.Request, response : express.Response) : Promise<void> {
    if (request.method === 'GET') {
      cbServiceInfoRespond(this.info, this.parameters, [this.methodReturn], response);
      return;
    } else {
      const resultLocation = await this.runService(request);
      if (resultLocation.error) {
        cbErrorRespond(resultLocation.result, response);
        return;
      } else {
        cbResultRespond(this.methodReturn.name, `${this.resultStore.getBaseURL()}/${resultLocation.result}`, response);
        return;
      }
    }
  }

  /**
   * @description Runs the service with the parameters from the ChainBuilder Request
   * @param {express.Request} request - Client Request Object
   * @returns {CbResult} - The location of the result in the result store
   */
  private async runService(request : express.Request) : Promise<CbResult> {
    const parameters = await this.getRequestParams(request as express.Request<any, any, { [key:string]:any }>);
    if (parameters) {
      if (parameters.error) {
        return { error: true, result: parameters.error };
      } else {
        if (parameters.params) {
          const result = await this.serviceMethod(parameters.params);
          if (!result.error) {
            const location = await this.resultStore.storeResult(parameters.params, result.result);
            return location;
          }
          return result;
        }
      }
    }
    return { error: true, result: 'Unknown Error' };
  }

  /**
   * @description Takes a ChainBuilder request and gets the parameters
   * @note Parameters either come directly from the request or are requested from other Services
   * @param {express.Request} request - Client Request Object
   */
  private async getRequestParams(request : express.Request<any, any, { [key:string]:any }>) : Promise<{ error: Nullable<string>, params: Nullable<CbArgs> }> {

    const params : string[] = Object.keys(this.parameters.arguments);

    const ret : { [key: string]: string[] } = {};

    for await (const param of params) {
      if (request.query[`${param}`]) {
        ret[param] = this.normalizeParam(request.query[`${param}`]);
      } else if (request.query[`${param}_href`]) {
        const result = await this.requestChainData(this.normalizeParam(request.query[`${param}_href`]));
        if (result) {
          ret[param] =  result;
        } else {
          return { error: 'Unable to Request Data from Previous Chain', params: null };
        }
      } else if (request.body[`${param}`]) {
        ret[param] = this.normalizeParam(request.body[`${param}`]);
      } else if (request.body[`${param}_href`]) {
        const result = await this.requestChainData(this.normalizeParam(request.body[`${param}_href`]));
        if (result) {
          ret[param] =  result;
        } else {
          return { error: 'Unable to Request Data from Previous Chain', params: null };
        }
      } else {
        return {
          error: `Missing Parameter: ${param}`,
          params: null,
        };
      }
    }

    return {
      error: null,
      params: ret,
    };
  }

  /**
   * @description Makes sure that the parameters list is of the correct type
   * @param {any} param - parameters to correct
   * @returns {string[]} - The corrected parameter list
   */
  private normalizeParam(param : any) : string[] {
    if (typeof param === 'string') {
      return [param];
    } else {
      return param as string[];
    }
  }

  /**
   * @description Requests data from other ChainBuilder services
   * @param {string[]} hrefs - URLs to request data from
   */
  private async requestChainData(hrefs : string[]) : Promise<Nullable<string[]>> {
    const params : string[] = [];
    for (const link of hrefs) {
      const data : Nullable<AxiosResponse> = await axios.get(link.concat('raw/'), { httpsAgent:this.httpsAgent })
        .catch(()=>{
          return null;
        });
      if (data) {
        if (data.data) {
          params.push(JSON.stringify(data.data));
        } else {
          return null;
        }
      } else {
        return null;
      }
    }
    return params;
  }

  /**
   * @description Sets up the service method to be run, sets the return type and parameters
   * @param {CbArgument[]} args - Arguments that the method accepts
   * @param  {CbMethod} method - Method to call when running the service
   */
  private setMethod(args : CbArgument[], method : CbMethod) : void {
    args.forEach((arg)=>{
      this.parameters.arguments[arg.chain_name] = {
        chain_name: `${arg.chain_name}_href`,
        description: arg.description,
        type: arg.type,
        repeatable: arg.repeatable,
        sample: arg.sample,
      };
    });

    this.serviceMethod = method;
  }

  /**
   * @description Gets the {@link ResultStore} the service uses
   * @returns {@link ResultStore}
   */
  public getResultStore() : ResultStore {
    return this.resultStore;
  }

  /**
   * @description Returns the Key of the service
   * @returns {Protect<string>}
   */
  public getKey() : Protect<string> {
    return this.info.key;
  }
}