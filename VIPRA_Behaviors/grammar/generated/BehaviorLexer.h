
// Generated from Behavior.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    COMMENT = 8, LINE_COMMENT = 9, WS = 10, COMMA = 11, COLON = 12, STATE_VAL = 13, 
    EVNT = 14, AN = 15, AT = 16, ADD = 17, AND = 18, ARE = 19, AFTER = 20, 
    ALWAYS = 21, AROUND = 22, ACTION = 23, BEHIND = 24, CONSIDER = 25, DECIMAL = 26, 
    DIRECTION = 27, DURATION = 28, END = 29, ENDS = 30, ENVIRONMENT = 31, 
    EVENT = 32, EXACTLY = 33, EVERY = 34, EVERYONE = 35, ENDING = 36, FOR = 37, 
    FROM = 38, FRONT = 39, FASTER = 40, GIVEN = 41, GOAL = 42, GROUP = 43, 
    HAS = 44, IN = 45, INTEGER = 46, IS = 47, IF = 48, LENGTH = 49, LOCATION = 50, 
    MAX = 51, METERS = 52, NAME = 53, NEAREST = 54, NORMAL = 55, NONE = 56, 
    OBSTACLE = 57, OCCUR = 58, OCCURRED = 59, OCCURRING = 60, OF = 61, ON = 62, 
    OR = 63, PEDESTRIAN = 64, PEDESTRIANS = 65, POSSIBLE = 66, POSITION = 67, 
    RADIUS = 68, RANDOM = 69, REQUIRED = 70, RESPONSE = 71, SCALE = 72, 
    SELF = 73, SELECT = 74, SELECTOR = 75, SET = 76, SECOND = 77, SECONDS = 78, 
    STATUS = 79, STARTING = 80, SLOWER = 81, STATES = 82, START = 83, STATE = 84, 
    STARTS = 85, SPEED = 86, SUBTRACT = 87, STIMULUS = 88, TARGET = 89, 
    TO = 90, THE = 91, THAT = 92, THEN = 93, THEIR = 94, THERES = 95, TYPES = 96, 
    TYPE = 97, UNCONDITIONALLY = 98, VALUE = 99, VELOCITY = 100, WHEN = 101, 
    WHILE = 102, WIDTH = 103, WILL = 104, WITH = 105, WITHIN = 106, ID = 107, 
    NUMBER = 108, FLOAT = 109
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
