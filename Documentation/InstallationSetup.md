# Installation and Setup

**File Path:** [Home](../MainPage.md) / [Installation and Setup](InstallationSetup.md) / 

This page is a guide to install and set up the project.

# R. Requirements

The following are the requirements for running the VIPRA simulation.

1. `CMake` - version 3.14^
2. `Make`
3. C++ compiler that supports C++17

Following are additional requirements for development

1. `ANTLR4` - version 4.11^

---
# Se. Setup

In `/VIPRA/` run:

1. `make release` for compiling in release mode

or

1. `make debug` for compiling in debug mode

or

1. `make profiling` for compiling in release mode with profiling output

# U. Utility

## U.1. Visualizer

We have a Python script for viewing the output of a simulation using the File output `Sink`.

`/UtilityScripts/Simulation_Output_Visualization/visualize.py`

Read more under the [Visualizer page](./ResearcherFiles/Visualizer.md)

---

[Go to Main Page](MainPage.md)

[Go to Researchers Page](./ResearcherFiles/Researchers.md)

[Go to Developers Page](MainPage.md)