
import { Module, ModuleType, ModuleRequest, ModuleUpload } from '../../../types/module/module.types';
import { File } from '../../../controllers/module/filestore';

const properModule : Module = {
  id: 'properModule',
  name: 'properModule',
  description: 'this is a proper module description',
  params: [
    {
      name: 'exampleParam',
      description: 'example param',
      type: 'string',
      multiple: false,
    },
  ],
  type: 'goals' as ModuleType,
};

const properModuleUpload : Partial<ModuleUpload> = {
  module: properModule,
  files: {
    srcFile: { buffer: new Buffer('this is the source file') } as File,
    headerFile: { buffer: new Buffer('this is the header file') } as File,
    metaFile: { buffer: new Buffer('this is the meta file') } as File,
  },
};

const missingIdModuleUpload : Partial<ModuleUpload> = {
  module: {
    name: 'properModule',
    description: 'this is a proper module description',
    params: [
      {
        name: 'exampleParam',
        description: 'example param',
        type: 'string',
        multiple: false,
      },
    ],
    type: 'goals' as ModuleType,
  },
  files: {
    srcFile: { buffer: new Buffer('this is the source file') } as File,
    headerFile: { buffer: new Buffer('this is the header file') } as File,
    metaFile: { buffer: new Buffer('this is the meta file') } as File,
  },
};

const missingNameModuleUpload : Partial<ModuleUpload> = {
  module: {
    id: 'missingPropsModule',
    description: 'this is a missing properities module description',
    params: [
      {
        name: 'exampleParam',
        description: 'example param',
        type: 'string',
        multiple: false,
      },
    ],
    type: 'goals' as ModuleType,
  },
  files: {
    srcFile: { buffer: new Buffer('this is the source file') } as File,
    headerFile: { buffer: new Buffer('this is the header file') } as File,
    metaFile: { buffer: new Buffer('this is the meta file') } as File,
  },
};

const missingFilesModuleUpload : Partial<ModuleUpload> = {
  module: {
    id: 'properModule',
    name: 'properModule',
    description: 'this is a proper module description',
    params: [
      {
        name: 'exampleParam',
        description: 'example param',
        type: 'string',
        multiple: false,
      },
    ],
    type: 'goals' as ModuleType,
  },
  files: {
    srcFile: { buffer: new Buffer('this is the source file') } as File,
    metaFile: { buffer: new Buffer('this is the meta file') } as File,
  },
};

const properModuleUpdate : Partial<ModuleUpload> = {
  module: {
    description: 'this is an updated description',
    params: [],
  },
  files: {
    srcFile: { buffer: new Buffer('this is the updated source file') } as File,
    headerFile: { buffer: new Buffer('this is the updated source file') } as File,
  },
};

const updatedModule : Module = {
  id: 'properModule',
  name: 'properModule',
  description: 'this is an updated description',
  params: [],
  type: 'goals' as ModuleType,
};

const idModuleUpdate : Partial<ModuleUpload> = {
  module: {
    id: 'shouldntchange',
  },
};

const nameModuleUpdate : Partial<ModuleUpload> = {
  module: {
    name: 'shouldntchange',
  },
};

const emptyModuleUpdate : Partial<ModuleUpload> = {

};

const filesModuleUpdate : Partial<ModuleUpload> = {
  files:{
    srcFile: { buffer: new Buffer('this is the updated source file') } as File,
  },
};

const NUM_MODULE_TYPES = 11;

export {
  properModuleUpload,
  missingNameModuleUpload,
  missingIdModuleUpload,
  properModule,
  missingFilesModuleUpload,
  properModuleUpdate,
  updatedModule,
  idModuleUpdate,
  nameModuleUpdate,
  emptyModuleUpdate,
  filesModuleUpdate,
  NUM_MODULE_TYPES,
};