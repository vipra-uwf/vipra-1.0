import winston from 'winston';

const { combine, timestamp, json} = winston.format;

const Logger = winston.createLogger({
    level: 'debug',
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