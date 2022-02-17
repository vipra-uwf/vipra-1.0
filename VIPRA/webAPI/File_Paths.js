
// Holds the file paths for regularly needed files -RG


const path = require('path');

const SIM_CONFIG_PATH    = path.resolve(__dirname, './../input_data/sim_config');
const OUTPUT_DATA_PATH   = path.resolve(__dirname, './../output_data/pedestrian_trajectory.json');
const SIM_OPTIONS_PATH   = path.resolve(__dirname, './../input_data/sim_options.json');

const SIM_RUN_PATH       = path.resolve(__dirname, './../run');


module.exports = 
{
    SIM_CONFIG_PATH,
    OUTPUT_DATA_PATH,
    SIM_OPTIONS_PATH,
    SIM_RUN_PATH
}