import express from "express";
import multer from "multer";
import { Status } from "../../../data_models/Status";
import { ModelMeta } from "../../../data_models/ModelMeta";
import { config } from "../../../configuration/config";
import { FileExists } from "../../../util/FileHandling/FileOperations";

const ModelFileStore = multer.diskStorage({
    destination: (req, file : Express.Multer.File, cb)=>{
        cb(null, config.Model.DB_URI);
    },
    filename: (req: any, file : Express.Multer.File, cb)=>{
        let fileName : string = req.body.modelname;
        fileName += file.originalname.endsWith('.hpp') ? ".hpp" : ".cpp";

        // TODO NEXT set this back
        if(FileExists(config.Model.DB_URI.concat('/', fileName))){
            cb(new Error("duplicate"), null);
        }

        // if(!CheckRequirements(req)){
        //    cb(new Error("missing"), null);
        // }

        cb(null, fileName);
    }
});

const ModelFilter = (req: any, file: Express.Multer.File, cb: any)=>{
    if(file.originalname.match(/\.(hpp|cpp)$/)){
        cb(null, true);
    }
    return cb(new Error("type"), false);
};

const upload = multer({
    storage: ModelFileStore,
    // fileFilter: ModelFilter
});

const CheckRequirements = (req : any) : boolean => {
    let ok = true;

    ok = ok && req.files.length === 2;
    ok = ok && req.body.modelname;
    ok = ok && req.body.description;

    return ok;
};

const StoreModel = async (req : express.Request<{}, {}, {modelname: string, description: string}, {}>) : Promise<{status: Status, modelMeta: ModelMeta}> => {
    // turned this into a promise to fit with the rest of the code base -RG

    return new Promise((resolve, reject)=>{
        upload.fields([
            {name: "source", maxCount:1},
            {name: "header", maxCount:1},
        ])(req, null, (err)=>{
            if (err){
                if(err.message === "duplicate"){
                    return resolve({
                        status: Status.CONFLICT,
                        modelMeta: null
                    });
                }
                if(err.message === "type"){
                    return resolve({
                        status: Status.BAD_REQUEST,
                        modelMeta: null
                    });
                }
                if(err.message === "missing"){
                    return resolve({
                        status: Status.BAD_REQUEST,
                        modelMeta: null
                    });
                }

                return reject(err);
            }

            const meta : ModelMeta = {
                name: req.body.modelname,
                description: req.body.description
            };

            return resolve({
                status: Status.SUCCESS,
                modelMeta: meta
            });
        });
    });
};

export {
    StoreModel
};