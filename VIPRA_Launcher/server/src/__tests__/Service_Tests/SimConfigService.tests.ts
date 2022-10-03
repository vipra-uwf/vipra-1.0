import { MockSimConfigRepo } from "../mocks/simconfig/simconfigrepo.mock";
MockSimConfigRepo();

import { LocalSimConfigRepo } from "../../repos/simconfig/simconfig.local.repo";
import { SimConfigService } from "../../services/simconfig/simconfig.service";
import { Status } from "../../types/status";
import { emptySimConfigUpdate, idSimConfigUpdate, missingModuleSimConfigUpload, missingNameSimConfigUpload, moduleSimConfigUpdate, nameSimConfigUpdate, properSimConfig, properSimConfigUpdate, properSimConfigUpload, updatedSimConfig } from "../values/simconfigs/simconfigs.values";



describe('SimConfigService', ()=>{

  const simconfigRepo : LocalSimConfigRepo = new LocalSimConfigRepo();
  let configService : SimConfigService;

  beforeEach(()=>{
    configService = new SimConfigService(simconfigRepo);
    jest.clearAllMocks();
  });

  it('Should Get SimConfigs', async ()=>{
    const getSpy = jest.spyOn(simconfigRepo, 'get');
    const firstResult = await configService.get('properSimConfig');
    expect(firstResult).toEqual(properSimConfig);
    expect(getSpy).toBeCalledTimes(1);

    const getAllSpy = jest.spyOn(simconfigRepo, 'getAll');
    const secondResult = await configService.getAll();
    expect(secondResult).toEqual([properSimConfig]);
    expect(getAllSpy).toBeCalledTimes(1);
    expect(getSpy).toBeCalledTimes(1);
  });

  it('Should Handle Proper SimConfig Uploads', async ()=> {
    const createSpy = jest.spyOn(simconfigRepo, 'create');

    const result = await configService.create(properSimConfigUpload);

    expect(result.status).toEqual(Status.CREATED);
    expect(result.object).toEqual(properSimConfig);
    expect(createSpy).toBeCalledTimes(1);
  });

  it('Should Handle SimConfigs Missing Properties', async ()=>{
    const createSpy = jest.spyOn(simconfigRepo, 'create');

    // Missing a property
    let result = await configService.create(missingNameSimConfigUpload);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull();
    expect(createSpy).toBeCalledTimes(0);

    createSpy.mockClear();

    // Missing a module
    result = await configService.create(missingModuleSimConfigUpload);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull();
    expect(createSpy).toBeCalledTimes(0);
  });

  it('Should Handle Updating SimConfigs', async ()=>{
    const updateSpy = jest.spyOn(simconfigRepo, 'update');

    let result = await configService.update('properSimConfig', properSimConfigUpdate);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.object).not.toBeNull();
    expect(updateSpy).toBeCalledTimes(1);

    updateSpy.mockClear();

    result = await configService.update('properSimConfig', moduleSimConfigUpdate);
    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.object).not.toBeNull();
    expect(updateSpy).toBeCalledTimes(1);
  });

  it('Should Handle Rejecting Improper Updates', async ()=>{
    const updateSpy = jest.spyOn(simconfigRepo, 'update');
    let result = await configService.update('properSimConfig', nameSimConfigUpdate);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull();
    expect(updateSpy).toBeCalledTimes(0);

    updateSpy.mockClear();

    // Missing a module
    result = await configService.update('properSimConfig', idSimConfigUpdate);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull();
    expect(updateSpy).toBeCalledTimes(0);

    updateSpy.mockClear();

    // Missing a module
    result = await configService.update('properSimConfig', emptySimConfigUpdate);

    expect(result.status).toEqual(Status.BAD_REQUEST);
    expect(result.object).toBeNull();
    expect(updateSpy).toBeCalledTimes(0);
  });
});