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
      modulesURL: path.resolve(`${__dirname}/../../../../Modules`),
    },
    simconfig: {
      simconfigURL: path.resolve(`${__dirname}/../../../../VIPRA/sims/configs/`),
    },
    vipra: {
      vipraDir: path.resolve(`${__dirname}/../../../../VIPRA`),
      behaviorDir: path.resolve(`${__dirname}/../../../../VIPRA/Base/dsl`),
    },
    simulation: {
      debugMode: false,
      maxConcurComps: 10,
    },
  };
};


export {
  initialSetup,
};