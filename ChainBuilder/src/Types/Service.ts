import express from 'express';
import { cbErrorRespond, cbResultRespond, cbServiceInfoRespond } from './Responses';
import { ResultStore } from './ResultStore.interface';
import { Parameter, ServiceInfo, Response } from './Types';

// TODO add a result store -RG
// TODO refactor this so it doesn't look so digusting and a bit more user friendly -RG

export class Service{

    private href            : string;
    private info            : ServiceInfo;
    private parameter       : Parameter;
    private response        : Response;

    private resultStore     : ResultStore;

    private serviceMethod   : Function;
    private methodParams    : {name : string, type : string};
    private methodReturn    : string;

    constructor(href : string, info : ServiceInfo, resultStore : ResultStore){
        this.href = href;
        this.info = info;
        this.resultStore = resultStore;
    }

    public async handleRequest(request : express.Request, response : express.Response) : Promise<void>{
        if(request.method === 'GET'){
            cbServiceInfoRespond(this.info, this.parameter, this.response, response);
            return;
        }else{
            const resultLocation : string = await this.callMethod(request, response);
            if(resultLocation){
                const data = {
                   "sum": {
                        "href": this.href.concat('%%', resultLocation)
                    }
                };
                cbResultRespond(response, data);
                return;
            }else{
                cbErrorRespond('Unable to complete request', response);
            }
        }
    }

    private async callMethod(request : express.Request, response : express.Response) : Promise<string>{
        const parameter = request.query[this.methodParams.name];
        if(parameter){
            const result = this.serviceMethod(parameter);
            return await this.resultStore.storeResult(result);
        }else{
            return null;
        }
    }

    // TODO change this to use reflection to get the required info about the method -RG
    public setMethod(argument : {name: string, type: string}, returnType : string,method : (arg : string | number)=> string | number) : void{
        this.methodParams = argument;
        this.methodReturn = returnType;

        this.serviceMethod = method;
    }


    public setResponse(response : Response) : void{
        this.response = response;
    }
    public setParameter(parameter : Parameter){
        this.parameter = parameter;
    }
    public getParameter() : Parameter{
        return this.parameter;
    }
    public getInfo() : ServiceInfo{
        return this.info;
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