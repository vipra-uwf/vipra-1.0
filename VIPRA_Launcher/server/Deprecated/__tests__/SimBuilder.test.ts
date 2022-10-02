
import { FilesControllerMock } from "./mocks/FilesController.mock";
import { ProcessRunnerMock } from "./mocks/ProcessRunner.mock";

FilesControllerMock();
ProcessRunnerMock();

import 'reflect-metadata';

import { ProcessRunner } from "../src/controllers/processes/ProcessRunner";
import { FilesController } from "../src/controllers/files/FilesController";
import { SimBuilder } from "../src/controllers/simulation/SimBuilder";
import { getInstalled_One_Missing, getInstalled_Two_Missing, missingModule, getInstalledModules, NUM_MISSING_MODULES, NUM_MODULES } from "./values/modules";
import { Status } from "../src/types/Status";

describe('SimBuilder', ()=>{

  const MockedPR = jest.mocked(ProcessRunner, true);

  let mockFC : FilesController = new FilesController();
  let mockPR : ProcessRunner = new ProcessRunner(mockFC);
  let simBuilder : SimBuilder;

  beforeEach(()=>{
    mockFC = new FilesController();
    mockPR = new ProcessRunner(mockFC);
    simBuilder = new SimBuilder(mockFC, mockPR);
  });

  afterEach(()=>{
    jest.clearAllMocks();
  });

  it('Should Build The Simulation on Startup', async ()=>{
    const buildModuleSpy = jest.spyOn(mockPR, 'buildModule');
    const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
    const humanBehaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
    const compileMainSpy = jest.spyOn(mockPR, 'compileMain');
    const compileGenMainSpy = jest.spyOn(mockPR, 'compileGenMain');

    const moveSpy = jest.spyOn(mockFC, 'moveFile');
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');

    const result = await simBuilder.startup(getInstalledModules());

    expect(result.message).not.toEqual(null);
    if(result.message){
        expect(simBuilder.getBuildStatus(result.message)).toEqual({ready:false, reason:"Currently Building Simulation"});
    }

    await new Promise(process.nextTick);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(buildModuleSpy).toHaveBeenCalledTimes(NUM_MODULES);
    expect(humanBehaviorSpy).toHaveBeenCalledTimes(1);
    expect(compileGenMainSpy).toHaveBeenCalledTimes(1);
    expect(compileMainSpy).toHaveBeenCalledTimes(1);
    expect(compileSimSpy).toHaveBeenCalledTimes(1);
    expect(moveSpy).toHaveBeenCalledTimes(1);
    expect(deleteSpy).toHaveBeenCalledTimes(1);

    const moduleOrder = buildModuleSpy.mock.invocationCallOrder[0];
    const behaviorOrder = humanBehaviorSpy.mock.invocationCallOrder[0];
    const genMainOrder = compileGenMainSpy.mock.invocationCallOrder[0];
    const mainOrder = compileMainSpy.mock.invocationCallOrder[0];
    const simOrder = compileSimSpy.mock.invocationCallOrder[0];

    expect(moduleOrder).toBeLessThan(genMainOrder);
    expect(behaviorOrder).toBeLessThan(mainOrder);
    expect(genMainOrder).toBeLessThan(mainOrder);
    expect(mainOrder).toBeLessThan(simOrder);
    expect(simBuilder.getSimState()).toEqual({ready:true, reason:null});
  });

  it("Should Handle Missing Modules on Startup", async ()=>{
    const buildModuleSpy = jest.spyOn(mockPR, 'buildModule');
    const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
    const humanBehaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
    const compileMainSpy = jest.spyOn(mockPR, 'compileMain');
    const compileGenMainSpy = jest.spyOn(mockPR, 'compileGenMain');
    const moveSpy = jest.spyOn(mockFC, 'moveFile');
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');

    const result = await simBuilder.startup(getInstalled_One_Missing());

    expect(result.status).toEqual(Status.BAD_REQUEST);
    await new Promise(process.nextTick);
    if(result.message){
        expect(simBuilder.getBuildStatus(result.message)).toEqual({ready:false, reason:`Missing Module Types: obstacle_set`});
    }
    expect(simBuilder.getSimState()).toEqual({ready:false, reason:`Missing Module Types: obstacle_set`});

    expect(buildModuleSpy).toHaveBeenCalledTimes(NUM_MODULES-NUM_MISSING_MODULES);
    expect(humanBehaviorSpy).toHaveBeenCalledTimes(1);
    expect(compileGenMainSpy).toHaveBeenCalledTimes(1);
    expect(compileMainSpy).toHaveBeenCalledTimes(0);
    expect(compileSimSpy).toHaveBeenCalledTimes(0);
    expect(moveSpy).toHaveBeenCalledTimes(0);
    expect(deleteSpy).toHaveBeenCalledTimes(0);
  });

  it("Should Handle Missing Modules on Adding a Module", async ()=>{
    const startup = await simBuilder.startup(getInstalled_Two_Missing());
    await new Promise(process.nextTick);
    
    expect(startup.status).toEqual(Status.BAD_REQUEST);

    const buildModuleSpy = jest.spyOn(mockPR, 'buildModule');
    const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
    const humanBehaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
    const compileMainSpy = jest.spyOn(mockPR, 'compileMain');
    const compileGenMainSpy = jest.spyOn(mockPR, 'compileGenMain');
    const moveSpy = jest.spyOn(mockFC, 'moveFile');
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');
    
    const add = await simBuilder.addedModule(missingModule);
    await new Promise(process.nextTick);

    expect(add.status).toBe(Status.SUCCESS);
    if (add.message) {
      expect(simBuilder.getBuildStatus(add.message)).toEqual({ ready: false, reason: "Missing Module Types: goals" });
    }

    expect(buildModuleSpy).toHaveBeenCalledTimes(1);
    expect(compileSimSpy).toHaveBeenCalledTimes(0);
    expect(humanBehaviorSpy).toHaveBeenCalledTimes(0);
    expect(compileMainSpy).toHaveBeenCalledTimes(0);
    expect(compileGenMainSpy).toHaveBeenCalledTimes(0);
    expect(moveSpy).toHaveBeenCalledTimes(0);
    expect(deleteSpy).toHaveBeenCalledTimes(0);

    expect(simBuilder.getSimState()).toEqual({ready:false, reason:"Missing Module Types: goals"});
  });

  // NOTE: assumes that startup works correctly, surface level check by looking at result
  // NOTE: startup has been called so Human Behavior & Generate Main do should not be called again -RG
  it("Should Build Modules And Rebuild Simulation", async ()=>{
    const startupResult = await simBuilder.startup(getInstalledModules());
    expect(startupResult.status).toEqual(Status.SUCCESS);
    await new Promise(process.nextTick);

    const genMainSpy = jest.spyOn(mockPR, 'compileGenMain');
    const behaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
    const moduleBuildSpy = jest.spyOn(mockPR, 'buildModule');
    const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
    const compileMainSpy = jest.spyOn(mockPR, 'compileMain');

    const result = await simBuilder.addedModule(missingModule);
    await new Promise(process.nextTick);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.message).not.toBeNull();
    expect(genMainSpy).toBeCalledTimes(0);
    expect(behaviorSpy).toBeCalledTimes(0);
    expect(moduleBuildSpy).toBeCalledTimes(1);
    expect(compileSimSpy).toBeCalledTimes(1);
    expect(compileMainSpy).toBeCalledTimes(1);
    expect(simBuilder.getBuildStatus(result.message||'')).toEqual({ready:true, reason:"Successfully Finished Build"});
    expect(simBuilder.getSimState()).toEqual({ready:true, reason:null});  
  });

  it("Should Properly Update The Simulation When Required Modules are Met", async ()=>{
    const startupResult = await simBuilder.startup(getInstalled_One_Missing());
    expect(startupResult.status).toEqual(Status.BAD_REQUEST);
    await new Promise(process.nextTick);

    const genMainSpy = jest.spyOn(mockPR, 'compileGenMain');
    const behaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
    const moduleBuildSpy = jest.spyOn(mockPR, 'buildModule');
    const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
    const compileMainSpy = jest.spyOn(mockPR, 'compileMain');

    const result = await simBuilder.addedModule(missingModule);
    await new Promise(process.nextTick);

    expect(result.status).toEqual(Status.SUCCESS);
    expect(result.message).not.toBeNull();
    expect(genMainSpy).toBeCalledTimes(0);
    expect(behaviorSpy).toBeCalledTimes(0);
    expect(moduleBuildSpy).toBeCalledTimes(1);
    expect(compileSimSpy).toBeCalledTimes(1);
    expect(compileMainSpy).toBeCalledTimes(1);
    expect(simBuilder.getBuildStatus(result.message||'')).toEqual({ready:true, reason:"Successfully Finished Build"});
    expect(simBuilder.getSimState()).toEqual({ready:true, reason:null});
  });

  it("Should handle Generate Main Failing to Compile", async()=>{

    const buildModuleSpy = jest.spyOn(mockPR, 'buildModule');
    const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
    const humanBehaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
    const compileMainSpy = jest.spyOn(mockPR, 'compileMain');
    const moveSpy = jest.spyOn(mockFC, 'moveFile');
    const deleteSpy = jest.spyOn(mockFC, 'deleteDir');

    const compileGenMainFail = jest.spyOn(mockPR, 'compileGenMain').mockImplementation(()=>{return new Promise((resolve)=>{resolve(Status.INTERNAL_ERROR);})});
    const startup = await simBuilder.startup(getInstalledModules());

    expect(startup.status).toEqual(Status.INTERNAL_ERROR);

    expect(buildModuleSpy).toBeCalledTimes(NUM_MODULES);
    expect(compileSimSpy).toBeCalledTimes(0);
    expect(humanBehaviorSpy).toBeCalledTimes(1);
    expect(compileMainSpy).toBeCalledTimes(0);
    expect(compileGenMainFail).toBeCalledTimes(1);
    expect(moveSpy).toBeCalledTimes(0);
    expect(deleteSpy).toBeCalledTimes(0);

    expect(simBuilder.getSimState()).toEqual({ ready: false, reason: 'Unable to Build Generate Main' });
  });

  it("Should Remove Modules when they are uninstalled", ()=>{

  });

  
  // missing: 

  // removeModule

  // isMissing
  
  // startup
  // genmain fail
    // behavior fail

  // compileSimulation
    // compilsim fail

  // addModule
    // module build fail


});