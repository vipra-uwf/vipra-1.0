
export interface Config {
  flags : Map<string, string>;
  app: {
    port : number;
    certDir : string;
  },
  vipra: {
    vipraDir : string;
    behaviorDir : string;
    simsDir : string;
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