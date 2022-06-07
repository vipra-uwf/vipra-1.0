import express from "express";
import { Behavior } from "../data_models/Behavior";
import { Status } from "../data_models/Status";

const RespondUnknownError = (response : express.Response) : void => {
    response.status(Status.INTERNAL_ERROR).json({error: "Unknown Error", detail: "An Unknown error occured, Action may not have completed successfully"});
};


const RespondError = (code : Status, error : string, detail : string, response : express.Response) : void => {
    response.status(code).json({
        error,
        detail
    });
};

const RespondSuccess = (response : express.Response, message? : string) : void => {
    if(message){
        response.status(Status.SUCCESS).json({});
    }else{
        response.status(Status.SUCCESS).json({message});
    }
};

const RespondBehavior = ( response : express.Response, behavior : Behavior) : void => {
    response.status(Status.SUCCESS).json({behavior});
};

const RespondFile = (response : express.Response, filePath : string) : void => {

};

const RespondData = (response : express.Response, data : any) : void => {
    response.status(Status.SUCCESS).json({data});
};

export {
    RespondUnknownError,
    RespondError,
    RespondSuccess,
    RespondBehavior,
    RespondData,
    RespondFile
};