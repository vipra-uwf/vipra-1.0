# Installation and Setup

**File Path:** [Home](../MainPage.md) / [Researchers](Researchers.md) / [Installation and Setup](InstallationSetup.md) / 


This page is a guide to install and set up the project.

# R. Requirements

The following are the requirements for running the VIPRA simulation.

1. `NodeJS` - version 17.0^
2. `CMake` - version 3.14^
3. `Make`
4. C++ compiler that supports C++17

Following are additional requirements for development

1. `ANTLR4` - version 4.11^

---
# SE. Setup

There are three main steps for setting up the simulation. *(This is temporary, a more permanent setup will be created in the future)*
1. ChainBuilder setup
2. VIPRA Launcher setup
3. Simulation Compilation

## SE.2. ChainBuilder

In `/ChainBuilder/` run:

1. `npm install`
2. `npm run build`
3. `npm pack`

## Se.3. VIPRA Launcher

In `/VIPRA_Launcher/server/` run:

1. `npm install`
2. `npm run build`

If you encounter errors with `npm install`:

1. Delete `package-lock.json`
2. Check that `typechain` in `package.json` points to the tarball created for ChainBuilder

If you encounter errors with `npm run build`:

*if you only get type errors, try moving on to the simulation compilation step*

1. Make sure you have Node 17 or later
2. Check that the `ChainBuilder` tarball was created properly

## SE.4. Simulation Compilation

In `/VIPRA/` run:

1. `make release` for compiling in release mode
 
or

1. `make debug` for compiling in debug mode

or

1. `make profiling` for compiling in release mode with profiling output

---
# Ru. Running

In `/VIPRA/` run:
`./VIPRA_SIM *Sim Config Path* *Module Params Path* *Pedestrians File Path* *Obstacle File Path* *Output File Path*`

An example `sim.config` and `module_params.json` are found in `SimConfigs/ExampleConfig/`

---

# U. Utility

## U.1. Visualizer

We have a Python script for viewing the output of a simulation.

`/UtilityScripts/Simulation_Output_Visualization/visualize.py`

To run:
1. `python3 visualize.py *Path to output.json* *Path to Obstacle File*`


---

[Return to Getting Started - Researchers](Researchers.md) 