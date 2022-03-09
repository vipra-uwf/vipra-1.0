
// Holds the file paths for regularly needed files -RG


const path = require('path');

const INPUT_DATA_PATH           = path.resolve(__dirname, './../../input_data');
const OUTPUT_DATA_PATH          = path.resolve(__dirname, './../../output_data/pedestrian_trajectory.json');
const SIM_OPTIONS_PATH          = path.resolve(__dirname, './../../input_data/sim_options.json');

const SIM_RUN_PATH              = path.resolve(__dirname, './../startSim');
const SIM_COMPILE_PATH          = path.resolve(__dirname, './../compileSim');

const PERMISSIONS_FILE_PATH     = path.resolve(__dirname, './permissions.json')
const ROUTE_PERMISSIONS_PATH    = path.resolve(__dirname, './route_permissions.json')


module.exports = 
{
    INPUT_DATA_PATH,
    OUTPUT_DATA_PATH,
    SIM_OPTIONS_PATH,
    SIM_RUN_PATH,
    SIM_COMPILE_PATH,
    PERMISSIONS_FILE_PATH,
    ROUTE_PERMISSIONS_PATH
}
