import fs from 'fs';
import tar from 'tar';

import { Status } from "../../data_models/Status";


const FileExists = (filePath: string) : boolean => {
    return fs.existsSync(filePath);
};

const DeleteFile = async (filePath: string) : Promise<Status> => {
    if(!FileExists(filePath)){
        return Status.NOT_FOUND;
    }else{
        fs.rmSync(filePath);
        return Status.SUCCESS;
    }
};

const TarFiles = async (folderPath : string, tarName: string, filePaths: string[]) : Promise<{status: Status, path: string}> => {
    const tarOptions = {
        file: folderPath.concat('/', tarName, '.tar'),
    };

    return new Promise((resolve, reject)=>{
        tar.create(tarOptions, filePaths, (err)=>{
            if(err){
                console.log(`[ERROR] Error in TarFiles: ${err}`);
                reject(err);
            }
            resolve({
                status: Status.SUCCESS,
                path: folderPath.concat('/', tarName, '.tar')
            });
        });
    });
};

export {
    FileExists,
    TarFiles
};