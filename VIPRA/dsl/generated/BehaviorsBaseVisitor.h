
// Generated from Behaviors.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"
#include "BehaviorsVisitor.h"


/**
 * This class provides an empty implementation of BehaviorsVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  BehaviorsBaseVisitor : public BehaviorsVisitor {
public:

  virtual antlrcpp::Any visitProgram(BehaviorsParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(BehaviorsParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConsideration(BehaviorsParser::ConsiderationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCount(BehaviorsParser::CountContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDescription(BehaviorsParser::DescriptionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAwake(BehaviorsParser::AwakeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSleeping(BehaviorsParser::SleepingContext *ctx) override {
    return visitChildren(ctx);
  }


};

