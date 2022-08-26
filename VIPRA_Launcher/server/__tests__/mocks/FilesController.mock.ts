import { Status } from "../../src/types/Status";
import { SUCCESSFUL_PATH } from "../values/paths";
import { mockInstalledModels } from "../values/modules";

export const FilesControllerMock = ()=>{
    jest.mock('../../src/controllers/files/FilesController', () => {
        return{
            FilesController: jest.fn().mockImplementation(()=>{
                return {
                    fileExists: (filePath:string)=>{return filePath===SUCCESSFUL_PATH;},
                    loadInstalledModules: ()=>{return mockInstalledModels();},
                    makeDir: ()=>{},
                    writeFileFromBuffer: ()=>{},
                    deleteDir: (dirPath:string)=>{if(dirPath===SUCCESSFUL_PATH){return Status.SUCCESS;} return Status.NOT_FOUND;},
                    deleteFile: (filePath:string)=>{if(filePath===SUCCESSFUL_PATH){return Status.SUCCESS;} return Status.NOT_FOUND;},
                    writeFile: ()=>{},
                    moveFile: ()=>{}
                }
            })
        }
    });
}