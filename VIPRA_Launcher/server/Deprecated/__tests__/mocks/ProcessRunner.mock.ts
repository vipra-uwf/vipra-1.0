import { Status } from "../../src/types/Status";

export const ProcessRunnerMock = () => {
    jest.mock('../../src/controllers/processes/ProcessRunner', ()=>{
        return{
            ProcessRunner: jest.fn().mockImplementation(()=>{
                return {
                    buildModule: ()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})},
                    compileHumanBehavior: ()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})},
                    compileGenMain: ()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})},
                    compileMain: ()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})},
                    compileSim: ()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS);})},
                    precompileHeaders: ()=>{return new Promise((resolve)=>{resolve(Status.SUCCESS)})}
                }
            })
        }
    });
}