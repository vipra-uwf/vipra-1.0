import express from 'express';
import https from 'https';
import { Link, Response, ServiceInfo, Parameter } from './Types';


const cbRespond = (response : Response, res : express.Response) : void => {
    // TODO
};

const cbLinksRespond = (links : Link[], res : express.Response) : void =>{
    res.setHeader('Content-Type', 'text/json;charset=UTF-8');
    res.status(200).json({
            'links': links,
            status: 'success'
        });
};

const cbResultRespond = (response : express.Response, data : {[key:string]:{href:string}}, expiration? : string) : void =>{
    response.status(200).json({
        status: 'success',
        data,
        expiration
    });
};

const cbErrorRespond = (message : string, response : express.Response) : void => {
    response.statusCode = 200;
    response.json({
        'status': 'error',
        'message': message
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
    cbRespond,
    cbErrorRespond,
    cbLinksRespond,
    cbServiceInfoRespond,
    cbResultRespond
};