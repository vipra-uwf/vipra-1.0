import fs   from 'fs';
import tar  from 'tar';

import { Status } from "../../data_models/Status";


const fileExists = (filePath: string) : boolean => {
    return fs.existsSync(filePath);
};

const deleteFile = async (filePath: string) : Promise<Status> => {
    if(!fileExists(filePath)){
        return Status.NOT_FOUND;
    }else{
        fs.rmSync(filePath);
        return Status.SUCCESS;
    }
};

const writeFile = (dirPath : string, filename : string, content : string) : void =>{
    fs.writeFileSync(dirPath.concat(filename), content);
};

const makeDir = (dirPath: string) : void => {
    if(!fs.existsSync(dirPath)){
        fs.mkdirSync(dirPath);
    }
};

const tarDirectory = async (folderPath : string, tarName: string, dirPath: string) : Promise<{status: Status, path: string}> => {
    const tarOptions = {
        file: folderPath.concat('/', tarName, '.tar'),
    };

    return new Promise((resolve, reject)=>{
        tar.create(tarOptions, [dirPath], (err)=>{
            if(err){
                console.log(`[ERROR] Error in TarFiles: ${err}`);
                reject(err);
            }
            resolve({
                status: Status.SUCCESS,
                path: tarOptions.file
            });
        });
    });
};

export {
    fileExists,
    deleteFile,
    tarDirectory,
    writeFile,
    makeDir
};