import fs   from 'fs';
import tar  from 'tar';

import { Logger } from '../../logging/Logging';
import { Status } from "../../data_models/Status";


const fileExists = (filePath: string) : boolean => {
    return fs.existsSync(filePath);
};

const deleteFile = (filePath: string) : Status => {
    if(!fileExists(filePath)){
        return Status.NOT_FOUND;
    }else{
        fs.rmSync(filePath);
        return Status.SUCCESS;
    }
};

const deleteDir = (dirPath : string, recursive : boolean) : Status => {
    if(!fileExists(dirPath)){
        return Status.NOT_FOUND;
    }else{
        fs.rm(dirPath, {recursive}, (err)=>{
            if(err){
                Logger.error(`Error in deleteDir: ${err.message}`);
                return Status.INTERNAL_ERROR;
            }
        });
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

const tarDirectory = async (baseDirPath : string, dirName: string, outDirPath : string) : Promise<{status: Status; path: string}> => {
    return new Promise((resolve, reject)=>{
        tar.create({
            cwd: baseDirPath,
            file: `${outDirPath}/${dirName}.tar`
        }, [dirName], (err)=>{
            if(err){
                Logger.error(`Error in TarFiles: ${err.message}`);
                reject(err);
            }
            resolve({
                status: Status.SUCCESS,
                path: baseDirPath.concat('\\', dirName, '.tar')
            });
        });
    });
};

export {
    fileExists,
    deleteFile,
    deleteDir,
    tarDirectory,
    writeFile,
    makeDir
};