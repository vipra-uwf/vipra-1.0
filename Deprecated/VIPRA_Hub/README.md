


# Module Routes
Routes used for creating / updating / downloading modules

## 1. /module
### 1.1 Method: GET
Returns the available types of modules

**Example Response:**
```json
{
	"data":{
	"Pedestiran Model": "pedestrianmodel",
	"todo",
	"todo"	
	}
}
```

## 2. /module/:type

### 2.1 Method: GET
Returns all modules of `type` that are currently published, with their descriptions.

**Example response:**
```json
{
	"data":
	[
		{name: "exampleModule", description: "this is an example model", type: "pedstrianmodel"},
		{name: "anotherModule", description: "this is another model", type: "pedestrianmodel"}
	]
}
```
### 2.2 Method POST
Creates a model, of type `type`, with the provided name, description and files.

**Request Format**
- Content-Type: `multipart/form-data`
- Fields:
	- *modulename (string) : the desired name for the module
	- *description (string) : a description of what the module is, and what it does
	- *publish (boolean) : whether the model should be publically visible
	- source (file) : the .cpp file for the model
	- header (file) : the .hpp file for the model

`* denotes a required field`

## 3. /module/:type/:name

### 3.1 Method: GET

Used for downloading Modules

### 3.2 Method: PUT

Used for updating Modules

### 3.3 Method: DELETE

Used for deleting Modules

## 4. /module/:type/:name/info

### 4.1 Method: GET
Returns information for the module

**Example Response**
```json
{
	"module":{
		"name": "exampleModule",
		"description": "this is a module",
		"type": "pedestrianmodel"
	}
}
```
## Module Types
These are the available module types
1. Pedestrian Model
	- **Designation:** "pedestrianmodel"
	- **Use:** Defines the model used to simulate pedestrian dynamics
3. todo
4. todo

# Map Routes

# Behavior Routes