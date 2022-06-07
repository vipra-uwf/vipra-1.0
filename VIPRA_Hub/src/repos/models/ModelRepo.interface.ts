import express from "express";

import { Status } from "../../data_models/Status";
import { ModelMeta } from "../../data_models/ModelMeta";

export interface IModelRepo{
    connect(dbURI : string) : void;
    getModel(name : string) : Promise<string>;
    getOptions() : Promise<ModelMeta>;
    deleteModel(name : string) : Promise<Status>;
    // TODO this takes in a request to handle the files but I don't really like this, want to find a better factoring -RG
    createModel(req : express.Request) : Promise<{status: Status, modelMeta: ModelMeta}>;
    updateModel(req : express.Request) : Promise<Status>;

    stageModel(name: string) : Promise<{status: Status, files: string[]}>;
}