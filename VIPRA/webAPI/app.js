
const express       = require("express");
const config        = require("./configurations/config");


const app = express();

// TODO!!!! THIS IS NOT SECURE , this will need changed -RG
const cors = require('cors')
app.use(cors());

const API_Routes = require("./routes/Sim_routes.js");
const User_Routes = require('./routes/User_routes');

app.use('/api', API_Routes);
app.use('/api', User_Routes);

app.listen(config.app.port);
console.log(`The server has started and is listening on port number:${config.app.port}`);
