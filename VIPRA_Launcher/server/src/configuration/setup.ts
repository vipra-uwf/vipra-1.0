import path from 'path';
import prompt from 'prompt-sync';
import ip from 'ip';

import { config }  from "./config";
import { fileExists, makeDir, matchFile, writeFile } from "../util/FileOperations";
import { compileMain, compileHumanBehavior, compileSim, compileGenMain } from "../util/Processes";
import { compileAllModules, loadInstalledModules, saveInstalledModules } from "../controllers/module/moduleLoading";
import { ModulesFile } from "../data_models/module";
import { Logger } from "../logging/Logging";

/* eslint-disable no-console */

const prompter = prompt();

const debugSetup = () : void => {
    const vipraDir = findVipra();

    config.vipra.vipraDir = vipraDir;
    config.vipra.behaviorDir = `${vipraDir}/Base/dsl`;
    config.vipra.simsDir = `${vipraDir}/sims`;
    config.vipra.outputDir = path.resolve('./OUTPUT');
    config.module.modulesFile = path.resolve(`./modules.json`);

    config.cb.url = `${ip.address()}:3001`;
    config.app.port = 3001;
    config.app.https = {
        key: "/usr/src/VIPRA/certs/local.pem",
        cert: "/usr/src/VIPRA/certs/local.crt",
        passphrase: null
    };

    config.setup = true;
    writeFile(path.resolve(`${__dirname}/config.json`), JSON.stringify(config));
};

// TODO: this will find the first instance of a file named vipra.info, if it is in the trash or something then this completely messes up -RG
const initialSetup = (argsMap : Map<string, string>) : void => {

    if(!config.setup){

        const vipraDir = findVipra();

        config.vipra.vipraDir = vipraDir;
        config.vipra.behaviorDir = `${vipraDir}/Base/dsl`;
        config.vipra.simsDir = `${vipraDir}/sims`;
        config.vipra.outputDir = path.resolve('./OUTPUT');
        config.module.modulesFile = path.resolve(`./modules.json`);

        setupHTTPS();

        config.setup = true;
        writeFile(path.resolve(`${__dirname}/config.json`), JSON.stringify(config));
    }

    // TODO check that nothing has broken since initial setup -RG

};

const findVipra = () : string => {
    const osType = process.platform;
    let vipraInfoPath : string;

    Logger.info(`Finding VIPRA Source Directory`);
    if(osType === 'win32'){
        vipraInfoPath = matchFile(/vipra\.info/, path.resolve(`C://`), true);
    }else{
        vipraInfoPath = matchFile(/vipra\.info/, path.resolve(`/`), true);
    }
    if(!vipraInfoPath){
        throw new Error(`Unable to find VIPRA Source Directory`);
    }

    Logger.info(`Found VIPRA Source at: ${path.dirname(vipraInfoPath)}`);
    return path.dirname(vipraInfoPath);
};

const setupHTTPS = () => {
    config.cb.url = getURL();
    config.app.https = getHTTPS();
    config.app.port = getPort();
};

const getPort = () : Number => {
    let port : Number = -1;
    while(port < 1 || port > 65535){
        port = parseInt(prompter("PORT Number for Server: "), 10);
    }
    return port;
}

// TODO provide output for improper input -RG

const getURL = () : string => {
    let url = "";
    while(!checkURL(url)){
        url = prompter("URL or IPv4 address for this server: ");
    }
    return httpsURL(url);
};

// TODO figure out how to best handle passphrase -RG
const getHTTPS = () : {key : string; cert: string; passphrase : string} => {
    let key = "";
    let ok = false;
    while(!ok){
        key = prompter("Path to HTTPS Key file: ");
        if(fileExists(key)){
           ok = true;
        }else{
            console.log(`Provided File does not exist: ${key}`);
        }
    }
    let cert = "";
    ok = false;
    while(!ok){
        cert = prompter("Path to HTTPS Cert file: ");
        if(fileExists(cert)){
            ok = true;
         }else{
             console.log(`Provided File does not exist: ${cert}`);
         }
    }

    return {
        key,
        cert,
        passphrase: null
    };
};

const httpsURL = (url : string) : string => {
    if(url.match(/^https:\/\//)){
        return url;
    }else{
        return `https://${url}`;
    }
};

const checkURL = (url : string) : boolean => {
    if(url.match(/^http:/)){
        return false;
    }
    if(!url.match(/^(https:\/\/)?(?:www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b(?:[-a-zA-Z0-9()@:%_\+.~#?&\/=]*)$/)
        &&
        !url.match(/(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?(:((6553[0-5])|(655[0-2][0-9])|(65[0-4][0-9]{2})|(6[0-4][0-9]{3})|([1-5][0-9]{4})|([0-5]{0,5})|([0-9]{1,4}))))?/)
    ){
        return false;
    }
    return true;
};

const startup = async (debugStartup : boolean) : Promise<void> => {
    makeDirectories();

    const modules : ModulesFile = loadInstalledModules();

    await compileHumanBehavior(debugStartup)
    .catch((error : string)=>{
        Logger.info(`compileHumanBehavior failed: ${error}`);
    });

    await compileAllModules(modules, debugStartup)
    .catch((error : string)=>{
        Logger.error(`compileAllModules failed: ${error}`);
    });
    saveInstalledModules(modules);

    await compileGenMain(debugStartup)
    .catch((error : string) => {
        Logger.error(`compileGenMain failed: ${error}`);
    });

    await compileMain(debugStartup)
    .catch((error : string)=>{
        Logger.error(`compileMain failed: ${error}`);
    });

    await compileSim(debugStartup)
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
    initialSetup,
    debugSetup,
    startup
};