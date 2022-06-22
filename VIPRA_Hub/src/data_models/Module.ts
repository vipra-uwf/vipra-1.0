export enum ModuleType{
    MODEL = 'pedestrianmodel',
    GOALS = 'goals',
    OUTPUT_WRITER = 'outputwriter',
    // TODO !!! add all module types -RG
}

export interface ModuleMeta{
    name: string;
    description: string;
    type : ModuleType;
}

export interface ModuleUpdate{
    name: string;
    type: ModuleType;
    description?: string;
    source?: string;
    header?: string;
    publish?: boolean;
}

export interface Module{
    name: string;
    description: string;
    type: ModuleType;
    source?: string;
    header?: string;
    publish: boolean;
}

export const toString = (meta : ModuleMeta) : string => {
    return `{name: ${meta.name}, description: ${meta.description}, type: ${meta.type}}`;
};

export const typeFromString = (type : string) : ModuleType =>{
    if(Object.values(ModuleType).some(
        (t : string) => t === type.toLowerCase())
        ){
        return type as ModuleType;
    }else{
        return null;
    }
};