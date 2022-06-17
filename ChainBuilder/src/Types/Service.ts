import express from 'express';
import https from 'https';
import { ResultStore } from './ResultStore';
import { cbErrorRespond, cbResultRespond, cbServiceInfoRespond } from './Responses';
import { Parameter, ServiceInfo, Response } from './Types';

import axios from 'axios';

// TODO allow multiple arguments
export class Service{

    private href            : string;
    private info            : ServiceInfo;
    private parameter       : Parameter;
    private response        : Response;

    private resultStore     : ResultStore;

    private serviceMethod   : (args : string[]) => Promise<string>;
    private methodParams    : {name : string, type : string};
    private methodReturn    : {name: string, type : string};

    private httpsAgent      : https.Agent;

    constructor(settings: {
        info : ServiceInfo,
        parameters  : {name : string, type : string},
        returnValue : {name : string, type : string},
        resultStore : ResultStore,
        method      : (args : string[]) => Promise<string>
    }){
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
        const parameters : string[] = await this.getRequestParams(request, response);
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


    public setMethod(argument : {name: string, type: string}, returnType : {name: string, type: string}, method : (args : string[])=> Promise<string>) : void{
        this.methodParams = argument;
        this.methodReturn = returnType;
        this.serviceMethod = method;

        // TODO remove the server part and assign elsewhere -RG
        // TODO remove the description and assign elsewhere -RG
        // TODO remove the sample and assign elsewhere -RG
        this.parameter = {
            arguments : {
                [argument.name]: {
                    chain_name: argument.name.concat('_href'),
                    description: "TODO",
                    type: argument.type,
                    repeatable: true,
                    sample: 15
                }
            },
            server:[
            ]
        };

        // TODO remove the description and assign elsewhere -RG
        this.response = {
            [returnType.name]: {
                description: 'TODO',
                type: returnType.type,
                sample: 15
            }
        };
    }


    // TODO NEXT one parameter causes this to interperet it as an array of one character strings -RG
    private async getRequestParams(request : express.Request, response : express.Response) : Promise<string[]>{
        if(request.query[this.methodParams.name]){
            const query = request.query[this.methodParams.name];
            let params : string[] = [];

            if(typeof query === "string"){
                params.push(query);
            }else{
                params = query as string[];
            }
            return params;
        }
        if(request.query[this.methodParams.name.concat('_href')]){
            const query = request.query[this.methodParams.name.concat('_href')];
            let hrefs : string[] = [];

            if(typeof query === "string"){
                hrefs.push(query);
            }else{
                hrefs = query as string[];
            }

            const params : string[] = await this.requestChainData(hrefs, response);
            return params;
        }
        if(request.body[this.methodParams.name.concat('_href')]){
            let hrefs : string[] = [];
            const body = request.body[this.methodParams.name.concat('_href')];

            if(typeof body === "string"){
                hrefs.push(body);
            }else{
                hrefs = body as string[];
            }

            const params : string[] = await this.requestChainData(hrefs, response);
            return params;
        }
        return null;
    }

    private async requestChainData(hrefs : string[], response : express.Response) : Promise<string[]>{
        let params : string[] = [];
        for(const link of hrefs){
            const data = await axios.get(link.concat('raw/'), {httpsAgent:this.httpsAgent})
            .catch((err)=>{
                console.log(`[ERROR] Error getting data from ${link}\nError: ${err}`);
                cbErrorRespond('Unable to get data from previous chain', response);
                return null;
            });
            if(data){
                params.push(data.data);
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