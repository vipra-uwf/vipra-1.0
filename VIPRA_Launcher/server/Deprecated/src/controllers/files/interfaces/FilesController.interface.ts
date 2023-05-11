
import fs from 'fs';
import { Nullable } from '../../../types/typeDefs';
import { Status } from '../../../types/Status';

export interface IFilesController {
  getDirContents(dirPath: string) : fs.Dirent[];
  getDirContents(dirPath: string) : fs.Dirent[];
  forAllFilesThatMatchDo(regex : RegExp, root : string, func : (filePath : string)=>void) : void;
  fileExists(filePath: string) : boolean;
  deleteFile(filePath: string) : Status;
  deleteDir(dirPath : string, recursive : boolean) : Status;
  readJsonFile<T>(filePath : string, options : { error:boolean }) : Nullable<T>;
  readJsonBuffer <T>(buffer : Buffer) : Nullable<T>;
  writeFile(filePath : string, content : string) : void;
  writeFileFromBuffer(filePath : string, buffer : Buffer) : Status;
  makeDir(dirPath: string) : void;
  tarDirectory(baseDirPath : string, dirName: string, outDirPath : string) : Promise<{ status: Status; path: Nullable<string> }>;
  extractTar(sourceDirPath : string, tarName : string, outDirPath : string) : Promise<{ status: Status; path: Nullable<string> }>;
  matchFile(regex : RegExp, dirPath : string, recursive : boolean) : Nullable<string>;
  checkReadPerms(filePath : string) : boolean;
  moveFile(fromPath : string, toPath : string) : void;
  readFile(filePath : string) : Nullable<string>;
}