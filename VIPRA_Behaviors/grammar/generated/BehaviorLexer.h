
// Generated from Behavior.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, COMMENT = 11, LINE_COMMENT = 12, WS = 13, 
    COMMA = 14, COLON = 15, STATE = 16, ACTION = 17, EVNT = 18, OBJECT = 19, 
    AN = 20, AT = 21, AND = 22, ARE = 23, AFTER = 24, ALWAYS = 25, AROUND = 26, 
    BEHIND = 27, CONSIDER = 28, DECIMAL = 29, DIRECTION = 30, END = 31, 
    ENDS = 32, ENVIRONMENT = 33, EVENT = 34, EXACTLY = 35, EVERY = 36, EVERYONE = 37, 
    FOR = 38, FROM = 39, FRONT = 40, FASTER = 41, GIVEN = 42, HAS = 43, 
    IN = 44, INTEGER = 45, IS = 46, LENGTH = 47, LOCATION = 48, METERS = 49, 
    NORMAL = 50, OBSTACLE = 51, OCCUR = 52, OCCURRED = 53, OCCURRING = 54, 
    OF = 55, OR = 56, PEDESTRIAN = 57, PEDESTRIANS = 58, POSSIBLE = 59, 
    RADIUS = 60, RANDOM = 61, REQUIRED = 62, SECOND = 63, SECONDS = 64, 
    SLOWER = 65, STATES = 66, STARTS = 67, SPEED = 68, TO = 69, THE = 70, 
    THAT = 71, THEN = 72, THEIR = 73, THERES = 74, TYPES = 75, VALUE = 76, 
    WHEN = 77, WHILE = 78, WIDTH = 79, WILL = 80, WITH = 81, WITHIN = 82, 
    ID = 83, NUMBER = 84, FLOAT = 85
  };

  explicit BehaviorLexer(antlr4::CharStream *input);

  ~BehaviorLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

