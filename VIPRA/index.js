#!/usr/bin/env node

const port = 3000;
const express = require("express");
const { exec } = require("child_process");

const app = express();

//To-do: exec statements running in random order

exec("sudo make cc", (err, stdout, stderr) => {
   console.log("Starting program compilation...");
   console.log(`stdout: ${stdout}`);
   
   if (err) {
      console.error(`err: ${err}`);
   }
   if (stderr) {
      console.error(`stderr: ${stderr}`);
   }
});

exec("sudo make generate_main", (err, stdout, stderr) => {
   console.log(`stdout: ${stdout}`);

   if (err) {
      console.error(`err: ${err}`);
   }
   if (stderr) {
      console.error(`stderr: ${stderr}`);
   }
   console.log("Program compiled");
});

exec("sudo make run", (err, stdout, stderr) => {
   console.log("Running program...");
   console.log(`stdout: ${stdout}`);

   if (err) {
       console.error(`err: ${err}`);
       return;
   }
   if (stderr) {
      console.error(`stderr ${stderr}`);
      return;
   }
   console.log("Program complete");
});

app.get("/", (req, res) => {
    res.send("Hello\n");
})


app.listen(port);
console.log(`The server has started and is listening on port number:${port}`);

