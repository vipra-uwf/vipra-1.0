/**
 * @module TypeChain
 */

import { CbMethod, ServiceInfo, ServiceOptions, Service, CBServer, CbResult, ResultStore, CbArgs } from 'typechain';
import { SimResultStore } from './resultStores/simResultStore';
import { config } from '../configuration/config';
import { SimManager } from '../controllers/simulation/SimManager';
import { SimParamStore } from './resultStores/simParamStore';
import { TestResultStore } from './resultStores/testResultStore';
import { container } from 'tsyringe';

/* eslint-disable */

// TODO make sure that url is proper format -RG
/**
 * @description Creates the ChainBuilder server for handling running the simulation
 * @param {boolean} simDebug - whether the results for the simulation should be canned
 * @param {boolean} paramsDebug - whether the results for config params should be canned
 */
const setupCB = (simDebug : boolean, paramsDebug : boolean) : CBServer => {
    const cbServer : CBServer = new CBServer(`${config.cb.url}/chainbuilder/`);

    setupSimulationService(cbServer, simResultStore(simDebug));
    setupParamsService(cbServer, paramsStore(paramsDebug));

    return cbServer;
};

/**
 * 
 */
const runSim : CbMethod = async (args: CbArgs) : Promise<CbResult> => {
    const simManager = container.resolve(SimManager);
    return await simManager.startSim(args);
};

/**
 *
 * @param debug
 */
const simResultStore = (debug : boolean) : ResultStore => {
    if(debug){
        return new TestResultStore("simresults");
    }else{
        return new SimResultStore("simresults");
    }
};

/**
 *
 * @param debug
 */
const paramsStore = (debug : boolean) : ResultStore => {
    if(debug){
        return new TestResultStore("simparams");
    }else{
        return new SimParamStore("simparams");
    }
};

/**
 *
 * @param cbServer
 * @param resultStore
 */
const setupSimulationService = (cbServer : CBServer, resultStore : ResultStore) => {

    const serviceInfo : ServiceInfo = {
        name: 'VIPRA_Sim',
        description: 'Service for running a VIPRA simulation',
        key: 'VIPRA_Sim12341234',
        version: '1.0.0.0',
        author: 'Rolland Goodenough',
        email: 'rtg13@students.uwf.edu',
        doc_href: 'https://vrs.chain-builder.net/'
    };

    const serviceOptions : ServiceOptions = {
        info: serviceInfo,
        parameters: [
            {
                name: 'configid',
                type: 'string',
                description: 'ID of the configuration to use to run the simulation',
                sample: 'f4ui-addv-943j-s98g'
            }
        ],
        returnValue: {
            name: 'simresults',
            type: 'string'
        },
        resultStore,
        method: runSim
    };

    const service : Service = new Service(serviceOptions);

    cbServer.addService({
        route: "services/simulation/",
        service
    });
};

/**
 *
 */
const getParams : CbMethod = async (args: CbArgs) : Promise<CbResult> => {
    const simManager = container.resolve(SimManager);
    const params = await simManager.getParams(args);
    return params;
};

/**
 *
 * @param cbServer
 * @param resultStore
 */
const setupParamsService = (cbServer : CBServer, resultStore : ResultStore) => {
    const serviceInfo : ServiceInfo = {
        name: 'VIPRA_Config_Params',
        description: 'Service for getting parameters for a VIPRA simulation configuration',
        key: 'VIPRA_Config_Params12341234',
        version: '1.0.0.0',
        author: 'Rolland Goodenough',
        email: 'rtg13@students.uwf.edu',
        doc_href: 'https://vrs.chain-builder.net/'
    };

    const serviceOptions : ServiceOptions = {
        info: serviceInfo,
        parameters: [
            {
                name: 'configid',
                type: 'string',
                description: 'ID of the configuration to get parameters for',
                sample: 'f4ui-addv-943j-s98g'
            }
        ],
        returnValue: {
            name: 'simparams',
            type: 'string'
        },
        resultStore,
        method: getParams
    };

    const service : Service = new Service(serviceOptions);

    cbServer.addService({
        route: "services/simparams/",
        service
    });
};

export {
    setupCB
};