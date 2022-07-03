import express from 'express';
import { Link, Response, ServiceInfo, Parameter } from './Types';

const cbLinksRespond = (links : Link[], res : express.Response) : void =>{
    res.setHeader('Content-Type', 'text/json;charset=UTF-8');
    res.status(200).json({
            links,
            status: 'success'
        });
};

const cbResultRespond = (response : express.Response, resultName : string, result : string, expiration? : string) : void => {
    response.status(200).json({
        data: {
            [resultName]: {
                'href': result
            }
        },
        status: 'success',
        expiration
    });
};

const cbRawRespond = (response : express.Response, result : string) => {
    response.status(200).send(result);
};

const cbFormatRespond = (baseHref : string, resultHash : string, formats : string[], response : express.Response) => {
    response.status(200).json({
        methods:["DELETE"],
        links: formats.map((format)=>{
            return {"href": baseHref.concat(resultHash, '/', format)};
        }),
        status: 'success'
    });
};

const cbErrorRespond = (message : string, response : express.Response) : void => {
    response.statusCode = 200;
    response.json({
        'status': 'error',
        message
    });
};

const cbServiceInfoRespond = (info : ServiceInfo, parameters : Parameter, responses : Response, res : express.Response) : void => {
    res.json({
        info,
        methods:['GET', 'POST'],
        status: 'success',
        parameters,
        responses
    });
};

export {
    cbErrorRespond,
    cbLinksRespond,
    cbServiceInfoRespond,
    cbResultRespond,
    cbFormatRespond,
    cbRawRespond
};