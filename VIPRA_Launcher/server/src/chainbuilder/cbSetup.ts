
import { CbMethod, ServiceInfo, ServiceOptions, Service, CBServer } from 'typechain';
import { SimResultStore } from './simResultStore';
import { config } from '../configuration/config';
import { SimManager } from '../controllers/simulation/SimManager';

const setupCB = () : CBServer => {

    const simManager = SimManager.getInstance();

    const runSim : CbMethod = async (args: {[key: string] : string[]}) : Promise<string> => {
        return await simManager.runSim(args);
    };

    const cbServer : CBServer = new CBServer(config.cb.url);

    const serviceInfo : ServiceInfo = {
        name: 'VIPRA_Sim',
        description: 'Service for running a VIPRA simulation',
        key: 'VIPRA_Sim12341234',
        version: '1.0.0.0',
        author: 'Rolland Goodenough',
        email: 'rtg13@students.uwf.edu',
        doc_href: 'https://vrs.chain-builder.net/'
    };

    const resultStore : SimResultStore = new SimResultStore("simresults");

    const serviceOptions : ServiceOptions = {
        info: serviceInfo,
        parameters: [
            {
                name: 'configid',
                type: 'string',
                description: 'ID of the configuration to use to run the simulation',
                sample: 'f4ui-addv-943j-s98g'
            },
            {
                name: 'parameters',
                type: 'string',
                description: 'List of the parameters to use to run the simulation',
                sample: ''
            }
        ],
        returnValue: {
            name: 'simresults',
            type: 'xyz'
        },
        resultStore,
        method: runSim
    };

    const service : Service = new Service(serviceOptions);

    cbServer.addService({
        route: "services/simulation/",
        service
    });

    return cbServer;
};

export {
    setupCB
};
