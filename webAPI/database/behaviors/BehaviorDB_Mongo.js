const mongoose = require('mongoose');

const ConnectDB = (uri)=>{
    const conn = mongoose.createConnection(uri);
    if(conn !== null){
        console.log(`[INFO] Behavior Database Connected`);
    }else{
        console.log(`[ERROR] Behavior Database Could NOT!! be Connected to`);
    }
    return conn.model('Behavior', require('../models/Mongo/Behavior'));
}

module.exports = {
    ConnectDB,
}