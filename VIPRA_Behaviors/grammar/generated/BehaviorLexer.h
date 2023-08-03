
// Generated from Behavior.g4 by ANTLR 4.13.0

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
    GOAL = 49, GROUP = 50, HAS = 51, IN = 52, INTEGER = 53, IS = 54, IF = 55, 
    LENGTH = 56, LEFT = 57, DIMENSIONS = 58, LOCATION = 59, MAX = 60, METERS = 61, 
    NAME = 62, NEAREST = 63, NORMAL = 64, NONE = 65, OBSTACLE = 66, OCCUR = 67, 
    OCCURRED = 68, OCCURRING = 69, OF = 70, ON = 71, OR = 72, PEDESTRIAN = 73, 
    PEDESTRIANS = 74, POINTS = 75, POSSIBLE = 76, POSITION = 77, RADIUS = 78, 
    RANDOM = 79, REQUIRED = 80, RECTANGLE = 81, RIGHT = 82, RESPONSE = 83, 
    SCALE = 84, SELF = 85, SELECT = 86, SELECTOR = 87, SET = 88, SECOND = 89, 
    SECONDS = 90, STATUS = 91, STARTING = 92, SLOWER = 93, SHAPE = 94, STATES = 95, 
    START = 96, STATE = 97, STARTS = 98, SPEED = 99, SUBTRACT = 100, STIMULUS = 101, 
    TARGET = 102, TO = 103, TOP = 104, THE = 105, THAT = 106, THEN = 107, 
    THEIR = 108, THERES = 109, TYPES = 110, TYPE = 111, UNCONDITIONALLY = 112, 
    VALUE = 113, VELOCITY = 114, WHEN = 115, WHILE = 116, WIDTH = 117, WILL = 118, 
    WITH = 119, WITHIN = 120, ID = 121, NUMBER = 122, FLOAT = 123
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

