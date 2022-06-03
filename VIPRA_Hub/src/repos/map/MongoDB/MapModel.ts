import { Schema } from 'mongoose';

interface IMap{
    name: string;
    content: string;
    description: string;
    publish: boolean;
    creator: string;
}

export const MapSchema = new Schema<IMap>({
    'name':{
        type: String,
        required: true,
        unique: true
    },
    'content':{
        type: String,
        require: true
    },
    'description':{
        type: String,
        require: true
    },
    'publish':{
        type: Boolean,
        required: true
    },
    'creator':{
        type: String,
        required: true
    }
});