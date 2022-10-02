import { MapController } from "../src/controllers/map/MapContoller";
import { FilesController } from "../src/controllers/files/FilesController";
import { FilesControllerMock } from "./mocks/FilesController.mock";

FilesControllerMock();


describe('MapController', ()=>{

  const mockFC = new FilesController();
  let sut : MapController = new MapController(mockFC);

  beforeEach(()=>{
    jest.resetAllMocks();
    sut = new MapController(mockFC);
  });

  it('Should Handle Adding Maps', ()=>{
    const bufferWriteSpy = jest.spyOn(mockFC, 'writeFileFromBuffer');
    const writeFileSpy = jest.spyOn(mockFC, 'writeFile');
    

  });

  it('Should Handle Removing Maps', ()=>{

  });

  it('Should Handle Rejecting Incomplete Maps', ()=>{

  });

  it('Should Handle Loading Maps on Startup', ()=>{

  });

});