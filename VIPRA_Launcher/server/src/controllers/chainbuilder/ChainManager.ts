import express              from 'express';
import { config } from '../../configuration/config';

import { inject, singleton }        from 'tsyringe';
import { CbArgs, CbArgument, CbResult, CbReturnValue, CbServiceInfo, CbServiceOptions, CBServiceRoot, Service } from 'typechain';
import { SimConfig }        from '../../types/simconfig';
import { FuncResult }       from '../../types/typeDefs';
import { IChainManager }    from './interfaces/ChainManager.interface';
import { Status } from '../../types/Status';
import { SimResultStore } from './resultStores/SimResultStore';
import { ISimManager } from '../simulation/interfaces/SimManager.interface';
import { IModuleController } from '../module/interfaces/ModuleController.interface';
import { Nullable } from 'typechain/dist/typedefs';
import { Module, ModuleType } from '../../types/module';
import { IFilesController } from '../files/interfaces/FilesController.interface';
import { MapsResultStore } from './resultStores/MapsResultStore';

/**
 * @description Handles Chainbuilder, creating/deleting services, routing requests etc
 */
@singleton()
export class ChainManager implements IChainManager {

  private serviceRoot : CBServiceRoot;

  private resultStore : SimResultStore;

  private simManager : ISimManager;

  private mc : IModuleController;

  private fc : IFilesController;

  private serviceMap : Map<string, { service: Service; route : string }>;

  constructor(@inject('ModuleController') moduleController : IModuleController, @inject('FilesController') fileController : IFilesController, @inject('SimManager') simManager : ISimManager) {
    this.simManager = simManager;
    this.mc = moduleController;
    this.fc = fileController;
    this.serviceMap = new Map();
    this.setupServiceRoot();
    this.setupResultStore();
    this.setupMapsService();
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
   * @description Creates a new service from a simulation configuration
   * @param {SimConfig} simconfig - sim config to create a service for
   */
  public addService(simconfig: SimConfig): FuncResult {

    const key = `${simconfig.name}${simconfig.id}`;

    const serviceInfo : CbServiceInfo = {
      name       : simconfig.name,
      description: simconfig.description,
      key,
      version    : '1.0.0.0',
      author     : simconfig.author,
      email      : simconfig.email,
      doc_href   : '',
    };

    const returnValue : CbReturnValue = {
      name: 'simresults',
      type: 'xyz',
      description: 'Results of simulation run',
    };

    const params : Nullable<CbArgument[]> = this.getParameters(simconfig);
    if (!params) {
      return { status: Status.BAD_REQUEST, message: 'Unable to get Parameters for configuration' };
    }

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
      method     : (args : CbArgs)=>{ args.configid = [simconfig.id]; return this.simManager.startSim(args);},
      server     : ['transient'],
    };
    const newService : Service = new Service(serviceOpts);
    const route : string = `services/${simconfig.name}`;

    this.serviceRoot.addService(newService, route);
    this.serviceMap.set(key, { service: newService, route });
    return { status: Status.SUCCESS, message: null };
  }

  /**
   * @description Removes the service with id
   * @param {string} id - id of simconfig to remove
   */
  public removeService(id: string): FuncResult {
    const service : Nullable<{ service: Service; route: string }> = this.serviceMap.get(id) || null;
    if (service) {
      this.serviceRoot.removeService(service.route);
      return { status: Status.SUCCESS, message: id };
    } else {
      return { status: Status.NOT_FOUND, message: null };
    }
  }

  /**
   * @description Sets up the {@link CBServiceRoot} with default values
   */
  private setupServiceRoot() : void {
    this.serviceRoot = new CBServiceRoot(`${config.cb.url}chainbuilder/`, { allowStoreSharing: true });
    this.serviceRoot.addRoute('/services');
  }
  
  /**
   * @description Sets up the {@link ResultStore} with default values
   */
  private setupResultStore() : void {
    this.resultStore = new SimResultStore('simulation', this.fc);
  }

  /**
   * @description Gets a full list of parameters needed for a config, null if error getting parameters
   * @param  {SimConfig} simconfig - config to get parameters of
   */
  private getParameters(simconfig : SimConfig) : Nullable<CbArgument[]> {
    let args : CbArgument[] = [
      {
        chain_name: 'mapID',
        type: 'string',
        description: 'Obstacle Map to run the simulation on',
        repeatable: false,
      },
      {
        chain_name: 'pedsID',
        type: 'string',
        description: '',
        repeatable: false,
      },
    ];
    // get parameters for each module
    for (const value of Object.values(ModuleType)) {
      if (simconfig[value as unknown as keyof SimConfig]) {
        const module : Nullable<Module> = this.mc.getModule(simconfig[value as unknown as keyof SimConfig] as string);
        if (module) { 
          args = args.concat(module.params.map((param)=>{
            return {
              chain_name: param.name,
              description: param.description,
              type: param.type,
              repeatable: param.multiple,
            };
          }));
        } else { 
          return null;
        }
      } else {
        return null;
      }
    }
    return args;
  }

  
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
      returnValue: { name: 'maps', type: 'string', description: 'Array Of all Maps installed on the server' },
      resultStore: new MapsResultStore('maps'),
      /**
       * @description Service method for returning maps (actual logic is in the result store)
       * @param  {{[key:string]:string[];}} args - arguments passed
       * @returns CbResult
       */
      // eslint-disable-next-line @typescript-eslint/no-unused-vars
      method: (args: { [key: string]: string[]; }): CbResult => {
        return { error: false, result: 'MAPS' };
      },
      server: [],
    };

    const service : Service = new Service(serviceOpts);
    this.serviceRoot.addService(service, '/services/maps');
  }
}