import fs from 'fs';

import { Module, ModuleInfo, ModulesFile, ModuleType, removeModule } from "../../src/types/module";
import { FileBuffers } from "../../src/util/FileStore";
import { SUCCESSFUL_PATH } from "./paths";

const goodModule : Module = {
  id: "ponjpojrnaiervnakdna",
  name: "goodModule",
  description: "this is a good module",
  params: [],
  dirPath: SUCCESSFUL_PATH,
  className: "GoodModule",
  type: ModuleType.MODEL,
  includePath: SUCCESSFUL_PATH,
  compiled: false
};

const goodModuleInfo : ModuleInfo = {
  id: "paornjbvapjnakjnairabgjin",
  name: "goodModule",
  description: "this is a good module upload",
  params: [],
  type: ModuleType.MODEL,
  className: 'GoodModule'
};

const checkInstalledGoodModule : Module = {
  "className": "GoodModule",
  "description": "this is a good module upload",
  "dirPath": "/paornjbvapjnakjnairabgjin",
  "id": "paornjbvapjnakjnairabgjin",
  "includePath": "/paornjbvapjnakjnairabgjin/goodModule.hpp",
  "name": "goodModule",
  "params": [],
  "type": ModuleType.MODEL,
  compiled: false
}

const duplicateModuleInfo : ModuleInfo = {
  id: "VbGjNW5NCkOmKAxvFmz5KwUV2zz469",
  name: "calm_pedestrian_model",
  description: "this describes a duplicate module",
  params: [],
  type: ModuleType.MODEL,
  className: 'CalmPedestrianModel'
};

const goodModuleBuffers : FileBuffers = [
    {name: "goodModule.cpp", buffer: new Buffer("cpp file buffer")},
    {name: "goodModule.hpp", buffer: new Buffer("hpp file buffer")},
    {name: "goodModule.mm", buffer: new Buffer("mm file buffer")},
];

const installedOutputDataWriters = [
    {
      "id": "esBm2A3I0yIbGvzW5bLY0yKHJTzVCj",
      "name": "json_timestep_writer",
      "description": "TODO",
      "params": [],
      "className": "JSONTIMESTEPWRITER",
      "type": "output_data_writer",
      "dirPath": "successful/path",
      "includePath": "successful/path",
      "compiled": false
    },
    {
      "id": "f8qt7eLCczzFMjToJBsA5qYUz1A8E6",
      "name": "json_writer",
      "description": "TODO",
      "params": [],
      "className": "JSONWRITER",
      "type": "output_data_writer",
      "dirPath": "successful/path",
      "includePath": "successful/path",
      "compiled": false
    }
  ];

const installedModulesInfo = {
    "input_data_loader": [
      {
        "id": "bQIGJDQw0Fgqo4oC3lH7mQerFGTQry",
        "name": "input_json_reader",
        "description": "TODO",
        "params": [],
        "type": "input_data_loader"
      }
    ],
    "human_behavior_model": [
      {
        "id": "e3y1yG6PSjrWzsptf6jHdfBElwFugQ",
        "name": "human_behavior_model",
        "description": "TODO",
        "params": [
          {
              "name": "random_seed",
              "type": "string",
              "description": "String used for seeding random number generation",
              "repeatable": false
          }
      ],
        "type": "human_behavior_model"
      }
    ],
    "output_data_writer": [
      {
        "id": "esBm2A3I0yIbGvzW5bLY0yKHJTzVCj",
        "name": "json_timestep_writer",
        "description": "TODO",
        "params": [],
        "type": "output_data_writer"
      },
      {
        "id": "f8qt7eLCczzFMjToJBsA5qYUz1A8E6",
        "name": "json_writer",
        "description": "TODO",
        "params": [],
        "type": "output_data_writer"
      }
    ],
    "simulation_output_handler": [
      {
        "id": "RfH40LtLJjHOlPIEeTj0i6ghBygQsZ",
        "name": "timestep_console_logger",
        "description": "TODO",
        "params": [
          {
              "name": "outputFrequency",
              "type": "integer",
              "description": "How frequently position samples are taken in the simulation",
              "repeatable": false
          }
      ],
        "type": "simulation_output_handler"
      },
      {
        "id": "0bQVYYyskvxYq6YW4J67z73UB6GbnU",
        "name": "timestep_output_handler",
        "description": "TODO",
        "params": [
          {
              "name": "outputFrequency",
              "type": "integer",
              "description": "How frequently position samples are taken in the simulation",
              "repeatable": false
          }
      ],
        "type": "simulation_output_handler",
      }
    ],
    "pedestrian_set": [
      {
        "id": "jLcPe7ZP8G15AFH5vPb6Wz2DrIVT94",
        "name": "calm_pedestrian_set",
        "description": "TODO",
        "params": [],
        "type": "pedestrian_set"
      }
    ],
    "obstacle_set": [
      {
        "id": "MTpemEr4jv5XTvgwO7q54Qco97Pnt4",
        "name": "airplane_obstacle_set",
        "description": "TODO",
        "params": [],
        "type": "obstacle_set"
      }
    ],
    "entity_set_factory": [
      {
        "id": "h6fJTJdM5L9q8wjXEvN6Cq8D14MUeX",
        "name": "calm_entity_set_factory",
        "description": "TODO",
        "params": [],
        "type": "entity_set_factory"
      }
    ],
    "goals": [
      {
        "id": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",
        "name": "calm_goals",
        "description": "TODO",
        "params": [],
        "type": "goals"
      }
    ],
    "pedestrian_dynamics_model": [
      {
        "id": "VbGjNW5NCkOmKAxvFmz5KwUV2zz469",
        "name": "calm_pedestrian_model",
        "description": "TODO",
        "params": [],
        "type": "pedestrian_dynamics_model"
      }
    ],
    "configuration_reader": [
      {
        "id": "5E4V21CyOwU5iMBfH97qlFDn6DlAlf",
        "name": "configuration_reader",
        "description": "TODO",
        "params": [],
        "type": "configuration_reader"
      }
    ],
    "clock": [
      {
        "id": "NUpICP9g2eBe9GGYBXmx1jofH9TC7k",
        "name": "clock",
        "description": "TODO",
        "params": [],
        "type": "clock"
      }
    ],
    "data": [
      {
        "id": "MJk1zG6WMVTwUT82QroZXohn3gnfT4",
        "name": "data",
        "description": "TODO",
        "params": [],
        "type": "data"
      }
    ],
    "simulation": [
      {
        "id": "QQgWGHtxsVWT1jIEXbxjKG1HA3iqI0",
        "name": "simulation",
        "description": "TODO",
        "params": [
          {
              "name": "time_step_size",
              "type": "integer",
              "description": "Size of each timestep of the simulation",
              "repeatable": false
          }
      ],
        "type": "simulation"
      }
    ]
  };

const getInstalledModules = ()=>{
    if(fs.existsSync(`${__dirname}/installedModules.json`)){
      try{
          const obj : ModulesFile = Object.assign([], JSON.parse(fs.readFileSync(`${__dirname}/installedModules.json`).toString()) as ModulesFile);
          return obj;
      }catch(e){
          throw new Error('Unable to read installedModules.json');      
      }
    }
    throw new Error('Unable to read installedModules.json');
};

// missing obstacle_set and goals
const getInstalled_Two_Missing = () : ModulesFile =>{
  const modules = getInstalledModules();
  if (!removeModule('MTpemEr4jv5XTvgwO7q54Qco97Pnt4',modules)) {
    throw new Error('Unable to remove MTpemEr4jv5XTvgwO7q54Qco97Pnt4 from modules');
  }
  if (!removeModule('Xz59g1o8HcsnMJlKaiYw00wZ19rB7P', modules)) {
    throw new Error('Unable to remove Xz59g1o8HcsnMJlKaiYw00wZ19rB7P from modules');
  }
  return modules;
}

const getInstalled_One_Missing = () : ModulesFile => {
  if(fs.existsSync(`${__dirname}/missingObstacleSet.json`)){
    try{
        const obj : ModulesFile = Object.assign([], JSON.parse(fs.readFileSync(`${__dirname}/missingObstacleSet.json`).toString()) as ModulesFile);
        return obj;
    }catch(e){
        throw new Error('Unable to read missingObstacleSet.json');      
    }
  }
  throw new Error('Unable to read missingObstacleSet.json');
}

const missingModule : Module = {
  id: "poaernvpaojernpvaiuernvpaojwn",
  name: "example_obstacle_set",
  description: "TODO",
  params: [],
  type: ModuleType.OBSTACLE_SET,
  className: 'ExampleObstacleSet',
  dirPath: 'successful/path',
  includePath: 'successful/path',
  compiled: false
}

const secondMissingModule : Module = {
    "id": "Xz59g1o8HcsnMJlKaiYw00wZ19rB7P",
    "name": "calm_goals",
    "description": "TODO",
    "params": [],
    "className": "CALMGOALS",
    "type": ModuleType.GOALS,
    "dirPath": "successful/path",
    "includePath": "successful/path",
    "compiled": false
}

const NUM_MODULES = 15;
const NUM_MISSING_MODULES = 1;
const MODULE_TYPE_COUNT = 13
const NON_EXISTANT_MODULE_ID = "thismoduledoesntexist";

export {
    goodModule,
    goodModuleInfo,
    checkInstalledGoodModule,
    goodModuleBuffers,
    duplicateModuleInfo,
    installedModulesInfo,
    NON_EXISTANT_MODULE_ID,
    NUM_MODULES,
    NUM_MISSING_MODULES,
    MODULE_TYPE_COUNT,
    missingModule,
    secondMissingModule,
    installedOutputDataWriters,
    getInstalledModules,
    getInstalled_One_Missing,
    getInstalled_Two_Missing
}