
# VIPRA WebAPI

# Contents
1. **Current Routes**
	- Simulation Paths
	- Behavior Paths
	- User Paths

2. **Configuration Options**

# 1. Current Routes
# Simulation Paths
These Paths deal with configuration and creation of simulations
## /sim
### GET
- **Function:**
	Returns the current simulation configuration options and there possible selections
	`see the Configurations Options section for current Configuration options`
- **Expected Request Contents:**
	- `none`
- **Response:**
	- **Success:** status: `200`
		- `data` contains the options
	- **Error:** status: `500`
		- Unknown Error, Options not returned

**Example Response:**
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

---
## /sim
### POST
- **Function:**
	Returns the Generated Simulation source files and a Vagrant file for setup of a build environment
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
	-	a
TODO add response to this
---
# Behavior Paths
## /sim/behaviors
### GET
-	**Function:**
	Returns available behavior options to the client
	`only returns publically published Behaviors and Behaviors published by the logged in user`
- **Expected Request Content:**
	- `none`
- **Response:**
	- **Success:** status: `200`
		- `data` contains all published Behaviors
	- **Error:** status: `500`
		- Unknown Error, Behaviors not returned

**Example Response:**
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
	-	Upload Behavior to Repo
- **Expected Request Content:**
	- `headers`: 
		- `Authorization`: 
			- *authentication token*
	- `body`: JSON
		- `"behavior"`
			- `"name"` : (string) name for behavior to be identified by
			- `"content"` : (string) the content of the behavior file
			- `"publish"` : (boolean) whether behavior should published to other users
- **Response:**
	- **Success**: status: `200`
		- Behavior was created on Repo
	- **Bad Request**: status:`400`
		- Behavior request was malformed, Behavior was not created
	- **Unauthorized**: status: `401`
		- User is not authenticated, Behavior was not created
	- **Error**:status `500`
		- Unknown Error, Behavior was not created

**Example Request Body:**
```json
{
    "behavior": {
        "name": "random_sleep",
		"content": "/**  * RANDOM SLEEP  */// This is a random sleep behavior. It models the scenario of a certain percent// of the population that suffers from narcolepsy. Specifically, someone// subject to this behavior will stop movement to take a nap for the specified// number of seconds.Consider a sleeper.// This indicates that precisely persons 0, 50, and 100 are going to be subject// to this behavior.// 2% of the population are a sleeper.// This randomly selects a ratio of pedestrians for this behavior. In this// case, a random 1 out of every 50 pedestrians is a sleeper.A random 1 out of every 50 pedestrians is a sleeper.// These are two states that the sleeper can be in. They can be named// anything, but it must be consistent throughout the entire file.A sleeper can be SLEEPING.A sleeper can be AWAKE.// Define the initial state of a sleeperA sleeper is initially AWAKE.// This indicates the state transition rules. In this case, we model a person// taking a two minute nap, then waking up 5 minutesA sleeper who is SLEEPING will be AWAKE after 120 seconds.A sleeper who is AWAKE will be SLEEPING after 300 seconds.// This tells the model how the sleeping state affects their behavior. In this// case a sleeping person is stopped, meaning all movement is ceased.A sleeper who is SLEEPING is STOPPED.A sleeper who is AWAKE will behave normally.",
        "publish": false
    }
}
```
---
## /sim/behaviors
### PUT
-	**Function:**
	-	Updates a behavior
- **Expected Request Content:**
	- `headers`:
		- `Authorization`:
			- *authentication token*
	- `body`: JSON
		- `"behavior"`:
			- `"name"`: (string) Name of behavior to update
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

**Example Request:** (sets a behavior to be published)
```json
{
    "behavior": {
	    "name": "injured_person",
        "publish": true
    }
}
```
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
		- `name`: name of behavior to be deleted
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

# User Paths
## /login
### POST
-	**Function:**
	-	Returns Authentication token
- **Expected Request Content:**
	- `body`:
		- `user`:
			- `email`: email of user to login as
			- `password`:  password for user
- **Response:**
	- **Success:** 
		- status: `200`
		- body: 
			- `token` : 
				- *authentication token*
		- Successfully Authenticated
	- **Bad Request**
		- status: `400`
		- User not Authenticated

**Example Response:**
```json
{
    "message": "Success",
    "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6InBlcm1UZXN0QHRlc3QuY29tIiwiaWF0IjoxNjQ4NjczMzA5LCJleHAiOjE2NDg3NTk3MDl9.4rW-viMPEpylpcrKyv5eecUd0tG9nUEA2gWTqKvp01Q"
}
```
---
## /register
### POST
-	**Function:**
	-	Creates User in User Repo
- **Expected Request Content:**
	- `body`
		- `"user"`:
			- `"email"`: email of user to register
			- `"password"`: passsword for future authentication
- **Response:**
	- **Success** status: `200`
		- User was created
	- **Bad Request** status: `400`
		- Request was malformed, User was not created
	- **Error** status: `500`
		- Unknown Error, User was not created
		
**Example Request:**
```json
{
    "user":{
        "email":"example@exampleemail.com",
        "password":"examplepassword"
    }
}
```
---
## /users/:userEmail
### DELETE
-	**Function:**
	-	Removes user from User Repo
- **Expected Request Content:**
	- `headers`:
		- `Authorization`: *authentication token*
	- `parameters`:
		- `userEmail`: email of user to delete
- **Response:**
	- **Success:**  status: `200`
		- User was removed
	- **Bad Request:** status: `400`
		- No user with provided name, User was not removed
	- **Unauthorized:** status: `401`
		- User was not authenticated OR User does not have access to remove the User, User was not removed
----
# 2. Configuration Options
TODO add simulation configuration options
---



