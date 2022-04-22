

const { SOURCE_DIR_PATH, BUILD_DIR_PATH, AUTOCONF_DIR_PATH, INCLUDE_DIR_PATH } = require('../../../configurations/File_Paths');
const { CopyFileFromTo, DeleteFile, CopyDirContentsTo, DeleteDirectory, MakeDir, MakeDirIfNotExists } = require('../../Files/FileOperations');
const tar = require('tar');

// TODO NEXT this

class mock_AutoconfBuilder{

    #callCounts;

    constructor(){
        this.Reset();
    }

    Reset(){
        this.#callCounts = {
            "BuildImage": 0,
            "MakeBuildDir": 0,
            "CleanUpBuild": 0
        };
    }

    async BuildImage(build_config, configID){
        this.#callCounts["BuildImage"]++;
    }

    async MakeBuildDir(configID){
        this.#callCounts["MakeBuildDir"]++;
        
    }

    async CleanUpBuild(configID){
        this.#callCounts["CleanUpBuild"]++;
    }
}

module.exports = mock_AutoconfBuilder;