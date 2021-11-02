const port = 3000
const express = require("express")
//const { exec } = require("child_process")

const app = express()

let allOutput = "Hello"

// exec("make ccr", (error, stdout, stderr) => {
//   if (error) {
//       console.log(`error: ${error.message}`);
//       return;
//   }
//   if (stderr) {
//       console.log(`stderr: ${stderr}`);
//       return;
//   }
//   console.log(`stdout: ${stdout}`);
// });

app.get("/", (req, res) => {
    res.send(allOutput)
})


app.listen(port)
console.log(`The server has started and is listening on port number:${port}`)

