/* eslint-disable jsdoc/require-jsdoc */

import { ModuleUpload } from '../../../types/module/module.types';
import { Status } from '../../../types/status';
import { Full } from '../../../types/typeDefs';
import { properModule } from '../../values/modules/modules.values';


/**
 * @description Mocks an EventSystem
 */
export const MockModuleRepo = () : void => {
  jest.mock('../../../repos/module/module.local.repo', () => {
    return {
      LocalModuleRepo: jest.fn().mockImplementation(()=>{
        return {
          getAll: ()=>{ return [properModule]; },
          get: (id : string)=>{
            if (id === 'properModule') { 
              return properModule; 
            }
            return null;
          },
          create: (upload : Full<ModuleUpload>)=>{
            if (upload.module.id === 'properModule') {  
              return { status: Status.CREATED, object: properModule };
            } else if (upload.module.id === 'duplicateModule') {
              return { status: Status.CONFLICT, object: properModule };
            }
          },
          delete: (id : string)=>{
            if (id === 'properModule') {  
              return { status: Status.CREATED, object: properModule };
            }
            return { status: Status.NOT_FOUND, object: null };
          },
          update: (id : string, module : Partial<ModuleUpload>)=>{
            if (id === 'properModule') {  
              return { status: Status.SUCCESS, object: { ...properModule, ...module.module } };
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