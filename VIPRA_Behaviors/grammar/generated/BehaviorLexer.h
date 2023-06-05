
// Generated from Behavior.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, COMMENT = 9, LINE_COMMENT = 10, WS = 11, COMMA = 12, COLON = 13, 
    STATE = 14, ACTION = 15, PARAMETER = 16, EVNT = 17, OBJECT = 18, AN = 19, 
    AT = 20, AND = 21, ARE = 22, AFTER = 23, ALWAYS = 24, AROUND = 25, BEHIND = 26, 
    CONSIDER = 27, DECIMAL = 28, DIRECTION = 29, END = 30, ENDS = 31, ENVIRONMENT = 32, 
    EVENT = 33, EXACTLY = 34, EVERY = 35, EVERYONE = 36, FOR = 37, FROM = 38, 
    FRONT = 39, FASTER = 40, GIVEN = 41, HAS = 42, IN = 43, INTEGER = 44, 
    IS = 45, METERS = 46, NORMAL = 47, OBSTACLE = 48, OCCUR = 49, OCCURRED = 50, 
    OCCURRING = 51, OF = 52, OR = 53, PEDESTRIAN = 54, PEDESTRIANS = 55, 
    POSSIBLE = 56, RANDOM = 57, REQUIRED = 58, SECOND = 59, SECONDS = 60, 
    SLOWER = 61, STATES = 62, STARTS = 63, SPEED = 64, TO = 65, THE = 66, 
    THAT = 67, THEN = 68, THEIR = 69, TYPES = 70, VALUE = 71, WHEN = 72, 
    WHILE = 73, WILL = 74, WITHIN = 75, ID = 76, NUMBER = 77, FLOAT = 78, 
    LOC = 79, POINTX = 80, POINTY = 81
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

