
import express from 'express';
import multer from 'multer';
import { Status } from '../types/status';

type File = Express.Multer.File;
type Files = { [name : string]: File[] | undefined };

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

const mapFields : multer.Field[] = [
  { name: 'map', maxCount: 1 },
];
/**
 * @description Adds uploaded Map files to request
 * @param {express.Request} req - client request
 */
const uploadMap = (req : express.Request) : Promise<Status> => {
  return new Promise<Status>((resolve, reject) => {
    upload.fields(mapFields)(req, {} as express.Response, (error) => {
      if (error) {
        reject(error);
      }
      resolve(Status.SUCCESS);
    });
  });
};


const behaviorFields : multer.Field[] = [
  { name: 'behavior', maxCount: 1 },
];
/**
 * @description Adds uploaded behavior file to request
 * @param {express.Request} req - client request
 */
const uploadBehavior = (req : express.Request) : Promise<Status> => {
  return new Promise<Status>((resolve, reject) => {
    upload.fields(behaviorFields)(req, {} as express.Response, (error) => {
      if (error) {
        reject(error);
      }
      resolve(Status.SUCCESS);
    });
  });
};


export {
  uploadModule,
  uploadMap,
  uploadBehavior,
  File,
  Files,
};