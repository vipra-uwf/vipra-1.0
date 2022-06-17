import fs from 'fs';
import path from 'path';
import { CBServer } from "./CBServer";
import { Service } from "./Types/Service";
import { EchoResultStore } from "./echoResultStore";


const server = new CBServer({
    port: 443,
    baseURL: 'https://192.168.1.120/',
    httpsCredentials: {
        key: fs.readFileSync(path.resolve('./certs/local.pem')),
        cert: fs.readFileSync(path.resolve('./certs/local.crt')),
    }
});

const echoStore = new EchoResultStore("additionTestStore");

const testMethod = async (arg : string[]) : Promise<string> => {
    let sum : number = 0;
    arg.forEach((value) =>{
        sum += parseInt(value, 10);
    });
    return sum.toString();
};

const testService = new Service({
        info: {
            "key": "fghfgh",
            "name": "addTest",
            "version": "1.0.0.0",
            "description": "haha it works",
            "author": "Rolland Goodenough",
            "email": "rtg13@students.uwf.edu",
            "doc_href": "https://dev.chain-builder.net/chainbuilder/chainphp/"
        },
        parameters: {name: "addend", type: "string"},
        returnValue: {name: "sum", type: "string"},
        resultStore: echoStore,
        method: testMethod
    });

server.addService({
    route: 'services/newone/',
    service: testService
});

server.start();
