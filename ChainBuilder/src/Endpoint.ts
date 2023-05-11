/**
 * @module Endpoint
 */

import express from 'express';
import { Node } from './Node.interface';
import { cbErrorRespond, cbLinksRespond } from './Responses';

import { Service } from './Service';
import { Nullable, Protect } from './typedefs';
import { Link } from './internalTypes';

/**
 * @description Node in a ChainBuilder Service tree, can hold a {@link Service} and/or a {@link ResultStore}
 */
export class Endpoint implements Node {

  private name        : string;

  private href        : string;

  private links       : Map<string, Endpoint>;

  private service     : Nullable<Service>;

  constructor(name : string, baseHref : string) {
    if (name === '') {
      throw new Error('Endpoint names cannot be empty');
    }
    this.name = name;
    this.service = null;
    this.href = `${baseHref}${name}/`;
    this.links = new Map();
  }

  /**
   * @description Adds the first string in route as an child {@link Endpoint} off of this, then calls addRoute on the created {@link Endpoint}
   * @param  {string[]} route - route to be added
   */
  public addRoute(route : string[]) : void {
    if (route.length > 0) {
      const root : Nullable<string> = route.shift() || null;
      if (root) {
        let startEP : Nullable<Endpoint> = this.links.get(root) || null;
        if (!startEP) {
          startEP = new Endpoint(root, this.href);
          this.links.set(root, startEP);
        }

        startEP.addRoute(route);
      } else {
        throw new Error('Error Adding Route');
      }
    }
  }

  /**
   * @description Takes a ChainBuilder Request and Responds accordingly
   * Either by running it's {@link Service},
   * or Providing it's Children {@link Endpoint}s
   * @param {express.Request} request - Client Request Object
   * @param {express.Response} response - Client Response Object
   */
  public async handleRequest(request : express.Request, response : express.Response) : Promise<void> {
    if (this.service) {
      await this.service.handleRequest(request, response)
        .catch(()=>{
          cbErrorRespond('Unknown Error Handling Request', response);
        });
    } else {
      cbLinksRespond(this.getLinks(), response);
    }
  }

  /**
   * @description Sets the {@link Endpoint}'s {@link Service}
   * @note Each {@link Endpoint} Can only have ONE {@link Service}, using this method will Overwrite the {@link Endpoint}'s {@link Service} if it has one
   * @param {Service} service - Service to add to the {@link Endpoint}
   */
  public setService(service : Service) : void {
    this.service = service;
  }

  
  /**
   * @description Removes the service from the endpoint
   * @returns void
   */
  public removeService() : void {
    this.service = null;
  }


  /**
   * @description Traverses the given route, returning the {@link Endpoint} at the end
   * @param {string[]} route - URL Route split by '/'
   * @returns {Nullable<Endpoint>} - The {@link Endpoint} at the end of the given route, null if no {@link Endpoint} exists at that route
   */
  public treeTraverse(route : string[]) : Nullable<Endpoint> {
    const popped : Nullable<string> = route.shift() || null;

    if (popped) {
      if (popped === '' || popped.includes('?')) {
        return this;
      }
      const next = this.links.get(popped);
      if (next) {
        return next.treeTraverse(route);
      } else {
        return null;
      }
    } else {
      return this;
    }
  }

  /**
   * @description Returns the {@link Endpoint}'s {@link Service} as a ReadOnly Object
   * @returns {Protect<Nullable<Service>>} the {@link Endpoint}'s {@link Service}
   */
  public getService() : Protect<Nullable<Service>> {
    return this.service;
  }

  /**
   * @description Gets the {@link Enpoint}'s Children {@link Endpoint}s as {@link Link}s
   * @returns {Link[]} Array of Children {@link Endpoint}s as {@link Link}s
   */
  public getLinks() : Link[] {
    const links : Link[] = [];
    for (const [name, endpoint] of this.links.entries()) {
      links.push({
        name,
        href: endpoint.getHref(),
      });
    }
    return links;
  }

  /**
   * @description Gets the Full URL for this {@link Endpoint}
   * @returns {Protect<string>} Full URL for this {@link Endpoint}
   */
  public getHref() : Protect<string> {
    return this.href;
  }

  /**
   * @description Gets the Name of this {@link Endpoint}
   * @returns {Protect<string>} The Name of this {@link Endpoint}
   */
  public getName() : Protect<string> {
    return this.name;
  }
}