# Middleware
## Format
**Middleware**
- Function
- Affect on Request/Reponse
---
### authenticate
-	**Function**
	-	Decodes User's `Authorization` header token
- **Affect**
	- adds `Auth` to the request
		- `req.Auth`: JSON Object
			- Contains:
				- `email`


# Classes

- *(interface)* denotes that a class is an interface with one or more implementations
- *(needs update)* denotes that a class/implementation does not currently work

## Contents
 1. **Authentication**
	- 1.1 Authenticator *(interface)*
		- 1.1.1 _JWT
	- 1.2 PasswordManager *(interface)*
		- 1.2.1 _bcrypt
2. **Managers**
	- 2.1 BehaviorManager
	- 2.2 ConfigManager
	- 2.3 SimManager *(interface)*
		- 2.3.1 _ProvideImage
		- 2.3.2 _RunSim *(needs update)*
	- 2.4 UpdateManager *(interface)*
		- 2.4.1 _NoUpdates
		- 2.4.2 _SSE *(needs update)*
	- 2.5 UserManager
3. **Repos**
	- 3.1 BehaviorRepo *(interface)*
		- 3.1.1 _Local *(needs update)*
		- 3.1.2 _Mongo
	- 3.2 ConfigRepo *(interface)*
		- 3.2.1 _Local *(needs update)*
		- 3.2.2 _NoSave
	- 3.3 UserRepo *(interface)*
		- 3.3.1 _Mongo 
4. **CompilationBuilders**
	- 4.1 Builders *(interface)*
		- 4.1.1 AutoconfBuilder
		- 4.1.2 DockerBuilder
5. **Database**
	- 5.1 BehaviorDB *(interface)*
		- 5.1.1 _Mongo
	- 5.2 UserDB *(interface)*
		 - 5.2.1 _Mongo
---
# 1. Authentication

## 1.1 Authenticator (interface)
### Responsiblity
- Handles Creation/Decoding of authentication tokens
### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `PasswordManager`: PasswordManager
		- `options`: JSON Object
- **Get Token** (async)
	- Parameters:
		- `user`: JSON Object
		- `dbUser`: JSON Object
	- Return Value:
		- `token`: string
			- `null on failure to authenticate`

**IMPLEMENTATIONS:**

- 1.1.1 **_JWT**
	- Create JSON Web Tokens as method of authentication
---
## 1.2 PasswordManager (interface)
### Responsibility
- Handles Hashing/Decoding of passwords
### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `none`
- **HashPassword** (async)
	- Parameters:
		- `password`: string
	- Return Value:
		- `hashedPass`: Promse\<string>
- **CheckPassword** (async)
	- Parameters:
		- `password`: string
		- `dbPassword`: string
	- Return Value:
		- `isSame`: Promise\<boolean>

**IMPLEMENTATIONS:**
- 1.2.1 **_bcrypt:**
---
# 2. Managers
## 2.1 **BehaviorManager**

### Responsibility
-	Handles Staging/Cleanup of Behaviors for simulation

### Methods
- **CONSTRUCTOR**
	- Parameters: 
		- `BehaviorRepo`
- **CreateBehavior** (async)
	- Parameters: 
		- `behaviorJSON`: JSON Object
		- `userAuth`: JSON Object
	- Return Value: 
		- `status`: Promise\<STATUS>
- **UpdateBehavior** (async)
	- Parameters:
		- `behaviorJSON`: JSON Object
		- `userAuth`: JSON Object
	- Return Value:
		- `status`: Promise\<STATUS>
- **StageBehavior** (async)
	- Parameters:
		- `behaviorName`: string
	- Return Value:
		- `isStaged`: Promise\<boolean>
- **UnStageBehavior** (async)
	- Parameters:
		- `behaviorName`: string
	- Return Value:
		- `isUnstaged`: Promise\<boolean>
- **DeleteBehavior** (async)
	- Parameters:
		- `behaviorName`: string
		- `userAuth`: JSON Object
	- Return Value:
		- `status`: Promise\<STATUS>
- **GetBehaviorOptions** (async)
	- Parameters:
		- `userAuth`: JSON Object
	- Return Value:
		- `options`: Promise\<JSON Object>
			- `null on failure to load`
---
## 2.2 **ConfigManger**
### Responsibility
- Handles Staging/Cleanup of sim_config.json

### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `ConfigRepo`: (ConfigRepo) Repo implementation

-	**CreateConfig** (async)
	-	Parameters:
		-	`configJSON`: JSON Object
		-	`paramsJSON`: JSON Object
	-	Return Value:
		-	`configID`: Promise\<string>

- **DeleteConfig** (async)
	- Parameters:
		- `configID`: string
	- Return Value:
		- `status`: Promise\<STATUS>

- **StageConfig** (async)
	- Parameters:
		- `configID`: string
		- `stagePath`: (string) Path to place sim_config.json & sim_params.json
	- Return Value:
		- `isStaged`: Promise\<boolean>

- **UnStage** (async)
	- Parameters:
		- `configID`: string
	- Return Value:
		- `isUnstaged`: Promise\<string>

## 2.3 **SimManager** (interface)
### Responsibility
- Handles Requests for simulation resources
### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `ConfigManager`
		- `BehaviorManager`
-	**HandleSimRequest** (async)
	-	Parameters:
		-	`reqBody`: JSON Object
		-	`userAuth`: JSON Object
		-	`response`: Response
	- Return Value:
		- `none`
-	**SendSimOptions**
	-	Parameters:
		-	`response`: Response

**IMPLEMENTATIONS**
- 2.3.1 **_ProvideCode**
	- `HandleSimRequest`
		- Responds to client with generated simulation (will respond with build tools in future)
- 2.3.2 **_RunSim**
	- `HandleSimRequest`
		- Starts Simulation with provided config - *updates are handled by UpdateManager*

---
## 2.4 **UpdateManager** (interface)
### Responsibility
- Handles providing clients with updates on simulation progress
### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `SimManager`: SimManager
- **ProvideUpdates** (async)
	- Parameters:
		- `simID`: string
	- Return Value:
		- `none`

**IMPLEMENTATIONS**
- 2.4.1 **_NoUpdates** 
	- `ProvideUpdates`
		- Responds to client with `404` as no updates are provided for simulations
- 2.4.2 **_SSE** (needs update)
	- `ProvideUpdates`
		- Responds to client with Server Sent Events from simulation

---
## 2.5 **UserManager**
### Responsibility
- Handles Creation/Editing of Users
### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `UserRepo`: User Repo
		- `Authenticator`: Authenticator
		- `PasswordManager`: PasswordManager
- **Login** (async)
	- Parameters:
		- `request`: Request
	- Return Value:
		- `token`: Promise\<JWT>
			- `null on failure to authenticate`
- **Register** (async)
	- Parameters:
		- `request`: Request
	- Return Value:
		- `status`: Promise\<STATUS>
- **EditUser** (async)
	- Parameters:
		- `request`: Request
		- `userAuth`: JSON Object
	- Return Value:
		- `status`: Promise\<STATUS>
- **RemoveUser** (async)
	- Parameters:
		- `request`: Request
		- `userAuth`: JSON Object
	- Return Value:
		- `status`: Promise\<STATUS>
---
# 3. Repos
## 3.1 BehaviorRepo
- **CONSTRUCTOR**
	- Parameters:
		- `DBcon`: DatabaseConnection
- **Create** (async)
	- Parameters:
		- `behaviorName`: string
		- `behaviorContent`: string
		- `behaviorCreator`: string
		- `publish`: boolean
	- Return Value:
		- `created`: Promise\<boolean>
- **Update** (async)
	- Parameters:
		- `behaviorName`: string
		- `behaviorContent`: string
		- `behaviorCreator`: string
		- `publish`: boolean
	- Return Value:
		- `updated`: Promise\<boolean>
- **Delete** (async)
	- Parameters:
		- `behaviorName`: string
	- Return Value:
		- `deleted`: Promise\<boolean>
- **GetOptions**
	- Parameters:
		- `user`: JSON Object
	- Return Value:
		- `options`: Promise\<JSON Object>
- **GetBehavior** (async)
	- Parameters:
		- `behaviorName`: string
	- Return Value:
		- `behavior`: Promise\<JSON Object>

**IMPLEMENTATIONS**

- 3.1.1 **_Local** (needs update)
	-	Stores Behaviors on local machine
- 3.1.2 **_Mongo**
	- Stores Behaviors on MongoDB database

---
## 3.2 ConfigRepo

- **CONSTUCTOR**
	- Parameters:
		- `DBcon`: DatabaseConnection
- **CreateSimConfig**
	- Parameters:
		- `configID`: string
		- `configJSON`: JSON Object
		- `paramsJSON`: JSON Object
	- Return Value:
		- `created`: Promise\<boolean>
- **DeleteSimConfig** (async)
	- Parameters:
		- `configID`: string
	- Return Value:
		- `status`: Promise\<STATUS>
- **StageConfig** (async)
	- Parameters:
		-	`configID`: string
	- Return Value:
		- `isStaged`: Promise\<boolean>
- **UnStageConfig**
	- Parameters:
		- `configID`: string
	- Return Value:
		- `isUnstaged`: Promise\<boolean>

**IMPLEMENTATIONS**

- 3.2.1 **_Local** (needs update)
	- Stores Configs on Local Machine
- 3.2.2 **_NoSave**
	- Does not store configs

---
## 3.3 UserRepo

- **CONSTRUCTOR**
	- Parameters:
		- `DBcon`: DatabaseConnection
- **RegisterUser** (async)
	- Parameters:
		- `email`: string
		- `hashedPass`: string
	- Return Value
		- `created`: Promise\<boolean>
- **DeleteUser** (async)
	- Parameters:
		- `email`: string
	- Return Value:
		- `deleted`: Promise\<boolean>
- **FindByEmail**
	- Parameters:
		- `email`: string
	- Return Value:
		- `user`: JSON Object
			- `null on failure to find`

**IMPLEMENTATIONS**

- 3.3.1 **_Mongo**
	- Stores Users on a MongoDB database

# 4. CompileBuilders
### Methods
- **CONSTRUCTOR**
	- Parameters:
		- `none`
- **BuildImage** (async)
	- Parameters:
		- `build_config`: JSON Object
		- `configID`: string
	- Return Value:
		- `buildPath`: (string) Path to the compressed folder to return to client
- **MakeBuildDir**
	- Parameters:
		- `configID`: (string) ID for simulation configuration

**Implementations**

 - 4.1 **AutoConf**
	- Returns Compressed folder with necessary Autoconf and Source code files for local compilation
- 4.2 **Docker**
	- Returns a compressed folder with a dockerfile and source code for local compilation


# 5. Database

## 5.1 BehaviorDB

- **ConnectDB**
	- Affect:
		- assigns `config.database.BehaviorDB` to database connection
	- Parameters:
		- `uri`: string
	- Return Value:
		- `none`

**IMPLEMENTATIONS**

- 5.1.1 **_Mongo**
	- `ConnectDB`
		- *important note:* `config.database.BehaviorDB` is of type mongoose.Model
		- Create Connection to MongoDB database

---
## 5.2 UserDB

- **ConnectDB**
	- Affect:
		- assigns `config.database.UserDB` to database connection
	- Parameters:
		- `uri`: string
	- Return Value:
		- `none`

**IMPLEMENTATIONS**

- 5.2.1 **_Mongo**
	- `ConnectDB`
		- *important note:* `config.database.UserDB` is of type mongoose.Model
		- Create Connection to MongoDB database