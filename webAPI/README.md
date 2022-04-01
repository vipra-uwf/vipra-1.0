
# VIPRA WebAPI

# Contents
1. **Current Routes**
	- Simulation Paths
	- Behavior Paths
	- User Paths
2. **Simulation Configuration Options**
3. **Behaviors**
4. **Server Setup**

# 1. Current Routes
# Simulation Paths
These Paths handle configuration and creation of simulations
## /sim
### GET
- **Function:**
	Returns the current simulation configuration options and their possible selections
	`see the Configurations Options section for current Configuration options`
- **Expected Request Contents:**
	- `none`
- **Response:**
```json
{
	"message": "SUCCESS",
	"data":
	{
	    "input_data_loader" : [
	        {
	            "DisplayName": "XML Input Reader",
	            "objectName": "inputXMLReader",
	            "type": "xml",
	            "configurations" : []
	        },
	        {
	            "DisplayName": "JSON Input Reader",
	            "objectName": "inputJSONReader",
	            "type": "json",
	            "configurations" : []
	        }
	    ],
	    "output_data_writer" : [
	        {
	            "DisplayName": "XML Output Writer",
	            "type": "xml",
	            "objectName": "xmlWriter",
	            "configurations": [
	                {"parentElementName": [
	                    "pedestrian-set"
	                ]},
	                {"childElementName": [
	                    "pedestrian"
	                ]}           
	            ]
	        },
	        {
	            "DisplayName": "JSON Output Writer",
	            "type": "json",
	            "objectName": "jsonWriter",
	            "configurations": [
	                {"parentElementName": [
	                    "pedestrian-set"
	                ]},
	                {"childElementName": [
	                    "pedestrian"
	                ]}
	            ]
	        },
	        {
	            "DisplayName": "JSON Timestep Output Writer",
	            "type": "json_timestep",
	            "objectName": "jsonTimestepWriter",
	            "configurations": [
	                {"parentElementName" : [
	                    "pedestrian-set"
	                ]},
	                {"childElementName" : [
	                    "pedestrian"
	                ]}
	            ]
	        }
	    ],
	    "simulation_output_handler" : [
	        {
	            "DisplayName": "Timestep Output Handler",
	            "type": "timestep_output_handler",
	            "objectName": "timestepOutputHandler",
	            "configurations" : [
	                {"outputFrequency": {
	                    "minimum": 0,
	                    "maximum": 100
	                }}
	            ]
	        },
	        {
	            "DisplayName": "Timestep Console Logger",
	            "type": "timestep_console_logger",
	            "objectName": "timestepConsoleLogger"
	        }
	    ],
	    "pedestrian_set" : [
	        {
	            "DisplayName": "Calm Pedestrian Set",
	            "objectName": "calmPedestrianSet",
	            "type" : "calm",
	            "name" : "a320_144_pedestrians",
	            "configurations" : [
	                {"parentElementName" : [
	                    "pedestrian-set"
	                ]}
	            ]
	        }
	    ],
	    "obstacle_set" : [
	        {
	            "DisplayName": "A320, 144 Pedestrians",
	            "objectName": "airplaneObstacleSet",
	            "type" : "airplane",
	            "name" : "a320_144_obstacles",
	            "configurations" : [
	                {"parentElementName" : [
	                    "pedestrian-set"
	                ]}
	            ]
	        }
	    ],
	    "entity_set_factory" : [
	        {
	            "DisplayName": "Calm Entity Set Factory",
	            "objectName": "calmEntitySetFactory",
	            "type" : "calm",
	            "configurations" : []
	        }
	    ],
	    "goals" : [
	        {
	            "DisplayName": "Calm Goals",
	            "objectName": "calmGoals",
	            "type" : "calm",
	            "configurations" : []
	        }
	    ],
	    "pedestrian_dynamics_model" : [
	        {
	            "DisplayName": "Calm Pedestrian Model",
	            "objectName": "calmPedestrianModel",
	            "type" : "calm",
	            "configurations" : []
	        }
	    ],
	    "human_behavior_model" : [
	        {
	            "DisplayName": "Human Behavior Model",
	            "objectName": "humanBehaviorModel",
	            "type" : "human",
	            "configurations" : {
	                "random_seed": {},
	                "behavior#": [
	                    "important_announcement",
	                    "injured_person",
	                    "random_sleep",
	                    "travel_in_group"
	                ]
	            }
	        }
	    ]
	}
}
```
- `The Configuration Options are explained in the Configuration Options section`
---
## /sim
### POST
- **Function:**
	Returns the Generated Simulation source files along with a Vagrant file for setup of the build environment
	`requires Authentication (see /login in User Paths)`
- **Expected Request Contents:**
	- `headers`: 
		- `Authorization`: 
			- *authentication token*
	- `body`: JSON
		- `sim_config`: 
			- *configuration options*
				- `for all options see Configuration Options`
		- `sim_params`: 
			- *simulation parameters*
				- `for all parameters see Configuration Options`

- **Example Request Body:**
```json 
{
	"sim_config" : {
		"input_data_loader": {
		"type": "json",
		"configuration": {}
		},
	"output_data_writer": {
		"type": "json_timestep",
		"configuration": {
			"parentElementName": "pedestrian-set",
			"childElementName": "pedestrian"
		}
	},
	"simulation_output_handler": {
		"type": "timestep_output_handler",
		"configuration": {
			"outputFrequency": 100
		}
	},
	"pedestrian_set": {
		"type": "calm",
		"name" : "a320_144_pedestrians",
		"configuration": {
			"parentElementName": "pedestrian-set"
		}
	},
	"obstacle_set": {
		"type": "airplane",
		"name" : "a320_144_obstacles",
		"configuration": {
			"parentElementName": "obstacle-set"
		}
	},
	"entity_set_factory": {
		"type": "calm",
		"configuration": {}
		},
	"goals": {
		"type": "calm",
		"configuration": {}
	},
	"pedestrian_dynamics_model": {
		"type": "calm",
		"configuration": {}
	},
	"human_behavior_model": {
		"type": "human",
		"configuration": {
		"random_seed": "1637762023",
		"behavior#": "injured_person"
	}
},
	"sim_params" : [
		{"luggage": "0.46"},
		{"exit_door_x": "23.25"},
		{"exit_door_y": "1.73"},
		{"aligning_stop_threshold": "0.2"},
		{"toward_aisle_stop_threshold": "0.4"},
		{"in_aisle_stop_threshold": "0.42"},
		{"time_step": "0.000"},
		{"time_step_size": "0.005"}
		]
	}
}
```
-	**Response:**
TODO this has not been defined yet
---
# Behavior Paths
These Paths deal with Creating/Editing/Deleting Behaviors
## /sim/behaviors
### GET
-	**Function:**
	Returns available behavior options to the client
	`only returns publically published Behaviors and Behaviors published by the logged in user`
	`optional Authentication (see /login in User Paths)`
- **Expected Request Content:**
	- `headers`:
		- `Authorization`:
			- *authentication token*
- **Response:**
```json
{
    "data": [
        {
            "name": "injured_person"
        },
        {
            "name": "important_announcement"
        },
        {
            "name": "random_sleep"
        }
    ]
}
```

---
## /sim/behaviors
### POST
-	**Function:**
	-	Uploads a new Behavior to the Repo
	`requires Authentication (see /login in User Paths)`
- **Expected Request Content:**
	- `headers`: 
		- `Authorization`: 
			- *authentication token*
	- `body`: JSON
		- `"behavior"`
			- `"name"` : (string) name for behavior to be identified by
			- `"content"` : (string) the content of the behavior file
			- `"publish"` : (boolean) whether behavior should published to other users
- **Request:**
```json
{
    "behavior": {
        "name": "random_sleep",
		"content": "/**  * RANDOM SLEEP  */// This is a random sleep behavior. It models the scenario of a certain percent// of the population that suffers from narcolepsy. Specifically, someone// subject to this behavior will stop movement to take a nap for the specified// number of seconds.Consider a sleeper.// This indicates that precisely persons 0, 50, and 100 are going to be subject// to this behavior.// 2% of the population are a sleeper.// This randomly selects a ratio of pedestrians for this behavior. In this// case, a random 1 out of every 50 pedestrians is a sleeper.A random 1 out of every 50 pedestrians is a sleeper.// These are two states that the sleeper can be in. They can be named// anything, but it must be consistent throughout the entire file.A sleeper can be SLEEPING.A sleeper can be AWAKE.// Define the initial state of a sleeperA sleeper is initially AWAKE.// This indicates the state transition rules. In this case, we model a person// taking a two minute nap, then waking up 5 minutesA sleeper who is SLEEPING will be AWAKE after 120 seconds.A sleeper who is AWAKE will be SLEEPING after 300 seconds.// This tells the model how the sleeping state affects their behavior. In this// case a sleeping person is stopped, meaning all movement is ceased.A sleeper who is SLEEPING is STOPPED.A sleeper who is AWAKE will behave normally.",
        "publish": false
    }
}
```
- **Response:**
	- `No return values`
---
## /sim/behaviors
### PUT
-	**Function:**
	-	Updates a behavior, Can be used to update a behavior's 'published' status or update the contents of the behavior file
	`behavior names cannot be updated or changed`
	`requires Authentication (see /login in User Paths)`
- **Expected Request Content:**
	- `headers`:
		- `Authorization`:
			- *authentication token*
	- `body`: JSON
		- `"behavior"`:
			- `"name"`: (string) Name of behavior to update
			- `"content"`: (string) behavior file contents
			- `"publish"`: (boolean) whether to publish behavior to other users
- **Request:**
```json
{
    "behavior": {
	    "name": "injured_person",
        "publish": true
    }
}
```
- **Response:**
	- `No return values`
---
## /sim/behaviors/:behaviorName
### DELETE
-	**Function:**
	-	Removes the Behavior with name `behaviorName` from the Repo
`only behaviors authored by the authenticated user can be deleted`
`requires Authentication (see /login in User Paths)`
- **Expected Request Content:**
	- `headers`:
		- `Authorization`:
			- *authentication token*
	- `parameters`:
		- `behaviorName`: name of behavior to be deleted
- **Response:**
	- `No return values`

# User Paths
These paths handle User Registration and Authentication
## /login
### POST
-	**Function:**
	-	Returns an authentication token identifying the recipient as the user
`the token returned from this request will be expected in the 'Authorization' header for requests that require Authentication`
- **Expected Request Content:**
	- `body`:
		- `user`:
			- `email`: email of user to login as
			- `password`:  password for user
- **Example Request:**
```json
{
    "user":{
        "email":"example@exampleemail.com",
        "password":"examplepassword"
    }
}
```
- **Response:**
```json
{
    "message": "Success",
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6InBlcm1UZXN0QHRlc3QuY29tIiwiaWF0IjoxNjQ4NjczMzA5LCJleHAiOjE2NDg3NTk3MDl9.4rW-viMPEpylpcrKyv5eecUd0tG9nUEA2gWTqKvp01Q"
}
```
- `token` : authentication token used for identifying the user in future requests
	-	expected in `Authorization` header for authenticated calls

---
## /register
### POST
-	**Function:**
	-	Creates a new User in User Repo
- **Expected Request Content:**
	- `body`
		- `"user"`:
			- `"email"`: email of user to register
			- `"password"`: passsword for future authentication
		
- **Example Request:**
```json
{
    "user":{
        "email":"example@exampleemail.com",
        "password":"examplepassword"
    }
}
```
- **Response:**
	- `No return values`
---
## /users/:userEmail
### DELETE
-	**Function:**
	-	Removes the User with email: `userEmail` from the User Repo
		`requires Authentication (see /login in User Paths)`
- **Expected Request Content:**
	- `headers`:
		- `Authorization`: *authentication token*
	- `parameters`:
		- `userEmail`: email of user to delete
- **Response:**
	- `No return Values`
----
# 2. Simulation Configuration Options

## Sim_Config Options
### `input_data_loader`
`required`
- **Function:**
	- Determines what file format simulation input will be provided in
- **Configuration Settings:**
	- `none`
- **Available Options:**
	- XML Input Reader
		- Reads XML formatted input
	- JSON Input Reader
		- Reads JSON formatted input

### `output_data_writer`
`required`
- **Function:**
	- Determines what file format simulation output will be produced in
- **Configuration Settings:**
	- `parentElementName`
		- TODO
	- `childElementName`
		- TODO
- **Available Options:**
	- `XML Output Writer`
		- outputs simulation results in an XML format
	- `JSON Output Writer`
		- outputs simulation results in a JSON format
	- `JSON Timestep Output Writer`
		- TODO

### `simulation_output_handler`
`required`
- **Function:**
	- Handles how output is produced
- **Configuration Settings:**
	- `outputFrequency`
		- TODO
- **Available Options:**
	- `Timestep Output Handler`
		- outputs simulation results to a file using the chosen `output_data_writer`
	- `Timestep Console Logger`
		- output simulation results directly to console

### `pedestrian_set`
`required`
- **Function:**
	- TODO
- **Configuration Settings:**
	- TODO
- **Options:**
	- TODO

### `obstacle_set`
`required`
- **Function:**
	- Determines the map that the simulation is run on
- **Configuration Settings:**
	- `parentElementName`
		- TODO
- **Options:**
	- `A320, 144 Pedestrians`
		- sets the map to a A320 with 144 pedestrians

### `entity_set_factory`
`required`
- **Function:**
	- TODO
- **Configuration Settings:**
	- TODO
- **Options:**
	- `Calm Entity Set Factory`

### `goals`
`required`
- **Function:**
	- Describes the goals of the pedestrians in the simulation
- **Configuration Settings:**
	- `none`
- **Options:**
	- `Calm Goals`

### `pedestrian_dynamics_model`
`required`
- **Function:**
	- Determines the rules for pedestrian dynamics
- **Configuration Settings:**
	- `none`
- **Options:**
	- `Calm Pedestrian Model`

### `human_behavior_model`
`required`
- **Function:**
	- Determines the active behaviors for the simulation
- **Configuration Settings:**
	- 
- **Options:**
	- `Human Behavior Model`

## Sim_Params Options

---
# 3. Behaviors
TODO add behavior definitions
---
# 4. Server Setup
TODO add server setup


