
// TODO fix makefile to build generated_main use configIDs

const express       = require("express");
const config        = require("./config");

const app = express();

const API_Routes = require("./routes/API_routes.js");

app.use('/api', API_Routes);

app.listen(config.app.port);
console.log(`The server has started and is listening on port number:${config.app.port}`);
