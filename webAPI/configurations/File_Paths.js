
// Holds the file paths for regularly needed files -RG


const path = require('path');

const VIPRA_FOLDER              = path.resolve(__dirname, "../../VIPRA");

const INPUT_DATA_PATH           = path.resolve(__dirname, `${VIPRA_FOLDER}/input_data`);
const OUTPUT_DATA_PATH          = path.resolve(__dirname, `${VIPRA_FOLDER}/output_data/pedestrian_trajectory.json`);
const SIM_OPTIONS_PATH          = path.resolve(__dirname, `${VIPRA_FOLDER}/input_data/sim_options.json`);

const IMAGES_DIR_PATH           = path.resolve(__dirname, './../../DockerImages');
const SOURCE_DIR_PATH           = path.resolve(__dirname, './../../src');
const INCLUDE_DIR_PATH          = path.resolve(__dirname, './../../include');
const BUILD_DIR_PATH            = path.resolve(__dirname, './../BUILDS');
const AUTOCONF_DIR_PATH         = path.resolve(__dirname, './../../Autoconf_files');

const BEHAVIOR_FOLDER_PATH      = path.resolve(__dirname, `${VIPRA_FOLDER}/input_data/behaviors`);

const SIM_RUN_PATH              = path.resolve(__dirname, './../scripts/startSim');
const SIM_GEN_PATH              = path.resolve(__dirname, './../scripts/generateSim');

module.exports = 
{
    INPUT_DATA_PATH,
    OUTPUT_DATA_PATH,
    SIM_OPTIONS_PATH,
    SIM_RUN_PATH,
    SIM_GEN_PATH,
    BEHAVIOR_FOLDER_PATH,
    IMAGES_DIR_PATH,
    INCLUDE_DIR_PATH,
    BUILD_DIR_PATH,
    SOURCE_DIR_PATH,
    AUTOCONF_DIR_PATH
}
