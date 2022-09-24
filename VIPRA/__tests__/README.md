# Module Testing

NOT COMPLETE


Module tests are created using [acutest](https://github.com/mity/acutest) with a custom layout

## Contents
1. Test Structure
2. Naming Conventions
3. Creating a Module Test

# 1. Test Structure
Tests are broken up into their Types, the Types being:
```
__tests__
	└─── Data_Sets
	└─── IO
	└─── Goals
	└─── Models
```
Each of these Types are broken up into the Modules that fit under them:
```
Data_Sets
  └─── Obstacle_Sets
  └─── Pedestrian_Sets
IO
  └─── input_data_loaders
  └─── output_data_writers
Goals
  └─── goals
Models
  └─── Behavior_Models
  └─── Pedestrian_Models
```
Each Module has multiple Implementations, each with their own test file and a `tests.hpp` file that combines each implementation
```
Goals
	└─── tests.hpp // Combines each of the module implementation tests together
	└─── example_goals.test.hpp // example implementation test file
	└─── another_goals.test.hpp // example implementation test file
```
Tests for new Module Implementations should be placed under the proper type
# 2. Naming Conventions
## 2.1 File Names
- Test File names should be in [snake case](https://www.curiouslychase.com/posts/most-common-programming-case-types/)
- Test File names should end with the extension `.test.hpp`

### Example:
When making tests for a Pedestrian Dynamics Model Module named `ExampleModel` the file name should be `example_model.tests.hpp`
## 2.2 Test Namespaces
Test Namespaces should:
- be in [snake case](https://www.curiouslychase.com/posts/most-common-programming-case-types/)
- End in `_TESTS`
## 2.3 Test Names

### 2.3.1 Test Function Names
 Test function names should:
- Be in  [snake case](https://www.curiouslychase.com/posts/most-common-programming-case-types/)
- Give a basic idea of what the test covers

## 2.4 Test Macros
### 2.4.1 Module Type Test Macros
Module Type Test Macros should:
- be in  [UPPER_CASE_SNAKE_CASE](https://www.curiouslychase.com/posts/most-common-programming-case-types/)
-  end in `_TESTS`
### 2.3.2 Implementation Test Macros
Implementation Test Macros should:
-  be in [snake_case](https://www.curiouslychase.com/posts/most-common-programming-case-types/) 

---
# 3. Creating a Module Test
This example walks through creating tests for a `Goals` module by the name of `ExampleGoals`
## 1. Create Test File
Find the appropriate directory. In our case, we are testing a `Goals` module so we will place our tests under `__tests__/Goals/example_goals.test.hpp`
## 2. Create Tests
Tests are created using [acutest](https://github.com/mity/acutest)
1. Start by including `__tests__/acutest/acutest.h` which holds the testing library used.
2. Create a namespace to house the tests following naming conventions, in our example it is `Example_Goals_TESTS`
3. Add the needed tests to the namespace
	- test methods are required to be of the type `void test_name(void)`
following this, we have two example tests: `void first_example_test(void)` & `void second_example_test(void)`
4. Create the Test macro
	- We name the macro `example_goals_tests`
	- each test needs to be added with the format `{"test description", namespace::testmethod}`
	- tests are separated by a comma, with NO trailing comma
```c++
// __tests__/Goals/example_goals.test.hpp
#pragma once
#include "./../acutest/acutest.h"
namespace Example_Goals_TESTS {
	void first_example_test(void) {
		// .. code testing functionality
	}
	void second_example_test(void) {
		// .. code testing functionality
	}
}
#define example_goals_tests \
	{"First Example Test", Example_Goals_TESTS::first_example_test}, \
	{"Second Example Test", Example_Goals_TESTS::second_example_test}
```

## 3. Add Tests to the Module Type Test
Each module type has a Module Type Test file, for our example the Module Type Test file is `__tests__/Goals/tests.cpp`

To add the tests we include the Test file we created with `#include "example_goals.test.hpp`, then we add the Implementation Macro to the Module Type Macro
- Implementation Macros are separated by a comma, with NO trailing comma
```c++
// __tests__/Goals/tests.hpp
#pragma  once

// example of another implementation being included
#include "another_goals.test.hpp"

#include "example_goals.test.hpp"

#define  GOALS_TESTS  another_goals_tests, example_goals_tests
```

## 4. Add The Implementation Source to ./sources 
Under the `__tests__/sources` file add the path to the module source directory. If the test uses multiple sources, add all of their directories.
```c++
// the source directory of the new goals module we are adding tests for
./../../Modules/Goals/ExampleGoals
```

## 5. Check That The Module Type Macro Is Included in Testing
Under `__tests__/Testing.cpp` check that the Module Type Macro is included in `TEST_LIST`

If it is not there add it in, separated with a comma
```c++
#include "acutest/acutest.h"
#include  "./Goals/tests.hpp"

TEST_LIST = {INPUT_DATA_LOADER_TESTS, GOALS_TESTS, {NULL, NULL}};
```

## Full Example
This is the full example split into the four files we had to edit
```c++
// __tests__/sources

// source directory for other modules that are being tested
./../Base/jsoncpp
./../Base/inputdataloader/input_json_reader/
./../Base/outputdatawriter/json_timestep_writer/

// the source directory of the new goals module we are adding tests for
./../../Modules/Goals/ExampleGoals
```
```c++
// __tests__/Testing.cpp
#include "acutest/acutest.h"

// each type is included here, however empty tests mess with testing so are not added to the list (until implementation tests are created for them)
#include "./IO/input_data_loader/tests.hpp"
#include "./IO/output_data_writer/tests.hpp"
#include "./Data_Sets/Obstacle_Sets/tests.hpp"
#include "./Data_Sets/Pedestrian_Sets/tests.hpp"
#include "./Models/Behavior_Model/tests.hpp"
#include "./Models/Pedestrian_Model/tests.hpp"

#include "./Goals/tests.hpp"

TEST_LIST = {INPUT_DATA_LOADER_TESTS, GOALS_TESTS, {NULL, NULL}};
```
```c++
// __tests__/Goals/tests.hpp
#pragma  once

// other goal module implementation test files are added
#include "another_goals.test.hpp"

// the test file we created for our module
#include "example_goals.test.hpp"

// combining all goal module tests
#define  GOALS_TESTS  example_goals_tests, another_goals_tests
```
```c++
// __tests__/Goals/example_goals.test.hpp
#pragma once
// including the test library header
#include "./../acutest/acutest.h"

// creating a namespace for the tests
namespace Example_Goals_TESTS {
	void first_example_test(void) {
		// .. code testing functionality
	}
	void second_example_test(void) {
		// .. code testing functionality
	}
}

// adding the tests to the test macro
#define example_goals_tests \
	{"First Example Test", Example_Goals_TESTS::first_example_test}, \
	{"Second Example Test", Example_Goals_TESTS::second_example_test}
```



