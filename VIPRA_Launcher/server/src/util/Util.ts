
// TODO: doesn't check for proper formatting -RG
const getCommandLineArguments = () : Map<string, string> => {
    const args = process.argv.slice(2);
    const params = new Map<string, string>();

    args.forEach((arg) => {
        const values = arg.split('=');
        params.set(values[0], values[1]);
    });

    return params;
};




export {
    getCommandLineArguments
};