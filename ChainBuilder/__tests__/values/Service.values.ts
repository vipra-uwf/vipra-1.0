import { CbMethod, CbResult, CbReturnType, CbServiceInfo, CbServiceOptions } from "../../src/@types/Types";
import { TestResultStore } from "./ResultStore.values";

const goodMethod : CbMethod = (args : { [key: string] : string[] }) : CbResult => {
  return { error: false, result : 'good' };
}

const badMethod : CbMethod = (args : { [key: string] : string[] }) : CbResult => {
  return { error: false, result : 'bad' };
}

const exampleServiceInfo : CbServiceInfo = {
  name       : "testservice",
  description: "this is a test service",
  key        : "asdfasdfasdf",
  version    : "1.0.0",
  author     : "Example Author",
  email      : "example@email.com",
  doc_href   : "example.com"
}

const exampleReturnValue : CbReturnType = {
  name: "examplevalue",
  type: "string"
}

const exampleServiceOptions : CbServiceOptions = {
  info       : exampleServiceInfo,
  parameters : [],
  returnValue: exampleReturnValue,
  resultStore: new TestResultStore('test'),
  method     : goodMethod,
  server     : []
}


export {
  exampleServiceInfo,
  exampleServiceOptions
}