const mongoose = require('mongoose');

const ConnectDB = (uri)=>{
    const conn = mongoose.createConnection(uri);
    return conn.model('Behavior', require('../models/Mongo/Behavior'));
}

module.exports = {
    ConnectDB,
}