import { CbMethod, CbResult, CbReturnValue, CbServiceInfo, CbServiceOptions } from "../../src/Types";
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

const exampleReturnValue : CbReturnValue = {
  name: "examplevalue",
  description: 'Example Value',
  type: "string"
}

const exampleServiceOptions : CbServiceOptions = {
  info: exampleServiceInfo,
  returnValue: exampleReturnValue,
  resultStore: new TestResultStore('test'),
  method: goodMethod,
  server: [],
  arguments: []
}


export {
  exampleServiceInfo,
  exampleServiceOptions
}