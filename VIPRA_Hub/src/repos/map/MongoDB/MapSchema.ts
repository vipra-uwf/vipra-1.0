import { Schema } from 'mongoose';
import { Map } from '../../../data_models/Map';


export const MapSchema = new Schema<Map>({
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