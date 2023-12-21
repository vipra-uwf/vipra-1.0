
// Generated from Behavior.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, COMMENT = 10, LINE_COMMENT = 11, WS = 12, COMMA = 13, 
    COLON = 14, STATE_VAL = 15, EVNT = 16, LOC_NAME = 17, AN = 18, AT = 19, 
    ADD = 20, AND = 21, ARE = 22, AFTER = 23, ALWAYS = 24, AROUND = 25, 
    ACTION = 26, BEHIND = 27, BOTTOM = 28, CONSIDER = 29, CIRCLE = 30, CENTER = 31, 
    CONDITION = 32, DECIMAL = 33, DIRECTION = 34, DURATION = 35, END = 36, 
    ENDS = 37, ENVIRONMENT = 38, ENTER = 39, EXIT = 40, EXISTS = 41, EVENT = 42, 
    EXACTLY = 43, EVERY = 44, EVERYONE = 45, ENDING = 46, FOR = 47, FROM = 48, 
    FRONT = 49, FASTER = 50, GIVEN = 51, GOAL = 52, GROUP = 53, HAS = 54, 
    IN = 55, INTEGER = 56, INITIAL = 57, IS = 58, IF = 59, LENGTH = 60, 
    LENGTHS = 61, LEFT = 62, LEAVE = 63, DIMENSIONS = 64, LOCATION = 65, 
    MAX = 66, METERS = 67, NAME = 68, NEAREST = 69, NORMAL = 70, NONE = 71, 
    NOT = 72, OBSTACLE = 73, OCCUR = 74, OCCURRED = 75, OCCURRING = 76, 
    OF = 77, ON = 78, OR = 79, PEDESTRIAN = 80, PEDESTRIANS = 81, POINTS = 82, 
    POSSIBLE = 83, POSITION = 84, RADIUS = 85, RANDOM = 86, REQUIRED = 87, 
    RECTANGLE = 88, RIGHT = 89, RESPONSE = 90, ROTATION = 91, SCALE = 92, 
    SELF = 93, SELECT = 94, SELECTOR = 95, SET = 96, SECOND = 97, SECONDS = 98, 
    STATUS = 99, STARTING = 100, SLOWER = 101, SHAPE = 102, STATES = 103, 
    START = 104, STATE = 105, STARTS = 106, SPEED = 107, SUBTRACT = 108, 
    STIMULUS = 109, TARGET = 110, TO = 111, TOP = 112, THE = 113, THAT = 114, 
    THEN = 115, THEIR = 116, THERES = 117, TYPES = 118, TYPE = 119, UNCONDITIONALLY = 120, 
    VALUE = 121, VELOCITY = 122, WHEN = 123, WHILE = 124, WHOSE = 125, WIDTH = 126, 
    WILL = 127, WITH = 128, WITHIN = 129, ID = 130, NUMBER = 131, FLOAT = 132
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

