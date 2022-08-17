import { test } from '@jest/globals';

import { FilesController } from '../src/controllers/files/FilesController';
import { ModuleController } from '../src/controllers/module/moduleController';

import { container } from 'tsyringe';
import { mockFilesController } from './mocks/FilesController.mock';
import { Status } from '../src/types/Status';
import { goodModuleBuffers, goodModuleUpload } from './values/modules';


test('Install Module', ()=>{
    
    container.register(FilesController, mockFilesController);
    const fc : mockFilesController = container.resolve(FilesController) as mockFilesController;
    const modController = container.resolve(ModuleController);

    fc.setFail(false);
    fc.setResultStatus(Status.SUCCESS);
    
    modController.installModule(goodModuleUpload, goodModuleBuffers);

});