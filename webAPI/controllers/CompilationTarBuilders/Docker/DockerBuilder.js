const fs = require('fs');
const fsExtra = require('fs-extra');
const tar = require('tar');

const { SOURCE_DIR_PATH, IMAGES_DIR_PATH, BUILD_DIR_PATH, INPUT_DATA_PATH } = require('../../../configurations/File_Paths');

// TODO add FileOperations and use those methods

class DockerBuilder{
    constructor(){
        throw(`DockerBuilder is needs updating to work with the current system`);
    }

    // TODO return more descriptive errors (maybe use a STATUS) -RG
    // TODO currently adds all source code, only needs to get what the sim_config requires -RG
    // TODO remove build files after returned -RG
    // returns filepath to zip/tar file
    async BuildImage(build_config, configID){
        const targetOS = build_config.targetOS;
        if(this.#checkOS(targetOS.OS)){
            const buildDir = await this.MakeBuildDir(configID);
            await this.#CopySourceToBuild(buildDir, configID);
            await this.#CopyDockerfile(buildDir, targetOS);
            await this.#CopyMakefile(buildDir, targetOS);
            //await this.#CopyGeneratedMain(buildDir, configID);
            await this.#PackageFiles(buildDir, targetOS, configID);
            return BUILD_DIR_PATH.concat('/', configID, '.tar');
        }else{
            return null;
        }
    }

    // TODO provide a more user friendly name for the tar file -RG
    async #PackageFiles(buildDir, targetOS, configID){
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

    // NOTE: goes through checkOS so doesn't need input checking -RG
    async #CopyMakefile(buildDir, targetOS){
        fs.copyFileSync(IMAGES_DIR_PATH.concat('/', targetOS.OS, '/Makefile'), buildDir.concat('/Makefile'));
    }

    // TODO doesn't check for errors -RG
    async MakeBuildDir(configID){
        const dirPath = BUILD_DIR_PATH.concat('/', configID);
        if(!fs.existsSync(dirPath)){
            await fs.mkdirSync(dirPath);
        }
        return dirPath;
    }

    // TODO copies all source, only need what the config calls for -RG
    async #CopySourceToBuild(buildDir, configID){
        await fsExtra.copy(SOURCE_DIR_PATH, buildDir);
    }

    // NOTE: goes through checkOS so doesn't need input checking -RG
    async #CopyDockerfile(buildDir, targetOS){
        fs.copyFileSync(IMAGES_DIR_PATH.concat('/', targetOS.OS, '/Dockerfile'), buildDir.concat('/Dockerfile'));
    }

    #checkOS(targetOS){
        if(targetOS === 'Linux'){
            return true;
        }
        console.log(`[ERROR] Target OS not set correctly: ${targetOS}`);
        return false;
    }
}

module.exports = DockerBuilder;