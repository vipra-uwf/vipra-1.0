import { Schema } from 'mongoose';

export interface IModel{
    name: string;
    description: string;
    source?: string;
    header?: string;
    creator: string;
    publish: boolean;
}

export const ModelSchema = new Schema<IModel>({
    name: {
        type: String,
        required: true,
        unique:true
    },
    description:{
        type: String,
        required: true
    },
    source: {
        type: String
    },
    header:{
        type: String
    },
    creator:{
        type: String,
        required: true
    },
    publish:{
        type: Boolean,
        required: true
    }
});