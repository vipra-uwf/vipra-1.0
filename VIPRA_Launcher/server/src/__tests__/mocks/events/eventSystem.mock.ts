/* eslint-disable jsdoc/require-jsdoc */


/**
 * @description Mocks an EventSystem
 */
export const MockEventSystem = () : void => {
  jest.mock('../../../controllers/events/eventSystem', () => {
    return {
      EventSystem: jest.fn().mockImplementation(()=>{
        return {
          emit: () : void => {},
          request: () : void => {},
          setRequestHandler: () : void => {},
          subscribe: () : void => {},
        };
      }),
    };
  });
};

/* eslint-enable */