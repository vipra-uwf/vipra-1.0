import { FilesController }  from '../controllers/files/FilesController';
import { ModuleController } from '../controllers/module/moduleController';
import { ProcessRunner }    from '../controllers/processes/ProcessRunner';
import { ConfigManager }    from '../controllers/simconfig/ConfigManager';
import { SimBuilder }       from '../controllers/simulation/SimBuilder';
import { SimManager }       from '../controllers/simulation/SimManager';
import { SimRunner }        from '../controllers/simulation/SimRunner';
import { ChainManager }     from '../controllers/chainbuilder/ChainManager';
import { container }        from 'tsyringe';

/**
 * @description Registers The implementations for Dependency Injections
 */
const setupDI = () : void => {
  container.register('ConfigManager', { useClass: ConfigManager });
  container.register('SimRunner', { useClass: SimRunner });
  container.registerSingleton('SimBuilder', SimBuilder);
  container.registerSingleton('ModuleController', ModuleController);
  container.registerSingleton('FilesController', FilesController);
  container.registerSingleton('ProcessRunner', ProcessRunner);
  container.registerSingleton('SimManager', SimManager);
  container.registerSingleton('ChainManager', ChainManager);
};



export {
  setupDI,
};