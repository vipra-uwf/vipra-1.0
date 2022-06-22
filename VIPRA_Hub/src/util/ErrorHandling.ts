import mongoose from "mongoose";
import { Logger } from "../logging/Logging";

import { Status } from "../data_models/Status";

export const MongoErrToStatus = (error : mongoose.MongooseError) : Status => {

    if(error.message.startsWith('E11000')){
        return Status.CONFLICT;
    }

    Logger.error(`Unhandled Mongoose Error Code: ${error}`);
    return Status.INTERNAL_ERROR;
};