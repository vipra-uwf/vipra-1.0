
# CURRENTLY IN PROGRESS

# Current Routes
## /sim
### GET
- **Function:**
		Returns JSON Contents of to the Client:
		`VIPRA/input_data/sim_options.json`
- **Expected Request Contents:**
	- `none`
- **Response:**
	- **Success:** status: `200`
		- Options returned successfully, `data` contains the options
	- **Error:** status: `500`
		- Unknown Error, Options not returned
- **Middleware:**
	- `Authenticate`
- **Call Path:**
	- `SimManager.SendSimOptions`
---
## /sim
### POST
- **Function:**
	Calls SimManager to handle the request
	`Functionality Depends on SimManager Implementation`
	`See SimManager in Controllers`
- **Expected Request Contents:**
	- `headers`: 
		- `Authorization`: 
			- *authentication token*
	- `body`: JSON
		- `"sim_config"`: 
			- *configuration options* 
		- `"sim_params"`: 
			- *simulation parameters*
-	**Response:**
	-	`See SimManager in Controllers`
- **Middleware**
	- `Authenticate`
	- `checkConfig`
- **Call Path:**
	- `SimManager.HandleSimRequest`
---
## /sim/updates/:simID
### GET
- **Function:**
	Provides Updates on simulation progress to the client
	`Exact Functionality Depends on UpdateManager Implementation`
	`See UpdateManager in Controllers`
- **Expected Request Content:**
	- `headers`: 
		- `Authorization: AUTHENTICATION TOKEN`
	- `parameters`
		- `simID`: id for simulation process
-	**Response:**
	-	`See UpdateManager in Controllers`
- **Middleware:**
	- `checkConfigID`
- **Call Path**
	-	`UpdateManager.ProvideUpdates`
---
## /sim/behaviors
### GET
-	**Function:**
	Returns available behavior options to the client
- **Expected Request Content:**
	- `none`
- **Response:**
	- **Success:** status: `200`
		- Behaviors returned successfully, `data` contains all published Behaviors
	- **Error:** status: `500`
		- Unknown Error, Behaviors not returned
- **Middleware:**
	- `Authenticate`
-	**Call Path:**
	-	`BehaviorManager.GetBehaviorOptions`
	-	`BehaviorRepo.GetOptions`
---
## /sim/behaviors
### POST
-	**Function:**
	-	Upload Behavior to Repo
- **Expected Request Content:**
	- `headers`: 
		- `Authorization`: 
			- *authentication token*
	- `body`: JSON
		- `"behavior"`
			- `"name"` : (string) behavior name
			- `"content"` : (string) behavior file content
			- `"publish"` : (boolean) whether to publish behavior to other users
- **Response:**
	- **Success**: status: `200`
		- Behavior was created on Repo
	- **Bad Request**: status:`400`
		- Behavior request was malformed, Behavior was not created
	- **Unauthorized**: status: `401`
		- User is not authenticated, Behavior was not created
	- **Error**:status `500`
		- Unknown Error, Behavior was not created
- **Middleware:**
	- `Authenticate`
- **Call Path:**
	- `BehaviorManager.CreateBehavior`
	- `BehaviorRepo.Create`
---
## /sim/behaviors
### PUT
-	**Function:**
	-	Updates Behaviors
- **Expected Request Content:**
	- `headers`:
		- `Authorization`:
			- *authentication token*
	- `body`: JSON
		- `"behavior"`:
			- `"name"`: (string) behavior name
			- `"content"`: (string) behavior file contents
			- `"publish"`: (boolean) whether to publish behavior to other users
- **Response:**
	- **Success:** status: `200`
		- Behavior was updated
	- **Bad Request:** status: `400`
		- Behavior request was malformed, Behavior was not updated
	- **Not Found:** status: `404`
		- No Behavior with provided name, Behavior was not updated
	- **Unauthorized:** status: `401`
		- User is not authenticated OR User does not have access to edit the behavior, Behavior was not updated
	- **Error:** status: `500`
		- Unknown Error, Behavior was not updated
- **Middleware**
	- `Authenticate`
- **Call Path:**
	- `BehaviorManager.UpdateBehavior`
	- `BehaviorRepo.Update`
---
## /sim/behaviors/:name
### DELETE
-	**Function:**
	-	Removes Behaviors from Repo
- **Expected Request Content:**
	- `headers`:
		- `Authorization`:
			- *authentication token*
	- `parameters`:
		- `name`: behavior name
- **Response:**
	- **Success:** status: `200`
		- Behavior was deleted
	- **Bad Request** status: `400`
		- Request was malformed, Behavior was not deleted
	- **Not Found** status: `404`
		- No Behavior with provided name, Behavior was not deleted
	- **Unauthorized** status: `401`
		- User is not authenticated OR User does not have access to delete the behavior, Behavior was not deleted
	- **Error** status: `500`
		- Unknown Error, Behavior was not deleted
- **Middleware**
	- `Authenticate`
- **Call Path:**
	- `BehaviorManager.DeleteBehavior`
	- `BehaviorRepo.Delete`
---
## /login
### POST
-	**Function:**
	-	Returns Authentication token
- **Expected Request Content:**
	- `body`:
		- `user`:
			- `email`: (string) user email
			- `password`: (string) user password
- **Response:**
	- **Success:** 
		- status: `200`
		- body: `token` : *authentication token*
		- Successfully Authenticated
	- **Bad Request**
		- status: `400`
		- User not Authenticated
- **Middleware**
	- `Authenticate`
- **Call Path:**
	- `UserManager.Login`
	- `UserRepo.FindByEmail`
	- `Authenticator.GetToken`
---
## /register
### POST
-	**Function:**
	-	Creates User in User Repo
- **Expected Request Content:**
	- `body`
		- `"user"`:
			- `"email"`: (string) user email
			- `"password"`: (string) user password
- **Response:**
	- **Success** status: `200`
		- User was created
	- **Bad Request** status: `400`
		- Request was malformed, User was not created
	- **Error** status: `500`
		- Unknown Error, User was not created
- **Middleware**
	- `Authenticate`
- **Call Path:**
	- `UserManager.RegisterUser`
	- `PasswordManager.HashPassword`
	- `UserRepo.Register`
---
## /users/:userEmail
### DELETE
-	**Function:**
	-	Removes user from User Repo
- **Expected Request Content:**
	- `headers`:
		- `Authorization`: *authentication token*
	-`parameters`:
		`userEmail`: user email
- **Response:**
	- **Success:**  status: `200`
		- User was removed
	- **Bad Request:** status: `400`
		- No user with provided name, User was not removed
	- **Unauthorized:** status: `401`
		- User was not authenticated OR User does not have access to remove the User, User was not removed
- **Middleware**
	- `Authenticate`
- **Call Path:**
	- `UserManager.RemoveUser`
	- `UserRepo.DeleteUser`
# Controllers

# Middleware
## authenticate
-	**Function**
	-	Decodes User's `Authorization` header token
- **Affect**
	- adds `Auth` to the request
		- `req.Auth`: JSON Object
			- Contains:
				- `email`

# Interfaces
## Contents
 1. **Authentication**
	- 1.1 Authenticator
		- 1.1.1 _JWT
	- 1.2 PasswordManager
		- 1.2.1 _bcrypt
2. **Managers**
	- 2.1 BehaviorManager
		- 2.1.1 BehaviorManager
	- 2.2 ConfigManager
		- 2.2.1 ConfigManager
	- 2.3 SimManager
		- 2.3.1 _ProvideCode
		- 2.3.2 _RunSim
	- 2.4 UpdateManager
		- 2.4.1 _NoUpdates
		- 2.4.2 _SSE
	- 2.5 UserManager
		- 2.5.1 UserManager
3. **Repos**
	- 3.1 BehaviorRepo
		- 3.1.1 _Local
		- 3.1.2 _Mongo
	- 3.2 ConfigRepo
		- 3.2.1 _Local
		- 3.2.2 _NoSave
	- 3.3 UserRepo
		- 3.3.1 _Mongo
4. **Database**
	- 4.1 BehaviorDB
		- 4.1.1 _Mongo
	- 4.2 UserDB
		 - 4.2.1 _Mongo

## 1. Authentication

## 1.1 Authenticator
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
## 1.2 PasswordManager
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
## 2. Managers
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
- **UnStage** (async)
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

**IMPLEMENTATIONS**

- 2.1.1 **BehaviorManager**

---
## 2.2 **ConfigManger**
### Responsibility
- Handles Staging/Cleanup of sim_config.json

### Methods
-	**CreateConfig** (async)
	-	Parameters:
		-	`configJSON`: JSON Object
		-	`paramsJSON`: JSON Object
	-	Return Value:
		-	`configID`: Promise\<string>
- **StageConfig** (async)
	- Parameters:
		- `configID`: string
	- Return Value:
		- `isStaged`: Promise\<boolean>
- **UnStage** (async)
	- Parameters:
		- `configID`: string
	- Return Value:
		- `isUnstaged`: Promise\<string>

**IMPLEMENTATIONS**

- 2.2.1 **_Local**
	- Saves configurations to the local machine
- 2.2.2 **_NoSave**
	- Unloads configurations after use

## 2.3 **SimManager**
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
## 2.4 **UpdateManager**
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
- 2.4.2 **_SSE**
	- `ProvideUpdates`
		- Responds to client with Server Sent Events from simulation

---
## 2.5 **UserManager**
### Responsibility
- Handles
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

**IMPLEMENTATIONS**
2.5.1 **UserManager**

---
## 3. Repos
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

- 3.1.1 **_Local**
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
- **UnStage**
	- Parameters:
		- `configID`: string
	- Return Value:
		- `isUnstaged`: Promise\<boolean>

**IMPLEMENTATIONS**

- 3.2.1 **_Local**
	- Stores Configs on Local Machine
- 3.2.2 **_NoSave**
	- Does not store configs

---
## 3.3 UserRepo

- **CONSTRUCTOR**
	- Parameters:
		- `DBcon`: DatabaseConnection
- **Register** (async)
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


## 4. Database

## 4.1 BehaviorDB

- **ConnectDB**
	- Affect:
		- assigns `config.database.BehaviorDB` to database connection
	- Parameters:
		- `uri`: string
	- Return Value:
		- `none`

**IMPLEMENTATIONS**

- 4.1.1 **_Mongo**
	- `ConnectDB`
		- *important note:* `config.database.BehaviorDB` is of type mongoose.Model
		- Create Connection to MongoDB database

---
## 4.2 UserDB

- **ConnectDB**
	- Affect:
		- assigns `config.database.UserDB` to database connection
	- Parameters:
		- `uri`: string
	- Return Value:
		- `none`

**IMPLEMENTATIONS**

- 4.2.1 **_Mongo**
	- `ConnectDB`
		- *important note:* `config.database.UserDB` is of type mongoose.Model
		- Create Connection to MongoDB database