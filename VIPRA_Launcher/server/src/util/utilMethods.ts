

import express from 'express';
import multer from 'multer';

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

export {
  getFormData,
};