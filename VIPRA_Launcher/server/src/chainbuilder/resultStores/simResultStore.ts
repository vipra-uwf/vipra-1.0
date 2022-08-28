/**
 * @module TypeChain
 */

import crypto from 'crypto';
import { FilesController } from '../../controllers/files/FilesController';
import { container } from 'tsyringe';

import { CbResult, ResultStore } from 'typechain';
import { Nullable } from '../../types/typeDefs';

const fc = container.resolve(FilesController);

/**
 *
 */
export class SimResultStore extends ResultStore {

  private resultMap : Map<string, string> = new Map();


  // NOTE: typechain requires this be async,
  // eslint-disable-next-line @typescript-eslint/require-await
  /**
   *
   * @param hash
   */
  async getResult(hash: string): Promise<CbResult> {
    const resultPath : Nullable<string> | undefined = this.resultMap.get(hash);

    if (resultPath) {
      if (!fc.fileExists(resultPath)) {
        return { error: true, result: 'Invalid Result Location' };
      }
      return { error: false, result: fc.readFile(resultPath) || '' };
    } else {
      return { error: true, result: 'Invalid Result Location' };
    }
  }

  // NOTE: typechain requires this be async,
  // eslint-disable-next-line @typescript-eslint/require-await
  /**
   *
   * @param result
   */
  async storeResult(result: string): Promise<CbResult> {
    const id = crypto.randomUUID();
    this.resultMap.set(id, result);
    return { error: false, result: id };
  }
}

/* eslint-enable */