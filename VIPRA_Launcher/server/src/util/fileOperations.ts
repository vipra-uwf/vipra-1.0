import fs from 'fs';
import { Nullable } from '../types/typeDefs';
import { Status } from '../types/status';

/**
 * @description Returns list of files in the provided directory
 *
 * @param  {string} dirPath - path to directory to get contents of
 */
const getDirContents = (dirPath: string) : fs.Dirent[] => {
  return fs.readdirSync(dirPath, { withFileTypes:true });
};

/**
 * @description Finds all files under root that match regex, and applies func
 *
 * @param  {RegExp} regex - regular expression to match file names
 * @param  {string} root - path to start directory
 * @param  {(filePath:string)=>void} func - function to be applied to each file found
 */
const forAllFilesThatMatchDo = (regex : RegExp, root : string, func : (filePath : string)=>void) : void => {
  const files : fs.Dirent[] = getDirContents(root);

  files.forEach((file)=>{
    const filePath = `${root}/${file.name}`;
    if (file.isDirectory()) {
      forAllFilesThatMatchDo(regex, filePath, func);
    } else {
      if (file.name.match(regex)) {
        func(filePath);
      }
    }
  });
};

/**
 * @description Returns if a file at the filepath exists
 * @param {string} filePath - absolute path to file
 */
const fileExists = (filePath : string) : boolean => {
  return fs.existsSync(filePath);
};

/**
 * @description Deletes the file at filePath
 * Returns Status.NOT_FOUND if the file does not exist
 *
 * @param  {string} filePath - path to file to delete
 */
const deleteFile = (filePath: string) : Status => {
  if (!fileExists(filePath)) {
    return Status.NOT_FOUND;
  } else {
    fs.rmSync(filePath);
    return Status.SUCCESS;
  }
};


/**
 * @description Deletes a directory
 * recursively deletes all child directories if recursive is set to true
 *
 * @param  {string} dirPath - path to directory to delete
 * @param  {boolean} recursive - whether to delete child directories
 */
const deleteDir = (dirPath : string, recursive : boolean) : Promise<Status> => {
  if (!fileExists(dirPath)) {
    return Promise.resolve(Status.NOT_FOUND);
  } else {
    return new Promise((resolve, reject)=>{
      fs.rm(dirPath, { recursive }, (err)=>{
        if (err) {
          reject(err);
        }
        resolve(Status.SUCCESS);
      });
    });
  }
};

/**
 * @description Writes content to file
 *
 * @param  {string} filePath - path to file to write to
 * @param  {string} content - string with content to be written to file
 */
const writeFile = (filePath : string, content : string) : void => {
  fs.writeFileSync(filePath, content);
};

/**
 * @description Writes content to file
 *
 * @param  {string} filePath - absolute path to file to be written to
 * @param  {Buffer} buffer - buffer with content to be written to file
 */
const writeFileFromBuffer = (filePath : string, buffer : Buffer) : Promise<Status> => {
  return new Promise((resolve)=> {
    fs.writeFileSync(filePath, buffer);
    resolve(Status.SUCCESS);
  });
};

/**
 * @description Makes a directory if it does not already exist
 *
 * @param  {string} dirPath - path to directory to be made
 */
const makeDir = (dirPath: string) : void => {
  if (!fs.existsSync(dirPath)) {
    fs.mkdirSync(dirPath);
  }
};

/**
 * @description Checks if the process has read permissions to a file
 *
 * @param  {string} filePath - path to file/directory to check permissions of
 */
const checkReadPerms = (filePath : string) : boolean => {
  try {
    fs.accessSync(filePath, fs.constants.R_OK);
    return true;
  } catch (err) {
    return false;
  }
};

/**
 * @description Returns the first instance of a file that matches regex
 *
 * @param  {RegExp} regex - regular expression to match filename
 * @param  {string} dirPath - starting directory
 * @param  {boolean} recursive - whether to check all children directories
 */
const matchFile = (regex : RegExp, dirPath : string, recursive : boolean) : Nullable<string> => {
  if (checkReadPerms(dirPath)) {
    try {
      const files : fs.Dirent[] = fs.readdirSync(dirPath, { withFileTypes:true });
      const match : number = files.findIndex((file)=>{
        if (file.name.match(regex)) {
          return true;
        }
        return false;
      });

      if (match !== -1) {
        return `${dirPath}/${files[match].name}`;
      }

      let recursiveMatch : Nullable<string> = null;
      if (recursive) {
        files.some((file)=>{
          if (file.isDirectory()) {
            recursiveMatch = matchFile(regex, `${dirPath}/${file.name}`, true);
            if (recursiveMatch) {
              return true;
            }
          }
        });
      }

      if (recursiveMatch) {
        return recursiveMatch;
      } else {
        return null;
      }
    } catch (err) {
      return null;
    }
  }
  return null;
};


/**
 * @description Moves a file from fromPath to toPath
 *
 * @param  {string} fromPath - path to file to move
 * @param  {string} toPath - path to where file is to be moved
 */
const moveFile = (fromPath : string, toPath : string) : void => {
  fs.copyFileSync(fromPath, toPath);
};

/**
 * @description Returns the contents of a file
 *
 * @param  {string} filePath - path to file to read
 */
const readFile = (filePath : string) : Nullable<string> => {
  try {
    return fs.readFileSync(filePath).toString();
  } catch (e) {
    return null;
  }
};

/**
 * @description Returns the object described by the JSON in the provided buffer
 * Returns null if the object is not of type T
 *
 * @param  {Buffer} buffer - buffer with JSON object
 */
const readJsonBuffer = <T>(buffer : Buffer) : Nullable<T> => {
  try {
    const obj : T = Object.assign({}, JSON.parse(buffer.toString()) as T);
    return obj;
  } catch (e) {
    return null;
  }
};

/**
 * @description Returns object described by JSON in the file at filePath
 * Returns null if the object is not of type T
 *
 * @param  {string} filePath - path to json file to read
 * @param  {{error:boolean}} options - read options (error, )
 * @param  {boolean} options.error - if true, if being unable to read the file it is treated as an error, if false, it's not
 */
const readJsonFile = <T>(filePath : string) : Nullable<T> => {
  try {
    const obj : T = Object.assign({}, JSON.parse(fs.readFileSync(filePath).toString()) as T);
    return obj;
  } catch (e) {
    return null;
  }
};

export {
  readFile,
  moveFile,
  checkReadPerms,
  matchFile,
  makeDir,
  deleteDir,
  writeFile,
  readJsonBuffer,
  readJsonFile,
  writeFileFromBuffer,
  deleteFile,
  forAllFilesThatMatchDo,
  getDirContents,
};