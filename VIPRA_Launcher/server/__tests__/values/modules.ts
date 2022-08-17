import { Module, ModuleInfo, ModulesFile, ModuleType } from "../../src/types/module";
import { FileBuffers } from "../../src/util/FileStore";
import { SUCCESSFUL_PATH } from "./paths";

import { FilesController } from "../../src/controllers/files/FilesController";
import { Nullable } from "../../src/types/typeDefs";

const fc = new FilesController();


const goodModule : Module = {
    id: "ponjpojrnaiervnakdna",
    name: "goodModule",
    description: "this is a good module",
    params: {},
    dirPath: SUCCESSFUL_PATH,
    className: "goodmodule",
    type: ModuleType.MODEL,
    includePath: SUCCESSFUL_PATH,
    compiled: true
};

const goodModuleUpload : ModuleInfo = {
    id: "paornjbvapjnakjnairabgjin",
    name: "goodModule",
    description: "this is a good module upload",
    params: {},
    type: ModuleType.MODEL
};

const goodModuleBuffers : FileBuffers = [
    {name: "goodModule.cpp", buffer: new Buffer("")},
    {name: "goodModule.hpp", buffer: new Buffer("")},
    {name: "goodModule.mm", buffer: new Buffer("")},
];

const installedModules : Nullable<ModulesFile> = fc.readJsonFile<ModulesFile>('./installedModules.json', {error: true});
if(!installedModules){
    throw new Error(`Unable to load installedModules.json`);
}


export {
    goodModule,
    goodModuleUpload,
    goodModuleBuffers,
    installedModules
}