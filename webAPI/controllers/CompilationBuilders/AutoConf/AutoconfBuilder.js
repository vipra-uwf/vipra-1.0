

const { SOURCE_DIR_PATH, BUILD_DIR_PATH, AUTOCONF_DIR_PATH, INCLUDE_DIR_PATH } = require('../../../configurations/File_Paths');
const { CopyFileFromTo, DeleteFile, CopyDirContentsTo, DeleteDirectory, MakeDir, MakeDirIfNotExists } = require('../../Files/FileOperations');
const tar = require('tar');


class AutoconfBuilder{
    constructor(){}

    // TODO return more descriptive errors (maybe use a STATUS) -RG
    // NOTE: build_config is not used for autoconf, but keeps the interface so is needed -RG
    async BuildImage(build_config, configID){
        const buildDir = await this.MakeBuildDir(configID);
        await this.#CopySourceToBuild(buildDir, configID);
        await this.#CopyIncludeToBuild(buildDir, configID);
        await this.#CopyAutoConfFiles(buildDir);
        //await this.#CopyGeneratedMain(buildDir, configID); - not needed as currently generates sim to build folder -RG
        await this.#PackageFiles(buildDir, configID);
        await DeleteDirectory(buildDir);
        return BUILD_DIR_PATH.concat('/', configID, '.tar');
    }

    // TODO provide a more user friendly name for the tar file -RG
    async #PackageFiles(buildDir, configID){
        const zipName = BUILD_DIR_PATH.concat('/', configID, '.tar');
        await tar.create(
            {
                cwd: BUILD_DIR_PATH,
                file: zipName
            },
            [configID])
            .catch((err)=>{
                console.log(`[ERROR] Error in PackageFiles: ${err}`);
            });
        return zipName;
    }

    async MakeBuildDir(configID){
        const dirPath = BUILD_DIR_PATH.concat('/', configID);
        await MakeDirIfNotExists(dirPath);
        return dirPath;
    }

    async CleanUpBuild(configID){
        const tarPath = BUILD_DIR_PATH.concat('/', configID, '.tar');
        return await DeleteFile(tarPath);
    }

    // TODO copies all source, only need what the config calls for -RG
    async #CopySourceToBuild(buildDir, configID){
        await CopyDirContentsTo(SOURCE_DIR_PATH, buildDir);
    }

    async #CopyIncludeToBuild(buildDir, configID){
        await CopyDirContentsTo(SOURCE_DIR_PATH, buildDir);
    }

    async #CopyAutoConfFiles(buildDir){
        return await CopyDirContentsTo(AUTOCONF_DIR_PATH, buildDir);
    }
}

module.exports = AutoconfBuilder;