import express from 'express';
import multer from "multer";
import path from 'path';
import { Status } from '../data_models/Status';


type Files = {[fieldname: string]: Express.Multer.File[]};

const fileStore = multer.memoryStorage();
const fileFilter = (req : express.Request, file : Express.Multer.File, cb : multer.FileFilterCallback)=>{
    const extension = path.extname(file.originalname);
    if(file.fieldname === 'header'){
        if(extension !== '.hpp'){
            return cb(new Error('type'));
        }
    }else{
        if(extension !== '.cpp'){
            return cb(new Error('type'));
        }
    }

    return cb(null, true);
};

const upload = multer({
    storage: fileStore,
    fileFilter
});


const storeFiles = async (req : express.Request) : Promise<Status> => {
    return new Promise((resolve, reject)=>{
        upload.fields([
            {name:"source", maxCount:1},
            {name:"header", maxCount:1}
        ])(req, null, (err : string)=>{
            if(err){
                if(err === 'type'){
                    resolve(Status.BAD_REQUEST);
                }
                reject(err);
            }

            resolve(Status.SUCCESS);
        });
    });
};

export {
    storeFiles,
    Files
};