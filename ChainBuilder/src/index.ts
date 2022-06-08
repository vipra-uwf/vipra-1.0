import { CBEndpoint } from "./CBEndpoint";
import { CBServer } from "./CBServer";

const server = new CBServer(80, 'http://localhost', 'services');

const test = server.getEndpoint(['services']);

const ep = new CBEndpoint('test');
const ep2 = new CBEndpoint('another');
const ep3 = new CBEndpoint('newone');

test.addEndpoint(ep);
test.addEndpoint(ep3);
ep.addEndpoint(ep2);

server.start();