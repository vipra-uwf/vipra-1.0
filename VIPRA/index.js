const port = 3000;
const express = require("express");
const exec = require("child_process").exec;

const app = express();

let vipraProcess = exec('./run.sh');
vipraProcess.stdout.on('data', function(data) {
	console.log(data);
});

app.get("/", (req, res) => {
    res.send("Hello\n");
})

app.listen(port);
console.log(`The server has started and is listening on port number:${port}`);


