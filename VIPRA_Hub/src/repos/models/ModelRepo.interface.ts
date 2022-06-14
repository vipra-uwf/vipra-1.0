import express from "express";
import { Status }           from "../../data_models/Status";
import { ModelMeta }        from "../../data_models/ModelMeta";
import { IModel }           from "./Mongo/ModelSchema";

export interface IModelRepo{
    connect(dbURI : string, stagingDir : string) : void;
    getOptions() : Promise<ModelMeta[]>;
    getModelInfo(name : string) : Promise<{status : Status, modelMeta : ModelMeta}>;
    createModel(model : IModel) : Promise<Status>;
    deleteModel(name : string) : Promise<Status>;
    updateModelSource(name : string, source : string) : Promise<Status>;
    updateModelHeader(name : string, header : string) : Promise<Status>;
    stageModel(name: string) : Promise<{status: Status, dirPath: string}>;
}