
// Generated from Behaviors.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorsParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by BehaviorsParser.
 */
class  BehaviorsVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by BehaviorsParser.
   */
    virtual antlrcpp::Any visitProgram(BehaviorsParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStatement(BehaviorsParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitConsideration(BehaviorsParser::ConsiderationContext *context) = 0;

    virtual antlrcpp::Any visitCount(BehaviorsParser::CountContext *context) = 0;

    virtual antlrcpp::Any visitDescription(BehaviorsParser::DescriptionContext *context) = 0;

    virtual antlrcpp::Any visitAwake(BehaviorsParser::AwakeContext *context) = 0;

    virtual antlrcpp::Any visitSleeping(BehaviorsParser::SleepingContext *context) = 0;


};

