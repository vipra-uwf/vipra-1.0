/**
 * @module Setup
 */

import path from 'path';
import prompt from 'prompt-sync';
import ip from 'ip';
import https from 'https';
import express from 'express';

import { config }  from './config';
import { FLAGS } from '../types/flags';
import { Logger } from '../logging/Logging';
import { container } from 'tsyringe';
import { FilesController } from '../controllers/files/FilesController';
import { FlagMap, Nullable } from '../types/typeDefs';

const fc = container.resolve(FilesController);

// NOTE: Need to change how setup is done, so this will be removed then -RG
// eslint-disable-next-line eslint-comments/disable-enable-pair
/* eslint-disable no-console */
const prompter = prompt();

/**
 * @description Searches the file system for vipra.info to locate the correct VIPRA_DEV install location
 */
const findVipra = () : string => {
  const osType = process.platform;
  let vipraInfoPath : Nullable<string> = null;

  Logger.info('Finding VIPRA Source Directory');
  if (osType === 'win32') {
    vipraInfoPath = fc.matchFile(/vipra\.info/, path.resolve('C://'), true);
  } else {
    vipraInfoPath = fc.matchFile(/vipra\.info/, path.resolve('/'), true);
  }
  if (!vipraInfoPath) {
    throw new Error('Unable to find VIPRA Source Directory');
  }

  Logger.info(`Found VIPRA Source at: ${path.dirname(vipraInfoPath)}`);
  return path.dirname(vipraInfoPath);
};


/**
 * @description Sets default values on startup
 * @note assumes the launcher is running on the docker container
 */
const debugSetup = () : void => {
  const vipraDir = findVipra();

  config.app.debug = true;
  config.vipra.vipraDir = vipraDir;
  config.vipra.behaviorDir = `${vipraDir}/Base/dsl`;
  config.vipra.simsDir = `${vipraDir}/sims`;
  config.vipra.outputDir = path.resolve('./OUTPUT');
  config.module.modulesFile = `${vipraDir}/sims/modules.json`;
  config.map.mapsFile = `${vipraDir}/sims/maps.json`;
  config.simconfig.configsFile = path.resolve('./simconfigs.json');

  config.cb.url = `${ip.address()}:3001/`;
  config.app.port = 3001;
  config.app.https = {
    key: '/usr/src/VIPRA/certs/local.pem',
    cert: '/usr/src/VIPRA/certs/local.crt',
    passphrase: null,
  };

  config.setup = true;
  fc.writeFile(path.resolve(`${__dirname}/config.json`), JSON.stringify(config));
};

/**
 * @description Prompts user to input the port the launcher will be listening on
 */
const getPort = () : number => {
  let port : number = -1;
  while (port < 1 || port > 65535) {
    port = parseInt(prompter('PORT Number for Server: '), 10);
  }
  return port;
};

/**
 * @description Makes sure that the url provided starts with 'https://'
 * @param {string} url - url to check
 */
const httpsURL = (url : string) : string => {
  if (url.at(url.length - 1) !== '/') {
    url = `${url}/`;
  }
  if (url.match(/^https:\/\//)) {
    return url;
  } else {
    return `https://${url}`;
  }
};

/**
 * @description Checks that the url provided is the proper format for either an IP address or URL
 * @param {string} url - url to check
 */
const checkURL = (url : string) : boolean => {
  if (url.match(/^http:/)) {
    return false;
  }
  if (!url.match(/^(https:\/\/)?(?:www\.)?[-a-zA-Z0-9@:%._\+~#=]{1,256}\.[a-zA-Z0-9()]{1,6}\b(?:[-a-zA-Z0-9()@:%_\+.~#?&\/=]*)$/)
        &&
        !url.match(/(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?(:((6553[0-5])|(655[0-2][0-9])|(65[0-4][0-9]{2})|(6[0-4][0-9]{3})|([1-5][0-9]{4})|([0-5]{0,5})|([0-9]{1,4}))))?/)
  ) {
    return false;
  }
  return true;
};

// TODO provide output for improper input -RG
/**
 * @description Prompts the user to input the url for reaching the server
 */
const getURL = () : string => {
  let url = '';
  while (!checkURL(url)) {
    url = prompter('URL or IPv4 address for this server: ');
  }
  return httpsURL(url);
};

// TODO figure out how to best handle passphrase -RG
/**
 * @description Prompts user to input paths to https certs
 */
const getHTTPS = () : { key : string; cert: string; passphrase : Nullable<string> } => {
  let key = '';
  let ok = false;
  while (!ok) {
    key = prompter('Path to HTTPS Key file: ');
    if (fc.fileExists(key)) {
      ok = true;
    } else {
      console.log(`Provided File does not exist: ${key}`);
    }
  }
  let cert = '';
  ok = false;
  while (!ok) {
    cert = prompter('Path to HTTPS Cert file: ');
    if (fc.fileExists(cert)) {
      ok = true;
    } else {
      console.log(`Provided File does not exist: ${cert}`);
    }
  }

  return {
    key,
    cert,
    passphrase: null,
  };
};



/**
 * @description Runs through the setup of https
 */
const setupHTTPS = () : void => {
  config.cb.url = getURL();
  config.app.https = getHTTPS();
  config.app.port = getPort();
};

// TODO this will find the first instance of a file named vipra.info, if it is in the trash or something then this completely messes up -RG
/**
 * @description Initial setup when first running the launcher, allows the user to input settings
 * @param {FlagMap} argsMap - map of command line arguements
 */
const initialSetup = (argsMap : FlagMap) : void => {

  if (!config.setup) {
    if (argsMap.has(FLAGS.DEBUG_SETUP)) {
      debugSetup();
    } else {

      const vipraDir = findVipra();

      config.vipra.vipraDir = vipraDir;
      config.vipra.behaviorDir = `${vipraDir}/Base/dsl`;
      config.vipra.simsDir = `${vipraDir}/sims`;
      config.vipra.outputDir = path.resolve(`${__dirname}/OUTPUT`);
      config.module.modulesFile = `${vipraDir}/sims/modules.json`;
      config.map.mapsFile = `${vipraDir}/sims/maps.json`;
      config.simconfig.configsFile = `${vipraDir}/sims/simconfigs.json`;

      setupHTTPS();

      config.setup = true;
      fc.writeFile(path.resolve(`${__dirname}/config.json`), JSON.stringify(config));
    }
  }

  // TODO check that nothing has broken since initial setup -RG

};



/**
 * @description Creates a https server
 * @param {Express} app - express app that handles the routing for the https server
 */
const setupHTTPSServer = (app : express.Express) : https.Server => {

  if (config.app.https.key && config.app.https.cert) {

    const key : Nullable<string> = fc.readFile(config.app.https.key);
    const cert : Nullable<string> = fc.readFile(config.app.https.cert);

    if (key && cert) {
      return https.createServer({
        key,
        cert,
        passphrase: undefined,
      }, app);
    }
  }

  throw new Error('Unable To Start HTTPS Server');
};


export {
  initialSetup,
  debugSetup,
  setupHTTPSServer,
};