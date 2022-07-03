import { config } from "./config";
import { makeDir } from "../util/FileOperations";



const initialSetup = () : void => {
    makeDirectories();
};


const makeDirectories = () : void =>{
    makeDir(config.vipra.vipraDir);
    makeDir(config.vipra.outputDir);
    makeDir(config.vipra.simsDir);
    makeDir(config.module.modulesDir);
};


export {
    initialSetup
};