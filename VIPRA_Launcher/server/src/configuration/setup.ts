import { config } from "./config";
import { makeDir } from "../util/FileOperations";
import { compileMain, compileHumanBehavior, compileSim, compileGenMain } from "../util/Processes";
import { compileAllModules, loadInstalledModules, saveInstalledModules } from "../controllers/module/moduleLoading";
import { ModulesFile } from "../data_models/module";
import { Logger } from "../logging/Logging";



const initialSetup = async () : Promise<void> => {
    makeDirectories();

    const modules : ModulesFile = loadInstalledModules();

    await compileHumanBehavior()
    .catch((error : string)=>{
        Logger.info(`compileHumanBehavior failed: ${error}`);
    });

    await compileAllModules(modules)
    .catch((error : string)=>{
        Logger.error(`compileAllModules failed: ${error}`);
    });
    saveInstalledModules(modules);

    await compileGenMain()
    .catch((error : string) => {
        Logger.error(`compileGenMain failed: ${error}`);
    });

    await compileMain()
    .catch((error : string)=>{
        Logger.error(`compileMain failed: ${error}`);
    });

    await compileSim()
    .catch((error : string) => {
        Logger.error(`compileSim failed: ${error}`);
    });
};

const makeDirectories = () : void =>{
    makeDir(config.vipra.vipraDir);
    makeDir(config.vipra.outputDir);
    makeDir(config.vipra.simsDir);
};


export {
    initialSetup
};