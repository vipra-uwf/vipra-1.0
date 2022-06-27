import path from 'path';

export const config ={
    app:{
        port: 3001
    },
    vipra:{
        vipraDir: path.resolve(`./TEST_VIPRA`)
    },
    module:{
        modulesFile : path.resolve(`./MODULES/modules.json`),
        tmpDir: path.resolve(`./TMP_DIR`)
    }
};