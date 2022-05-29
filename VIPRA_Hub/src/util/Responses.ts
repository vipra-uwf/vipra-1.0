import express from "express";
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

export {
    RespondUnknownError,
    RespondError
};