#include <stdexcept>

#include <spdlog/spdlog.h>

#include <builder/behavior_error_listener.hpp>

namespace BHVR {
void BehaviorErrorListener::syntaxError(antlr4::Recognizer*, antlr4::Token*, size_t line,
                                        size_t charPositionInLine, const std::string& msg,
                                        std::exception_ptr) {
  spdlog::error("Behavior Syntax Error: Line {}:{}, {}", line, charPositionInLine, msg);
  throw std::runtime_error("");
}

void BehaviorErrorListener::reportAmbiguity(antlr4::Parser*, const antlr4::dfa::DFA&, size_t startIndex,
                                            size_t stopIndex, bool, const antlrcpp::BitSet&,
                                            antlr4::atn::ATNConfigSet*) {
  spdlog::error("Behavior Ambiguity Error: Line {}:{}", startIndex, stopIndex);
  throw std::runtime_error("");
}

void BehaviorErrorListener::reportAttemptingFullContext(antlr4::Parser*, const antlr4::dfa::DFA&, size_t,
                                                        size_t, const antlrcpp::BitSet&,
                                                        antlr4::atn::ATNConfigSet*) {}

void BehaviorErrorListener::reportContextSensitivity(antlr4::Parser*, const antlr4::dfa::DFA&, size_t, size_t,
                                                     size_t, antlr4::atn::ATNConfigSet*) {}
}  // namespace BHVR