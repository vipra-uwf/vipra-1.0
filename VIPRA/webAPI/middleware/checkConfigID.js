
const fs = require('fs')

const { INPUT_DATA_PATH } = require('./../configurations/File_Paths')

const checkConfigID = (req, res, next)=>{
    
    const configID = req.body.configID;
    fs.exists(INPUT_DATA_PATH.concat('/', configID), (e)=>{
        if(!e){
            res.status(400).send("No Simulation Config with ID: " + configID);
        }
        else{
            next();
        }
    });
}

module.exports = {
    checkConfigID
}