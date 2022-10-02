import { OperationResult } from '../types/typeDefs';

import express from 'express';

type Request = express.Request;

export interface BaseController<DataType> {
  getAll() : Promise<OperationResult<DataType[]>>;
  get(req : Request) : Promise<OperationResult<DataType>>;
  create(req : Request) : Promise<OperationResult<DataType>>;
  update(req : Request) : Promise<OperationResult<DataType>>;
  delete(req : Request) : Promise<OperationResult<DataType>>;
}