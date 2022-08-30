import { FilesControllerMock } from "./mocks/FilesController.mock";
import { ModuleControllerMock } from "./mocks/ModuleController.mock";
import { SimBuilderMock } from "./mocks/SimBuilder.mock";

FilesControllerMock();
ModuleControllerMock();
SimBuilderMock();

import 'reflect-metadata';

import { ConfigManager } from "../src/controllers/simconfig/ConfigManager";
import { FilesController } from "../src/controllers/files/FilesController";
import { ModuleController } from "../src/controllers/module/moduleController";
import { SimBuilder } from "../src/controllers/simulation/SimBuilder";
import { badConfig, goodConfig, goodConfigUpdate } from "./values/simconfig";
import { Status } from "../src/types/Status";
import { MODULE_TYPE_COUNT } from "./values/modules";


describe("ConfigManager", ()=>{

  let mockSB : SimBuilder;
  let mockFC : FilesController;
  let mockMC : ModuleController;

  let configManager : ConfigManager;

  beforeEach(()=>{
    jest.clearAllMocks();
    mockFC = new FilesController();
    mockMC = new ModuleController(mockSB, mockFC);
    configManager = new ConfigManager(mockMC, mockFC);
  });

  it("Should Load Simulation Configurations on Startup", ()=>{

  });

  it("Should Handle Creating New Simulation Configurations", ()=>{
    const makeDirSpy = jest.spyOn(mockFC, 'makeDir');
    const filewriteSpy = jest.spyOn(mockFC, 'writeFile');
    const moduleCheckSpy = jest.spyOn(mockMC, 'checkModule');

    const result = configManager.addConfig(goodConfig);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.message).not.toBeNull();
    expect(makeDirSpy).toBeCalledTimes(1);
    expect(filewriteSpy).toBeCalledTimes(1);
    expect(moduleCheckSpy).toBeCalledTimes(MODULE_TYPE_COUNT);
  });

  it("Should Handle Incorrect Configurations", ()=>{
    const makeDirSpy = jest.spyOn(mockFC, 'makeDir');
    const filewriteSpy = jest.spyOn(mockFC, 'writeFile');
    const moduleCheckSpy = jest.spyOn(mockMC, 'checkModule');

    const result = configManager.addConfig(badConfig);

    expect(result).toEqual({ status: Status.BAD_REQUEST, message: `Module Not Found: badmodule` });
    expect(makeDirSpy).toBeCalledTimes(0);
    expect(filewriteSpy).toBeCalledTimes(0);
    expect(moduleCheckSpy).toBeCalledTimes(6);
  });

  it("Should Handle Duplicate Configurations", ()=>{
    const first = configManager.addConfig(goodConfig);
    expect(first.status).toEqual(Status.SUCCESS);
    expect(first.message).not.toBeNull;

    const makeDirSpy = jest.spyOn(mockFC, 'makeDir');
    const filewriteSpy = jest.spyOn(mockFC, 'writeFile');
    const moduleCheckSpy = jest.spyOn(mockMC, 'checkModule');

    const result = configManager.addConfig(goodConfig);

    expect(result.status).toEqual(Status.CONFLICT);
    expect(makeDirSpy).toBeCalledTimes(0);
    expect(filewriteSpy).toBeCalledTimes(0);
    expect(moduleCheckSpy).toBeCalledTimes(0);
  });

  it("Should Handle Deleting Simulation Configurations", ()=>{
    const first = configManager.addConfig(goodConfig);
    expect(first.status).toEqual(Status.SUCCESS);
    expect(first.message).not.toBeNull;
    
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');

    const result = configManager.deleteConfig(first.message || '');

    expect(result).toEqual({ status: Status.SUCCESS, message: null });
    expect(deleteSpy).toBeCalledTimes(1);
    expect(configManager.getConfigs().length).toEqual(0);
  });

  it("Should Handle Updating Simulation Configurations", ()=>{
    const first = configManager.addConfig(goodConfig);
    expect(first.status).toEqual(Status.SUCCESS);
    expect(first.message).not.toBeNull;

    const writeSpy = jest.spyOn(mockFC, 'writeFile');

    const result = configManager.updateConfig(first.message || '', goodConfigUpdate);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(writeSpy).toBeCalledTimes(1);
    expect(configManager.getConfig(first.message||'')?.description).toEqual('this is an updated config');
  });

  // test that partial simconfigs are properly converted to full simconfigs
  // eg they fail if they are missing modules etc

});