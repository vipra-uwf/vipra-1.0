const mongoose = require('mongoose');

const ConnectDB = (uri)=>{
    const conn = mongoose.createConnection(uri)
    if(conn !== null){
        console.log("[INFO] User Database Connected");
    }else{
        console.log(`[ERROR] User Database Could NOT!! be Connected to`);
    }
    return conn.model('User', require('../models/Mongo/User'));
}

module.exports = {
    ConnectDB
}