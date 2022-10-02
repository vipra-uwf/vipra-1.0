
import express from 'express';
import multer from 'multer';
import { Status } from '../../types/status';

type File = Express.Multer.File;
type Files = Express.Multer.File[];

const moduleStore = multer.memoryStorage();
const upload = multer({
  storage: moduleStore,
});

const moduleFields : multer.Field[] = [
  { name: 'source', maxCount:1 },
  { name: 'header', maxCount:1 },
  { name: 'meta', maxCount:1 },
];

/**
 * @description Adds uploaded module files to request
 * @param {express.Request} req - client request
 */
const uploadModule = (req : express.Request) : Promise<Status> => {
  return new Promise<Status>((resolve, reject) => {
    upload.fields(moduleFields)(req, {} as express.Response, (error) => {
      if (error) {
        reject(error);
      }
      resolve(Status.SUCCESS);
    });
  });
};


export {
  uploadModule,
  File,
  Files,
};