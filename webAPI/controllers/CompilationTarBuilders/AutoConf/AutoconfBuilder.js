const tar = require('tar');

const { SOURCE_DIR_PATH, BUILD_DIR_PATH, AUTOCONF_DIR_PATH, INCLUDE_DIR_PATH } = require('../../../configurations/File_Paths');
const { CopyFileFromTo, DeleteFile, CopyDirContentsTo, DeleteDirectory, MakeDir, MakeDirIfNotExists } = require('../../Files/FileOperations');


class AutoconfBuilder{

    #baseBuildPath;
    #srcPath;
    #includePath;
    
    constructor(pathOptions){
        if(pathOptions.buildPath){
            this.#baseBuildPath = pathOptions.buildPath;
        }else{
            throw(`[FATAL] No Build Path for AutoConfBuilder, pathOptions requires: buildPath`);
        }
        if(pathOptions.srcPath){
            this.#srcPath = pathOptions.srcPath;
        }else{
            throw(`[FATAL] No Source Path for AutoConfBuilder, pathOptions requires: srcPath`);
        }
        if(pathOptions.includePath){
            this.#includePath = pathOptions.includePath;
        }else{
            throw(`[FATAL] No Include Path for AutoConfBuilder, pathOptions requires: includePath`);
        }
    }

    // TODO return more descriptive errors (maybe use a STATUS) -RG
    // NOTE: build_config is not used for autoconf, but keeps the interface so is needed -RG
    async BuildCompilationTar(build_config, configID){
        const buildDir = await this.MakeBuildDir(configID);
        await this.#CopySourceToBuild(buildDir, configID);
        await this.#CopyIncludeToBuild(buildDir, configID);
        await this.#CopyAutoConfFiles(buildDir);
        const packaged = await this.#PackageFiles(buildDir, configID);

        if(packaged){
            await DeleteDirectory(buildDir);
            return this.#baseBuildPath.concat('/', configID, '.tar');
        }else{
            return null;
        }
    }

    // TODO provide a more user friendly name for the tar file -RG
    async #PackageFiles(buildDir, configID){
        const zipName = this.#baseBuildPath.concat('/', configID, '.tar');
        let errored = false;
        await tar.create(
            {
                cwd: this.#baseBuildPath,
                file: zipName
            },
            [configID])
            .catch((err)=>{
                console.log(`[ERROR] Error in PackageFiles: ${err}`);
                errored = true;
            });
        if(errored){
            return null;
        }else{
            return zipName;
        }
    }

    async MakeBuildDir(configID){
        const dirPath = this.#baseBuildPath.concat('/', configID);
        await MakeDir(dirPath);
        return dirPath;
    }

    async CleanUpBuild(configID){
        const tarPath = this.#baseBuildPath.concat('/', configID, '.tar');
        return await DeleteFile(tarPath);
    }

    // TODO currently copies all source, change to only need what the config calls for -RG
    async #CopySourceToBuild(buildDir, configID){
        await CopyDirContentsTo(this.#srcPath, buildDir);
    }

    async #CopyIncludeToBuild(buildDir, configID){
        await CopyDirContentsTo(this.#includePath, buildDir);
    }

    async #CopyAutoConfFiles(buildDir){
        return await CopyDirContentsTo(AUTOCONF_DIR_PATH, buildDir);
    }
}

module.exports = AutoconfBuilder;