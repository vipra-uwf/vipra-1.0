import express from 'express';
import https from 'https';
import { ResultStore } from './ResultStore';
import { cbErrorRespond, cbResultRespond, cbServiceInfoRespond } from './Responses';
import { Parameter, ServiceInfo, Response, ServiceOptions, CbMethod } from './Types';

import axios, { AxiosResponse } from 'axios';

export class Service{

    private href            : string;
    private info            : ServiceInfo;
    private parameter       : Parameter;
    private response        : Response;

    private resultStore     : ResultStore;

    private serviceMethod   : CbMethod;
    private methodParams    : {name : string; type : string}[];
    private methodReturn    : {name: string; type : string};

    private httpsAgent      : https.Agent;

    constructor(settings : ServiceOptions){
        this.info = settings.info;
        this.httpsAgent = new https.Agent({
            rejectUnauthorized: false
        });
        this.resultStore = settings.resultStore;
        this.setMethod(settings.parameters, settings.returnValue, settings.method);
    }

    public async handleRequest(request : express.Request, response : express.Response) : Promise<void>{
        if(request.method === 'GET'){
            cbServiceInfoRespond(this.info, this.parameter, this.response, response);
            return;
        }else{
            const resultLocation : string = await this.runService(request, response);
            if(resultLocation){
                const data = this.resultStore.getHref().concat(resultLocation, '/');
                cbResultRespond(response, this.methodReturn.name, data);
                return;
            }else{
                cbErrorRespond('Unable to complete request', response);
                return;
            }
        }
    }

    private async runService(request : express.Request, response : express.Response) : Promise<string>{
        const parameters : { [key: string]: string[] } = await this.getRequestParams(request as express.Request<any, any, {[key:string]:any}>, response);
        if(parameters){
            const result : string = await this.serviceMethod(parameters);
            if(result){
                const location = await this.resultStore.storeResult(result);
                return location;
            }
            return null;
        }
        return null;
    }


    public setMethod(argument : {name: string; type: string; description: string; sample: string}[], returnType : {name: string; type: string}, method : CbMethod){
        this.methodParams = argument;
        this.methodReturn = returnType;
        this.serviceMethod = method;

        // TODO remove the server part and assign elsewhere -RG
        // TODO remove the description and assign elsewhere -RG
        // TODO remove the sample and assign elsewhere -RG

        this.parameter = {
            arguments : {},
            server:[]
        };

        argument.forEach((arg)=>{
            this.parameter.arguments[arg.name] = {
                chain_name: `${arg.name}_href`,
                description: arg.description,
                type: arg.type,
                repeatable: true,
                sample: arg.sample
            };
        });



        // TODO remove the description and assign elsewhere -RG
        this.response = {
            [returnType.name]: {
                description: 'TODO',
                type: returnType.type,
                sample: 15
            }
        };
    }

    private async getRequestParams(request : express.Request<any, any, {[key:string]:any}>, response : express.Response) : Promise<{ [key: string]: string[] }>{

        const params : string[] = this.methodParams.map((arg)=>{
            return arg.name;
        });

        if(request.query){
            let query : {[key:string] : string[]};
            // NOTE: we check if we were provided with hrefs or raw values, based on that we either fetch or use directly
            //       values/hrefs can come in either the query or body so we need to check both
            //          checking whether query[param] is a string is a quirk of typescipt as if there is only one parameter provided it will be interpereted as an array of strings with length 1 -RG
            if(request.query[`${params.at(0)}_href`]){
                for await (const param of params){
                    if(typeof request.query[param] === "string"){
                        query[param] = await this.requestChainData([request.query[param] as string], response);
                    }else{
                        query[param] = await this.requestChainData(request.query[param] as string[], response);
                    }
                }
            }else{
                params.forEach((param)=>{
                    if(typeof (request.query[param]) === "string"){
                        query[param] = [request.query[param] as string];
                    }else{
                        query[param] = request.query[param] as string[];
                    }
                });
            }
            return query;
        }
        if(request.body){
            let query : {[key:string] : string[]};
            // NOTE: we check that the member exists and that it is correct, this error is not needed -RG
            if(request.body[`${params.at(0)}_href`]){
                for await (const param of params){
                    if(request.body[param]){
                        if(typeof request.body[param] === "string"){
                            query[param] = await this.requestChainData([request.body[param] as string], response);
                        }else{
                            query[param] = await this.requestChainData(request.body[param] as string[], response);
                        }
                    }else{
                        cbErrorRespond("Missing Parameters", response);
                        return null;
                    }
                }
            }
            return query;
        }
        return null;
    }

    private async requestChainData(hrefs : string[], response : express.Response) : Promise<string[]>{
        const params : string[] = [];
        for(const link of hrefs){
            // eslint-disable-next-line @typescript-eslint/no-unsafe-assignment
            const data : AxiosResponse = await axios.get(link.concat('raw/'), {httpsAgent:this.httpsAgent})
            .catch((err)=>{
                cbErrorRespond('Unable to get data from previous chain', response);
                return null;
            });
            if(data){
                if(data.data){
                    params.push(JSON.stringify(data.data));
                }
            }
        }
        return params;
    }

    public getParameter() : Parameter{
        return this.parameter;
    }
    public getInfo() : ServiceInfo{
        return this.info;
    }
    public setHref(href : string){
        this.href = href;
    }
    public setResultStore(store : ResultStore){
        store.setResultType(this.methodReturn.name, this.methodReturn.type);
        this.resultStore = store;
    }
    public getResultStore() : ResultStore {
        return this.resultStore;
    }
    public setName(name : string){
        this.info.description = name;
    }
    public setKey(key : string){
        this.info.key = key;
    }
    public setDescription(description : string){
        this.info.description = description;
    }
    public setVersion(version : string){
        this.info.version = version;
    }
    public setAuthor(author : string){
        this.info.author = author;
    }
    public setEmail(email: string){
        this.info.email = email;
    }
    public setDocHref(href : string){
        this.info.doc_href = href;
    }
}