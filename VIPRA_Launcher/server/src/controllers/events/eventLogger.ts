import winston from 'winston';


export const evLogger = winston.createLogger({
  transports: [new winston.transports.Console()],
  level: 'debug',
  format: winston.format.combine(
    winston.format.timestamp({ format: 'YYYY-MM-DD HH:mm::ss' }),
    winston.format.align(),
    winston.format.json(),
  ),
});