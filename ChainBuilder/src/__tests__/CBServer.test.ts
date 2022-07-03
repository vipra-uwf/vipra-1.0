import fs from 'fs';

import { CBServer } from '../@types/CBServer';

const key = fs.readFileSync(`./certs/local.pem`);
const cert = fs.readFileSync(`./certs/local.crt`);

test('Add Route', ()=>{

    const cbServer = new CBServer('https://192.168.1.120/');

    cbServer.addRoute('/services/route1');
    cbServer.addRoute('/services/route2/');

    let hasRoute = cbServer.hasRoute('/services');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services/');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services/route1');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services/route1/');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services/route2');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services/route2/');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services//route2');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services//route2/');
    expect(hasRoute).toBe(true);

    hasRoute = cbServer.hasRoute('/services/notaroute');
    expect(hasRoute).toBe(false);

    hasRoute = cbServer.hasRoute('/');
    expect(hasRoute).toBe(false);
});


