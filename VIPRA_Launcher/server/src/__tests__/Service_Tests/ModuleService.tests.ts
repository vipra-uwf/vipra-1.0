
import { MockModuleRepo } from '../mocks/module/modulerepo.mock';
MockModuleRepo();

import { LocalModuleRepo } from '../../repos/module/module.local.repo';
import { ModuleService } from '../../services/module/module.service';
import { emptyModuleUpdate, filesModuleUpdate, idModuleUpdate, missingFilesModuleUpload, missingIdModuleUpload, missingNameModuleUpload, nameModuleUpdate, properModule, properModuleUpdate, properModuleUpload, updatedModule } from '../values/modules/modules.values';
import { Status } from '../../types/status';


describe('ModuleService', ()=>{

  const moduleRepo : LocalModuleRepo = new LocalModuleRepo();
  let moduleService : ModuleService;

  beforeEach(()=>{
    moduleService = new ModuleService(moduleRepo);
    jest.clearAllMocks();
  });

  it('Should Get Modules Properly', async ()=>{
    const getSpy = jest.spyOn(moduleRepo, 'get');
    const firstResult = await moduleService.get('properModule');
    expect(firstResult).toEqual(properModule);
    expect(getSpy).toBeCalledTimes(1);

    const getAllSpy = jest.spyOn(moduleRepo, 'getAll');
    const secondResult = await moduleService.getAll();
    expect(secondResult).toEqual([properModule]);
    expect(getAllSpy).toBeCalledTimes(1);
    expect(getSpy).toBeCalledTimes(1);
  });

  it('Should Handle Creating Proper Modules', async ()=>{
    const createSpy = jest.spyOn(moduleRepo, 'create');
    
    const result = await moduleService.create(properModuleUpload);

    expect(result.status).toEqual(Status.CREATED);
    expect(result.object).toEqual(properModuleUpload.module);

    expect(createSpy).toBeCalledTimes(1);
  });

  it('Should Handle Modules Missing Properties', async ()=>{
    const createSpy = jest.spyOn(moduleRepo, 'create');
    
    let result = await moduleService.create(missingNameModuleUpload);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toEqual(null);
    expect(createSpy).toBeCalledTimes(0);

    createSpy.mockClear();

    result = await moduleService.create(missingIdModuleUpload);
    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toEqual(null);
    expect(createSpy).toBeCalledTimes(0);
  });

  it('Should Handle Modules Missing Files', async ()=>{
    const createSpy = jest.spyOn(moduleRepo, 'create');
    
    const result = await moduleService.create(missingFilesModuleUpload);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toEqual(null);

    expect(createSpy).toBeCalledTimes(0);
  });

  it('Should Handle Updating Modules', async ()=>{
    const updateSpy = jest.spyOn(moduleRepo, 'update');

    let result = await moduleService.update('properModule', properModuleUpdate);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.object).toEqual(updatedModule);
    expect(updateSpy).toBeCalledTimes(1);

    updateSpy.mockClear();

    result = await moduleService.update('properModule', filesModuleUpdate);
    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.object).toEqual(properModule);
    expect(updateSpy).toBeCalledTimes(1);
  });

  it('Should Handle Rejecting Improper Updates', async ()=>{
    const createSpy = jest.spyOn(moduleRepo, 'update');

    // attempting to update properties that shouldn't be updated
    let result = await moduleService.update('properModule', idModuleUpdate);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull;
    expect(createSpy).toBeCalledTimes(0);

    result = await moduleService.update('properModule', nameModuleUpdate);
    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull;
    expect(createSpy).toBeCalledTimes(0);

    // missing update properties
    result = await moduleService.update('properModule', emptyModuleUpdate);
    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull;
    expect(createSpy).toBeCalledTimes(0);

  });
});