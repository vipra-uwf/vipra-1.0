const port = 3000;
const express = require("express");
const exec = require("child_process").exec;
const app = express();

let vipraProcess = exec('./run.sh');
vipraProcess.stdout.on('data', function(data) {
		console.log(data);
});

let main = require('./controllers/main');

app.get("/", main.home);

app.listen(port);
console.log(`The server has started and is listening on port number:${port}`);
