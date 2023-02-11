import { createLogger, format, transports }  from 'winston';
const { combine, colorize, timestamp, printf } = format;

// NOTE: the shadow is necessary -RG
// eslint-disable-next-line @typescript-eslint/no-shadow
const LogFormat = printf(({ level, message, timestamp }) => {
  return `${timestamp as string} ${level}: ${message as string}`;
});


/**
 * @description Class to handle logging
 */
export const Logger = createLogger({
  level: 'debug',
  format: combine(
    timestamp(),
    colorize(),
    LogFormat,
  ),
  transports: [
    new transports.Console(),
  ],
});