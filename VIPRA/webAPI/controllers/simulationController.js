
// All Functions for setting up and running a simulation


const { SIM_OPTIONS_PATH, INPUT_DATA_PATH, OUTPUT_DATA_PATH, SIM_RUN_PATH, SIM_COMPILE_PATH } = require('./../File_Paths');

const spawn                                = require('child_process').spawn;

const cID_Process_Map = new Map();

// TODO remove console logs from this file


// TODO Spawn a proper process and feed it with the unique configID for the configuration chosen -RG
const spawnSimulation = (configID) => {
    let ps = spawn('sh', [SIM_RUN_PATH, configID]).on('spawn', ()=>{
        cID_Process_Map.set(configID, ps);
    });
    ps.on('close', (data)=>{
        cID_Process_Map.delete(configID);
    })
    return ps.connected;
}

const spawnCompile = (configID) =>{
    let ps = spawn('sh', [SIM_COMPILE_PATH, configID]);
    ps.stdout.on('data', (data)=>{console.log(data.toString())})
    ps.stderr.on('data', (data)=>{console.log(data.toString()); })
}


const sendSimOptions = async (response)=>{

    //TODO on error send proper response -RG
    console.log("Sending Options");

    return fs.readFile(SIM_OPTIONS_PATH, (err, data)=>{
        if(err){
            response.send("Error Reading From Options File");
        }else{
            response.send(data);
        }
    });
}

// TODO check for errors in compilation
const compileSimulation = (configID) =>{
    console.log("COMPILING SIMULTAION");
    spawnCompile(configID);
}

// TODO actually run the simulation and get the pid
// TODO check for errors in running simulation
// TODO this compiles the simulation as well, may want to move
const StartSim = (configID) => {
    compileSimulation(configID);
    console.log("STARTING SIMULATION");
    spawnSimulation(configID);
}



module.exports = 
{
    sendSimOptions,
    compileSimulation,
    StartSim,
    cID_Process_Map
}