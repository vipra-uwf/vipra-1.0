
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
    EVENT = 31, EXACTLY = 32, EVERYONE = 33, FASTER = 34, FROM = 35, FRONT = 36, 
    GIVEN = 37, HAS = 38, IN = 39, IS = 40, METERS = 41, NORMAL = 42, OBSTACLE = 43, 
    OCCUR = 44, OCCURRED = 45, OCCURRING = 46, OF = 47, OR = 48, PEDESTRIAN = 49, 
    PEDESTRIANS = 50, POSSIBLE = 51, RANDOM = 52, SECONDS = 53, SLOWER = 54, 
    STATES = 55, STARTS = 56, SPEED = 57, THE = 58, THEN = 59, THEIR = 60, 
    TYPES = 61, WHEN = 62, WHILE = 63, WILL = 64, WITHIN = 65, ID = 66, 
    NUMBER = 67, FLOAT = 68
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

