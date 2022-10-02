import { Status } from "../../src/types/Status";

export const SimBuilderMock = () => {
    jest.mock('../../src/controllers/simulation/SimBuilder', ()=>{
        return{
            SimBuilder: jest.fn().mockImplementation(()=>{
                return {
                    setFlags: (flags : Map<string, string>)=>{},
                    addedModule: ()=>{return {status : Status.SUCCESS, message : null};},
                    compileSimulation: ()=>{return {status : Status.SUCCESS, message : null};},
                    removedModule: ()=>{return {status: Status.SUCCESS, message: null};}
                }
            })
        }
    });
}