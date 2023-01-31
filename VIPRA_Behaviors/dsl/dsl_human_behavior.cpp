#include "dsl_human_behavior.hpp"
#include "generated/BehaviorLexer.h"
#include "generated/BehaviorParser.h"

#include <antlr4-runtime/support/Any.h>

#include <spdlog/spdlog.h>

VIPRA::stateUID findState(std::vector<std::string> states, const std::string& stateName);

VIPRA::stateUID
findState(std::vector<std::string> states, const std::string& stateName) {
  VIPRA::size stateCnt = states.size();
  for (VIPRA::idx i = 0; i < stateCnt; ++i) {
    if (states.at(i) == stateName) {
      return static_cast<VIPRA::stateUID>(i);
    }
  }
  DSL_Exception::Throw("Invalid Behavior State: " + stateName);
  return 0;
}

DslHumanBehavior::DslHumanBehavior(const std::string& fileName, unsigned int seedNum) : HumanBehavior(), seed(seedNum) {
  std::ifstream dslFile(fileName);
  std::string   line;

  antlr4::ANTLRInputStream  input(dslFile);
  BehaviorLexer             lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BehaviorParser            parser(&tokens);

  BehaviorParser::ProgramContext* tree = parser.program();

  this->visitProgram(tree);
}