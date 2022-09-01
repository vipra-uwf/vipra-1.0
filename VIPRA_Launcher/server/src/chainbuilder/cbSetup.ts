/**
 * @module TypeChain
 */

import { CbMethod, ServiceInfo, ServiceOptions, Service, CBServer, CbResult, ResultStore, CbArgs } from 'typechain';
import { config } from '../configuration/config';
// import { SimManager } from '../controllers/simulation/SimManager';
import { container } from 'tsyringe';
import { SimResultStore } from './resultStores/simResultStore';
import { ISimManager } from '../controllers/simulation/interfaces/SimManager.interface';


const simManager : ISimManager = container.resolve('SimManager');

// on creating a new config, create a new service

// save results based on the inputs



/**
 * @description CBMethod to run the simulation from a chainbuilder request
 * @param {CbArgs} args - chainbuilder args
 */
const runSim : CbMethod = async (args: CbArgs) : Promise<CbResult> => {
  return simManager.startSim(args);
};


/**
 * @description Sets up the chainbuilder simulation service
 * @param {CBServer} cbServer - chainbuilder server hosting the services
 * @param {ResultStore} resultStore - result store for holding results
 */
const setupSimulationService = (cbServer : CBServer, resultStore : ResultStore) : void => {

  const serviceInfo : ServiceInfo = {
    name: 'VIPRA_Sim',
    description: 'Service for running a VIPRA simulation',
    key: 'VIPRA_Sim12341234',
    version: '1.0.0.0',
    author: 'Rolland Goodenough',
    email: 'rtg13@students.uwf.edu',
    doc_href: 'https://vrs.chain-builder.net/',
  };

  const serviceOptions : ServiceOptions = {
    info: serviceInfo,
    parameters: [
      {
        name: 'configid',
        type: 'string',
        description: 'ID of the configuration to use to run the simulation',
        sample: 'f4ui-addv-943j-s98g',
      },
    ],
    returnValue: {
      name: 'simresults',
      type: 'string',
    },
    resultStore,
    method: runSim,
  };

  const service : Service = new Service(serviceOptions);

  cbServer.addService({
    route: 'services/simulation/',
    service,
  });
};

// TODO make sure that url is proper format -RG
/**
 * @description Creates the ChainBuilder server for handling running the simulation
 * @param {boolean} simDebug - whether the results for the simulation should be canned
 * @param {boolean} paramsDebug - whether the results for config params should be canned
 */
const setupCB = () : CBServer => {
  const cbServer : CBServer = new CBServer(`${config.cb.url}/chainbuilder/`);
  setupSimulationService(cbServer, new SimResultStore('sims'));
  return cbServer;
};

export {
  setupCB,
};