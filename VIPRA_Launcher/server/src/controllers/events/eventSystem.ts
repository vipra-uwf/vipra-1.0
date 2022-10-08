
import { Nullable } from '../../types/typeDefs';
import { evLogger } from './eventLogger';
import { EventHandler, EventType, RequestHandler, RequestType } from './eventTypes';


/**
 * @description System for handling events
 */
export class EventSystem {

  private handlersMap : Map<EventType, EventHandler[]>;

  private requestMap : Map<RequestType, RequestHandler>;

  constructor() {
    this.handlersMap = new Map();
    this.requestMap = new Map();
  }

  /**
   * @description Emits an event for all registered handlers
   * @param {EventType} event - type of event
   * @param {any} data - data that goes along with the event
   */
  public async emit<DataType>(event : EventType, data : Nullable<DataType>) : Promise<void> {
    if (data) {
      evLogger.info(`EMIT: ${Object.values(EventType)[event]} ; DATA: ${JSON.stringify(data)}`);
      const handlers : Nullable<EventHandler[]> = this.handlersMap.get(event) || null;
      if (handlers) {
        await Promise.all(handlers);
      }
    } else {
      evLogger.error(`NO DATA : EMIT ; EVENT : ${Object.values(EventType)[event]} ; DATATYPE : ${typeof data}`);
    }
  }

  /**
   * @description Emits a request event, if a handler is attached the requested object is returned
   * @param {any} select - information used to find specific object
   * @param {RequestType} type - type of object requested
   */
  public async request<DataType>(type : RequestType, select : unknown) : Promise<Nullable<DataType>> {
    evLogger.info(`REQUEST : ${Object.values(RequestType)[type]}, SELECT: ${select as string || 'NULL'}`);
    const handler = this.requestMap.get(type) || null;
    if (handler) {
      return await handler(select) as Nullable<DataType>;
    } else {
      evLogger.error(`FAIL: REQUEST: ${type}, SELECT: ${select as string || 'NULL'}`);
      return null;
    }
  }

  /**
   * @throws
   * @description Sets the request handler for a data request, throws error if there is already a request handler for the type
   * @param {RequestType} datatype - type of request the handler is for
   * @param {RequestHandler} handler - handler for request
   */
  public setRequestHandler(datatype : RequestType, handler : RequestHandler) : void {
    const type = Object.values(RequestType)[datatype];
    evLogger.info(`REGISTER : ${type}`);
    if (this.requestMap.has(datatype)) {
      evLogger.info(`FAIL: REGISTER: ${type}`);
      throw new Error(`Attempt to Set Multiple Request Handlers for: ${type}`);
    }
    this.requestMap.set(datatype, handler);
  }
  
  /**
   * @description Subscribes a handler to an event
   * @param  {EventType} event - type of event to subscribe to
   * @param  {EventHandler} handler - handler function to subscribe
   */
  public subscribe(event : EventType, handler : EventHandler) : void {
    evLogger.info(`SUBSCRIBE: ${Object.values(EventType)[event]}`);
    const handlerArray : Nullable<EventHandler[]> = this.handlersMap.get(event) || null;
    if (handlerArray) {
      handlerArray.push(handler);
    }
  }
}