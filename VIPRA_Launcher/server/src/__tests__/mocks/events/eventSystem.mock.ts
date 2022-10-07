/* eslint-disable jsdoc/require-jsdoc */

import { RequestType } from "../../../controllers/events/eventTypes";


/**
 * @description Mocks an EventSystem
 */
export const MockEventSystem = () : void => {
  jest.mock('../../../controllers/events/eventSystem', () => {
    return {
      EventSystem: jest.fn().mockImplementation(()=>{
        return {
          emit: () : void => {},
          request: (type : RequestType, select : any) : any => { 
            if (select.id){
              if (select.id === 'good') {
                return select; 
              }
            }
            return null;
          },
          setRequestHandler: () : void => {},
          subscribe: () : void => {},
        };
      }),
    };
  });
};

/* eslint-enable */