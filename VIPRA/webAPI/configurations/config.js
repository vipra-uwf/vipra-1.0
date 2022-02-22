// TODO uncomment this to link to the machines environment variables -RG
// NOTE: not needed for quiet a while -RG
//const env = process.env.NODE_ENV
const env = 'testing'

const testing = {
    app:{
        port:3000
    },
    fileIO:{
        FileCreator: require('./../controllers/InputFileCreator_Local')
    },
    simulation:{
        SimManager:     require('../controllers/SimManager_API'),
        IDManager:      require('../controllers/IDManager_RandomUUID'),
        UpdateManager:  require('../controllers/UpdateManager_SSE.js')
    }
}


const config = {
    testing,
}

module.exports = config[env];