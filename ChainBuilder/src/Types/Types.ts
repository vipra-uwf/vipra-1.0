interface Response{
    [key : string]:
    {
        description     : string,
        type            : 'float' | 'string',
        sample?         : string | number,
        sample_href?    : string
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
            chain_name: string,
            description: string,
            // TODO add more types -RG
            type: 'float' | 'string',
            repeatable: true | false,
            sample: string | number
        },
    };
    server:[
        'transient',
        'cachable'
    ];
}

export{
    Link,
    ServiceInfo,
    Parameter,
    Response
};
