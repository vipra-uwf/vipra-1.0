#include "behavior_builder.hpp"
#include "generated/BehaviorLexer.h"
#include "generated/BehaviorParser.h"

#include <antlr4-runtime/support/Any.h>
#include <spdlog/spdlog.h>

HumanBehavior currBehavior;

HumanBehavior
BehaviorBuilder::build(const std::filesystem::path& fileName, VIPRA::seed seedNum) {
  currBehavior = HumanBehavior();
  std::ifstream dslFile(fileName);

  antlr4::ANTLRInputStream  input(dslFile);
  BehaviorLexer             lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BehaviorParser            parser(&tokens);

  BehaviorParser::ProgramContext* tree = parser.program();

  visitProgram(tree);

  return currBehavior;
}