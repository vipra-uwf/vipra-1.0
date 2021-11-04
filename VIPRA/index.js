const port = 3000;
const express = require("express");
const { exec } = require("child_process");

const app = express();

exec("./run.sh", (stdout) => {
  console.log(`stdout: ${stdout}`);
});

//Or exec("make", ...)
//exec("make generated_main", ...)
//exec("./generated_main", ...)

app.get("/", (req, res) => {
    res.send("Hello");
})


app.listen(port);
console.log(`The server has started and is listening on port number:${port}`);

