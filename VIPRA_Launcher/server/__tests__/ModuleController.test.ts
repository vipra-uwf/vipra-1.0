import { FilesControllerMock } from './mocks/FilesController.mock';
import { SimBuilderMock } from './mocks/SimBuilder.mock';
import { ProcessRunnerMock } from './mocks/ProcessRunner.mock';

FilesControllerMock();
SimBuilderMock();
ProcessRunnerMock();


import 'reflect-metadata';

import { FilesController } from '../src/controllers/files/FilesController';
import { SimBuilder } from '../src/controllers/simulation/SimBuilder';
import { ProcessRunner } from '../src/controllers/processes/ProcessRunner';
import { ModuleController } from '../src/controllers/module/moduleController';

import { ModuleType } from '../src/types/module';
import { Status } from '../src/types/Status';
import { checkInstalledGoodModule, duplicateModuleInfo, goodModuleBuffers, goodModuleInfo, installedModulesInfo, installedOutputDataWriters, getInstalledModules, NON_EXISTANT_MODULE_ID } from './values/modules';


describe('ModuleController', () =>{
    
  const MockedFC = jest.mocked(FilesController, true);
  const MockedSimBuilder = jest.mocked(SimBuilder, true);
  const MockedProcessRunner = jest.mocked(ProcessRunner, true);

  let mockFC : FilesController = new FilesController();
  let mockProcessRunner : ProcessRunner = new ProcessRunner(mockFC);
  let mockSimBuilder : SimBuilder = new SimBuilder(mockFC, mockProcessRunner);
  let moduleController = new ModuleController(mockSimBuilder, mockFC);

  beforeEach(()=>{
    mockSimBuilder = new SimBuilder(mockFC, mockProcessRunner);
    mockFC = new FilesController();
    moduleController = new ModuleController(mockSimBuilder, mockFC);
    MockedFC.mockClear();
    MockedSimBuilder.mockClear();
    MockedProcessRunner.mockClear();
  });

  it("Should Load Modules on construction", ()=>{
    const loadSpy = jest.spyOn(mockFC, 'loadInstalledModules');
    let moduleController = new ModuleController(mockSimBuilder, mockFC);

    expect(loadSpy).toBeCalledTimes(1);
    expect(moduleController.getModules()).toMatchObject(getInstalledModules());
  });

  it("Should Install Proper Modules", async ()=>{
    const writeSpy = jest.spyOn(mockFC, 'writeFileFromBuffer');
    const mkdirSpy = jest.spyOn(mockFC, 'makeDir');
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');

    const result = await moduleController.installModule(goodModuleInfo, goodModuleBuffers);
    const modules = moduleController.getModulesofType(ModuleType.MODEL);

    expect(result).toEqual({status:Status.SUCCESS, message:null});
    expect(modules).toContainEqual(checkInstalledGoodModule);
    expect(writeSpy).toBeCalledTimes(3);
    expect(mkdirSpy).toBeCalledTimes(1);
    expect(deleteSpy).toBeCalledTimes(0);
  });

  it("Should Reject Duplicate Modules", async ()=>{
    const writeSpy = jest.spyOn(mockFC, 'writeFileFromBuffer');
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');
    const result = await moduleController.installModule(duplicateModuleInfo, goodModuleBuffers);

    expect(result).toEqual({status:Status.CONFLICT, message:'Duplicate Module ID: VbGjNW5NCkOmKAxvFmz5KwUV2zz469'});
    expect(writeSpy).toBeCalledTimes(0);
    expect(deleteSpy).toBeCalledTimes(0);
  });

  it("Should Return Module Info", async ()=>{
    expect(moduleController.getModules()).toMatchObject(getInstalledModules());
    expect(moduleController.allModulesInfo()).toMatchObject(installedModulesInfo);
    expect(moduleController.getModulesofType(ModuleType.OUTPUT_DATA_WRITER)).toEqual(installedOutputDataWriters);

    const check = new ModuleController(mockSimBuilder, mockFC);
    expect(moduleController).toEqual(check);
  });

  it("Should Delete Modules", async ()=>{
    const removeSpy = jest.spyOn(mockSimBuilder, 'removeModule');
    const deleteDirSpy = jest.spyOn(mockFC, 'deleteDir');
    const deleteFileSpy = jest.spyOn(mockFC, 'deleteFile');
    const writeSpy = jest.spyOn(mockFC, 'writeFile');
    const sbremoveSpy = jest.spyOn(mockSimBuilder, 'removeModule');

    const result = moduleController.removeModule('f8qt7eLCczzFMjToJBsA5qYUz1A8E6');

    expect(result).toEqual({status: Status.SUCCESS, message: null});
    expect(deleteDirSpy).toBeCalledTimes(1);
    expect(deleteDirSpy).toBeCalledWith('successful/path', false);
    expect(deleteFileSpy).toBeCalledTimes(1);
    expect(deleteFileSpy).toBeCalledWith('/build/f8qt7eLCczzFMjToJBsA5qYUz1A8E6.o');
    expect(writeSpy).toBeCalledTimes(1);
    expect(removeSpy).toBeCalledTimes(1);
    expect(sbremoveSpy).toBeCalledTimes(1);
  });

  it("Should Handle Improper Module Deletes", async ()=>{
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');
    const writeSpy = jest.spyOn(mockFC, 'writeFile');

    const result = await moduleController.removeModule(NON_EXISTANT_MODULE_ID);

    expect(result).toEqual({status: Status.NOT_FOUND, message: "Unable to find module"});
    expect(deleteSpy).toBeCalledTimes(0);
    expect(writeSpy).toBeCalledTimes(0);
  });
});