/**
 * @module CBServiceRoot
 */


import express from 'express';


import { Node } from './Node.interface';
import { Endpoint } from './Endpoint';
import { cbErrorRespond } from './Responses';
import { ResultStore } from './ResultStore';
import { Service } from './Service';
import { Nullable } from './typedefs';
import { CbRootOptions } from './Types';


/**
 * @description ChainBuilder Server that handles routing of requests to {@link Endpoint}s and their {@link Service} and/or {@link ResultStore}
 */
export class CBServiceRoot {
  private endpoints       : Map<string, Endpoint>;

  private resultStores    : Map<string, ResultStore>;

  private baseURL         : string;

  private opts            : CbRootOptions;

  constructor(baseURL : string, options? : CbRootOptions) {
    this.baseURL = this.correctURL(baseURL);
    this.endpoints = new Map();
    this.resultStores = new Map();
    this.setOptions(options);
  }

  /**
   * @description Routes a Chainbuilder Request to the proper Endpoint
   * @param {express.Request} request - Client Request Object
   * @param {express.Response} response - Client Response Object
   */
  public handleChainBuilderRequest(request : express.Request, response: express.Response) : void {
    const node : Nullable<Node> = this.getNode(request.path);
    if (node) {
      node.handleRequest(request, response)
        .catch(()=>{
          cbErrorRespond('Unknown Error Processing Request', response);
        });
    } else {
      cbErrorRespond(`No Endpoint At: ${request.originalUrl}`, response);
    }
  }

  /**
   * @description Takes a URL route and returns the endpoint it coresponds to
   * @param {string} route - URL route to get endpoint of
   * @returns {Nullable<Endpoint>} Endpoint at route, null if no endpoint
   */
  public getNode(route : string | string[]) : Nullable<Node> {
    let routeArr : string[];
    if (typeof(route) === 'string') {
      routeArr = route.split('/').filter((value)=>{
        return value !== '';
      });
    } else {
      routeArr = route;
    }
    
    const popped : Nullable<string> = routeArr.shift() || null;

    if (popped) {
      if (popped === 'data') {
        return this.getResultStore(routeArr);
      } else {
        return this.getEndpoint(popped, routeArr);
      }
    } else {
      return null;
    }
  }
  
  /**
   * @throws
   * @description Adds an empty {@link Endpoint} at the provided route
   * @note If the route has N parts, the route N-1 is created with an empty {@link Endpoint}
   * @param {string} route - Route to create
   */
  public addRoute(route : string[]) : void {
    const routeDup : string[] = Object.assign([], route);
    const root : Nullable<string> = routeDup.shift() || null;

    if (root) {
      if (root === 'data') {
        throw new Error('Routes Starting with /data are Reserved');
      }

      let startEP : Nullable<Endpoint> = this.endpoints.get(root) || null;
      if (!startEP) {
        startEP = new Endpoint(root, this.baseURL);
        this.endpoints.set(root, startEP);
      }

      startEP.addRoute(routeDup);

    } else {
      throw new Error('Attempted To Create an Empty Route');
    }
  }

  /**
   * @throws
   * @description Adds a service to the provided {@link Endpoint}, creates the {@link Endpoint} if it does not already exist
   * @note Calls {@link CBServer.addRoute}, to create route if it doesn't already exist
   * @note Each {@link Endpoint} can only have one {@link Service}
   * @param {Service} service - Service to add to the Endpoint
   * @param {string} route - Route to the Endpoint
   */
  public addService(service : Service, route : string[]) : void {
    this.addRoute(route);
    const endpoint : Nullable<Endpoint> = this.getNode(route) as Endpoint;
    if (endpoint) {
      endpoint.setService(service);
      this.addResultStore(service.getResultStore(), `${service.getResultStore().getName()}_results`);
    } else {
      throw new Error('Attempt to Add a Service to an Endpoint that doesn\'t exits');
    }
  }

  
  /**
   * @description Removes the service that resides at route
   * @param  {string} route - route of service to remove
   * @returns void
   */
  public removeService(route : string[]) : void {
    const endpoint : Nullable<Endpoint> = this.getNode(route) as Nullable<Endpoint>;
    if (endpoint) {
      endpoint.removeService();
    }
  }

  /**
   * @description Sets whether {@linke ResultStores} are allowed to be shared between services
   * @param  {boolean} allow - whether to allow sharing
   */
  public allowStoreSharing(allow : boolean) : void {
    this.opts.allowStoreSharing = allow;
  }
  
  /**
   * @throws
   * @description Adds a {@link ResultStore} to the ServiceRoot
   * @note ResultStores should not be added by themselves, they should be added with their respective {@link Service}
   * @param  {ResultStore} resultStore - ResultStore to add
   * @param  {string} name - Name of the {@link ResultStore}
   */
  private addResultStore(resultStore : ResultStore, name : string) : void {
    if (!this.resultStores.has(name)) {
      this.resultStores.set(name, resultStore);
      resultStore.setBaseURL(`${this.baseURL}data/${name}`);
    } else {
      if (!this.opts.allowStoreSharing) {
        throw new Error(`Duplicate ResultStore: ${name}`);
      }
    }
  }
  
  /**
   * @description Gets the Endpoint at the End of the provided route
   * @param  {string} root - First Endpoint in the route
   * @param  {string[]} routeArr - Subsequent Endpoints
   * @returns {Nullable<Endpoint>} The Endpoint at the provided route, null if no Endpoint
   */
  private getEndpoint(root : string, routeArr : string[]) : Nullable<Endpoint> {
    const start : Nullable<Endpoint> = this.endpoints.get(root) || null;   
    if (start) {
      return start.treeTraverse(routeArr);
    } else {
      return null;
    }
  }

  /**
   * @description Gets the result store at the route
   * @param  {string[]} routeArr - route to store
   * @returns {Nullable<ResultStore>} The ResultStore, null if one doesn't exist
   */
  private getResultStore(routeArr : string[]) : Nullable<ResultStore> {
    return this.resultStores.get(routeArr[0]) || null;
  }

  /**
   * @description Ensures that the provided URL is valid
   * @param {string} url - URL to check
   * @returns {string} The Corrected URL
   */
  private correctURL(url : string) : string {
    if (url.at(url.length - 1) !== '/') {
      return `${url}/`;
    } else {
      return url;
    }
  }

  /**
   * @description Sets the options if they are provided, default values if not
   * @param  {CbRootOptions} opts - options the client provided
   */
  private setOptions(opts? : CbRootOptions) : void {
    if (opts) {
      this.opts = opts;
    } else {
      this.opts = {};
      this.opts.allowStoreSharing = false;
    }
  }
}