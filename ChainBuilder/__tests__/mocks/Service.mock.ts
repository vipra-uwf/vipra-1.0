import express from 'express';
import { CbServiceOptions } from '../../src/Types';

export const ServiceMock = ()=>{
  jest.mock('../../src/Service', () => {
      return{
          Service: jest.fn().mockImplementation((opts : CbServiceOptions)=>{
              return {
                handleRequest: (request : express.Request, response : express.Response) => {},
                getResultStore: () => {return opts.resultStore;},
                getKey: ()=>{return 'asdfasdfasdf';}
              }
          })
      }
  });
}