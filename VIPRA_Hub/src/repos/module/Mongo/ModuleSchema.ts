import { Schema } from 'mongoose';
import { Module } from '../../../data_models/Module';


const ModuleSchema = new Schema<Module>({
    name: {
        type: String,
        required: true,
        unique:false
    },
    description:{
        type: String,
        required: true
    },
    type:{
        type: String,
        required: true
    },
    source: {
        type: String
    },
    header:{
        type: String
    },
    publish:{
        type: Boolean,
        required: true
    }
});

ModuleSchema.index(
    {name:1, type:1}, {unique:true}
);


export {
    ModuleSchema
};