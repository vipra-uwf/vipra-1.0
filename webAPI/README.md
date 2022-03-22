
# CURRENTLY IN PROGRESS

# Current Routes
## /api
### GET
- **Function:**
		Returns JSON Contents of:
		`VIPRA/input_data/sim_options.json`
- **Call Path:**
	`none`
---
## /api/sim
### POST
- **Function:**
	Creates "sim_config`uniqueID`.json" for use in configuring the simulation in `VIPRA/input_data/`
	And
	Spawn a daemon process for running the simulation
	And
	Redirects the user to `/api/sim/updates/`
- **Call Path:**
	-`setSimConfig`
	-`StartSim`
	-`redirectToUpdates`
---
## /api/sim/updates
### GET
- **Function:**
	Provides Server Sent Events  to the client
- **Call Path**
---

# Controllers
# Middleware