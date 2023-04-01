
// Generated from Behavior.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, COMMENT = 9, LINE_COMMENT = 10, WS = 11, COMMA = 12, COLON = 13, 
    STATE = 14, ACTION = 15, ATTRIBUTE = 16, PARAMETER = 17, EVNT = 18, 
    OBJECT = 19, AFTER = 20, AND = 21, ALWAYS = 22, AN = 23, ARE = 24, AROUND = 25, 
    BEHIND = 26, CONSIDER = 27, DIRECTION = 28, END = 29, ENDS = 30, ENVIRONMENT = 31, 
    EVENT = 32, EXACLTY = 33, EVERYONE = 34, FASTER = 35, FROM = 36, FRONT = 37, 
    GIVEN = 38, HAS = 39, IN = 40, IS = 41, METERS = 42, NORMAL = 43, OBSTACLE = 44, 
    OCCUR = 45, OCCURRED = 46, OCCURRING = 47, OF = 48, OR = 49, PEDESTRIAN = 50, 
    PEDESTRIANS = 51, POSSIBLE = 52, RANDOM = 53, SECONDS = 54, SLOWER = 55, 
    STATES = 56, STARTS = 57, SPEED = 58, THE = 59, THEN = 60, THEIR = 61, 
    WHEN = 62, WHILE = 63, WILL = 64, WITHIN = 65, ID = 66, FLOAT = 67, 
    NUMBER = 68
  };

  BehaviorLexer(antlr4::CharStream *input);
  ~BehaviorLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

