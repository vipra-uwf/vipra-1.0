import { IncomingMessage, ServerResponse } from 'http';
import { CBResponse, cbServiceInfoRespond } from './CBResponse';
import { HTTPRequestType } from "./HTTPRequestType";
import { Parameter } from "./Parameter";
import { ServiceInfo } from "./ServiceInfo";

export class CBService{

    private info        : ServiceInfo;
    private parameters  : Parameter[];
    private responses   : CBResponse[];

    constructor(info : ServiceInfo){
        this.info = info;
    }

    public handleRequest(request : IncomingMessage, response : ServerResponse) : void{
        if(request.method === 'GET'){
            cbServiceInfoRespond(this.info, this.parameters, this.responses, response);
            return;
        }



    }

    public addParameter(parameter : Parameter){
        this.parameters.push(parameter);
    }
    public setParameters(parameters : Parameter[]){
        this.parameters = parameters;
    }
    public getParameters() : Parameter[]{
        return this.parameters;
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