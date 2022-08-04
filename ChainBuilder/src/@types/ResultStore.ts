import express from 'express';
import { cbErrorRespond, cbFormatRespond, cbRawRespond, cbResultRespond } from './Responses';


// TODO add result expiration -RG

export abstract class ResultStore{

    protected href            : string;
    protected name            : string;
    protected resultName      : string;
    protected type            : string;

    abstract getResult(hash : string) : Promise<{error: boolean; result: string}>;
    abstract storeResult(result : string) : Promise<{error: boolean; result: string}>;

    constructor(name : string){
        this.name = name;
    }

    public handleRequest(path : string[], response : express.Response) : void{
        const resultHash = path[0];
        const format = path[1];
        if(format){
            this.respondResult(resultHash, format, response)
            .catch((error)=>{
                cbErrorRespond('Error Retrieving Result from Result Store', response);
            });
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
        if(!result.error){
            switch(format){
                case 'raw':
                    cbRawRespond(response, result.result);
                    return;
                case 'json':
                    cbResultRespond(response, this.resultName, result.result);
                    return;
                default:
                    cbErrorRespond('Incorrect Format', response);
                    return;
            }
        }else{
            cbErrorRespond(result.result, response);
        }
    }
    private respondFormats(resultHash : string, response : express.Response) {
        cbFormatRespond(this.href, resultHash, ['raw', 'json'],  response);
    }
}