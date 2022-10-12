import { OperationResult } from '../types/typeDefs';

import express from 'express';
import { BaseService } from '../services/base.service';
import { Identifiable, UploadType } from '../types/uploading.types';
import { Status } from '../types/status';
import { EventSystem } from './events/eventSystem';
import { EventType } from './events/eventTypes';

type Request = express.Request;

/**
 * @description Base class for controllers
 */
export abstract class BaseController<DataType extends Identifiable> {


  protected abstract setupEventHandlers() : void;
  protected abstract setupRequestHandlers() : void;
  protected abstract createUpload(req : Request) : Promise<OperationResult<Partial<UploadType<DataType>>>>;

  protected evSys : EventSystem;

  protected service : BaseService<DataType>;

  private type : string;

  constructor(type : string, evSys : EventSystem, service : BaseService<DataType>) {
    this.service = service;
    this.evSys = evSys;
    this.type = type;
    this.setupEventHandlers();
    this.setupRequestHandlers();
  }

  /**
   * @description Returns all installed maps
   */
  getAll(): Promise<OperationResult<DataType[]>> {
    return Promise.resolve({ status: Status.SUCCESS, object: this.service.getAll() });
  }

  /**
   * @description Controller for Maps
   * @param {Request} req - client Request object
   */
  async get(req: Request): Promise<OperationResult<DataType>> {
    const id = req.params.id;
    if (id) {
      const map = await this.service.get({ id } as Partial<DataType>);
      if (map && map.length > 0) {
        return { status: Status.SUCCESS, object: map[0] };
      } else {
        return { status: Status.NOT_FOUND, object: null };
      }
    }

    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @param {Request} req - client Request object
   * @description Controller for Maps
   */
  async create(req: Request): Promise<OperationResult<DataType>> {
    const request = await this.createUpload(req);
    if (request.status === Status.SUCCESS) {
      if (request.object) {
        const created = await this.service.create(request.object);
        if (created.status === Status.CREATED) {
          void this.evSys.emit<DataType>(EventType.NEW, this.type, created.object);
        }
        return created;
      } else {
        return { status: Status.INTERNAL_ERROR, object: null };
      }
    }

    return { status: Status.BAD_REQUEST, object: null };
  }

  /**
   * @param {Request} req - client Request object
   * @description Controller for Maps
   */
  async update(req: Request): Promise<OperationResult<DataType>> {
    const id = req.params.id;
    if (id) {
      const upload = await this.createUpload(req);
      if (upload.status === Status.SUCCESS) {
        if (upload.object) {
          const updated = await this.service.update(id, upload.object);
          if (updated.status === Status.SUCCESS) {
            void this.evSys.emit<DataType>(EventType.UPDATE, this.type, updated.object);
          }
          return updated;
        } else {
          return { status: Status.INTERNAL_ERROR, object: null };
        }
      }
    }
    return Promise.resolve({ status: Status.BAD_REQUEST, object: null });
  }
  
  /**
   * @param {Request} req - client Request object
   * @description Controller for Maps
   */
  async delete(req: Request): Promise<OperationResult<DataType[]>> {
    const id = req.params.id;
    if (id) {
      const deleted = await this.service.delete({ id } as Partial<DataType>);
      if (deleted.status === Status.SUCCESS) {
        void this.evSys.emit<DataType[]>(EventType.DELETE, this.type, deleted.object);
      }
      return deleted;
    }
    return { status: Status.BAD_REQUEST, object: null };
  }
}