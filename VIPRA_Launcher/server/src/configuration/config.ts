/**
 * @module Config
 */

import 'reflect-metadata';
import { Nullable } from "../types/typeDefs";
import { container } from "tsyringe";
import { FilesController } from "../controllers/files/FilesController";


const fc = container.resolve(FilesController);

interface Config{
    setup : boolean;
    app: {
        debug : boolean;
        port : Number;
        https: {key : string | null; cert : string | null; passphrase : Nullable<string>};
    };
    cb: {url : string};
    vipra: {vipraDir : string; simsDir : string; behaviorDir : string; outputDir: string};
    simconfig: {configsFile : string};
    module: {modulesFile : string};
    map: {mapsFile : string};
}

const loadConfig = (configFile : string) : Config => {
    const conf = fc.readJsonFile<Config>(configFile, {error: false});
    if(!conf){
        return {
            setup: false,
            app: {
                debug : false,
                port: -1,
                https: {key: null, cert: null, passphrase: null}
            },
            cb: {url: ''},
            vipra: {vipraDir: '', simsDir: '', behaviorDir: '', outputDir: ''},
            simconfig: {configsFile: ''},
            module: {modulesFile: ''},
            map: {mapsFile: ''}
        };
    }
    return conf;
};

export const config : Config = loadConfig(`${__dirname}/config.json`);