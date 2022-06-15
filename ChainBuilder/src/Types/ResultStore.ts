import express from 'express';
import { cbErrorRespond, cbFormatRespond, cbResultRespond } from './Responses';

export abstract class ResultStore{

    protected href            : string;
    protected name            : string;
    protected resultName      : string;
    protected type            : string;

    abstract getResult(hash : string) : Promise<string>;
    abstract hashResult(result : string) : Promise<string>;
    abstract storeResult(result : string) : Promise<string>;

    constructor(name : string){
        this.name = name;
    }

    public handleRequest(path : string[], response : express.Response) : void{
        const resultHash = path[2];
        const format = path[3];
        if(format){
            this.respondResult(resultHash, format, response);
        }else{
            this.respondFormats(resultHash, response);
        }
    }
    public setResultType(resultName : string, type : string){
        this.resultName = resultName;
        this.type = type;
    }
    public getName() : string {
        return this.name;
    }
    public getResultName() : string {
        return this.resultName;
    }
    public setHref(href : string){
        this.href = href;
    }
    public getHref() : string {
        return this.href;
    }
    private async respondResult(resultHash : string, format : string, response : express.Response) {
        const result = await this.getResult(resultHash);
        if(result){
            switch(format){
                case 'raw':
                    response.send(result);
                    return;
                case 'json':
                    cbResultRespond(response, this.resultName, result);
                    return;
                default:
                    cbErrorRespond('Incorrect Format', response);
                    return;
            }
        }else{
            cbErrorRespond('No Result at that Location', response);
        }
    }
    private respondFormats(resultHash : string, response : express.Response) {
        cbFormatRespond(this.href, resultHash, ['raw', 'json'],  response);
    }
}