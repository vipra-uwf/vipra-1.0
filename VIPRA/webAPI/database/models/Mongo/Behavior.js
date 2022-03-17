const mongoose = require('mongoose');


const behaviorSchema = new mongoose.Schema({
    'name':{
        type:String,
        required:true,
        unique:true
    },
    'content':{
        type:String,
        require:true
    },
    'publish':{
        type:Boolean,
        required:true
    },
    'creator':{
        type:String,
        required:true
    }
});

module.exports = behaviorSchema;