
export interface Config {
  flags : Map<string, string>;
  app: {
    baseURL : string;
    port : number;
    certDir : string;
  },
  vipra: {
    vipraDir : string;
    behaviorDir : string;
    outputDir : string;
    exeName : string;
  },
  modules: {
    modulesDir : string;
    modulesFilePath : string;
  };
  simconfig: {
    simconfigDir : string;
  };
  simulation: {
    debugMode : boolean;
    maxConcurComps : number;
  };
  map: {
    mapsDir : string;
  };
  behavior: {
    behaviorsDir : string;
  };
  launcher: {
    repoDir : string;
  }
}