import express from 'express';

import { OMap, MapInfo, mapToInfo } from '../types/map';
import { respondCreated, respondData, respondError, respondSuccess, respondUnknownError } from '../util/Responses';
import { IMapController } from '../controllers/map/interfaces/MapController.interface';
import { Nullable } from '../types/typeDefs';
import { Status } from '../types/Status';
import multer from 'multer';
import { Logger } from '../logging/Logging';

type MapRequestBody = {
  id? : string;
  name? : string;
  description? : string;
};

const store = multer();

/**
 * @description Creates the router for Maps requests
 * @param {IMapController} mapsController - map controller implementation
 * @returns {express.Router} map routes router
 */
const mapRouter = (mapsController : IMapController) : express.Router=>{
  const mapRoutes : express.Router = express.Router();


  mapRoutes.get('/', (req : express.Request, res : express.Response) => {
    const maps : MapInfo[] = mapsController.getAllMaps().map((map) => { return mapToInfo(map); });
    respondData(maps, res);
  });

  mapRoutes.get('/:id', (req : express.Request, res : express.Response) => {
    const map : Nullable<OMap> = mapsController.getMap(req.params.id);
    if (map) {
      const mapInfo : MapInfo = mapToInfo(map);
      respondData(mapInfo, res);
    } else {
      respondError(Status.NOT_FOUND, 'Map Not Found', `No Map with ID: ${req.params.id}`, res);
    }
  });

  mapRoutes.post('/', store.single('map'), (req : express.Request, res : express.Response) => {
    const body : MapRequestBody = req.body as MapRequestBody;
    if (req.file && req.file.buffer) {
      const added = mapsController.addMap(body, req.file.buffer);
      switch (added.status) {
        case Status.CREATED:
          respondCreated(res);
          break;
        case Status.BAD_REQUEST:
          respondError(Status.BAD_REQUEST, '', '', res);
          break;
        case Status.INTERNAL_ERROR:
          respondUnknownError(res);
          break;
        default:
          Logger.error(`Unhandled Status in POST map/ : ${added.status}`);
          respondUnknownError(res);
      }
    } else {
      respondError(Status.BAD_REQUEST, 'Missing File', 'Map File Missing', res);
    }
  });

  mapRoutes.delete('/:id', (req : express.Request, res : express.Response) => {
    const removed = mapsController.removeMap(req.params.id);

    switch (removed.status) {
      case Status.SUCCESS:
        respondSuccess(res);
        break;
      case Status.BAD_REQUEST:
        respondError(Status.BAD_REQUEST, 'Missing Properties', '', res);
        break;
      case Status.NOT_FOUND:
        respondError(Status.NOT_FOUND, 'Map Not Found', `No Map with ID: ${req.params.id}`, res);
        break;
      case Status.INTERNAL_ERROR:
        break;
      default:
        Logger.error(`Unhandled Status in DELETE map/:id : ${removed.status}`);
        respondUnknownError(res);
    }
  });


  return mapRoutes;
};


export {
  mapRouter,
};