import express from 'express';
import multer from 'multer';
import { Nullable } from 'src/types/typeDefs';

const upload = multer();

/**
 * @description Parses out a request's form data, placing it in req.body
 * @param {express.Request} req - client request object
 */
const getFormData = <FormFields>(req : express.Request) : Promise<Partial<FormFields>> => {
  return new Promise(resolve => {
    upload.none()(req, {} as express.Response, ()=>{
      resolve(req.body as Partial<FormFields>);
    });
  });
};

/**
 * @description Checks if a child_process exited with an error
 * @param {Nullable<number>} code - Return code from process, if it stopped itself
 * @param {Nullable<NodeJS.Signals>} signal - Return signal from process
 */
const errorExit = (code : Nullable<number>, signal : Nullable<NodeJS.Signals>) : boolean => {
  if ((code && code !== 0)) {
    return true;
  }
  if (signal === 'SIGABRT' || signal === 'SIGBREAK' || signal === 'SIGINT' || signal === 'SIGKILL') {
    return true;
  }

  return false;
};

export {
  getFormData,
  errorExit,
};