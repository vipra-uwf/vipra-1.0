
import express from 'express';
// import { Config } from '../../configuration/config';

// import { CbArgs, CbArgument, CbMethod, CbResult, CbReturnValue, CbServiceInfo, CbServiceOptions, CBServiceRoot, Service } from 'typechain';
// import { EventSystem } from '../events/eventSystem';
// import { SimResultStore } from './ResultStores/simulation.resultstore';
// import { MapsResultStore } from './ResultStores/maps.resultstore';
// import { EventType, RequestType } from '../events/eventTypes';
// import { SimConfig } from '../../types/simconfig/simconfig.types';
// import { SimConfigController } from '../simconfig/simconfig.controller';
// import { ModuleParam } from '../../types/module/module.types';
// import { Nullable } from '../../types/typeDefs';
// import { SimRunner } from '../../runners/simulation/simulation.runner';
import { CBServiceRoot } from 'typechain';

/**
 * @description Handles Chainbuilder, creating/deleting services, routing requests etc
 */
export class ChainBuilderController {

  private serviceRoot : CBServiceRoot;

  //   private resultStore : SimResultStore;

  //   private serviceMap : Map<string, { service: Service; route : string }>;

  //   private evSys : EventSystem;

  //   private baseURL : string;

  //   private simRunner : SimRunner;

  //   private config : Config;

  //   constructor(config : Config, evSys : EventSystem) {
  //     this.evSys = evSys;
  //     this.config = config;
  //     this.setupServiceRoot();
  //     this.setupResultStore();
  //     this.setupMapsService();
  //     this.setupEventHandlers();
  //   }


  /**
   * @description Hands a request off to it's {@link CBServiceRoot}, for routing/hanlding
   * @param {express.Request} req - Client Request Object
   * @param {express.Response} res - Client Response Object
   */
  public handleChainBuilderRequest(req: express.Request, res: express.Response): void {
    this.serviceRoot.handleChainBuilderRequest(req, res);
  }

  //   /**
  //    * @description Registers the appropriate event handlers
  //    */
  //   private setupEventHandlers() : void {
  //     this.evSys.subscribe(EventType.NEW_SIMCONFIG, this.addService);
  //     this.evSys.subscribe(EventType.UPDATE_SIMCONFIG, this.updateService);
  //     this.evSys.subscribe(EventType.DELETE_SIMCONFIG, this.deleteService);
  //   }

  //   /**
  //    * @description Method for adding a new service from a simconfig
  //    * @param {SimConfig} simconfig - simconfig added 
  //    * @param {SimConfigController} source - source simconfig came from
  //    */
  //   private addService = async (simconfig : SimConfig) : Promise<void> => {
  //     const key = `${simconfig.name}${simconfig.id}`;

  //     const serviceInfo : CbServiceInfo = {
  //       name       : simconfig.name,
  //       description: simconfig.description,
  //       key,
  //       version    : '1.0.0.0',
  //       author     : '',
  //       email      : '',
  //       doc_href   : '',
  //     };

  //     const returnValue : CbReturnValue = {
  //       name: 'simresults',
  //       type: 'xyz',
  //       description: 'Results of simulation run',
  //     };

  //     // TODO request params, emit fail if fails
  //     const params : Nullable<CbArgument[]> = (await this.evSys.request<ModuleParam[]>(RequestType.SIM_CONFIG_PARAMS, { id: simconfig.id }))?.map((param) : CbArgument => {
  //       return {
  //         chain_name: `${param.name}_href`,
  //         description: param.description,
  //         type: param.type,
  //         repeatable: param.multiple,
  //       };
  //     }) || null;
    
  //     if (params) {
  //       const serviceOpts : CbServiceOptions = {
  //         info       : serviceInfo,
  //         arguments  : params,
  //         returnValue,
  //         resultStore: this.resultStore,
  //         /**
  //          * @description ChainBuilder Method to run for starting a simulation
  //          * @note The configid for the simconfig is not provided from ChainBuilder, but added in here
  //          * @param  {CbArgs} args - ChainBuilder Arguments
  //          */
  //         method     : this.serviceMethod(simconfig.id), // TODO
  //         server     : ['transient'],
  //       };
  //       const newService : Service = new Service(serviceOpts);
  //       const route : string = `services/${simconfig.name}`;
  
  //       this.serviceRoot.addService(newService, route);
  //       this.serviceMap.set(key, { service: newService, route });
  //     }
  //   };

  //   /**
  //    * @description Handler function for updating services
  //    * @param {SimConfig} simconfig - simconfig that was updated
  //    * @param {SimConfigController} source - source simconfig came from
  //    */
  //   private updateService = (simconfig : SimConfig, source : SimConfigController) : void => {

  //   };

  //   /**
  //    * @description Handler function for removing services
  //    * @param {SimConfig} simconfig - simconfig that was updated
  //    * @param {SimConfigController} source - source simconfig came from
  //    */
  //   private deleteService = (simconfig : SimConfig, source : SimConfigController) : void => {

  //   };

  //   /**
  //    * @description Starts the service used for getting currently installed maps
  //    */
  //   private setupMapsService() : void {
  //     const serviceInfo : CbServiceInfo = {
  //       name: 'installedMaps',
  //       description: 'Returns all installed VIPRA Maps',
  //       key: 'installedMaps_phiuavdrfpiunjavdfkjnaevuipheargpuiohn',
  //       version: '1.0.0.0',
  //       author: 'Rolland Goodenough',
  //       email: 'rtg13@students.uwf.edu',
  //       doc_href: '',
  //     };

  //     const serviceOpts : CbServiceOptions = {
  //       info: serviceInfo,
  //       arguments: [],
  //       returnValue: { name: 'maps', type: 'JSON[]', description: 'Array Of all Maps installed on the server' },
  //       resultStore: new MapsResultStore('maps'),
  //       /**
  //        * @description Service method for returning maps (actual logic is in the result store)
  //        */
  //       method: (): CbResult => {
  //         return { error: false, result: 'MAPS' };
  //       },
  //       server: [],
  //     };

  //     const service : Service = new Service(serviceOpts);
  //     this.serviceRoot.addService(service, '/services/maps');
  //   }

  //   /**
  //    * @description Sets up the {@link ResultStore} with default values
  //    */
  //   private setupResultStore() : void {
  //     this.resultStore = new SimResultStore('simulation');
  //   }
  
  //   /**
  //    * @description Sets up the {@link CBServiceRoot} with default values
  //    */
  //   private setupServiceRoot() : void {
  //     this.serviceRoot = new CBServiceRoot(`${this.baseURL}chainbuilder/`, { allowStoreSharing: true });
  //     this.serviceRoot.addRoute('/services');
  //   }

  //   /**
  //    * @description Creates the service function for a given config
  //    * @param {string} id - simconfig id
  //    */
  //   private serviceMethod(id : string) : CbMethod {
  //     return (args : CbArgs) : Promise<CbResult> => {

  //       const map : Nullable<string> = args.map[0];
      
//       if (map) {
//         //this.simRunner.runSim(id);
//       }
//     };
//   }
}