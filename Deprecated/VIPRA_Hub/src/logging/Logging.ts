import winston from 'winston';
import { logConf } from '../configuration/logConf';

const { combine, timestamp, json} = winston.format;

const Logger = winston.createLogger({
    level: logConf.Level,
    transports:[
        new winston.transports.Console()
    ],
    format: combine(
        timestamp(),
        json()
    )
});


export {
    Logger
};