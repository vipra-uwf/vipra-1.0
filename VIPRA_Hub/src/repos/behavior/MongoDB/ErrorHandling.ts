import { Status } from "../../../data_models/Status";

export const MongoErrToStatus = (error : number) : Status => {
    switch(error){
        case 11000:
            return Status.CONFLICT;
        default:
            console.log(`[Error] Unhandled Mongoose Error Code: ${error}`);
            return Status.INTERNAL_ERROR;
    }
};