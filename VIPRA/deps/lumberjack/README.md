# LumberJack

LumberJack is meant to be a very simple header-only Logging library.

Currently it's functionality is limited but I hope to add much more in the future.


# How To Use
```c++
#include "lumberjack/lumberjack.hpp"
#include "lumberjack/loggers/consoleLogger.hpp"
#include "lumberjack/loggers/fileLogger.hpp"

int main() {
	LJ::Logger<LJ::ConsoleLogger> consoleLogger{LJ::WARN};
	
	// will only output messages with proper Level
	LJ::Warn(consoleLogger, "Example Warning");
	LJ::Debug(consoleLogger, "Example Debug"); // won't print
	
	// Console & File Loggers use the fmt library for string formatting
	LJ::Error(consoleLogger, "Formatting {}", "Example");
	
	// creates a logger that will output to a file, defaults to Level ERROR
	LJ::Logger<LJ::FileLogger> fileLogger{"example.log"};
	
	// can change the level of a logger
	fileLogger.setLevel(LJ::DEBUG);
}
```

## Adding Custom Logger Implementations

Adding a Custom Logger Implementation is simple.

```c++
// Lambdas can be used to create Loggers
auto lambdaExample = [](LJ::Level lvl, const std::string& message){
	std::cout << message << std::endl;
};

LJ::Logger<decltype(lambdaExample)> lmdaLogger{LJ::DEBUG};
LJ::Info(lmdaLogger, "Example");
```

```c++
// Classes with operator() overloaded can be used

class SimpleLogger {
public:
  // log functions are only called if the message is of the proper level
  // LJ::Level is passed simply for end use
  void operator()(LJ::Level lvl, const std::string& message) {
	std::cout << message << std::endl;
  }
};

// Logger Implementations can be very flexible
class TestLogger {
public:
  // add any constructors that may be needed
  TestLogger(std::string param) : exampleVar(std::move(param)) {}

  // this is a simple function that just logs the message along with the class' exampleVar
  void operator()(LJ::Level lvl, const std::string& message) {
    std::cout << exampleVar << " " << message << std::endl;
  }

  // allows for custom log function definitions, here an extra string can be passed to overwrite exampleVar
  void operator()(LJ::Level lvl, const std::string& message,
                  std::string replace) {
    exampleVar = std::move(replace);
    std::cout << exampleVar << " " << message << std::endl;
  }

private:
  std::string exampleVar;
};

int main() {

  LJ::Logger<SimpleLogger> simpleLogger{};
  LJ::Error(simpleLogger, "Example") // outputs: Example
	
  LJ::Logger<TestLogger> testLogger{"parameter"};
  LJ::Error(testLogger, "Test"); // outputs: parameter Test
  LJ::Error(testLogger, "Test2", "Changed"); // outputs: Changed Test2

  return 0;
}
```