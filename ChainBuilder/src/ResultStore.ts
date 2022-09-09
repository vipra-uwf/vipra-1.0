/**
 * @module ResultStore
 */
import express from 'express';
import { Node } from './Node.interface';
import { cbErrorRespond, cbFormatRespond, cbRawRespond } from './Responses';
import { Nullable } from './typedefs';
import { CbArgs, CbResult } from './Types';


/**
 * @abstract
 * @description Holds Results from a {@link Service}
 */
export abstract class ResultStore implements Node {

  protected baseURL         : string;

  protected name            : string;

  protected resultName      : string;

  protected type            : string;

  abstract getResult(locationID : string) : Promise<CbResult> | CbResult;
  abstract storeResult(args : CbArgs, result : string) : Promise<CbResult> | CbResult;

  constructor(name : string) {
    this.name = name;
  }

  /**
   * @description Handles a ChainBuilder request for results
   * @param {express.Request} request - Client Request Object
   * @param {express.Response} response - Client Response Object
   */
  public async handleRequest(request : express.Request, response : express.Response) : Promise<void> {
    const resultLocation = this.getLocation(request);
    if (resultLocation.location) {
      if (resultLocation.format) {
        await this.respondResult(resultLocation.location, resultLocation.format, response);
      } else {
        this.respondFormats(resultLocation.location, response);
      }
    } else {
      cbErrorRespond('No Result at the provided Location', response);
    }
  }

  /**
   * @note only raw format is actually used in ChainBuilder
   * @description Responds to the client with the result at location
   * @param  {string} location - string that identifies a result
   * @param  {string} format - format for response
   * @param  {express.Response} response - client response object
   */
  private async respondResult(location : string, format : string, response : express.Response) : Promise<void> {
    const result = await this.getResult(location);
    if (!result.error) {
      switch (format) {
        case 'raw':
          cbRawRespond(result.result, response);
          break;
        default:
          cbErrorRespond('Incorrect Format', response);
      }
    } else {
      cbErrorRespond(result.result, response);
    }
  }

  /**
   * @note only raw is actually used in ChainBuilder
   * @description Responds to the client with the available formats for a response
   * @param  {string} location - string that identifies a result
   * @param  {express.Response} response - client response object
   */
  private respondFormats(location : string, response : express.Response) : void {
    cbFormatRespond(this.baseURL, location, ['raw'], response);
  }


  /**
   * @description Gets the Location string from a request
   * @param  {express.Request} request - Client Request Object
   * @returns {Nullable<string>} The location string, null if no location provided
   */
  private getLocation(request : express.Request) : { location : Nullable<string>, format : Nullable<string> } {
    const route : string[] = request.path.split('/').filter((value)=>{
      return value !== '';
    });
    const index : number = route.findIndex((value) => {
      if (value === `${this.name}_results`) {
        return true;
      }
    });
    if (route[index + 1]) {
      if (route[index + 2]) {
        return { location : route[index + 1], format : route[index + 2] };
      } else {
        return { location : route[index + 1], format : null };
      }
    } else {
      return { location:null, format:null };
    }
  }

  /**
   * @description Sets the Base Url of the {@link ResultStore}
   * @param  {string} url - Url to set
   */
  public setBaseURL(url : string) : void {
    this.baseURL = url;
  }

  /**
   * @description gets the URL for this {@link ResultStore}
   * @returns {string} URL
   */
  public getBaseURL() : string {
    return this.baseURL;
  }

  /**
   * @description Returns the name of this ResultStore
   * @returns {string} name of ResultStore
   */
  public getName() : string { 
    return this.name;
  }
}