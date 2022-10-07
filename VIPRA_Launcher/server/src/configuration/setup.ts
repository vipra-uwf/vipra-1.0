import { Config } from './config';


/**
 * @note currently hardcoded
 * @description Sets config variables
 */
const initialSetup = () : Config => {
  return {
    modules: {
      modulesFilePath: `${__dirname}/modules.json`,
      modulesURL: `${__dirname}/../../../../Modules`,
    },
    simconfig: {
      simconfigURL: `${__dirname}/../../../../VIPRA/sims/configs/`,
    },
    vipra: {
      vipraDir: `${__dirname}/../../../../VIPRA`,
      behaviorDir: `${__dirname}/../../../../VIPRA/Base/dsl`,
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