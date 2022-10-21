import { Files } from '../util/filestore';

export interface Identifiable { id:string; }

export type UploadType<DataType extends Identifiable> = {
  object: Partial<DataType>;
  files: Files;
};

export interface RepoType<DataType extends Identifiable> {
  object : DataType;
  dirPath : string;
}

export interface UploadRequest {
  body: Partial<{
    [key : string] : any;
  }>;
  files? : Files;
}