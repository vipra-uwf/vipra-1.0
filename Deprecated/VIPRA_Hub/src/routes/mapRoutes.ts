import express      from "express";

import { MapsContoller }         from "../controllers/map/MapsController";
import { config }               from "../configuration/config";
import { Status }               from "../data_models/Status";
import { RespondData, RespondError, RespondUnknownError, RespondSuccess, RespondBehavior, RespondCreated } from "../util/Responses";
import { Map, CheckMap } from "../data_models/Map";
import { Logger } from "../logging/Logging";


const MapRoutes : express.Router = express.Router();

const mapRepo = config.Map.MapRepo();
mapRepo.connect(config.Behavior.DB_URI);

const MapController : MapsContoller = new MapsContoller(mapRepo);

MapRoutes.get('/', (req, res)=>{
    MapController.getOptions()
    .then((options)=>{
        RespondData(res, options);
    })
    .catch((error)=>{
        Logger.error(`Error in GET /map: ${error}`);
        RespondUnknownError(res);
    });
});

MapRoutes.post('/', (req : express.Request<{}, {}, {map : Map}, {}>, res)=>{
    if(!CheckMap(req.body.map)){
        RespondError(Status.BAD_REQUEST, "Invalid Request", "The Request was missing, or had incorrect, attributes for a Map", res);
        return;
    }
    const map : Map = req.body.map;

    MapController.createMap(map)
    .then((created)=>{
        switch(created){
            case Status.SUCCESS:
                RespondCreated(res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            case Status.CONFLICT:
                RespondError(Status.CONFLICT, "Duplicate Name", "Map Names are required to be unique", res);
                break;
            default:
                Logger.error(`Unkown Error in POST /map: ${created}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(`Error in POST /map: ${error}`);
        RespondUnknownError(res);
    });
});

MapRoutes.put('/:name', (req : express.Request<{name: string}, {}, {map : Map}, {}>, res)=>{
    const map : Map = req.body.map;
    const name = req.params.name;

    if(!map.content && !map.description && !map.publish){
        RespondError(Status.BAD_REQUEST, "Invalid Request", "The Request was missing required attributes", res);
        return;
    }

    MapController.updateMap(name, map)
    .then((updated)=>{
        switch(updated){
            case Status.SUCCESS:
                RespondSuccess(res);
                break;
            case Status.BAD_REQUEST:
                RespondError(Status.BAD_REQUEST,"Bad Request","The Request was missing required attributes for a Map",res);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Map was found with the provided name", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(`Unhandled Status in PUT /map: ${updated}`);
                RespondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(`Error in PUT /map: ${error}`);
        RespondUnknownError(res);
    });
});

MapRoutes.get('/:name', (req, res)=>{
    MapController.getMap(req.params.name)
    .then((result)=>{
        switch(result.status){
            case Status.SUCCESS:
                RespondData(res, result.map);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Map with the provided name was found", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(`Unhandled Status in GET /map: ${result.status}`);
                RespondUnknownError(res);
                break;
        }
    })
    .catch((error)=>{
        Logger.error(`Error in GET /map`);
        RespondUnknownError(res);
    });
});

MapRoutes.delete('/:name', (req, res)=>{
    MapController.deleteMap(req.params.name)
    .then((deleted)=>{
        switch(deleted){
            case Status.SUCCESS:
                RespondSuccess(res);
                break;
            case Status.NOT_FOUND:
                RespondError(Status.NOT_FOUND, "Not Found", "No Map was found with the provided name", res);
                break;
            case Status.INTERNAL_ERROR:
                RespondUnknownError(res);
                break;
            default:
                Logger.error(`Unhandled Status in DELETE /map: ${deleted}`);
                RespondUnknownError(res);
        }
    })
    .catch((error)=>{
        Logger.error(`Error in DELETE /map: ${error}`);
        RespondUnknownError(res);
    });
});

export {MapRoutes};
