import express from "express";
import { Logger } from "../logging/Logging";
import { Behavior } from "../data_models/Behavior";
import { Status } from "../data_models/Status";

const respondUnknownError = (response : express.Response) : void => {
    response.status(Status.INTERNAL_ERROR).json({error: "Unknown Error", detail: "An Unknown error occured, Action may not have completed successfully"});
};


const respondError = (code : Status, error : string, detail : string, response : express.Response) : void => {
    response.status(code).json({
        error,
        detail
    });
};

const respondCreated = (response : express.Response) : void =>{
    response.status(Status.CREATED).json({});
};

const respondSuccess = (response : express.Response, message? : string) : void => {
    if(message){
        response.status(Status.SUCCESS).json({});
    }else{
        response.status(Status.SUCCESS).json({message});
    }
};

const respondBehavior = ( response : express.Response, behavior : Behavior) : void => {
    response.status(Status.SUCCESS).json({behavior});
};

const respondFile = (response : express.Response, filePath : string,
    cleanup?: {
        filename : string;
        callback : (filename : string) => Promise<void>;
    }) : void => {

    response.download(filePath, (err)=>{
        if(err){
            Logger.error(`Error in respondFile: ${err.message}`);
        }
        if(cleanup){
            cleanup.callback(cleanup.filename)
            .catch((error : string)=>{
                Logger.error(`Error in Model Cleanup: ${error}`);
            });
        }
    });
};

const respondData = (response : express.Response, data : any) : void => {
    response.status(Status.SUCCESS).json({data});
};

export {
    respondUnknownError,
    respondError,
    respondSuccess,
    respondBehavior,
    respondData,
    respondFile,
    respondCreated
};