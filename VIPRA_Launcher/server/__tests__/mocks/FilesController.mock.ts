import fs from 'fs';
import { ModulesFile } from '../../src/types/module';

import { Status } from "../../src/types/Status";
import { installedModules } from '../values/modules';

type Nullable<T> = T | null;
const SUCCESSFUL_PATH = 'successful/path';
const FAILED_PATH = 'failed/path';


export class mockFilesController{

    private fail            : boolean;
    private resultStatus    : Status;
    
    constructor() {
        this.fail = false;
        this.resultStatus = Status.SUCCESS;
    }

    public setFail(fail : boolean) : void {
        this.fail = fail;
    }

    public setResultStatus(status : Status) : void {
        this.resultStatus = status;
    }

    public getDirContents(dirPath: string) : fs.Dirent[] {
        if(this.fail){
            return [new fs.Dirent()];
        }else{
            return [];
        }
    }

    public forAllFilesThatMatchDo(regex : RegExp, root : string, func : (filePath : string)=>void) : void {
        return;
    }

    public fileExists (filePath: string) : boolean {
        return !this.fail;
    }

    public deleteFile(filePath: string) : Status {
        return this.resultStatus;
    }

    public deleteDir(dirPath : string, recursive : boolean) : Status {
        return this.resultStatus;
    }

    public readFile(filePath : string) : Nullable<string> {
        if(this.fail){
            return null;
        }else{
            return 'test file contents';
        }
    }

    public moveFile(fromPath : string, toPath : string) : void {
        return;
    }

    public checkReadPerms (filePath : string) : boolean {
        return !this.fail;
    }

    public matchFile (regex : RegExp, dirPath : string, recursive : boolean) : Nullable<string> {
        if(this.fail){
            return null;
        }else{
            return 'successful/path';
        }
    }

    public async extractTar (sourceDirPath : string, tarName : string, outDirPath : string) : Promise<{status: Status; path: Nullable<string>}> {
        if(!this.fail){
            return {status: Status.SUCCESS, path: SUCCESSFUL_PATH};
        }else{
            return {status: Status.NOT_FOUND, path: null}
        }
    }

    public async tarDirectory(baseDirPath : string, dirName: string, outDirPath : string) : Promise<{status: Status; path: Nullable<string>}> {
        if(this.resultStatus === Status.SUCCESS){
            return {status: this.resultStatus, path: 'example/path'};
        }else{
            return {status: this.resultStatus, path: null};
        }
    }

    public makeDir(dirPath: string) : void {
        return;
    }

    public writeFileFromBuffer(dirPath : string, filename : string, buffer : Buffer) : Status {
        return this.resultStatus;
    }

    public writeFile(filePath : string, content : string) : void {
        return;
    }

    public readJsonFile<T>(filePath : string, options : {error:boolean}) : Nullable<T> {
        if(filePath === SUCCESSFUL_PATH){
            return {} as T;
        }else{
            return null;
        }
    }

    public readJsonBuffer <T>(buffer : Buffer) : Nullable<T> {
        if(!this.fail){
            return {} as T;
        }else{
            return null;
        }
    }

    public loadInstalledModules(baseDirPath : string) : ModulesFile {
        if(this.fail){
            return new ModulesFile();
        }else{
            return installedModules as ModulesFile;
        }
    }
}