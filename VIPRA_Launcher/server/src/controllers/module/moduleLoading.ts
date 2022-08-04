import { forAllFilesThatMatchDo, readJsonFile, writeFile } from "../../util/FileOperations";
import { Module, ModulesFile, verifyModule } from "../../data_models/module";
import { config } from "../../configuration/config";
import { Logger } from "../../logging/Logging";
import { buildModule } from "../../util/Processes";


// TODO !!! see about modules with paths for names and whether it is a security concern -RG

const loadInstalledModules = () : ModulesFile => {
    const modules : ModulesFile = new ModulesFile();
    forAllFilesThatMatchDo(/.*\.mm/, config.vipra.vipraDir, (filePath : string)=>{
        const module : Module = verifyModule(readJsonFile<Module>(filePath, {error: true}));
        if(module){
            const basePath : string = filePath.substring(0, filePath.indexOf(`/${module.name}.mm`));
            module.dirPath = `${basePath}`;
            module.includePath = `${basePath}/${module.name}.hpp`;
            Logger.info(`Found Module: ${module.name}:${module.id} ${module.type}`);
            modules[module.type].push(module);
        }
    });
    return modules;
};

const saveInstalledModules = (modules : ModulesFile) : void => {
    writeFile(config.module.modulesFile, JSON.stringify(modules));
};

const compileAllModules = async (modules : ModulesFile, debug : boolean) : Promise<void> =>{
    for(const key of Object.keys(modules)){
        for(const value of Object.values(modules.getModules(key))){
            await buildModule(value, debug)
            .catch((error : string)=>{
                value.compiled = false;
                Logger.error(`Unable to build module: ${value.name}:${value.id} ERROR: ${error}`);
            });
            value.compiled = true;
        }
    }
};

const readModules = () : ModulesFile => {
    const modules = new ModulesFile();
    Object.assign(modules, readJsonFile<ModulesFile>(config.module.modulesFile, {error: true}));
    return modules;
};


export {
    loadInstalledModules,
    saveInstalledModules,
    compileAllModules,
    readModules
};