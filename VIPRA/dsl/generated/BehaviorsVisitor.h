
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

    virtual antlrcpp::Any visitStateSelector(BehaviorsParser::StateSelectorContext *context) = 0;

    virtual antlrcpp::Any visitStateDeclaration(BehaviorsParser::StateDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStateTransition(BehaviorsParser::StateTransitionContext *context) = 0;

    virtual antlrcpp::Any visitStateAction(BehaviorsParser::StateActionContext *context) = 0;


};

