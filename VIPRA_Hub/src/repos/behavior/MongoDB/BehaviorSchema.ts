import { Schema } from 'mongoose';
import { Behavior } from '../../../data_models/Behavior';

export const BehaviorSchema = new Schema<Behavior>({
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