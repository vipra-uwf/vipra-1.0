import express from 'express';
import https from 'https';
import { ResultStore } from './ResultStore';
import { cbErrorRespond, cbResultRespond, cbServiceInfoRespond } from './Responses';
import { Parameter, ServiceInfo, Response, ServiceOptions, CbMethod, CbResult } from './Types';

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
            const resultLocation = await this.runService(request, response);
            if(resultLocation.error){
                cbErrorRespond(resultLocation.result, response);
                return;
            }else{
                const data = this.resultStore.getHref().concat(resultLocation.result, '/');
                cbResultRespond(response, this.methodReturn.name, data);
                return;
            }
        }
    }

    private async runService(request : express.Request, response : express.Response) : Promise<CbResult>{
        const parameters = await this.getRequestParams(request as express.Request<any, any, {[key:string]:any}>, response);
        if(parameters.error){
            return {error: true, result: parameters.error};    
        }else{
            const result = await this.serviceMethod(parameters.params);
            if(!result.error){
                const location = await this.resultStore.storeResult(result.result);
                return location;
            }
            return result;
        }
        
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

    private async getRequestParams(request : express.Request<any, any, {[key:string]:any}>, response : express.Response) : Promise<{error: string, params: {[key: string]: string[]}}>{

        const params : string[] = this.methodParams.map((arg)=>{
            return arg.name;
        });

        let ret : {[key: string]: string[]} = {};

        for await (const param of params){
            if(request.query[`${param}`]){
                ret[param] = this.normalizeParam(request.query[`${param}`]);
            }else if(request.query[`${param}_href`]){
                ret[param] = await this.requestChainData(this.normalizeParam(request.query[`${param}_href`]), response);
            }else if(request.body[`${param}`]){
                ret[param] = this.normalizeParam(request.body[`${param}`]);
            }else if(request.body[`${param}_href`]){
                ret[param] = await this.requestChainData(this.normalizeParam(request.body[`${param}_href`]), response);
            }else{
                return {
                    error: `Missing Parameter: ${param}`,
                    params: null
                };
            }
        }

        return {
            error: null,
            params: ret
        };
    }

    private normalizeParam(param : any) : string[]{
        if(typeof param === "string"){
            return [param as string];
        }else{
            return param as string[];
        }
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