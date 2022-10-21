import path from 'path';

import { Config } from './config';


/**
 * @note currently hardcoded
 * @description Sets config variables
 */
const initialSetup = () : Config => {
  return {
    modules: {
      modulesFilePath: path.resolve(`${__dirname}/modules.json`),
      modulesDir: path.resolve(`${__dirname}/../../../../Modules`),
    },
    simconfig: {
      simconfigDir: path.resolve(`${__dirname}/../../../../SimConfigs`),
    },
    vipra: {
      vipraDir: path.resolve(`${__dirname}/../../../../VIPRA`),
      behaviorDir: path.resolve(`${__dirname}/../../../../VIPRA/Base/dsl`),
    },
    simulation: {
      debugMode: false,
      maxConcurComps: 10,
    },
    map : {
      mapsDir: path.resolve(`${__dirname}/../../../../Maps`),
    },
  };
};


export {
  initialSetup,
};