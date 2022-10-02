import winston, { transports } from 'winston';


export const evLogger = winston.createLogger({
  transports: [transports.Console],
  level: 'debug',
  format: winston.format.combine(
    winston.format.timestamp({ format: 'YYYY-MM-DD HH:mm::ss' }),
    winston.format.json(),
  ),
});