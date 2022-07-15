import fs   from 'fs';
import tar  from 'tar';

import { Logger } from '../logging/Logging';
import { Status } from "../data_models/Status.e";


const getDirContents = (dirPath: string) : fs.Dirent[] => {
    return fs.readdirSync(dirPath, {withFileTypes:true});
};

const forAllFilesThatMatchDo = (regex : RegExp, root : string, func : (filePath : string)=>void) : void => {
    const files : fs.Dirent[] = getDirContents(root);

    files.forEach((file)=>{
        const filePath = `${root}/${file.name}`;
        if(file.isDirectory()){
            forAllFilesThatMatchDo(regex, filePath, func);
        }else{
            if(file.name.match(regex)){
                func(filePath);
            }
        }
    });
};

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

const readJsonFile = <T>(filePath : string) : T => {
    try {
        const json : T = JSON.parse(fs.readFileSync(filePath).toString()) as T;
        return json;
    } catch(e){
        Logger.error(`readJsonFile: Unable to Load Object from : ${filePath}`);
        return null;
    }
};

const writeFile = (filePath : string, content : string) : void =>{
    fs.writeFileSync(filePath, content);
};


const writeFileFromBuffer = (dirPath : string, filename : string, buffer : Buffer) : Status =>{
    fs.writeFileSync(dirPath.concat('/', filename), buffer);
    return Status.SUCCESS;
};

const makeDir = (dirPath: string) : void => {
    if(!fs.existsSync(dirPath)){
        fs.mkdirSync(dirPath);
    }
};

const tarDirectory = (baseDirPath : string, dirName: string, outDirPath : string) : Promise<{status: Status; path: string}> => {
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

const extractTar = async (sourceDirPath : string, tarName : string, outDirPath : string) : Promise<{status: Status; path: string}> => {
    makeDir(outDirPath);
    await tar.extract({cwd: outDirPath, file: sourceDirPath.concat('/', tarName)});
    return {status: Status.SUCCESS, path: `${outDirPath}`};
};

const matchFile = (regex : RegExp, dirPath : string, recursive : boolean) : string => {
    const files : fs.Dirent[] = fs.readdirSync(dirPath, {withFileTypes:true});
    const match : number = files.findIndex((file)=>{
        if(file.name.match(regex)){
            return true;
        }
        return false;
    });

    if(match !== -1){
        return `${dirPath}/${files[match].name}`;
    }

    let recursiveMatch : string;
    if(recursive && match === -1){
        files.every((file)=>{
            if(file.isDirectory()){
                recursiveMatch = matchFile(regex, `${dirPath}/${file.name}`, true);
                return (!recursiveMatch);
            }
        });
    }

    if(recursiveMatch){
        return recursiveMatch;
    }else{
        return null;
    }
};

const moveFile = (fromPath : string, toPath : string) : void => {
    fs.copyFileSync(fromPath, toPath);
};


export {
    fileExists,
    deleteFile,
    deleteDir,
    tarDirectory,
    getDirContents,
    extractTar,
    readJsonFile,
    writeFile,
    writeFileFromBuffer,
    forAllFilesThatMatchDo,
    makeDir,
    moveFile,
    matchFile
};