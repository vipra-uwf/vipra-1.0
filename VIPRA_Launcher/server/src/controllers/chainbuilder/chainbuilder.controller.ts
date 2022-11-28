
import express from 'express';
import { Config } from '../../configuration/config';

import { CbArgs, CbArgument, CbMethod, CbResult, CbReturnValue, CbServiceInfo, CbServiceOptions, CBServiceRoot, Service } from 'typechain';
import { EventSystem } from '../events/eventSystem';
import { SimResultStore } from './ResultStores/simulation.resultstore';
import { MapsResultStore } from './ResultStores/maps.resultstore';
import { EventHandler, EventType, RequestType } from '../events/eventTypes';
import { SimConfig } from '../../types/simconfig/simconfig.types';
import { ModuleParam } from '../../types/module/module.types';
import { Nullable } from '../../types/typeDefs';
import { ISimController } from '../simulation/interfaces/simulation.controller.interface';

/**
 * @description Handles Chainbuilder, creating/deleting services, routing requests etc
 */
export class ChainBuilderController {

  private serviceRoot : CBServiceRoot;

  private resultStore : SimResultStore;

  private serviceMap : Map<string, { service: Service; route : string }>;

  private evSys : EventSystem;

  private baseURL : string;

  private config : Config;

  private simController : ISimController;

  constructor(config : Config, simController : ISimController, evSys : EventSystem) {
    this.evSys = evSys;
    this.config = config;
    this.baseURL = `${config.app.baseURL}/simulation/`;
    this.simController = simController;
    this.setupServiceRoot();
    this.setupResultStore();
    this.setupMapsService();
    this.setupEventHandlers();
  }


  /**
   * @description Hands a request off to it's {@link CBServiceRoot}, for routing/hanlding
   * @param {express.Request} req - Client Request Object
   * @param {express.Response} res - Client Response Object
   */
  public handleChainBuilderRequest(req: express.Request, res: express.Response): void {
    this.serviceRoot.handleChainBuilderRequest(req, res);
  }

  /**
   * @description Registers the appropriate event handlers
   */
  private setupEventHandlers() : void {
    this.evSys.subscribe(EventType.NEW, 'SimConfig', this.addService);
    this.evSys.subscribe(EventType.UPDATE, 'SimConfig', this.updateService);
    this.evSys.subscribe(EventType.DELETE, 'SimConfig', this.deleteService);
  }

  /**
   * @description Method for adding a new service from a simconfig
   * @param {SimConfig} simconfig - simconfig added 
   * @param {SimConfigController} source - source simconfig came from
   */
  private addService = async (simconfig : SimConfig) : Promise<void> => {
    const key = `${simconfig.name}${simconfig.id}`;

    const serviceInfo : CbServiceInfo = {
      name       : simconfig.name,
      description: simconfig.description,
      key,
      version    : '1.0.0.0',
      author     : '',
      email      : '',
      doc_href   : '',
    };

    const returnValue : CbReturnValue = {
      name: 'simresults',
      type: 'xyz',
      description: 'Results of a simulation run',
    };

    const params : Nullable<CbArgument[]> = (await this.evSys.request<ModuleParam[]>(RequestType.DATA, 'SimConfigParams', { id: simconfig.id }))?.map((param) : CbArgument => {
      return {
        chain_name: `${param.name}_href`,
        description: param.description,
        type: param.type,
        repeatable: param.multiple,
      };
    }) || null;
    
    if (params) {
      const serviceOpts : CbServiceOptions = {
        info       : serviceInfo,
        arguments  : params,
        returnValue,
        resultStore: this.resultStore,
        /**
         * @description ChainBuilder Method to run for starting a simulation
         * @note The configid for the simconfig is not provided from ChainBuilder, but added in here
         * @param  {CbArgs} args - ChainBuilder Arguments
         */
        method     : this.serviceMethod(simconfig.id),
        server     : ['transient'],
      };
      const newService : Service = new Service(serviceOpts);
      const route : string = `services/${simconfig.name}`;
  
      this.serviceRoot.addService(newService, ['services', simconfig.name]);
      this.serviceMap.set(key, { service: newService, route });
    } else {
      void this.evSys.emit<SimConfig>(EventType.FAIL, 'SimConfig', simconfig);
    }
  };

  /**
   * @description Handler function for updating services
   * @param {SimConfig} simconfig - simconfig that was updated
   * @param {SimConfigController} source - source simconfig came from
   */
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  private updateService : EventHandler = (simconfig : SimConfig) : void => {
    throw new Error('Not Implemented');
  };

  /**
   * @description Handler function for removing services
   * @param {SimConfig} simconfig - simconfig that was updated
   * @param {SimConfigController} source - source simconfig came from
   */
  // eslint-disable-next-line @typescript-eslint/no-unused-vars
  private deleteService : EventHandler = (simconfig : SimConfig) : void => {
    throw new Error('Not Implemented');
  };

  /**
   * @description Starts the service used for getting currently installed maps
   */
  private setupMapsService() : void {
    const serviceInfo : CbServiceInfo = {
      name: 'installedMaps',
      description: 'Returns all installed VIPRA Maps',
      key: 'installedMaps_phiuavdrfpiunjavdfkjnaevuipheargpuiohn',
      version: '1.0.0.0',
      author: 'Rolland Goodenough',
      email: 'rtg13@students.uwf.edu',
      doc_href: '',
    };

    const serviceOpts : CbServiceOptions = {
      info: serviceInfo,
      arguments: [],
      returnValue: { name: 'maps', type: 'JSON[]', description: 'Array Of all Maps installed on the server' },
      resultStore: new MapsResultStore('maps', this.evSys),
      /**
       * @description Service method for returning maps (actual logic is in the result store)
       */
      method: (): CbResult => {
        return { error: false, result: 'MAPS' };
      },
      server: [],
    };

    const service : Service = new Service(serviceOpts);
    this.serviceRoot.addService(service, ['services', 'maps']);
  }

  /**
   * @description Sets up the {@link ResultStore} with default values
   */
  private setupResultStore() : void {
    this.resultStore = new SimResultStore('simulation');
  }
  
  /**
   * @description Sets up the {@link CBServiceRoot} with default values
   */
  private setupServiceRoot() : void {
    this.serviceRoot = new CBServiceRoot(`${this.baseURL}/chainbuilder`, { allowStoreSharing: true });
    this.serviceRoot.addRoute(['services']);
  }

  /**
   * @description Creates the service function for a given config
   * @param {string} id - simconfig id
   */
  private serviceMethod(id : string) : CbMethod {
    return async (args : CbArgs) : Promise<CbResult> => {
      const mapID : Nullable<string> = args.map[0] || null;
      const pedID : Nullable<string> = args.peds[0] || null;
      if (mapID && pedID) {
        const result = await this.simController.startSim(id, mapID, pedID, args);
        if (result) {
          return { error: false, result };
        } else {
          return { error: true, result: 'Error Running Simulation' };
        }
      } else {
        return { error: true, result: 'Missing Parameters' };
      }
    };
  }
}