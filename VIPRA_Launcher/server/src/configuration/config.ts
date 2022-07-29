import path from 'path';
import fs from 'fs';
import { readJsonFile } from '../util/FileOperations';

// TODO!!!! change this to be set from environment -RG

interface Config{
    setup : boolean;
    app: {
        port : Number;
        https: {key : string | null; cert : string | null; passphrase : string | null};
    };
    cb: {url : string};
    vipra: {vipraDir : string; simsDir : string; behaviorDir : string; outputDir: string};
    module: {modulesFile : string};
}

const loadConfig = (configFile : string) : Config => {
    const conf = readJsonFile<Config>(configFile, {error: false});
    if(!conf){
        return {
            setup: false,
            app: {
                port: -1,
                https: {key: null, cert: null, passphrase: null}
            },
            cb: {url: ''},
            vipra: {vipraDir: '', simsDir: '', behaviorDir: '', outputDir: ''},
            module: {modulesFile: ''}
        };
    }
    return conf;
};

export const config : Config = loadConfig(`${__dirname}/config.json`);