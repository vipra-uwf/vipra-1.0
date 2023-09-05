# Adding Modules

This is a temporary process for adding new modules, an automated solution will be added in the future.

### 1. Adding The Files

The first step is to add the source files.

Each module should have:
1. `.hpp` file
2. `.cpp` file
3. `.mm` file

Module files are added under the directory for their type in the `Modules` directory in a separate directory.

Example:
```
A Goals module named 'example_goals' goes under:
Modules/Goals/example_goals/
```

#### Missing .mm File

If a module is missing a .mm File, adding one is simple.

In the directory with the `.hpp` and `.cpp` files create a new `.mm` file with the modules name.

Example:
```
For a Goals module named 'example_goals':
Modules/Goals/example_goals/example_goals.mm

{
    "id": "poiar09haerkjnaerv", // Random ID
    "name": "example_goals",    // Name that matches source file and directory names
    "description": "This is an example goals module", // Description, can be anything
    "params": [],               // Params can be left blank for now
    "className": "ExampleGoals",   // Name of class in the .hpp file
    "type": "goals"             // module type
}
```

### 2. Adding Module to modules.json

Each module needs to be added to `VIPRA/modules.json`.

Under the module type add a JSON object with an `id`, `name`, `className`, and `dirPath`.

```
"goals": [                              // Find module type
  { ... another goals module },
  { ... another goals module },
  {                                     // Add new module information
    "id": "poiar09haerkjnaerv",         // Match ID from .mm file
    "name": "example_goals",            // Match name from .mm file
    "className": "ExampleGoals",        // Match class name from .mm file
    "dirPath": "../Modules/Goals/example_goals" // Add path to the modules directory
  }
]
```

### 3. Recompile

When adding new modules the simulation needs to be re-compiled.

Follow the steps in [Installation and Setup](../../InstallationSetup.md)