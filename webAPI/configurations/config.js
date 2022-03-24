// TODO!!! uncomment this to link to the machines environment variables -RG
// NOTE: not needed for quiet a while -RG
//const env = process.env.NODE_ENV
const env = 'testing'

//VipraTest
//LBQdDpyga5s7S8j9

const testing = {
    app:{
        port:3000
    },
    fileIO:{
        FileCreator: require('../controllers/Configuration/SimConfigManager_Local')
    },
    simulation:{
        SimManager:     require('../controllers/Simulation/Sim/SimManager_ProvideCode'),
        UpdateManager:  require('../controllers/Simulation/Updates/UpdateManager_NoUpdates.js'),
        ConfigManager:  require('../controllers/Configuration/ConfigManager_NoSave')
    },
    repos:{
        UserRepo:       require('../controllers/Repos/Users/UserRepo_Mongo'),
        BehaviorRepo:   require('../controllers/Repos/Behaviors/BehaviorRepo_Mongo'),
        ConfigRepo:     require('../controllers/Repos/Configs/ConfigRepo_NoSave')
    },
    database:{
        BehaviorDB_Con: null,
        BehaviorDB: require('../database/behaviors/BehaviorDB_Mongo'),
        // TODO!!! make this an environment variable -RG
        BehaviorURI: "mongodb+srv://VipraTest:LBQdDpyga5s7S8j9@cluster0.oovhk.mongodb.net/VIPRA?retryWrites=true&w=majority",
        UserDB_Con: null,
        UserDB: require('../database/users/UserDB_Mongo'),
        // TODO!!! make this an environment variable _RG
        UserURI: "mongodb+srv://VipraTest:LBQdDpyga5s7S8j9@cluster0.oovhk.mongodb.net/VIPRA?retryWrites=true&w=majority"
    },
    behavior:{
        BehaviorManager: require('../controllers/Behavior/BehaviorManager')
    },
    users:{
        UserManager:        require('../controllers/Users/UserManager'),
        PasswordManager:    require('../controllers/Authentication/PasswordManager_bcrypt'),
    },
    authentication:{
        RequirePerms:   false,
        Authenticator:  require('../controllers/Authentication/Authenticator_JWT').Authenticator,
        DecodeToken:         require('../controllers/Authentication/Authenticator_JWT').DecodeToken,
        // TODO!!! make this an environment variable
        JWT_SECRET:     "testingSecret",
        JWT_EXPIRATION: 86400
    }
}


const config = {
    testing,
}

module.exports = config[env];