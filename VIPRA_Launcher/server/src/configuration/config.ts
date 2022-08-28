/**
 * @module Configuration
 */

import fs from 'fs';
import { Nullable } from '../types/typeDefs';

interface Config {
  setup : boolean;
  app: {
    debug : boolean;
    port : number;
    https: { key : string | null; cert : string | null; passphrase : Nullable<string> };
  };
  cb: { url : string };
  vipra: { vipraDir : string; simsDir : string; behaviorDir : string; outputDir: string };
  simconfig: { configsFile : string };
  module: { modulesFile : string };
  map: { mapsFile : string };
}

/**
 * @description Loads the configuration file and sets config
 * @param  {string} configFile - path to config file
 */
const loadConfig = (configFile : string) : Config => {
  if (fs.existsSync(configFile)) {
    const conf : Config = JSON.parse(fs.readFileSync(configFile).toString()) as Config;
    if (conf) {
      return conf;
    }
  }
  return {
    setup: false,
    app: {
      debug : false,
      port: -1,
      https: { key: null, cert: null, passphrase: null },
    },
    cb: { url: '' },
    vipra: { vipraDir: '', simsDir: '', behaviorDir: '', outputDir: '' },
    simconfig: { configsFile: '' },
    module: { modulesFile: '' },
    map: { mapsFile: '' },
  };
};

export const config : Config = loadConfig(`${__dirname}/config.json`);