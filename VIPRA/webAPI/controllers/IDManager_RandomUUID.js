
const crypto = require('crypto');

class IDManager_UUID{
    constructor(){}

    GetID(request){
        if(request.body.configID == null){
            return crypto.randomUUID();
        }else{
            return request.body.configID;
        }
    }
}


module.exports = IDManager_UUID;