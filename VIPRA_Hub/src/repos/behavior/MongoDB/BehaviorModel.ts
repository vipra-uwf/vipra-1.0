import { Schema } from 'mongoose';

interface IBehavior{
    name: string;
    content: string;
    description: string;
    publish: boolean;
    creator: string;
}

export const BehaviorSchema = new Schema<IBehavior>({
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