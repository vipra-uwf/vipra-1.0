import express from 'express';

import { respondData, respondError, respondSuccess, respondUnknownError } from '../util/Responses';
import { SimConfig, SimConfigIDs }        from '../data_models/simconfig';
import { ConfigManager }    from '../controllers/simconfig/ConfigManager';
import { Status }           from '../data_models/Status.e';
import { Logger }           from '../logging/Logging';


const simConfigRouter = (configManager : ConfigManager) : express.Router => {

    const simConfigRoutes   : express.Router    = express.Router();
    configManager.loadConfigs();

    // TODO!!!!: this returns file paths etc, remove those before sending -RG
    simConfigRoutes.get('/', (req, res)=>{
        respondData(configManager.getConfigs(), res);
    });

    simConfigRoutes.post('/', (req : express.Request<{}, {}, {simconfig : SimConfigIDs; name : string; description : string}>, res)=>{
        const simconf : SimConfigIDs = req.body.simconfig;
        if(simconf){
            configManager.createConfig(simconf)
            .then((created)=>{
                switch(created.status){
                    // TODO return the created config
                    case Status.CREATED:
                        respondSuccess(res);
                        break;
                    case Status.BAD_REQUEST:
                        respondError(Status.BAD_REQUEST, `Missing Attributes`, `The Provided config was missing required modules or the chosen modules are not available`, res);
                        break;
                    case Status.CONFLICT:
                        respondError(Status.CONFLICT, 'Dupicate Configuration', `The provided configuration matches another config: ${created.config.name}`, res);
                        break;
                    case Status.INTERNAL_ERROR:
                        respondUnknownError(res);
                        break;
                    default:
                        Logger.error(`Unhandled Status in createConfig: ${created.status}`);
                        respondUnknownError(res);
                }
            })
            .catch((error : string)=>{
                Logger.error(`createConfig: ${error}`);
                respondUnknownError(res);
            });
        }else{
            respondError(Status.BAD_REQUEST, `No Configuration`, `No Simulation Configuration was provided`, res);
        }
    });

    simConfigRoutes.delete('/:id', (req, res)=>{
        const removed = configManager.removeConfig(req.params.id);
        switch(removed){
            case Status.SUCCESS:
                respondSuccess(res);
                break;
            case Status.NOT_FOUND:
                respondError(Status.NOT_FOUND, `Not Found`, `No Simulation Configuration with that ID was found`, res);
                break;
            default:
                Logger.error(`Unhandled Status in removeConfig: ${removed}`);
                respondUnknownError(res);
        }
    });
    return simConfigRoutes;
};


export {
    simConfigRouter
};