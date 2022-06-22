import winston from 'winston';
import { logConf } from '../configuration/logConf';

const Logger = winston.createLogger({
    level: logConf.Level,
    transports:[
        new winston.transports.Console()
    ]
});


export {
    Logger
};