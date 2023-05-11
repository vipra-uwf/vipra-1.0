/* eslint-disable jsdoc/require-jsdoc */

import { SimConfigUpload } from '../../../types/simconfig/simconfig.types';
import { Status } from '../../../types/status';
import { Full } from '../../../types/typeDefs';
import { properSimConfig } from '../../values/simconfigs/simconfigs.values';


/**
 * @description Mocks an EventSystem
 */
export const MockSimConfigRepo = () : void => {
  jest.mock('../../../repos/simconfig/simconfig.local.repo', () => {
    return {
      LocalSimConfigRepo: jest.fn().mockImplementation(()=>{
        return {
          getAll: ()=>{ return [properSimConfig]; },
          get: (id : string)=>{
            if (id === 'properSimConfig') { 
              return properSimConfig; 
            }
            return null;
          },
          create: (upload : Full<SimConfigUpload>)=>{
            if (upload.id === 'properSimConfig') {  
              return { status: Status.CREATED, object: properSimConfig };
            } else if (upload.id === 'duplicateSimConfig') {
              return { status: Status.CONFLICT, object: properSimConfig };
            }
          },
          delete: (id : string)=>{
            if (id === 'properSimConfig') {  
              return { status: Status.CREATED, object: properSimConfig };
            }
            return { status: Status.NOT_FOUND, object: null };
          },
          update: (id : string, simconfig : Partial<SimConfigUpload>)=>{
            if (id === 'properSimConfig') {  
              return { status: Status.SUCCESS, object: { ...properSimConfig, ...simconfig } };
            }
            return { status: Status.NOT_FOUND, object: null };
          },
          stage: ()=>{},
        };
      }),
    };
  });
};

/* eslint-enable */