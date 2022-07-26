import { ResultStore } from "./ResultStore";

type CbMethod = (args : {[key: string] : string[]}) => Promise<string>;

interface Response{
    [key : string]:
    {
        description     : string;
        type            : string;
        sample?         : string | number;
        sample_href?    : string;
    };
}

interface ServiceInfo{
    name            : string;
    description     : string;
    key             : string;
    version         : string;
    author          : string;
    email           : string;
    doc_href        : string;
}

interface Link{
    name: string;
    href: string;
}

interface Parameter{
    arguments : {
        [key: string] : {
            chain_name: string;
            description: string;
            type: string;
            repeatable: true | false;
            sample?: string | number;
        };
    };
    server:[
    ];
}

interface ServiceOptions{
    info: ServiceInfo;
    parameters: {name: string; type: string; description: string; sample: string}[];
    returnValue: {name: string; type: string};
    resultStore: ResultStore;
    method: CbMethod;
}

export{
    Link,
    ServiceInfo,
    Parameter,
    CbMethod,
    ServiceOptions,
    Response
};
