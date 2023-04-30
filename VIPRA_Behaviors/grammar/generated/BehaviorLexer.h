
// Generated from Behavior.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  BehaviorLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, COMMENT = 9, LINE_COMMENT = 10, WS = 11, COMMA = 12, COLON = 13, 
    STATE = 14, ACTION = 15, PARAMETER = 16, EVNT = 17, OBJECT = 18, AFTER = 19, 
    AND = 20, ALWAYS = 21, AN = 22, ARE = 23, AROUND = 24, BEHIND = 25, 
    CONSIDER = 26, DIRECTION = 27, END = 28, ENDS = 29, ENVIRONMENT = 30, 
    EVENT = 31, EXACTLY = 32, EVERY = 33, EVERYONE = 34, FASTER = 35, FROM = 36, 
    FRONT = 37, GIVEN = 38, HAS = 39, IN = 40, IS = 41, METERS = 42, NORMAL = 43, 
    OBSTACLE = 44, OCCUR = 45, OCCURRED = 46, OCCURRING = 47, OF = 48, OR = 49, 
    PEDESTRIAN = 50, PEDESTRIANS = 51, POSSIBLE = 52, RANDOM = 53, REQUIRED = 54, 
    SECONDS = 55, SLOWER = 56, STATES = 57, STARTS = 58, SPEED = 59, THE = 60, 
    THAT = 61, THEN = 62, THEIR = 63, TYPES = 64, WHEN = 65, WHILE = 66, 
    WILL = 67, WITHIN = 68, ID = 69, NUMBER = 70, FLOAT = 71
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

