#include <spdlog/spdlog.h>

#include <behavior/behavior_error_listener.hpp>

void
BehaviorErrorListener::syntaxError(antlr4::Recognizer* recognizer,
                                   antlr4::Token*      offendingSymbol,
                                   size_t              line,
                                   size_t              charPositionInLine,
                                   const std::string&  msg,
                                   std::exception_ptr  e) {
  spdlog::error("Behavior Syntax Error: Line {}:{}, {}", line, charPositionInLine, msg);
  exit(1);
}

void
BehaviorErrorListener::reportAmbiguity(antlr4::Parser*            recognizer,
                                       const antlr4::dfa::DFA&    dfa,
                                       size_t                     startIndex,
                                       size_t                     stopIndex,
                                       bool                       exact,
                                       const antlrcpp::BitSet&    ambigAlts,
                                       antlr4::atn::ATNConfigSet* configs) {
  spdlog::error("Behavior Ambiguity Error: Line {}:{}", startIndex, stopIndex);
  exit(1);
}

void
BehaviorErrorListener::reportAttemptingFullContext(antlr4::Parser*            recognizer,
                                                   const antlr4::dfa::DFA&    dfa,
                                                   size_t                     startIndex,
                                                   size_t                     stopIndex,
                                                   const antlrcpp::BitSet&    conflictingAlts,
                                                   antlr4::atn::ATNConfigSet* configs) {}

void
BehaviorErrorListener::reportContextSensitivity(antlr4::Parser*            recognizer,
                                                const antlr4::dfa::DFA&    dfa,
                                                size_t                     startIndex,
                                                size_t                     stopIndex,
                                                size_t                     prediction,
                                                antlr4::atn::ATNConfigSet* configs) {}