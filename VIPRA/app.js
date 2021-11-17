const port = 3000;
const express = require("express");

const app = express();

let main = require('./controllers/main');

app.get("/", main.home);

app.listen(port);
console.log(`The server has started and is listening on port number:${port}`);


