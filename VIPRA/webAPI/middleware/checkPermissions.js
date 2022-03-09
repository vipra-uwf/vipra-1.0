
const fs = require('fs')

const config                                                = require('./../configurations/config')
const { PERMISSIONS_FILE_PATH, ROUTE_PERMISSIONS_PATH }     = require('./../configurations/File_Paths')

const decode = config.users.Decode;

const PermissionsJSON = JSON.parse(fs.readFileSync(PERMISSIONS_FILE_PATH));
const RoutePermsJSON = JSON.parse(fs.readFileSync(ROUTE_PERMISSIONS_PATH));

if(!PermissionsJSON){
    console.log('[FATAL] Fatal Error reading Permissions JSON file');
    throw 'Unable to read permissions'
}

const checkPermissions = async (req, res, next)=>{
    
    if(config.users.RequirePerms){
        const user = await decode(req, config.users.JWT_SECRET);
        if(!user){
            res.status(400).json({message:'Invalid Token'});
            return;
        }

        // TODO!! get permissions for user (have to decide how best to do this) -RG
        const perms = RoutePermsJSON[user.roles];

        if(!perms.includes(req.originalUrl)){
            res.status(400).json({message:'No Permission For This Resource'});
            return;
        }
    }else{
        console.log("[WARNING] Permissions Requirement is NOT enabled!!");
    }
    next();
}

module.exports = {
    checkPermissions
}