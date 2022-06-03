import { ModelMeta } from "../../data_models/ModelMeta";
import { Status } from "../../data_models/Status";
import { IModelRepo } from "../../repos/models/ModelRepo.interface";


export class ModelsController{

    private modelRepo : IModelRepo;

    constructor(modelRepo : IModelRepo){
        this.modelRepo = modelRepo;
    }

    public async getOptions() : Promise<{status: Status, models: ModelMeta[]}>{
        throw new Error("Not Implemented");
    }

    public async getModel(name : string) : Promise<ModelMeta>{
        throw new Error("Not Implemented");
    }

    public async createModel() : Promise<Status>{
        throw new Error("Not Implemented");
    }

    public async updateModel() : Promise<Status>{
        throw new Error("Not Implemented");
    }

    public async deleteModel(name : string) : Promise<Status>{
        throw new Error("Not Implemented");
    }
}