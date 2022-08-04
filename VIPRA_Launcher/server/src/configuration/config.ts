import { readJsonFile } from '../util/FileOperations';

interface Config{
    setup : boolean;
    app: {
        debug : boolean;
        port : Number;
        https: {key : string | null; cert : string | null; passphrase : string | null};
    };
    cb: {url : string};
    vipra: {vipraDir : string; simsDir : string; behaviorDir : string; outputDir: string};
    simconfig: {configsFile : string};
    module: {modulesFile : string};
}

const loadConfig = (configFile : string) : Config => {
    const conf = readJsonFile<Config>(configFile, {error: false});
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
            module: {modulesFile: ''}
        };
    }
    return conf;
};

export const config : Config = loadConfig(`${__dirname}/config.json`);