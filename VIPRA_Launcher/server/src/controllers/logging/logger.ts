
import winston from 'winston';


/**
 * @description Class to handle logging
 */
export class Logger {
  
  private logger : winston.Logger;

  constructor() {
    this.logger = winston.createLogger({
      transports: [winston.transports.Console],
      level: 'debug',
      format: winston.format.combine(
        winston.format.timestamp({ format: 'YYYY-MM-DD HH:mm::ss' }),
        winston.format.json(),
      ),
    });
  }

  /**
   * @description Logs an error message
   * @param {string} message - message to log
   */
  public error(message : string) : void {
    this.logger.error(message);
  }

  /**
   * @description Logs an info message
   * @param {string} message - message to log
   */
  public info(message : string) : void {
    this.logger.info(message);
  }

  /**
   * @description Logs a debug message
   * @param {string} message - message to log
   */
  public debug(message : string) : void {
    this.logger.debug(message);
  }
}
