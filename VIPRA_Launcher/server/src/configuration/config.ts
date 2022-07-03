import path from 'path';
import fs from 'fs';

// TODO!!!! change this to be set from environment -RG


export const config = {
    app:{
        port: 443,
        https:{
            key: fs.readFileSync(path.resolve('./certs/local.pem')),
            cert: fs.readFileSync(path.resolve('./certs/local.crt')),
            passphrase: null as string
        }
    },
    cb:{
        url: "https://192.168.1.120/",
    },
    vipra:{
        vipraDir: path.resolve(`./TEST_VIPRA`),
        simsDir: path.resolve(`./SIMS`),
        outputDir: path.resolve(`./OUTPUT`),
        scripts:{
            genMain: path.resolve('./src/scripts/genMain'),
            moduleObj: path.resolve('./src/scripts/buildObject'),
            compConfig: path.resolve('./src/scripts/compConfig'),
            runSim: path.resolve('./src/scripts/runSim')
        }
    },
    module:{
        modulesDir : path.resolve(`./MODULES`),
    }
};