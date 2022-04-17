

# VIPRA

# Contents
1. **Current Routes**
	- Simulation Paths
	- Behavior Paths
	- User Paths
2. **Simulation Configuration Options**
3. **Compilation**
4. **Dependencies**
5.  **Behaviors**
---
# 1. Current Routes
# Simulation Paths
These Paths handle configuration and creation of simulations
## /sim
### Method: GET
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
### Method: POST
`requires Authentication (see /login in User Paths)`
- **Function:**
	Returns the Generated Simulation source files along with a files for compilation using AutoTools `see compilation for more information`
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
	- File download: 
		- `name`: `VIPRA.tar`
			-	Tar Conents:
				-	`generated_main.cpp`
				-	`source code`
				-	`compile`
				-	`configure.ac`
				-	`Makefile.am`
				-	`AUTHORS`
				-	`ChangeLog`
				-	`NEWS`
				-	`README`
	-	`see compilation for more information`
---
# Behavior Paths
These Paths deal with Creating/Editing/Deleting Behaviors
## /sim/behaviors
### Method: GET
`optional Authentication (see /login in User Paths)`
-	**Function:**
	Returns available behavior options to the client
	`only returns publically published Behaviors and Behaviors published by the logged in user`

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
### Method: POST
`requires Authentication (see /login in User Paths)`
-	**Function:**
	-	Uploads a new Behavior to the Repo
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
### Method: PUT
`requires Authentication (see /login in User Paths)`
-	**Function:**
	-	Updates a behavior, Can be used to update a behavior's 'published' status or update the contents of the behavior file
	`behavior names cannot be updated or changed`
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
### Method: DELETE
`requires Authentication (see /login in User Paths)`
-	**Function:**
	-	Removes the Behavior with name `behaviorName` from the Repo
`only behaviors authored by the authenticated user can be deleted`
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
### Method: POST
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
### Method: POST
-	**Function:**
	-	Creates a new User in User Repo
- **Expected Request Content:**
	- `body`
		- `"user"`:
			- `"email"`: email of user to register
			- `"password"`: password for future authentication
		
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
### Method: DELETE
`requires Authentication (see /login in User Paths)`
-	**Function:**
	-	Removes the User with email: `userEmail` from the User Repo
- **Expected Request Content:**
	- `headers`:
		- `Authorization`: *authentication token*
	- `parameters`:
		- `userEmail`: email of user to delete
- **Response:**
	- `No return Values`
----
# 2. Simulation Configuration Options
- options marked `required` **must** be included in requests
## Sim_Config Options
### `input_data_loader`
`required`
- **Function:**
	- Determines what file format simulation input will be provided in (either JSON or XML)
- **Configuration Settings:**
	- `none`
- **Available Options:**
	- XML Input Reader
		- Reads XML formatted input
	- JSON Input Reader
		- Reads JSON formatted input
---
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
---
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
---
### `pedestrian_set`
`required`
- **Function:**
	- TODO
- **Configuration Settings:**
	- TODO
- **Options:**
	- TODO
---
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
---
### `entity_set_factory`
`required`
- **Function:**
	- TODO
- **Configuration Settings:**
	- TODO
- **Options:**
	- `Calm Entity Set Factory`
---
### `goals`
`required`
- **Function:**
	- Describes the goals of the pedestrians in the simulation
- **Configuration Settings:**
	- `none`
- **Options:**
	- `Calm Goals`
---
### `pedestrian_dynamics_model`
`required`
- **Function:**
	- Determines the rules for pedestrian dynamics
- **Configuration Settings:**
	- `none`
- **Options:**
	- `Calm Pedestrian Model`
---
### `human_behavior_model`
`required`
- **Function:**
	- Determines the active behaviors for the simulation
- **Configuration Settings:**
	- TODO
- **Options:**
	- `Human Behavior Model`
---
## Sim_Params Options
- `luggage`
	- TODO
- `exit_door_x`
	- TODO
- `exit_door_y`
	- TODO
- `aligning_stop_threshold`
	- TODO
- `toward_aisle_stop_threshold`
	- TODO
- `in_aisle_stop_threshold`
	- TODO
- `time_step`
	- TODO
- `time_step_size`
	- TODO
---

# 3. Compilation

*Given all dependencies are satisfied `see 4. Dependencies`*
- Extract `VIPRA.tar` to any directory
- Run `./compile` from the directory `VIPRA.tar` was extracted to
	- *`compile` should inform you of any missing depedencies*
- The compiled `VIPRA` executable will be located in the directory
---
# 4. Dependencies
## 1. **AutoConf**
Used for the compilation of VIPRA
### Installation
`$ sudo apt-get install autoconf`
### Website
`https://www.gnu.org/software/autoconf/`

---
## 2. **AutoMake**
Used for the compilation of VIPRA
### Installation
`$ sudo apt-get install automake`
### Website
`https://www.gnu.org/software/automake/`

---
## 3. **Antlr4 Runtime**
Used for parsing of Behaviors & Policies
### Installation
`$ sudo apt-get install libantlr4-runtime-dev`
### Website
`https://www.antlr.org/`

---
# 4. Behaviors
# Human Behaviors

Human behaviors are modeled with the Human Behavioral Model. This shares the same lifecycle of the Pedestrian Dynamics Model, but intends to alter the velocity of individual pedestrians.

Each iteration of the simulation, the human behavior model is updated. It will modify certain aspects of the pedestrianset (e.g., velocity, propulsion) before the pedestrian dynamics model is run.

Individual behaviors can have state (such as defining groups of travelers) that exist directly on the HumanBehavior class. The human behavior model (HBM) runs a list of these states in the order they were defined in `sim_config.json`.

## Changes to Existing Code

To support the human behaviors, we had to change a bit of how Pedestrian Dynamics Model worked. The original design involved (in the update() method) the entirety of the positions, velocities, speeds, and propulsions to be computed, and subsequently set by value as the new list. In order to have the HBM influence these values, we had to modify their values directly. This also had the effect of reducing the amount of data copied from the stack to the heap, which 
theoretically should improve performance.

Essentially, the human behavior makes influencing changes to the pedestrian set's velocities, speeds, and propulsions, but otherwise lets the pedestrian dynamics model to actually move the pedestrians.

We also set the movement state to HUMAN, which was already there, but not yet used. In the function `updateMovementState()` on the Pedestrian Dynamics Model we check for this state to avoid resetting it to STOPPED or PED_DYNAM. The goal here was to avoid unnecessary changes to the PDM and keep most of the new logic in the HBM.

## Anatomy of a Human Behavior

This project defines "building blocks" that allow researchers to describe aspects of human behavior. These building blocks compose to form many possible complex behaviors with relatively simple code. It also allows researchers who run the simulation to describe human behaviors in structured English, rather than a programming language.

When researchers encounter a behavior that cannot be described using existing building blocks, the software developers have the option of enhancing existing blocks or defining new ones. The idea is that over time that the VIPRA human behavioral model can be rich enough to meet most of the needs of researchers describing human behavior.

### Consideration

This is a formal declaration of the name of the behavior. It's used for logging output and to help describe the behavior in a distinctive manner. This can be any word or hyphenated word. 

Example:

```
Consider a sleeper.
```

### Selector

When the simulation starts, the human behavior model (HBM) selects a subset of the pedestrians in the simulation. Those people are selected just to be tracked by the behavior. The selector doesn't influence exactly what the behavior is, or what state the person is. It just indicates that this individual was selected for that behavior.

Example:

```
A random 1 out of every 50 pedestrians is a sleeper.
```

### States

Human behaviors can be described using states. For example, a person can be listening to an announcement.

Example:

```
A sleeper can be SLEEPING.
A sleeper can be AWAKE.
```

### Transition

The transition is composed of a before-state, an after-state, and a condition. Several conditions exist as options.
`See the "conditions" directory for examples.`

Example:

```
A sleeper who is SLEEPING will be AWAKE after 120 seconds.
A sleeper who is AWAKE will be SLEEPING after 300 seconds.
```

### State-Action

Each iteration of the simulation, if the selected person is in the specified state, perform that action (for example, slow down or speed up). The actions are defined in the "actions" directory.

Example:

```
A sleeper who is SLEEPING is STOPPED.
A sleeper who is AWAKE will behave normally.
```

Note: there is no code defined for the "will behave normally" action. The HBM will effectively ignore behaviors that have no visitors defined.

### Decider

This tells the simulation that the movement states are being tracked by the human behavior model, and not the pedestrian dynamics model. For example, if a person is stopped because of the human behavior model, we don't want the pedestrian dynamics model to overwrite its state and have it move again, so its decider will return true. But if a person is slowed down by the human behavior model, we want the pedestrian dynamics model to continue to guide that person to its goal, so its decider will return false.

NOTE: This was a part of the original design, but it turned out that deciders were un-necessary. Each action is associated with a state, and it turned out that the simplest way to model the behavior was to simply apply the action on a selected person if they are in the specified state, and ignore the decider.

## The Human Behavior Environment

Some behaviors operate on changes to the environment. These can be described very similarly to pedestrian states, in that states are defined and state transitions can be expressed. There are no actions associated with the environment state, however. The actions are defined only on the pedestrian, and those actions are tied to the pedestrian states.

### Environment State

The environment can be in a specified state, like "ANNOUNCING." Typically, we recommend these to be in all-caps to help improve readability, but it can be lower-case as well.

Example:

```
The environment can be ANNOUNCING.
```

### Environment State Transition

This describes under what scenarios the environment can be transitioned. These can use the same types of conditions that we have defined for pedestrian state transitions.

```
The environment that is ANNOUNCING will be POST_ANNOUNCING after 30 seconds.
```

# Domain-Specific Language (DSL)

Each behavior is described in a ".behavior" file in the root of the VIPRA directory. Several examples are provided:

* random_sleep.behavior - describes a random person that will fall asleep and stop movement for a pre-defined amount of time.
* important_announcement.behavior - describes an environmental change when an announcement is happening. Everyone will
  stop in reaction to this announcement.
* injured_person.behavior - describes an individual that is injured and walks slowly.

You can specify these in the `input_data/sim_config.json` file under the "behaviors" section.

The DSL is developed with [ANTLR4](https://www.antlr.org/), so in order to run the application you will need the ANTLR4 runtime. To compile the application, you will also need the ANTLR4 development files provided by your Linux distribution. If you want to add new capabilities to the DSL, you will also need the ANTLR4 tool installed. See the Makefile for instructions for individual distributions.

## New Behaviors

If a new behavior can be described using the same selectors, state transitions, and actions, no new code needs to be written. You can just write the new ".behavior" file and reference it in `input_data/sim_config.json` and the system should pick it up.

If you need new selectors, the best approach is to write the ".behavior" file and work your way backwards. These files support C++-style comments, so you can comment out portions of the file that are not yet implemented. Then modify the grammar file "Behaviors.g4" to tell ANTLR how to parse the file. See ANTLR documentation for details. 

NOTE: The [official book](https://pragprog.com/titles/tpantlr2/the-definitive-antlr-4-reference/) is a very good reference for this. In my opinion it is well worth the cost to avoid the frustration of learning without it.

Once the grammar file has been updated you need to re-generate the DSL code. This command is in the Makefile, so all you need to do is run `make grammar`. This command assumes you have `antlr4` defined in your shell.

Finally, use the visitor pattern (as described by the ANTLR4 documentation) to override a visitor for the new statement you defined. You can reference the existing visitors as examples.

When you re-compile the application, you can run it against your new behavior and monitor the result.

### Testing

You can use ANTLR4's "grun" utility to graphically test your grammar and behavior. Unfortunately this only works in Java. To test the parsing logic of your grammar:

```shell
antlr4 Behaviors.g4
javac *.java
alias grun='java org.antlr.v4.gui.TestRig'
grun Behaviors program -gui random_sleep.behavior
```

This should print a nice GUI to show how the generated ANTLR4 code would parse your file. When you subsequently run `make grammar` it will re-generate these files in C++ and behave identically to its java counterpart.
