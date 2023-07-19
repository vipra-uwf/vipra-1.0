
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
    METERS = 51, NAME = 52, NEAREST = 53, NORMAL = 54, OBSTACLE = 55, OCCUR = 56, 
    OCCURRED = 57, OCCURRING = 58, OF = 59, ON = 60, OR = 61, PEDESTRIAN = 62, 
    PEDESTRIANS = 63, POSSIBLE = 64, POSITION = 65, RADIUS = 66, RANDOM = 67, 
    REQUIRED = 68, RESPONSE = 69, SCALE = 70, SELF = 71, SELECT = 72, SELECTOR = 73, 
    SET = 74, SECOND = 75, SECONDS = 76, STATUS = 77, STARTING = 78, SLOWER = 79, 
    STATES = 80, START = 81, STATE = 82, STARTS = 83, SPEED = 84, SUBTRACT = 85, 
    STIMULUS = 86, TARGET = 87, TO = 88, THE = 89, THAT = 90, THEN = 91, 
    THEIR = 92, THERES = 93, TYPES = 94, TYPE = 95, UNCONDITIONALLY = 96, 
    VALUE = 97, VELOCITY = 98, WHEN = 99, WHILE = 100, WIDTH = 101, WILL = 102, 
    WITH = 103, WITHIN = 104, ID = 105, NUMBER = 106, FLOAT = 107
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

