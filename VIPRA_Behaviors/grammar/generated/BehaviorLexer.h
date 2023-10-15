
// Generated from Behavior.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    COMMENT = 8, LINE_COMMENT = 9, WS = 10, COMMA = 11, COLON = 12, STATE_VAL = 13, 
    EVNT = 14, LOC_NAME = 15, AN = 16, AT = 17, ADD = 18, AND = 19, ARE = 20, 
    AFTER = 21, ALWAYS = 22, AROUND = 23, ACTION = 24, BEHIND = 25, BOTTOM = 26, 
    CONSIDER = 27, CIRCLE = 28, CENTER = 29, CONDITION = 30, DECIMAL = 31, 
    DIRECTION = 32, DURATION = 33, END = 34, ENDS = 35, ENVIRONMENT = 36, 
    ENTER = 37, EXIT = 38, EVENT = 39, EXACTLY = 40, EVERY = 41, EVERYONE = 42, 
    ENDING = 43, FOR = 44, FROM = 45, FRONT = 46, FASTER = 47, GIVEN = 48, 
    GOAL = 49, GROUP = 50, HAS = 51, IN = 52, INTEGER = 53, INITIAL = 54, 
    IS = 55, IF = 56, LENGTH = 57, LEFT = 58, LEAVE = 59, DIMENSIONS = 60, 
    LOCATION = 61, MAX = 62, METERS = 63, NAME = 64, NEAREST = 65, NORMAL = 66, 
    NONE = 67, OBSTACLE = 68, OCCUR = 69, OCCURRED = 70, OCCURRING = 71, 
    OF = 72, ON = 73, OR = 74, PEDESTRIAN = 75, PEDESTRIANS = 76, POINTS = 77, 
    POSSIBLE = 78, POSITION = 79, RADIUS = 80, RANDOM = 81, REQUIRED = 82, 
    RECTANGLE = 83, RIGHT = 84, RESPONSE = 85, SCALE = 86, SELF = 87, SELECT = 88, 
    SELECTOR = 89, SET = 90, SECOND = 91, SECONDS = 92, STATUS = 93, STARTING = 94, 
    SLOWER = 95, SHAPE = 96, STATES = 97, START = 98, STATE = 99, STARTS = 100, 
    SPEED = 101, SUBTRACT = 102, STIMULUS = 103, TARGET = 104, TO = 105, 
    TOP = 106, THE = 107, THAT = 108, THEN = 109, THEIR = 110, THERES = 111, 
    TYPES = 112, TYPE = 113, UNCONDITIONALLY = 114, VALUE = 115, VELOCITY = 116, 
    WHEN = 117, WHILE = 118, WIDTH = 119, WILL = 120, WITH = 121, WITHIN = 122, 
    ID = 123, NUMBER = 124, FLOAT = 125
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

