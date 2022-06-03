import { ModelMeta } from "../../data_models/ModelMeta";


export interface IModelRepo{
    connect(dbURI : string) : void;
    getModel(name : string) : Promise<string>;
    getOptions() : Promise<ModelMeta>;
}