
import { ServiceMock } from './mocks/Service.mock';

ServiceMock();

import { Service } from '../src/Service';
import { CBServiceRoot } from '../src/CBServiceRoot';
import { exampleServiceInfo, exampleServiceOptions } from './values/Service.values';
import { Endpoint } from '../src/Endpoint';

describe("ServiceRoot", ()=>{


  beforeEach(()=>{

  });

  it('Should Handle Adding Endpoints', ()=>{
    const sut = new CBServiceRoot('test.com');
    sut.addRoute(['test']);
    expect(sut.getNode('test')).not.toBeNull();
    expect(sut.getNode('test/')).not.toBeNull();
    expect(sut.getNode('/test')).not.toBeNull();
    expect(sut.getNode('/test/')).not.toBeNull();

    expect(sut.getNode('test/route')).toBeNull();

    sut.addRoute(['test','route']);

    expect(sut.getNode('test')).not.toBeNull();
    expect(sut.getNode('test/')).not.toBeNull();
    expect(sut.getNode('/test')).not.toBeNull();
    expect(sut.getNode('/test/')).not.toBeNull();
    expect(sut.getNode('test/route')).not.toBeNull();
    expect(sut.getNode('/test/route')).not.toBeNull();
    expect(sut.getNode('/test/route/')).not.toBeNull();
  });

  it('Should Handle Adding Services', ()=>{
    const sut = new CBServiceRoot('test.com');
    const service = new Service(exampleServiceOptions);
    expect((sut.getNode('test/service') as Endpoint)?.getService()).toBeUndefined();
    sut.addService(service, ['test', 'service']);
    expect((sut.getNode('test/service') as Endpoint)?.getService()).not.toBeFalsy();
  });

  it('Should Route Requests Correctly', ()=>{
    const sut = new CBServiceRoot('test.com');
    sut.addRoute(['test', 'route']);

    expect(sut.getNode('test/route?test=test')).not.toBeNull();
  });

  
});