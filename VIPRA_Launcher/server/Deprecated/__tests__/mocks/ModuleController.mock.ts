import { Status } from "../../src/types/Status";

export const ModuleControllerMock = () => {
    jest.mock('../../src/controllers/module/moduleController', ()=>{
        return{
            ModuleController: jest.fn().mockImplementation(()=>{
                return {
                    getModules: ()=>{},
                    setFlags: (flags : Map<string, string>)=>{},
                    addModule: ()=>{return {status : Status.SUCCESS, message : null};},
                    compileSimulation: ()=>{return {status : Status.SUCCESS, message : null};},
                    removeModule: ()=>{return {status: Status.SUCCESS, message: null};},
                    checkModule: (id : string)=>{
                        if(id === 'goodmodule'){
                            return {status: Status.SUCCESS, message: null};
                        }else{
                            return {status: Status.NOT_FOUND, message: null};
                        }
                    }
                }
            })
        }
    });
}

// getModules() : Protect<ModulesFile>;
//   allModulesInfo() : { [type: string] : ModuleInfo[] };
//   getModulesofType(type : ModuleType) : Module[];
//   installModule(moduleInfo : ModuleInfo, fileBuffers : FileBuffers) : Promise<FuncResult>;
//   removeModule(id : string) : FuncResult;
//   checkModule(id : string) : FuncResult;