import express from "express";
import { Status } from "../data_models/Status.e";

const respondUnknownError = (response : express.Response) : void => {
    response.status(Status.INTERNAL_ERROR).json({error: "Unknown Error", detail: "An Unknown error occured, Action may not have completed successfully"});
};


const respondError = (code : Status, error : string, detail : string, response : express.Response) : void => {
    response.status(code).json({
        error,
        detail
    });
};

const respondSuccess = (response : express.Response, message? : string) : void => {
    if(message){
        response.status(Status.SUCCESS).json({});
    }else{
        response.status(Status.SUCCESS).json({message});
    }
};

// this works for now, need to change later -RG

const respondData = (data : any, response : express.Response) : void => {
    // eslint-disable-next-line @typescript-eslint/no-unsafe-assignment
    response.status(Status.SUCCESS).json({data});
};

export {
    respondUnknownError,
    respondError,
    respondSuccess,
    respondData,
};