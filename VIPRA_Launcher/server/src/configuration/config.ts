
export interface Config {
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
}