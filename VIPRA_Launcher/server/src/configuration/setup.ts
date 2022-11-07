import express from 'express';
import path from 'path';
import https from 'https';

import { FLAGS } from '../types/flags/flags.types';
import { Config } from './config';
import { readFile } from '../util/fileOperations';
import { Logger } from '../controllers/logging/logger';
import { Nullable } from '../types/typeDefs';

/**
 * @description Creates a map containing the commandline flags and their respective values
 *
 * @note values are set to '' if the flag was input with an = -RG
 */
const getCommandLineArguments = () : Map<string, string> => {

  const args = process.argv.slice(2);
  const params = new Map<string, string>();

  args.forEach((arg) => {
    const values = arg.split('=');
    params.set(values[0], values[1]);
  });

  if (params.has(FLAGS.FLAGS_FILE)) {
    const filePath = params.get(FLAGS.FLAGS_FILE);
    if (filePath) {
      const flagsfile : Nullable<string> = readFile(filePath);
      if (flagsfile) {
        const flags : string[] = flagsfile.split('\n');
        flags.forEach((line)=>{
          const flag = line.split('=');
          params.set(flag[0], `${flag[1] ? flag[1] : ''}`);
        });
      }
    }
  }
  return params;
};

/**
 * @note currently hardcoded
 * @description Sets config variables
 */
const initialSetup = () : Config => {
  const flags = getCommandLineArguments();
  return {
    flags,
    app: {
      certDir: path.resolve(`${__dirname}/../../certs`),
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
      debugMode: flags.has(FLAGS.DEBUG_BUILD),
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