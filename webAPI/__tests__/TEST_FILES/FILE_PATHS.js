const path = require('path')



const EXISTANT_FILE = path.resolve(__dirname, 'EXISTANT_FILE');
const NON_EXISTANT_FILE = path.resolve(__dirname, 'NON_EXISTANT_FILE');
const NON_EXISTANT_DIR = path.resolve(__dirname, 'NON_EXISTANT_DIR');
const TEST_TEXT_FILE = path.resolve(__dirname, 'TEST_TEXT');
const TESTFILE_DIR = path.resolve(__dirname);

const CONFIGS_DIR = path.resolve(__dirname, 'CONFIGS_DIR');

const TEST_DIR = path.resolve(__dirname, 'TEST_DIR');
const COPYTEST_DIR = path.resolve(__dirname, 'COPYTEST_DIR');

const MAKEDIR_PATH = path.resolve(__dirname, 'MAKEDIR');

module.exports = {
    EXISTANT_FILE,
    TEST_DIR,
    NON_EXISTANT_FILE,
    TEST_TEXT_FILE,
    COPYTEST_DIR,
    TESTFILE_DIR,
    CONFIGS_DIR,
    MAKEDIR_PATH,
    NON_EXISTANT_DIR
}