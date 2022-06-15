import { CBServer } from "./CBServer";
import { Service } from "./Types/Service";
import { EchoResultStore } from "./echoResultStore";


const server = new CBServer({
    port: 80,
    baseURL: 'http://192.168.1.120',
    root: 'services'
});

const echoStore = new EchoResultStore("additionTestStore");

const testMethod = async (arg : string[]) : Promise<string> => {
    return arg[0];
};

const testService = new Service({
        info: {
            "key": "qwerqwerqwer",
            "name": "newadditiontest",
            "version": "1.0.0.0",
            "description": "haha it works",
            "author": "Robert Pahle",
            "email": "robert.pahle@gmail.com",
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
