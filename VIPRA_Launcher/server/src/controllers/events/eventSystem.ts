
import { Nullable } from '../../types/typeDefs';
import { evLogger } from './eventLogger';
import { EventData, EventHandler, EventType, RequestHandler, RequestType } from './eventTypes';


type HandlersMap = Map<EventData, Map<EventType, EventHandler[]>>;
type RequestMap = Map<EventData, Map<RequestType, RequestHandler>>;

/**
 * @description System for handling events
 */
export class EventSystem {

  private eventHandlers : HandlersMap;

  private requestMap : RequestMap;

  constructor() {
    this.eventHandlers = new Map();
    this.requestMap = new Map();
  }

  /**
   * @description Emits an event for all registered handlers
   * @param {EventType} event - type of event
   * @param {string} dataType - string of datatype
   * @param {DataType} data - data that goes along with the event
   */
  public async emit<DataType>(event : EventType, dataType : EventData,  data : Nullable<DataType>) : Promise<void> {
    if (data) {
      evLogger.info(`EMIT: ${Object.values(EventType)[event]} ; TYPE: ${dataType} ; DATA: ${JSON.stringify(data)}`);
      const typeHandlers = this.eventHandlers.get(dataType) || null;
      if (typeHandlers) {
        const handlers = typeHandlers.get(event) || null;
        if (handlers) {
          await Promise.all(handlers.map((handler)=>{
            return handler(data);
          }));
        }
      } else {
        evLogger.warn(`NO HANDLER FOR EVENT: ${Object.values(EventType)[event]} ; TYPE: ${dataType}`);
      }
    } else {
      evLogger.warn(`EMITTED WITH NO DATA: ${Object.values(EventType)[event]} ; TYPE: ${dataType}`);
    }
  }

  /**
   * @description Emits a request event, if a handler is attached the requested object is returned
   * @param {any} select - information used to find specific object
   * @param {EventData} dataType - type of object requested
   * @param {RequestType} type - type of request
   */
  public async request<DataType>(type : RequestType, dataType : EventData, select : unknown) : Promise<Nullable<DataType>> {
    evLogger.info(`REQUEST : ${Object.values(RequestType)[type]} ; DATATYPE: ${dataType} ; SELECT: ${JSON.stringify(select) || 'NULL'}`);
    const map = this.requestMap.get(dataType) || null;
    if (map) {
      const handler = map.get(type);
      if (handler) {
        return await handler(select) as Nullable<DataType>;
      }
    }
    evLogger.error(`FAIL: REQUEST: ${type} ; DATATYPE: ${dataType} ; SELECT: ${JSON.stringify(select) || 'NULL'}`);
    return null;
  }

  /**
   * @throws
   * @description Sets the request handler for a data request, throws error if there is already a request handler for the type
   * @param {RequestType} requestType - type of request the handler is for
   * @param {EventData} dataType - data type of request
   * @param {RequestHandler} handler - handler for request
   */
  public setRequestHandler(requestType : RequestType, dataType : EventData,  handler : RequestHandler) : void {

    if (!this.requestMap.has(dataType)) {
      this.requestMap.set(dataType, new Map());
    }
    const map = this.requestMap.get(dataType);
    if (map) {
      if (map.has(requestType)) {
        const type = Object.values(RequestType)[requestType];
        evLogger.info(`FAIL: REGISTER: ${dataType} : ${type}`);
        throw new Error(`Attempt to Set Multiple Request Handlers for: ${dataType} : ${type}`);
      }
      map.set(requestType, handler);
    }
  }
  
  /**
   * @description Subscribes a handler to an event
   * @param  {EventType} event - type of event to subscribe to
   * @param  {string} dataType - string of data type
   * @param  {EventHandler} handler - handler function to subscribe
   */
  public subscribe(event : EventType, dataType : EventData, handler : EventHandler) : void {
    evLogger.info(`SUBSCRIBE: ${Object.values(EventType)[event]} ; TYPE: ${dataType}`);
    if (!this.eventHandlers.has(dataType)) {
      this.eventHandlers.set(dataType, new Map());
    }

    const typeHandlers = this.eventHandlers.get(dataType) || null;
    if (typeHandlers) {
      if (!typeHandlers.has(event)) {
        typeHandlers.set(event, []);
      }
      const eventHandlers = typeHandlers.get(event);
      if (eventHandlers) {
        eventHandlers.push(handler);
      }
    }
  }
}