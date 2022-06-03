import { ModelMeta } from "../../../data_models/ModelMeta";
import { IModelRepo } from "../ModelRepo.interface";



export class ModelRepo implements IModelRepo{
    connect(dbURI: string): void {
        throw new Error("Method not implemented.");
    }

    getModel(name: string): Promise<string> {
        throw new Error("Method not implemented.");
    }
    
    getOptions(): Promise<ModelMeta> {
        throw new Error("Method not implemented.");
    }
}