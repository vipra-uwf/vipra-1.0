
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
    MAX = 51, METERS = 52, NAME = 53, NEAREST = 54, NORMAL = 55, OBSTACLE = 56, 
    OCCUR = 57, OCCURRED = 58, OCCURRING = 59, OF = 60, ON = 61, OR = 62, 
    PEDESTRIAN = 63, PEDESTRIANS = 64, POSSIBLE = 65, POSITION = 66, RADIUS = 67, 
    RANDOM = 68, REQUIRED = 69, RESPONSE = 70, SCALE = 71, SELF = 72, SELECT = 73, 
    SELECTOR = 74, SET = 75, SECOND = 76, SECONDS = 77, STATUS = 78, STARTING = 79, 
    SLOWER = 80, STATES = 81, START = 82, STATE = 83, STARTS = 84, SPEED = 85, 
    SUBTRACT = 86, STIMULUS = 87, TARGET = 88, TO = 89, THE = 90, THAT = 91, 
    THEN = 92, THEIR = 93, THERES = 94, TYPES = 95, TYPE = 96, UNCONDITIONALLY = 97, 
    VALUE = 98, VELOCITY = 99, WHEN = 100, WHILE = 101, WIDTH = 102, WILL = 103, 
    WITH = 104, WITHIN = 105, ID = 106, NUMBER = 107, FLOAT = 108
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

