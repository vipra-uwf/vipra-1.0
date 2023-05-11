import { MockEventSystem } from '../mocks/events/eventSystem.mock';
MockEventSystem();

import { MockLogger } from '../mocks/Logger.mock';
MockLogger();

import { MockModuleService } from '../mocks/module/moduleservice.mock';
MockModuleService();

import { ModuleController } from '../../controllers/module/module.controller';
import { EventSystem } from '../../controllers/events/eventSystem';
import { Logger } from '../../controllers/logging/logger';
import { ModuleService } from '../../services/module/module.service';

describe('ModuleController', ()=>{
  
  const evSys = new EventSystem();
  const logger = new Logger();
  const moduleService = new ModuleService();
  

  let moduleController : ModuleController;
  

  beforeEach(()=>{
    moduleController = new ModuleController(evSys, logger, moduleService);
    jest.clearAllMocks();
  });

  it('Should Initialize Properly', ()=>{
    const setRequestSpy = jest.spyOn(evSys, 'setRequestHandler');
  
    moduleController = new ModuleController(evSys, logger, moduleService);

    expect(setRequestSpy).toBeCalledTimes(1);    
  });

  

});