import { ParamSet } from "./simparam";


export enum ModuleType{
    MODEL                   = 'pedestrian_dynamics_model',
    GOALS                   = 'goals',
    OUTPUT_DATA_WRITER      = 'output_data_writer',
    INPUT_DATA_LOADER       = 'input_data_loader',
    SIM_OUTPUT_HANDLER      = 'simulation_output_handler',
    PEDESTRIAN_SET          = 'pedestrian_set',
    OBSTACLE_SET            = 'obstacle_set',
    ENTITY_SET_FACTORY      = 'entity_set_factory',
    HUMAN_BEHAVIOR_MODEL    = 'human_behavior_model',
    CONFIGURATION_READER    = 'configuration_reader',
    CLOCK                   = 'clock',
    DATA                    = 'data',
    SIMULATION              = 'simulation'
}

export class ModulesFile{
    input_data_loader : Module[];
    human_behavior_model : Module[];
    output_data_writer : Module[];
    simulation_output_handler : Module[];
    pedestrian_set : Module[];
    obstacle_set : Module[];
    entity_set_factory : Module[];
    goals : Module[];
    pedestrian_dynamics_model : Module[];
    configuration_reader: Module[];
    clock : Module[];
    data : Module[];
    simulation : Module[];

    constructor(){
        this.input_data_loader = [];
        this.human_behavior_model = [];
        this.output_data_writer = [];
        this.simulation_output_handler = [];
        this.pedestrian_set = [];
        this.obstacle_set = [];
        this.entity_set_factory = [];
        this.goals = [];
        this.pedestrian_dynamics_model = [];
        this.configuration_reader = [];
        this.clock = [];
        this.data = [];
        this.simulation = [];
    }

    public getModules(type : string) : Module[]{
        return this[type as ModuleType];
    }

    public getModulesofType(type : ModuleType) : Module[]{
        return this[type];
    }

    public getModule(id : string) : Module {
        for(const [key, value] of Object.entries(this)){
            const modules = value as Module[];
            const index = modules.findIndex((mod) => {
                if(mod.id === id){
                    return true;
                }
            });
            if(index !== -1){
                return modules[index];
            }
        }

        return null;
    }

    public removeModule(id : string) {
        for(const [key, value] of Object.entries(this)){
            const modules = value as Module[];
            const index = modules.findIndex((mod) => {
                if(mod.id === id){
                    return true;
                }
            });
            if(index !== -1){
                this[key as ModuleType] = this[key as ModuleType].splice(index, 1);
            }
        }
    }
}

export interface ModuleInfo{
    id          : string;
    name        : string;
    description : string;
    params      : ParamSet;
    type        : ModuleType;
}

export interface Module{
    id          : string;
    name        : string;
    description : string;
    params      : ParamSet;
    dirPath     : string;
    className   : string;
    type        : ModuleType;
    includePath : string;
    compiled    : boolean;
}

export const verifyModule = (obj : any) : Module =>{
    if(obj){
        if (
            "id" in obj &&
            "name" in obj &&
            "description" in obj &&
            "className" in obj &&
            "type" in obj
        ){
            // eslint-disable-next-line @typescript-eslint/no-unsafe-argument, @typescript-eslint/no-unsafe-member-access
            if(Object.values(ModuleType).includes(obj.type)){
                return obj as Module;
            }
        }
    }

    return null;
};