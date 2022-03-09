
const config = require('./../configurations/config')

const ConfigManager = new config.simulation.ConfigManager();

const checkConfigID = (req, res, next)=>{
    
    let configID= req.body.configID;

    if(req.params.configID){
        configID = req.params.configID;
    }

    if(configID){
        fs.exists(INPUT_DATA_PATH.concat('/', configID), (e)=>{
            if(!e){
                res.status(400).send("No Simulation Config with ID: " + configID);
            }
            else{
                next();
            }
        });
    }else{
        res.status(400).send("No Simulation Config with ID: " + configID);
    }
}

module.exports = {
    checkConfigID
}