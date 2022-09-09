import express              from 'express';
import { config } from '../../configuration/config';

import { inject, singleton }        from 'tsyringe';
import { CbArgs, CbParameter, CbReturnType, CbServiceInfo, CbServiceOptions, CBServiceRoot, Service } from 'typechain';
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

  constructor(@inject('ModuleController') moduleController : IModuleController, @inject('FilesController') fileController : IFilesController, @inject('SimManager') simManager : ISimManager) {
    this.simManager = simManager;
    this.mc = moduleController;
    this.fc = fileController;
    this.setupServiceRoot();
    this.setupResultStore();
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
  public addNewService(simconfig: SimConfig): FuncResult {

    const serviceInfo : CbServiceInfo = {
      name       : simconfig.name,
      description: simconfig.description,
      key        : `${simconfig.name}${simconfig.id}`,
      version    : '1.0.0',
      author     : simconfig.author,
      email      : simconfig.email,
      doc_href   : '',
    };

    const returnType : CbReturnType = {
      name: 'simresults',
      type: 'xyz',
    };

    const params : Nullable<CbParameter[]> = this.getParameters(simconfig);
    if (!params) {
      return { status: Status.BAD_REQUEST, message: 'Unable to get Parameters for configuration' };
    }

    const serviceOpts : CbServiceOptions = {
      info       : serviceInfo,
      parameters : params,
      returnValue: returnType,
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

    this.serviceRoot.addService(newService, `services/${simconfig.name}`);
    return { status: Status.SUCCESS, message: null };
  }

  /**
   * @description Removes the service with id
   * @param {string} id - id of simconfig to remove
   */
  public removeService(id: string): FuncResult {
    // TODO
    return { status: Status.SUCCESS, message: id };
  }

  /**
   * @description Sets up the {@link CBServiceRoot} with default values
   */
  private setupServiceRoot() : void {
    this.serviceRoot = new CBServiceRoot(config.cb.url, { allowStoreSharing: true });
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
  private getParameters(simconfig : SimConfig) : Nullable<CbParameter[]> {
    let params : CbParameter[] = [
      {
        name: 'mapID',
        type: 'string',
        description: 'Obstacle Map to run the simulation on',
        repeatable: false,
      },
      {
        name: 'pedsID',
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
          params = params.concat(module.params);
        } else { 
          return null;
        }
      } else {
        return null;
      }
    }
    return params;
  }
}