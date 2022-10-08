
import winston from 'winston';


/**
 * @description Class to handle logging
 */
export const Logger = winston.createLogger({
  transports: [new winston.transports.Console()],
  level: 'debug',
  format: winston.format.combine(
    winston.format.json(),
    winston.format.timestamp({ format: 'YYYY-MM-DD HH:mm::ss' }),
    winston.format.align(),
  ),
});
 