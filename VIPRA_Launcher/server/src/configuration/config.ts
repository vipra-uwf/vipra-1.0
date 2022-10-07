
export interface Config {
  vipra: {
    vipraDir : string;
    behaviorDir : string;
  },
  modules: {
    modulesURL : string;
    modulesFilePath : string;
  };
  simconfig: {
    simconfigURL : string;
  };
  simulation: {
    debugMode : boolean;
    maxConcurComps : number;
  };
}