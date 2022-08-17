/**
 * @module Util
 */

import { Nullable } from "../types/typeDefs";
import { FLAGS } from "../types/flags";
import { container } from "tsyringe";
import { FilesController } from "../controllers/files/FilesController";



const fc = container.resolve(FilesController);

/**
 * @description Creates a map containing the commandline flags and their respective values
 *
 * @note values are set to '' if the flag was input with an = -RG
 */
const getCommandLineArguments = () : Map<string, string> => {

    // TODO stop for flags that don't exist -RG
    // TODO doesn't check for proper formatting -RG

    const args = process.argv.slice(2);
    const params = new Map<string, string>();

    args.forEach((arg) => {
        const values = arg.split('=');
        params.set(values[0], values[1]);
    });

    if(params.has(FLAGS.FLAGS_FILE)){
        const filePath = params.get(FLAGS.FLAGS_FILE);
        if(filePath){
            const flagsfile : Nullable<string> = fc.readFile(filePath);
            if(flagsfile){
                const flags : string[] = flagsfile.split('\n');
                flags.forEach((line)=>{
                    const flag = line.split('=');
                    params.set(flag[0], `${flag[1] ? flag[1] : ''}`);
                });
            }
        }
    }
    return params;
};


export {
    getCommandLineArguments
};