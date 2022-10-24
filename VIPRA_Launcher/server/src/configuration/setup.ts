import express from 'express';
import path from 'path';
import https from 'https';

import { Config } from './config';
import { readFile } from 'src/util/fileOperations';
import { Logger } from 'src/controllers/logging/logger';


/**
 * @note currently hardcoded
 * @description Sets config variables
 */
const initialSetup = () : Config => {
  return {
    app: {
      certDir: path.resolve(`${__dirname}`),
      port: 3000,
    },
    modules: {
      modulesFilePath: path.resolve(`${__dirname}/modules.json`),
      modulesDir: path.resolve(`${__dirname}/../../../../Modules`),
    },
    simconfig: {
      simconfigDir: path.resolve(`${__dirname}/../../../../SimConfigs`),
    },
    vipra: {
      vipraDir: path.resolve(`${__dirname}/../../../../VIPRA`),
      behaviorDir: path.resolve(`${__dirname}/../../../../VIPRA/Base/dsl`),
      simsDir: path.resolve(`${__dirname}/../../../../VIPRA/sims`),
    },
    simulation: {
      debugMode: false,
      maxConcurComps: 10,
    },
    map : {
      mapsDir: path.resolve(`${__dirname}/../../../../Maps`),
    },
  };
};


/**
 * @description Creates and returns a HTTPS server
 * @param {express.Application} app - main app
 * @param {Config} config - configuration object
 */
const setupHTTPS = (app : express.Application, config : Config) : https.Server => {
  const cert = readFile(`${config.app.certDir}/cert.crt`);
  const key = readFile(`${config.app.certDir}/key.pem`);
  if (cert && key) {
    return https.createServer({
      key,
      cert,
      passphrase: undefined,
    }, app);
  }
  Logger.error('Unable to start HTTPS Server');
  throw new Error('Unable to start HTTPS Server');
};


export {
  initialSetup,
  setupHTTPS,
};