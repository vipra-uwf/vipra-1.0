
// TODO Output from simulation all goes into output_files/

const express       = require("express");
const config        = require("./configurations/config");
const cors = require('cors')

const app = express();

// TODO THIS IS NOT SECURE , this will need changed -RG
app.use(cors());

const API_Routes = require("./routes/API_routes.js");

app.use('/api', API_Routes);

app.listen(config.app.port);
console.log(`The server has started and is listening on port number:${config.app.port}`);
