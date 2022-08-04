import { FLAGS } from "../data_models/flags";
import { readFile } from "./FileOperations";

// TODO: doesn't check for proper formatting -RG
const getCommandLineArguments = () : Map<string, string> => {
    const args = process.argv.slice(2);
    const params = new Map<string, string>();

    args.forEach((arg) => {
        const values = arg.split('=');
        params.set(values[0], values[1]);
    });

    if(params.has(FLAGS.FLAGS_FILE)){
        const flagsfile = readFile(params.get(FLAGS.FLAGS_FILE)).split('\n');
        flagsfile.forEach((line)=>{
            const flag = line.split('=');
            params.set(flag[0], `${flag[1] ? flag[1] : ''}`);
        });
    }
    return params;
};




export {
    getCommandLineArguments
};