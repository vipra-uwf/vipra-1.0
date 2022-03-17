const mongoose = require('mongoose');

let UserDB_Con = null;

const ConnectDB = (uri)=>{
    const conn = mongoose.createConnection(uri)
    console.log("[INFO] Behavior Database Connected");
    UserDB_Con = conn.model('User', require('../models/Mongo/User'));
}

module.exports = {
    ConnectDB,
    UserDB_Con
}