
export interface Config {
  vipra: {
    vipraDir : string;
    behaviorDir : string;
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