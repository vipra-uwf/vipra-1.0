import { Status } from "../../src/types/Status";

export const ModuleControllerMock = () => {
    jest.mock('../../src/controllers/module/ModuleController', ()=>{
        return{
            SimBuilder: jest.fn().mockImplementation(()=>{
                return {
                    setFlags: (flags : Map<string, string>)=>{},
                    addModule: ()=>{return {status : Status.SUCCESS, message : null};},
                    compileSimulation: ()=>{return {status : Status.SUCCESS, message : null};},
                    removeModule: ()=>{return {status: Status.SUCCESS, message: null};}
                }
            })
        }
    });
}