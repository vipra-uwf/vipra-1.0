/**
 * @module FilesController
 */

import 'reflect-metadata';
import fs   from 'fs';
import tar  from 'tar';
import { singleton } from "tsyringe";


import { Nullable } from '../../types/typeDefs';
import { Logger } from '../../logging/Logging';
import { Status } from "../../types/Status";


import { Module, ModulesFile } from '../../types/module';


/**
 * @description Handles file I/O
 *
 * @note Created to allow for mocking of file operations -RG
 */
@singleton()
export class FilesController {

    /**
     * @description Returns list of files in the provided directory
     *
     * @param  {string} dirPath - path to directory to get contents of
     */
    public getDirContents(dirPath: string) : fs.Dirent[] {
        return fs.readdirSync(dirPath, {withFileTypes:true});
    }
    /**
     * @description Finds all files under root that match regex, and applies func
     *
     * @param  {RegExp} regex - regular expression to match file names
     * @param  {string} root - path to start directory
     * @param  {(filePath:string)=>void} func - function to be applied to each file found
     */
    public forAllFilesThatMatchDo(regex : RegExp, root : string, func : (filePath : string)=>void) : void {
        const files : fs.Dirent[] = this.getDirContents(root);

        files.forEach((file)=>{
            const filePath = `${root}/${file.name}`;
            if(file.isDirectory()){
                this.forAllFilesThatMatchDo(regex, filePath, func);
            }else{
                if(file.name.match(regex)){
                    func(filePath);
                }
            }
        });
    }
    /**
     * @description Returns whether the file exists
     *
     * @param  {string} filePath - path to file to check for
     */
    public fileExists (filePath: string) : boolean {
        return fs.existsSync(filePath);
    }

    /**
     * @description Deletes the file at filePath
     * Returns Status.NOT_FOUND if the file does not exist
     *
     * @param  {string} filePath - path to file to delete
     */
    public deleteFile(filePath: string) : Status {
        if(!this.fileExists(filePath)){
            return Status.NOT_FOUND;
        }else{
            fs.rmSync(filePath);
            return Status.SUCCESS;
        }
    }


    /**
     * @description Deletes a directory
     * recursively deletes all child directories if recursive is set to true
     *
     * @param  {string} dirPath - path to directory to delete
     * @param  {boolean} recursive - whether to delete child directories
     */
    public deleteDir(dirPath : string, recursive : boolean) : Status{
        if(!this.fileExists(dirPath)){
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
    }

    /**
     * @description Returns object described by JSON in the file at filePath
     * Returns null if the object is not of type T
     *
     * @param  {string} filePath - path to json file to read
     * @param  {{error:boolean}} options - read options (error, )
     * @param  {boolean} options.error - if true, if unable to read the file it is treated as an error, if false, it's not
     */
    public readJsonFile<T>(filePath : string, options : {error:boolean}) : Nullable<T> {
        try {
            const json : T = JSON.parse(fs.readFileSync(filePath).toString()) as T;
            return json;
        } catch(e){
            if(options.error){
                Logger.error(`readJsonFile: Unable to Load Object from : ${filePath}`);
            }
            return null;
        }
    }

    /**
     * @description Returns the object described by the JSON in the provided buffer
     * Returns null if the object is not of type T
     *
     * @param  {Buffer} buffer - buffer with JSON object
     */
    public readJsonBuffer <T>(buffer : Buffer) : Nullable<T> {
        try{
            const obj : T = Object.assign({}, JSON.parse(buffer.toString()) as T);
            return obj;
        }catch(e){
            return null;
        }
    }

    /**
     * @description Writes content to file
     *
     * @param  {string} filePath - path to file to write to
     * @param  {string} content - string with content to be written to file
     */
    public writeFile(filePath : string, content : string) : void {
        fs.writeFileSync(filePath, content);
    }

    /**
     * @description Writes content to file
     *
     * @param  {string} filePath - absolute path to file to be written to
     * @param  {Buffer} buffer - buffer with content to be written to file
     */
    public writeFileFromBuffer(filePath : string, buffer : Buffer) : Status{
        fs.writeFileSync(filePath, buffer);
        return Status.SUCCESS;
    }

    /**
     * @description Makes a directory if it does not already exist
     *
     * @param  {string} dirPath - path to directory to be made
     */
    public makeDir(dirPath: string) : void {
        if(!fs.existsSync(dirPath)){
            fs.mkdirSync(dirPath);
        }
    }

    /**
     * @description Creates a .tar file with the content of the provided directory
     * Returns the path to the created .tar file
     *
     * @param  {string} baseDirPath - path to directory containing the directory to be tarred
     * @param  {string} dirName - name of directory
     * @param  {string} outDirPath - path to directory where .tar is to be placed
     */
    public tarDirectory(baseDirPath : string, dirName: string, outDirPath : string) : Promise<{status: Status; path: Nullable<string>}> {
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
    }


    /**
     * @description Extracts the contents of a .tar file
     * Creates outDirPath if it does not already exist
     *
     * @param  {string} sourceDirPath - path to directory containing the .tar file
     * @param  {string} tarName - the name of the tar file (include .tar)
     * @param  {string} outDirPath - the path of the directory to write the contents to
     */
    public async extractTar (sourceDirPath : string, tarName : string, outDirPath : string) : Promise<{status: Status; path: Nullable<string>}> {
        this.makeDir(outDirPath);
        await tar.extract({cwd: outDirPath, file: sourceDirPath.concat('/', tarName)});
        return {status: Status.SUCCESS, path: `${outDirPath}`};
    }

    /**
     * @description Returns the first instance of a file that matches regex
     *
     * @param  {RegExp} regex - regular expression to match filename
     * @param  {string} dirPath - starting directory
     * @param  {boolean} recursive - whether to check all children directories
     */
    public matchFile (regex : RegExp, dirPath : string, recursive : boolean) : Nullable<string> {
        if(this.checkReadPerms(dirPath)){
            try{
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

                let recursiveMatch : Nullable<string> = null;
                if(recursive){
                    files.some((file)=>{
                        if(file.isDirectory()){
                            recursiveMatch = this.matchFile(regex, `${dirPath}/${file.name}`, true);
                            if(recursiveMatch){
                                return true;
                            }
                        }
                    });
                }

                if(recursiveMatch){
                    return recursiveMatch;
                }else{
                    return null;
                }
            }catch (err){
                return null;
            }
        }
        return null;
    }
    /**
     * @description Checks if the process has read permissions to a file
     *
     * @param  {string} filePath - path to file/directory to check permissions of
     */
    public checkReadPerms (filePath : string) : boolean {
        try{
            fs.accessSync(filePath, fs.constants.R_OK);
            return true;
        }catch (err){
            Logger.info(`No READ Permissions for: ${filePath}`);
            return false;
        }
    }

    /**
     * @description Moves a file from fromPath to toPath
     *
     * @param  {string} fromPath - path to file to move
     * @param  {string} toPath - path to where file is to be moved
     */
    public moveFile(fromPath : string, toPath : string) : void {
        fs.copyFileSync(fromPath, toPath);
    }

    /**
     * @description Returns the contents of a file
     *
     * @param  {string} filePath - path to file to read
     */
    public readFile(filePath : string) : Nullable<string>{
        try{
            return fs.readFileSync(filePath).toString();
        }catch (e){
            return null;
        }
    }

    /**
     * @description Returns a {@link ModulesFile} containing all installed modules
     * Returns an empty {@link ModulesFile} if no modules are installed
     *
     * @param  {string} baseDirPath - root directory to start searching for .mm files from
     */
    public loadInstalledModules(baseDirPath : string) : ModulesFile {
        const ret : ModulesFile = new ModulesFile();
        this.forAllFilesThatMatchDo(/.*\.mm/, baseDirPath, (filePath : string)=>{
            const module : Nullable<Module> = this.readJsonFile<Module>(filePath, {error: true});
            if(module){
                const basePath : string = filePath.substring(0, filePath.indexOf(`/${module.name}.mm`));
                module.dirPath = `${basePath}`;
                module.includePath = `${basePath}/${module.name}.hpp`;
                Logger.info(`Found Module: ${module.name}:${module.id} ${module.type}`);
                module.compiled = this.fileExists(`${baseDirPath}/build/${module.id}.o`);

                ret[module.type].push(module);
            }
        });
        return ret;
    }


    // /**
    //  * @description Loads all sim.config files under baseDirPath
    //  * @param  {string} baseDirPath - root directory to start looking for sim.config files
    //  * @returns SimConfig
    //  */
    // public loadConfigs(baseDirPath : string) : Map<string, SimConfig> {
    //     const configs : Map<string, SimConfig> = new Map();
    //     fc.forAllFilesThatMatchDo(/sim\.config/, baseDirPath, (filePath : string)=>{
    //         const simconfigIDs = fc.readJsonFile<SimConfigIDs>(filePath , {error:false});
    //         if(simconfigIDs){
    //             const id = path.basename(path.dirname(filePath));
    //             const simconfig = this.makeSimConfig(id, simconfigIDs);
    //             if(simconfig){
    //                 Logger.info(`Found Simulation Configuration at: ${filePath}`);
    //                 this.configs.set(id, simconfig);
    //             }
    //         }
    //     });
    //     Logger.info(`Finished Loading Simulation Configurations`);
    //     return configs;
    // }
}