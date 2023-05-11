/* eslint-disable jsdoc/require-jsdoc */


/**
 * @description Mocks an EventSystem
 */
export const MockLogger = () : void => {
  jest.mock('../../controllers/logging/logger', () => {
    return {
      Logger: jest.fn().mockImplementation(()=>{
        return {
          error : ():void=>{},
          info : ():void=>{},
          debug :():void=>{},
        };
      }),
    };
  });
};

/* eslint-enable */