
# VIPRA Launcher

The VIPRA Launcher is the web backend for interaction with the VIPRA simulation. It is written in Typescript and uses [Express](https://expressjs.com/) for routing.

Currently the Launcher handles:
- Keeping track of installed `Modules`, `Maps`, `Behaviors`, and `SimConfigs`
- Hosting a  [ChainBuilder](https://www.chain-builder.net/) service for running simulations (see Typechain Documentation)
- Keeping the VIPRA simulation updated/compiled with all installed `Modules`

# Sections

1. Launcher Structure
2. Running The Launcher
3. Event System
4. Build System
5. Utility Methods
---
# 1. Running the Launcher
**1.1 Compiling / Running**
**1.2 Flags**

## 1.1 Compiling / Running
In `/VIPRA_Launcher/server`:
`npm install` : gets npm package dependencies
`npm run build` : transpiles source code
`node ./dist/index.js *flags*` : starts the launcher

## 1.2 Flags
Flags are set from the command line when starting the launcher
ex.
- `node ./dist/index.js -debugparams=/path/to/params -nobuild`

Flags are either set with `*flag*=*value*` or simply `flag`
ex.
- `debugconfig=exampleconfig`
- `nobuild`

**Current Flags**
1.  `flagsfile` : `=*path*`
-  Path  to  file  containing  flags
2.  `debugbuild`
-  Builds  the  simulation  with  debug  flags
3.  `debugrun`
-  Runs  the  Simulation  after  each  SUCCESS  SimBuild  event
4.  `debugmap` : `=*path*`
-  Overrides  map  file  input  with  path  provided
5.  `debugpeds` : `=*path*`
-  Overrides  pedestrian  file  with  path  provided
6.  `debugparams` : `=*path*`
-  Overrides  parameter  input  and  uses  the  parameter  file  at  the  provided  path
7.  `debugconfig` : `=*config id*`
-  Overrides  configID  provided  to  simulation
8.  `debugoutput` : `=*path*`
-  Overrides  output  location  for  simulation  run
9.  `vipradir` : `=*path*`
-  Sets  the  Path  to  the  VIPRA  directory
10.  `noserver`
-  Runs  Launcher  without  starting  a  HTTP/HTTPS  server
11.  `noclean`
-  Simulation  Builds  will  NOT  clean  up  build  files
12.  `nobuild`
-  Simulation  is  NOT  built  on  startup
13.  `certs` : `=*path*`
-  Sets  the  Path  to  the  HTTPS  certifications  directory

---

# 2. Launcher Structure

The basic route a request takes is as follows:
CRUD requests:
`Router -> Controller -> Service -> Repo`

Simulation requests:
`Router -> SimController -> ChainBuilderController`

## 2.1 Routers
`/routes`

Routers hold the routes for a given data type or logical group of operations.

Simple CRUD operation routes on data types can be quickly created with:
`createRouter<DataType>('DataType Name', DataTypeController);`

## 2.2 Controllers
`/controllers`

Controllers are the entry point for specific requests. They take requests and convert them to the required types, route them to the proper service and emit events.

### 2.2.TODO BaseController
`/controllers/base.controller.ts`
Simple CRUD controllers can be created by extending `BaseController<DataType>`

### 2.2.TODO Current Controllers
**2.2.TODO.1 Controllers that extend BaseController**
- ModuleController
- MapController
- PedestrianController
- BehaviorController
- SimConfigController

**2.2.TODO.2 Other Controllers**
- SimController
- ChainBuilderController

## 2.3 Service
`/services`

Services are meant to check that request objects are in the proper format and send them to the proper repo

## 2.4 Repo
`/repos`

Repos keep track of installed objects

## 2.5 Runners
`/controllers/runners`

Runners start and control external processes

**Current Runners:**
- `SimRunner` : runs VIPRA simulation
- `CompilationRunner` : runs compilation processes

---

# 3. Event System
`/controllers/events`

The Event system is a really simplified message system for controllers to "talk" to each other

**3.1 Events**
`/controllers/events/eventSystem.ts`

Controllers can `subscribe` to events to take handle events and `emit` events to tell other controllers of a new event.

**3.2 Requests**
`/controllers/events/eventSystem.ts`

Controllers can request data from the event system through `request(RequestType, EventData, selectObj)`

**3.2 Event Types**
`/controllers/events/eventTypes.ts`

The current Event Types are:
1. NEW
2. UPDATE
3. DELETE
4. FAIL
5. SUCCESS

Each Event Type has an `EventData` data type for `SimConfigs`, `Maps`, `Modules`, etc.

---

# 4. Build System
`/controllers/simulation/simulation.builder.ts`

**Issues:** Needs updating to work with CMake, only handles modules with one source and one header

The Launcher keeps the VIPRA simulation up-to-date compiled as new `Modules` are added.

