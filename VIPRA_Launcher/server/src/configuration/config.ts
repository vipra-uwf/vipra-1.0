import path from 'path';
import fs from 'fs';

// TODO!!!! change this to be set from environment -RG

export const config = {
    env:{
        scriptRunner: 'sh'
    },
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
        vipraDir: path.resolve(`../../VIPRA_DEV`),
        vipraMake: path.resolve(`../../VIPRA_DEV/sims`),
        simsDir: path.resolve(`../../VIPRA_DEV/sims`),
        behaviorMake: path.resolve(`../../VIPRA_DEV/Base/dsl`),
        outputDir: path.resolve(`./OUTPUT`)
    },
    module:{
        modulesFile : path.resolve(`./modules.json`),
    }
};