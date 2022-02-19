
// TODO maybe able to use this to decide on implementations -RG

// TODO uncomment this to link to the machines environment variables -RG
// NOTE: not needed for quiet a while -RG
//const env = process.env.NODE_ENV
const env = 'testing'

const testing = {
    app:{
        port:3000
    }
}


const config = {
    testing,
}

module.exports = config[env];