import winston from 'winston';
import { loggingConfig } from '../configuration/loggingConfig';

const { combine, timestamp, json} = winston.format;

// eslint-disable-next-line @typescript-eslint/naming-convention
const Logger = winston.createLogger({
    level: loggingConfig.level,
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