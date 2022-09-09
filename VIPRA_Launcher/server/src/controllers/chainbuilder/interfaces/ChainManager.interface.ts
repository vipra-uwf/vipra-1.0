import express        from 'express';
import { SimConfig }  from '../../../types/simconfig';
import { FuncResult } from '../../../types/typeDefs';


export interface IChainManager {
  addNewService(simconfig : SimConfig) : FuncResult;
  removeService(id : string) : FuncResult;
  handleChainBuilderRequest(req : express.Request, res : express.Response) : void;
}
