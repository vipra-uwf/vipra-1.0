// TODO!!! uncomment this to link to the machines environment variables -RG
// NOTE: not needed for quiet a while -RG
//const env = process.env.NODE_ENV
const env = 'testing'

const testing = {
    app:{
        port:3000
    },
    fileIO:{
        FileCreator: require('../controllers/Configuration/SimConfigManager_Local')
    },
    simulation:{
        SimManager:     require('../controllers/Simulation/SimManager_API'),
        UpdateManager:  require('../controllers/Simulation/UpdateManager_SSE.js'),
        ConfigManager:  require('../controllers/Configuration/SimConfigManager_Local.js')
    },
    repos:{
        UserRepo:   require('../controllers/Repos/Users/UserRepo_Mock'),
        ConfigRepo: require('../controllers/Repos/Configs/ConfigRepo_Local'),
        BehaviorRepo: require('../controllers/Repos/Behaviors/BehaviorRepo_Local')
    },
    behavior:{
        BehaviorManager: require('../controllers/Behavior/BehaviorManager')
    },
    users:{
        UserManager:        require('../controllers/Users/UserManager_Local'),
        PasswordManager:    require('../controllers/Authentication/PasswordManager_bcrypt'),
        // TODO!!! make this an environment variable
        JWT_SECRET:     "testingSecret",
        JWT_EXPIRATION: 86400
    },
    authentication:{
        RequirePerms: false,
        Authenticator:  require('../controllers/Authentication/Authentication_JWT').Authenticator,
        Decode:         require('../controllers/Authentication/Authentication_JWT').Decode
    }
}


const config = {
    testing,
}

module.exports = config[env];