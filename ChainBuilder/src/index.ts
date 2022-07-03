
export * from './@types/Types';
export * from './@types/Service';
export * from './@types/Endpoint';
export * from './@types/CBServer';
export * from './@types/ResultStore';
export * from './@types/Responses';

// import fs from 'fs';
// import path from 'path';
// import { CBServer } from './@types/CBServer';
// import { ResultStore } from './@types/ResultStore';
// import { Service } from './@types/Service';
// import { CbMethod, ServerOptions, ServiceInfo, ServiceOptions } from "./@types/Types";
// import { TestResultStore } from './test';

// // eslint-disable-next-line @typescript-eslint/require-await
// const runSim : CbMethod = async (args: {[key: string] : string[]}) : Promise<string> => {
//     return "5";
// };

// const options : ServerOptions = {
//     port: 443,
//     baseURL: "https://192.168.1.120/",
//     httpsCredentials: {
//         key: fs.readFileSync(path.resolve('./certs/local.pem')),
//         cert: fs.readFileSync(path.resolve('./certs/local.crt')),
//     }
// };

// // eslint-disable-next-line @typescript-eslint/no-unsafe-assignment
// const cbServer : CBServer = new CBServer(options);

// const serviceInfo : ServiceInfo = {
//     name: 'VIPRA_Sim',
//     description: 'Service for running a VIPRA simulation',
//     key: 'VIPRA_Sim12341234',
//     version: '1.0.0.0',
//     author: 'Rolland Goodenough',
//     email: 'rtg13@students.uwf.edu',
//     doc_href: 'https://vrs.chain-builder.net/'
// };

// // eslint-disable-next-line @typescript-eslint/no-unsafe-assignment
// const resultStore : TestResultStore = new TestResultStore("SimResults");

// const serviceOptions : ServiceOptions = {
//     info: serviceInfo,
//     parameters: [
//         {
//             name: 'configid',
//             type: 'string',
//             description: 'ID of the configuration to use to run the simulation',
//             sample: 'f4ui-addv-943j-s98g'
//         },
//         {
//             name: 'parameters',
//             type: 'string',
//             description: 'List of the parameters to use to run the simulation',
//             sample: ''
//         }
//     ],
//     returnValue: {
//         name: 'simresults',
//         type: 'xyz'
//     },
//     resultStore,
//     method: runSim
// };

// const service : Service = new Service(serviceOptions);

// cbServer.addService({
//     route: "/services/simulation/",
//     service
// });


// cbServer.start();
