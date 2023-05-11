/**
 * @module FileStore
 */
import express from 'express';
import multer from 'multer';
import path from 'path';
import tar from 'tar';

import { Readable } from 'stream';
import { Status } from '../types/Status';
import { respondError } from './Responses';
import { ModuleInfo, verifyModule } from '../types/module';

import { Logger } from '../logging/Logging';
import { container } from 'tsyringe';
import { FilesController } from '../controllers/files/FilesController';
import { Nullable } from '../types/typeDefs';

const fc = container.resolve(FilesController);

type FileBuffers = { name:string;buffer:Buffer }[];

declare module 'express-serve-static-core'{
  interface Request {
    fileBuffers?: FileBuffers;
    module?: ModuleInfo;
  }
}

type Files = { [fieldname: string]: Express.Multer.File[] };

const moduleStore = multer.memoryStorage();

/**
 * @description Multer Filter function that checks the uploaded file has the extenstion .tar
 *
 * @param  {express.Request} req - client request object
 * @param  {Express.Multer.File} file - uploaded file
 * @param  {multer.FileFilterCallback} cb - Multer callback
 */
const moduleFilter = (req : express.Request, file : Express.Multer.File, cb : multer.FileFilterCallback) : void => {
  const extension = path.extname(file.originalname);
  if (extension !== '.tar') {
    return cb(new Error('type'));
  }
  return cb(null, true);
};

const uploadModule = multer({
  storage: moduleStore,
  fileFilter: moduleFilter,
});

/**
 * @description Reads the .mm file of the uploaded module
 *
 * @param  {Buffer} buffer - buffer object that contains the contents of a module's .mm file
 */
const getInfo = (buffer : Buffer) : Nullable<ModuleInfo> => {
  const meta : Nullable<ModuleInfo> = fc.readJsonBuffer<ModuleInfo>(buffer);
  return meta;
};

/**
 * @middleware
 * @description Uploads module .tar files and unzips it in memory for installing through the {@link ModuleController}
 * @note Ends Call chain and responds to client if the module is not properly uploaded -RG
 *
 * @param  {express.Request} req - client request object
 * @param  {express.Response} res - client response object
 * @param  {express.NextFunction} next - next middleware to call on successful completion
 */
const storeModule = (req : express.Request, res : express.Response, next : express.NextFunction) : void => {
  // upload file to multer store
  uploadModule.single('module')(req, res, (error : string)=>{
    if (error) {
      respondError(Status.BAD_REQUEST, 'Missing Module', 'Missing Module Tar file', res);
    } else {
      if (req.file) {
        let moduleInfo : Nullable<ModuleInfo> = null;
        let fileCnt : number = 0;
        req.fileBuffers = [];

        // setup readable stream with uploaded multer file
        const file = new Readable();

        // NOTE: setting _read to noop is required, so the errors for doing so are set off for this line -RG
        // eslint-disable-next-line no-underscore-dangle, @typescript-eslint/no-empty-function, jsdoc/require-jsdoc
        file._read = () : void =>{};
        file.push(req.file.buffer);
        file.push(null);

        file.on('error', (err : Error)=>{
          // when error is emitted do
          file.destroy();
          Logger.error(`storeModule: ${err.message}`);
          respondError(Status.BAD_REQUEST, err.message, '', res);
        });

        file
          .pipe(new tar.Parse())
          .on('entry', (entry : tar.ReadEntry)=>{
            // for each file in extracted tar do

            if (entry.type === 'File') {

              // checking user doesn't send too many files in tar
              if (fileCnt > 3) {
                file.emit('error', new Error('Unexpected Number of Files'));
              }

              // checking file path is an expected type
              const ext = path.extname(entry.path);
              if (ext !== '.hpp' && ext !== '.cpp' && ext !== '.mm') {
                file.emit('error', new Error(`Unexpected File Type: ${ext}`));
              } else {

                // when finished reading file, add to buffers to be written later
                entry.on('data', (data)=>{
                  if (ext === '.mm') {
                    // if mm file, read module info. error if wrong
                    moduleInfo = verifyModule(getInfo(data));
                    if (moduleInfo) {
                      req.module = moduleInfo;
                    } else {
                      file.emit('error', new Error('Unable to read .mm file'));
                    }
                  }
                  fileCnt++;
                  const name : string = path.basename(entry.path);
                  if (req.fileBuffers) {
                    req.fileBuffers.push({ name, buffer: data });
                  }
                });
              }
            }
            // go to next file in tar
            entry.resume();
          })
          .on('close', ()=>{
            // if close was not caused by error
            if (!file.destroyed) {
              next();
            }
          });
      }
    }
  });
};

export {
  storeModule,
  Files,
  FileBuffers,
};