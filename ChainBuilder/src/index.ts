import { Endpoint } from "./Types/Endpoint";
import { CBServer } from "./CBServer";
import { Service } from "./Types/Service";
import { EchoResultStore } from "./Types/EchoResultStore";

const server = new CBServer(80, 'http://192.168.1.119', 'services');

const test = server.getEndpoint(['services']);

const echoResultStore = new EchoResultStore();

const ep3 = new Endpoint('newone');

test.addEndpoint(ep3);

const testMethod = (arg : number) : number => {
    return arg;
};

const testService = new Service(ep3.getHref(), {
    "key": "addition_test",
    "name": "additiontest",
    "version": "1.0.0.0",
    "description": "haha it works",
    "author": "Robert Pahle",
    "email": "robert.pahle@gmail.com",
    "doc_href": "https://dev.chain-builder.net/chainbuilder/chainphp/"
}, echoResultStore);

testService.setParameter({
    "arguments": {
        "addend": {
            "chain_name": "addend_href",
            "description": "addend",
            "type": "float",
            "repeatable": true,
            "sample": 15
        }
    },
    "server": [
        "transient",
        "cachable"
    ]
});
testService.setResponse({
    "sum": {
        "description": "sum of the given numbers",
        "type": "float",
        "sample": 15
    }
});

testService.setMethod(
    {name: "addend", type: "float"},
    "float",
    testMethod
);

ep3.setService(testService);

server.start();
