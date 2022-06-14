
export interface ModelMeta{
    name: string;
    description: string;
}

export const toString = (meta : ModelMeta) : string => {
    return `{name: ${meta.name}, description: ${meta.description}}`;
}