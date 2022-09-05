import express from 'express';


export interface Node {

  handleRequest(request : express.Request, response : express.Response) : Promise<void>;

}