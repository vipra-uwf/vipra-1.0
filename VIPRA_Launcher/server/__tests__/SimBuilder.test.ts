
import { FilesControllerMock } from "./mocks/FilesController.mock";
import { ProcessRunnerMock } from "./mocks/ProcessRunner.mock";

FilesControllerMock();
ProcessRunnerMock();

import 'reflect-metadata';

import { ProcessRunner } from "../src/controllers/processes/ProcessRunner";
import { FilesController } from "../src/controllers/files/FilesController";
import { SimBuilder } from "../src/controllers/simulation/SimBuilder";
import { getInstalledMissing, mockInstalledModels, NUM_MISSING_MODULES, NUM_MODULES } from "./values/modules";
import { Status } from "../src/types/Status";
import { ModuleController } from "../src/controllers/module/moduleController";



describe('SimBuilder', ()=>{

    const MockedFC = jest.mocked(FilesController, true);
    const MockedProcessRunner = jest.mocked(ProcessRunner, true);

    let mockFC : FilesController = new FilesController();
    let mockPR : ProcessRunner = new ProcessRunner(mockFC);
    let simBuilder : SimBuilder;

    beforeEach(()=>{
        mockFC = new FilesController();
        mockPR = new ProcessRunner(mockFC);
        simBuilder = new SimBuilder(mockFC, mockPR);
        MockedFC.mockClear();
        MockedProcessRunner.mockClear();
    });

    it('Should Build The Simulation on Startup', async ()=>{
        const buildModuleSpy = jest.spyOn(mockPR, 'buildModule');
        const compileSimSpy = jest.spyOn(mockPR, 'compileSim');
        const humanBehaviorSpy = jest.spyOn(mockPR, 'compileHumanBehavior');
        const compileMainSpy = jest.spyOn(mockPR, 'compileMain');
        const compileGenMainSpy = jest.spyOn(mockPR, 'compileGenMain');

        const moveSpy = jest.spyOn(mockFC, 'moveFile');
        const deleteSpy = jest.spyOn(mockFC, 'deleteDir');

        const result = await simBuilder.startup(mockInstalledModels());

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

        const result = await simBuilder.startup(getInstalledMissing());

        expect(result.status).toEqual(Status.BAD_REQUEST);
        await new Promise(process.nextTick);
        expect(result.message).not.toBeNull();
        if(result.message){
            expect(simBuilder.getBuildStatus(result.message)).toEqual({ready:false, reason:`Missing Module Types: obstacle_set`});
        }
        expect(simBuilder.getSimState()).toEqual({ready:false, reason:`Missing Module Types: obstacle_set`});

        expect(buildModuleSpy).toHaveBeenCalledTimes(NUM_MODULES-NUM_MISSING_MODULES);
        expect(humanBehaviorSpy).toHaveBeenCalledTimes(1);
        expect(compileGenMainSpy).toHaveBeenCalledTimes(0);
        expect(compileMainSpy).toHaveBeenCalledTimes(0);
        expect(compileSimSpy).toHaveBeenCalledTimes(0);
        expect(moveSpy).toHaveBeenCalledTimes(0);
        expect(deleteSpy).toHaveBeenCalledTimes(0);
    });

    it("Should Handle Missing Modules on Build", ()=>{

    });

    it("Should Build Modules And Rebuild Simulation", ()=>{

    });

    // builds modules

    // removes modules

    


});