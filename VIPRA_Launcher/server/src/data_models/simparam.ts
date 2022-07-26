
export interface SimParam{
    name : string;
    value : string | number;
}

export interface ParamSet{
    [name : string] : SimParam;
}