import { Schema } from 'mongoose';

interface behavior{
    name: string;
    content: string;
    publish: boolean;
    creator: string;
}

export const behaviorScema = new Schema<behavior>({
    'name':{
        type: String,
        required:true,
        unique:true
    },
    'content':{
        type: String,
        require:true
    },
    'publish':{
        type:Boolean,
        required:true
    },
    'creator':{
        type: String,
        required:true
    }
});