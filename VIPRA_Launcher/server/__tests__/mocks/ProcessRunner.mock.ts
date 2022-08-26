import { Status } from "../../src/types/Status";

export const ProcessRunnerMock = () => {
    jest.mock('../../src/controllers/processes/ProcessRunner', ()=>{
        return{
            ProcessRunner: jest.fn().mockImplementation(()=>{
                return {
                    buildModule: jest.fn(()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})}),
                    compileHumanBehavior: jest.fn(()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})}),
                    compileGenMain: jest.fn(()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})}),
                    compileMain: jest.fn(()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})}),
                    compileSim: jest.fn(()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})}),
                    precompileHeaders: jest.fn(()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS)})})
                }
            })
        }
    });
}