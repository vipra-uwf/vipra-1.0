import { compileMain, compileSim } from "../../util/Processes";
import { Status } from "../../data_models/Status.e";




export const generateSimulation = async () : Promise<Status> => {

    // generate_main
    // compile main
    // compile simulation

    const mainGen = await compileMain();
    if(mainGen !== Status.SUCCESS){
        return mainGen;
    }

    const mainComp = await compileSim();
    if(mainGen !== Status.SUCCESS){
        return mainComp;
    }

    return Status.SUCCESS;
};