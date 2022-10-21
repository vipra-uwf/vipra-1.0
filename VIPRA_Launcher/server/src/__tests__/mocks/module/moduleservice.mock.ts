/* eslint-disable jsdoc/require-jsdoc */

import { Module, ModuleUpload } from '../../../types/module/module.types';
import { Status } from '../../../types/status';
import { Nullable, OperationResult } from '../../../types/typeDefs';
import { properModule } from '../../values/modules/modules.values';


/**
 * @description Mocks an EventSystem
 */
export const MockModuleService = () : void => {
  jest.mock('../../../services/module/module.service', () => {
    return {
      ModuleService: jest.fn().mockImplementation(()=>{
        return {
          getAll : ():Module[]=>{ return [properModule];},
          get : (id : string):Nullable<Module>=>{ if (id === 'properModule') { return properModule; } else { return null; } },
          create : (object : Partial<ModuleUpload>):OperationResult<Module> => { 
            if (object.module?.id === 'properModule') {
              return { status: Status.CREATED, object: properModule };
            } else if (object.module?.id === 'badModule') {
              return { status: Status.BAD_REQUEST, object: null };
            } else if (object.module?.id === 'duplicateModule') {
              return { status: Status.CONFLICT, object: properModule };
            } else {
              return { status: Status.NOT_FOUND, object: null };
            }
          },
          update : ():void=>{},
          delete : ():void=>{},
          stage : ():void=>{},
        };
      }),
    };
  });
};

/* eslint-enable */