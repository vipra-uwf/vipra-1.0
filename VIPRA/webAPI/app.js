const port = 3000;
const express = require("express");

const app = express();

const API_Routes = require("./routes/API_routes.js");



app.use('/', API_Routes);

app.listen(port);
console.log(`The server has started and is listening on port number:${port}`);
