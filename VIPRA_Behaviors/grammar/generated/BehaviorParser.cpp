
// Generated from Behavior.g4 by ANTLR 4.12.0


#include "BehaviorVisitor.h"

#include "BehaviorParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct BehaviorParserStaticData final {
  BehaviorParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  BehaviorParserStaticData(const BehaviorParserStaticData&) = delete;
  BehaviorParserStaticData(BehaviorParserStaticData&&) = delete;
  BehaviorParserStaticData& operator=(const BehaviorParserStaticData&) = delete;
  BehaviorParserStaticData& operator=(BehaviorParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag behaviorParserOnceFlag;
BehaviorParserStaticData *behaviorParserStaticData = nullptr;

void behaviorParserInitialize() {
  assert(behaviorParserStaticData == nullptr);
  auto staticData = std::make_unique<BehaviorParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "event", "event_Single", "event_Lasting", 
      "condition", "connector", "or_Connector", "and_Connector", "sub_condition", 
      "condition_Time_Elapsed_From_Event", "condition_Event_Occurred", "condition_Event_Occurring", 
      "condition_Event_One_Time", "value_number", "number_random", "random_number", 
      "random_float", "direction", "dir", "direction_of", "infront", "behind", 
      "around", "object", "ped_Selector", "selector", "selector_Percent", 
      "selector_Exactly_N_Random", "selector_Everyone", "selector_Area", 
      "id_list", "action", "conditional_action", "un_conditional_action", 
      "sub_action", "action_atom", "action_Stop", "action_atom_Percent_Walk_Speed", 
      "action_Push", "action_Be", "declaration", "decl_Ped", "decl_Ped_State", 
      "decl_Env_State"
    },
    std::vector<std::string>{
      "", "'.'", "'+'", "'%'", "'@stop'", "'@walk'", "'x'", "'@push'", "'@be set to'", 
      "", "", "", "','", "':'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "COMMENT", "LINE_COMMENT", "WS", 
      "COMMA", "COLON", "STATE", "ACTION", "PARAMETER", "EVNT", "OBJECT", 
      "AN", "AT", "AND", "ARE", "AFTER", "ALWAYS", "AROUND", "BEHIND", "CONSIDER", 
      "DECIMAL", "DIRECTION", "END", "ENDS", "ENVIRONMENT", "EVENT", "EXACTLY", 
      "EVERY", "EVERYONE", "FASTER", "FROM", "FRONT", "GIVEN", "HAS", "IN", 
      "INTEGER", "IS", "METERS", "NORMAL", "OBSTACLE", "OCCUR", "OCCURRED", 
      "OCCURRING", "OF", "OR", "PEDESTRIAN", "PEDESTRIANS", "POSSIBLE", 
      "RANDOM", "REQUIRED", "SECONDS", "SLOWER", "STATES", "STARTS", "SPEED", 
      "TO", "THE", "THAT", "THEN", "THEIR", "TYPES", "VALUE", "WHEN", "WHILE", 
      "WILL", "WITHIN", "ID", "NUMBER", "FLOAT", "LOC", "POINTX", "POINTY"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,79,421,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,1,0,1,0,1,0,4,0,94,8,0,11,0,12,0,95,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,110,8,1,1,2,1,2,3,2,114,8,2,
  	1,3,1,3,1,3,3,3,119,8,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,128,8,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,5,5,139,8,5,10,5,12,5,142,9,5,1,6,1,6,3,
  	6,146,8,6,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,1,9,3,9,158,8,9,1,10,1,
  	10,1,10,1,10,1,10,3,10,165,8,10,1,10,1,10,3,10,169,8,10,1,11,1,11,3,11,
  	173,8,11,1,11,1,11,3,11,177,8,11,1,11,1,11,1,11,1,12,1,12,3,12,184,8,
  	12,1,12,1,12,3,12,188,8,12,1,12,1,12,1,12,1,13,1,13,3,13,195,8,13,1,13,
  	1,13,3,13,199,8,13,1,13,1,13,1,14,1,14,1,14,3,14,206,8,14,1,15,1,15,3,
  	15,210,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,3,19,233,8,19,1,20,1,
  	20,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,1,
  	24,1,24,3,24,252,8,24,1,25,1,25,3,25,256,8,25,1,25,1,25,1,25,1,25,3,25,
  	262,8,25,1,25,1,25,1,25,1,25,3,25,268,8,25,1,25,1,25,1,25,3,25,273,8,
  	25,1,25,1,25,3,25,277,8,25,1,26,1,26,1,26,1,26,3,26,283,8,26,1,27,1,27,
  	1,27,1,27,1,28,1,28,1,28,1,28,1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,30,
  	1,30,1,31,1,31,3,31,304,8,31,1,31,3,31,307,8,31,1,31,3,31,310,8,31,1,
  	31,5,31,313,8,31,10,31,12,31,316,9,31,1,32,1,32,3,32,320,8,32,1,33,1,
  	33,1,33,1,33,1,33,1,33,1,34,1,34,1,34,1,34,1,34,1,34,1,35,1,35,1,35,5,
  	35,337,8,35,10,35,12,35,340,9,35,1,36,1,36,1,36,1,36,3,36,346,8,36,1,
  	37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,
  	40,1,41,1,41,1,41,1,41,3,41,367,8,41,1,42,1,42,1,42,1,42,3,42,373,8,42,
  	1,42,3,42,376,8,42,1,42,3,42,379,8,42,1,42,5,42,382,8,42,10,42,12,42,
  	385,9,42,1,43,1,43,1,43,1,43,1,43,1,43,3,43,393,8,43,1,43,3,43,396,8,
  	43,1,43,5,43,399,8,43,10,43,12,43,402,9,43,1,44,1,44,1,44,1,44,1,44,1,
  	44,3,44,410,8,44,1,44,3,44,413,8,44,1,44,5,44,416,8,44,10,44,12,44,419,
  	9,44,1,44,0,0,45,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,
  	38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,
  	84,86,88,0,5,2,0,19,19,64,64,2,0,19,19,66,66,2,0,31,31,61,61,2,0,53,54,
  	74,74,2,0,22,22,44,44,433,0,90,1,0,0,0,2,109,1,0,0,0,4,113,1,0,0,0,6,
  	115,1,0,0,0,8,124,1,0,0,0,10,136,1,0,0,0,12,145,1,0,0,0,14,147,1,0,0,
  	0,16,150,1,0,0,0,18,157,1,0,0,0,20,159,1,0,0,0,22,170,1,0,0,0,24,181,
  	1,0,0,0,26,192,1,0,0,0,28,205,1,0,0,0,30,209,1,0,0,0,32,211,1,0,0,0,34,
  	217,1,0,0,0,36,223,1,0,0,0,38,232,1,0,0,0,40,234,1,0,0,0,42,239,1,0,0,
  	0,44,242,1,0,0,0,46,244,1,0,0,0,48,251,1,0,0,0,50,276,1,0,0,0,52,282,
  	1,0,0,0,54,284,1,0,0,0,56,288,1,0,0,0,58,292,1,0,0,0,60,294,1,0,0,0,62,
  	301,1,0,0,0,64,319,1,0,0,0,66,321,1,0,0,0,68,327,1,0,0,0,70,333,1,0,0,
  	0,72,345,1,0,0,0,74,347,1,0,0,0,76,349,1,0,0,0,78,356,1,0,0,0,80,359,
  	1,0,0,0,82,366,1,0,0,0,84,368,1,0,0,0,86,386,1,0,0,0,88,403,1,0,0,0,90,
  	91,3,84,42,0,91,93,5,1,0,0,92,94,3,2,1,0,93,92,1,0,0,0,94,95,1,0,0,0,
  	95,93,1,0,0,0,95,96,1,0,0,0,96,1,1,0,0,0,97,98,3,4,2,0,98,99,5,1,0,0,
  	99,110,1,0,0,0,100,101,3,82,41,0,101,102,5,1,0,0,102,110,1,0,0,0,103,
  	104,3,50,25,0,104,105,5,1,0,0,105,110,1,0,0,0,106,107,3,64,32,0,107,108,
  	5,1,0,0,108,110,1,0,0,0,109,97,1,0,0,0,109,100,1,0,0,0,109,103,1,0,0,
  	0,109,106,1,0,0,0,110,3,1,0,0,0,111,114,3,6,3,0,112,114,3,8,4,0,113,111,
  	1,0,0,0,113,112,1,0,0,0,114,5,1,0,0,0,115,116,7,0,0,0,116,118,5,17,0,
  	0,117,119,5,33,0,0,118,117,1,0,0,0,118,119,1,0,0,0,119,120,1,0,0,0,120,
  	121,5,72,0,0,121,122,5,48,0,0,122,123,3,10,5,0,123,7,1,0,0,0,124,125,
  	7,0,0,0,125,127,5,17,0,0,126,128,5,33,0,0,127,126,1,0,0,0,127,128,1,0,
  	0,0,128,129,1,0,0,0,129,130,5,72,0,0,130,131,5,48,0,0,131,132,3,10,5,
  	0,132,133,5,21,0,0,133,134,5,30,0,0,134,135,3,10,5,0,135,9,1,0,0,0,136,
  	140,3,18,9,0,137,139,3,12,6,0,138,137,1,0,0,0,139,142,1,0,0,0,140,138,
  	1,0,0,0,140,141,1,0,0,0,141,11,1,0,0,0,142,140,1,0,0,0,143,146,3,14,7,
  	0,144,146,3,16,8,0,145,143,1,0,0,0,145,144,1,0,0,0,146,13,1,0,0,0,147,
  	148,5,52,0,0,148,149,3,18,9,0,149,15,1,0,0,0,150,151,5,21,0,0,151,152,
  	3,18,9,0,152,17,1,0,0,0,153,158,3,20,10,0,154,158,3,22,11,0,155,158,3,
  	24,12,0,156,158,3,26,13,0,157,153,1,0,0,0,157,154,1,0,0,0,157,155,1,0,
  	0,0,157,156,1,0,0,0,158,19,1,0,0,0,159,160,5,23,0,0,160,161,3,28,14,0,
  	161,162,5,58,0,0,162,164,5,38,0,0,163,165,7,0,0,0,164,163,1,0,0,0,164,
  	165,1,0,0,0,165,166,1,0,0,0,166,168,5,17,0,0,167,169,5,33,0,0,168,167,
  	1,0,0,0,168,169,1,0,0,0,169,21,1,0,0,0,170,172,5,40,0,0,171,173,7,0,0,
  	0,172,171,1,0,0,0,172,173,1,0,0,0,173,174,1,0,0,0,174,176,5,17,0,0,175,
  	177,5,33,0,0,176,175,1,0,0,0,176,177,1,0,0,0,177,178,1,0,0,0,178,179,
  	5,41,0,0,179,180,5,49,0,0,180,23,1,0,0,0,181,183,5,71,0,0,182,184,7,1,
  	0,0,183,182,1,0,0,0,183,184,1,0,0,0,184,185,1,0,0,0,185,187,5,17,0,0,
  	186,188,5,33,0,0,187,186,1,0,0,0,187,188,1,0,0,0,188,189,1,0,0,0,189,
  	190,5,44,0,0,190,191,5,50,0,0,191,25,1,0,0,0,192,194,5,70,0,0,193,195,
  	7,1,0,0,194,193,1,0,0,0,194,195,1,0,0,0,195,196,1,0,0,0,196,198,5,17,
  	0,0,197,199,5,33,0,0,198,197,1,0,0,0,198,199,1,0,0,0,199,200,1,0,0,0,
  	200,201,7,2,0,0,201,27,1,0,0,0,202,206,5,75,0,0,203,206,5,76,0,0,204,
  	206,3,30,15,0,205,202,1,0,0,0,205,203,1,0,0,0,205,204,1,0,0,0,206,29,
  	1,0,0,0,207,210,3,34,17,0,208,210,3,32,16,0,209,207,1,0,0,0,209,208,1,
  	0,0,0,210,31,1,0,0,0,211,212,5,19,0,0,212,213,5,56,0,0,213,214,5,75,0,
  	0,214,215,5,63,0,0,215,216,5,75,0,0,216,33,1,0,0,0,217,218,5,19,0,0,218,
  	219,5,56,0,0,219,220,5,76,0,0,220,221,5,63,0,0,221,222,5,76,0,0,222,35,
  	1,0,0,0,223,224,3,38,19,0,224,225,5,73,0,0,225,226,5,75,0,0,226,227,5,
  	45,0,0,227,37,1,0,0,0,228,233,3,40,20,0,229,233,3,42,21,0,230,233,3,44,
  	22,0,231,233,3,46,23,0,232,228,1,0,0,0,232,229,1,0,0,0,232,230,1,0,0,
  	0,232,231,1,0,0,0,233,39,1,0,0,0,234,235,5,42,0,0,235,236,5,29,0,0,236,
  	237,5,51,0,0,237,238,5,74,0,0,238,41,1,0,0,0,239,240,5,42,0,0,240,241,
  	5,39,0,0,241,43,1,0,0,0,242,243,5,26,0,0,243,45,1,0,0,0,244,245,5,25,
  	0,0,245,47,1,0,0,0,246,247,5,2,0,0,247,252,5,53,0,0,248,249,5,2,0,0,249,
  	252,5,47,0,0,250,252,5,18,0,0,251,246,1,0,0,0,251,248,1,0,0,0,251,250,
  	1,0,0,0,252,49,1,0,0,0,253,254,5,57,0,0,254,256,5,13,0,0,255,253,1,0,
  	0,0,255,256,1,0,0,0,256,257,1,0,0,0,257,258,3,52,26,0,258,259,7,3,0,0,
  	259,261,7,4,0,0,260,262,5,19,0,0,261,260,1,0,0,0,261,262,1,0,0,0,262,
  	263,1,0,0,0,263,264,3,62,31,0,264,277,1,0,0,0,265,266,5,57,0,0,266,268,
  	5,13,0,0,267,265,1,0,0,0,267,268,1,0,0,0,268,269,1,0,0,0,269,270,3,58,
  	29,0,270,272,5,44,0,0,271,273,5,19,0,0,272,271,1,0,0,0,272,273,1,0,0,
  	0,273,274,1,0,0,0,274,275,3,62,31,0,275,277,1,0,0,0,276,255,1,0,0,0,276,
  	267,1,0,0,0,277,51,1,0,0,0,278,283,3,54,27,0,279,283,3,56,28,0,280,283,
  	3,58,29,0,281,283,3,60,30,0,282,278,1,0,0,0,282,279,1,0,0,0,282,280,1,
  	0,0,0,282,281,1,0,0,0,283,53,1,0,0,0,284,285,3,28,14,0,285,286,5,3,0,
  	0,286,287,5,51,0,0,287,55,1,0,0,0,288,289,5,34,0,0,289,290,3,28,14,0,
  	290,291,5,51,0,0,291,57,1,0,0,0,292,293,5,36,0,0,293,59,1,0,0,0,294,295,
  	5,36,0,0,295,296,5,42,0,0,296,297,5,77,0,0,297,298,5,44,0,0,298,299,5,
  	19,0,0,299,300,5,74,0,0,300,61,1,0,0,0,301,314,5,74,0,0,302,304,5,12,
  	0,0,303,302,1,0,0,0,303,304,1,0,0,0,304,306,1,0,0,0,305,307,5,21,0,0,
  	306,305,1,0,0,0,306,307,1,0,0,0,307,309,1,0,0,0,308,310,5,19,0,0,309,
  	308,1,0,0,0,309,310,1,0,0,0,310,311,1,0,0,0,311,313,5,74,0,0,312,303,
  	1,0,0,0,313,316,1,0,0,0,314,312,1,0,0,0,314,315,1,0,0,0,315,63,1,0,0,
  	0,316,314,1,0,0,0,317,320,3,66,33,0,318,320,3,68,34,0,319,317,1,0,0,0,
  	319,318,1,0,0,0,320,65,1,0,0,0,321,322,5,19,0,0,322,323,5,74,0,0,323,
  	324,5,72,0,0,324,325,3,70,35,0,325,326,3,10,5,0,326,67,1,0,0,0,327,328,
  	5,19,0,0,328,329,5,74,0,0,329,330,5,72,0,0,330,331,5,24,0,0,331,332,3,
  	70,35,0,332,69,1,0,0,0,333,338,3,72,36,0,334,335,5,66,0,0,335,337,3,72,
  	36,0,336,334,1,0,0,0,337,340,1,0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,
  	339,71,1,0,0,0,340,338,1,0,0,0,341,346,5,15,0,0,342,346,3,74,37,0,343,
  	346,3,80,40,0,344,346,3,76,38,0,345,341,1,0,0,0,345,342,1,0,0,0,345,343,
  	1,0,0,0,345,344,1,0,0,0,346,73,1,0,0,0,347,348,5,4,0,0,348,75,1,0,0,0,
  	349,350,5,5,0,0,350,351,3,28,14,0,351,352,5,6,0,0,352,353,5,67,0,0,353,
  	354,5,46,0,0,354,355,5,62,0,0,355,77,1,0,0,0,356,357,5,7,0,0,357,358,
  	5,74,0,0,358,79,1,0,0,0,359,360,5,8,0,0,360,361,5,14,0,0,361,81,1,0,0,
  	0,362,367,3,84,42,0,363,367,3,86,43,0,364,367,3,88,44,0,365,367,1,0,0,
  	0,366,362,1,0,0,0,366,363,1,0,0,0,366,364,1,0,0,0,366,365,1,0,0,0,367,
  	83,1,0,0,0,368,369,5,27,0,0,369,370,5,19,0,0,370,383,5,74,0,0,371,373,
  	5,12,0,0,372,371,1,0,0,0,372,373,1,0,0,0,373,375,1,0,0,0,374,376,5,21,
  	0,0,375,374,1,0,0,0,375,376,1,0,0,0,376,378,1,0,0,0,377,379,5,19,0,0,
  	378,377,1,0,0,0,378,379,1,0,0,0,379,380,1,0,0,0,380,382,5,74,0,0,381,
  	372,1,0,0,0,382,385,1,0,0,0,383,381,1,0,0,0,383,384,1,0,0,0,384,85,1,
  	0,0,0,385,383,1,0,0,0,386,387,5,55,0,0,387,388,5,53,0,0,388,389,5,60,
  	0,0,389,390,5,22,0,0,390,400,5,14,0,0,391,393,5,12,0,0,392,391,1,0,0,
  	0,392,393,1,0,0,0,393,395,1,0,0,0,394,396,5,21,0,0,395,394,1,0,0,0,395,
  	396,1,0,0,0,396,397,1,0,0,0,397,399,5,14,0,0,398,392,1,0,0,0,399,402,
  	1,0,0,0,400,398,1,0,0,0,400,401,1,0,0,0,401,87,1,0,0,0,402,400,1,0,0,
  	0,403,404,5,55,0,0,404,405,5,32,0,0,405,406,5,60,0,0,406,407,5,22,0,0,
  	407,417,5,14,0,0,408,410,5,12,0,0,409,408,1,0,0,0,409,410,1,0,0,0,410,
  	412,1,0,0,0,411,413,5,21,0,0,412,411,1,0,0,0,412,413,1,0,0,0,413,414,
  	1,0,0,0,414,416,5,14,0,0,415,409,1,0,0,0,416,419,1,0,0,0,417,415,1,0,
  	0,0,417,418,1,0,0,0,418,89,1,0,0,0,419,417,1,0,0,0,44,95,109,113,118,
  	127,140,145,157,164,168,172,176,183,187,194,198,205,209,232,251,255,261,
  	267,272,276,282,303,306,309,314,319,338,345,366,372,375,378,383,392,395,
  	400,409,412,417
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  behaviorParserStaticData = staticData.release();
}

}

BehaviorParser::BehaviorParser(TokenStream *input) : BehaviorParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

BehaviorParser::BehaviorParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  BehaviorParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *behaviorParserStaticData->atn, behaviorParserStaticData->decisionToDFA, behaviorParserStaticData->sharedContextCache, options);
}

BehaviorParser::~BehaviorParser() {
  delete _interpreter;
}

const atn::ATN& BehaviorParser::getATN() const {
  return *behaviorParserStaticData->atn;
}

std::string BehaviorParser::getGrammarFileName() const {
  return "Behavior.g4";
}

const std::vector<std::string>& BehaviorParser::getRuleNames() const {
  return behaviorParserStaticData->ruleNames;
}

const dfa::Vocabulary& BehaviorParser::getVocabulary() const {
  return behaviorParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView BehaviorParser::getSerializedATN() const {
  return behaviorParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

BehaviorParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Decl_PedContext* BehaviorParser::ProgramContext::decl_Ped() {
  return getRuleContext<BehaviorParser::Decl_PedContext>(0);
}

std::vector<BehaviorParser::StatementContext *> BehaviorParser::ProgramContext::statement() {
  return getRuleContexts<BehaviorParser::StatementContext>();
}

BehaviorParser::StatementContext* BehaviorParser::ProgramContext::statement(size_t i) {
  return getRuleContext<BehaviorParser::StatementContext>(i);
}


size_t BehaviorParser::ProgramContext::getRuleIndex() const {
  return BehaviorParser::RuleProgram;
}


std::any BehaviorParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ProgramContext* BehaviorParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, BehaviorParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    decl_Ped();
    setState(91);
    match(BehaviorParser::T__0);
    setState(93); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(92);
      statement();
      setState(95); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 180144071128907778) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & 6145) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

BehaviorParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::EventContext* BehaviorParser::StatementContext::event() {
  return getRuleContext<BehaviorParser::EventContext>(0);
}

BehaviorParser::DeclarationContext* BehaviorParser::StatementContext::declaration() {
  return getRuleContext<BehaviorParser::DeclarationContext>(0);
}

BehaviorParser::Ped_SelectorContext* BehaviorParser::StatementContext::ped_Selector() {
  return getRuleContext<BehaviorParser::Ped_SelectorContext>(0);
}

BehaviorParser::ActionContext* BehaviorParser::StatementContext::action() {
  return getRuleContext<BehaviorParser::ActionContext>(0);
}


size_t BehaviorParser::StatementContext::getRuleIndex() const {
  return BehaviorParser::RuleStatement;
}


std::any BehaviorParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::StatementContext* BehaviorParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, BehaviorParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      event();
      setState(98);
      match(BehaviorParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      declaration();
      setState(101);
      match(BehaviorParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(103);
      ped_Selector();
      setState(104);
      match(BehaviorParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(106);
      action();
      setState(107);
      match(BehaviorParser::T__0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EventContext ------------------------------------------------------------------

BehaviorParser::EventContext::EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Event_SingleContext* BehaviorParser::EventContext::event_Single() {
  return getRuleContext<BehaviorParser::Event_SingleContext>(0);
}

BehaviorParser::Event_LastingContext* BehaviorParser::EventContext::event_Lasting() {
  return getRuleContext<BehaviorParser::Event_LastingContext>(0);
}


size_t BehaviorParser::EventContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent;
}


std::any BehaviorParser::EventContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::EventContext* BehaviorParser::event() {
  EventContext *_localctx = _tracker.createInstance<EventContext>(_ctx, getState());
  enterRule(_localctx, 4, BehaviorParser::RuleEvent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(111);
      event_Single();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      event_Lasting();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_SingleContext ------------------------------------------------------------------

BehaviorParser::Event_SingleContext::Event_SingleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::OCCUR() {
  return getToken(BehaviorParser::OCCUR, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Event_SingleContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}

tree::TerminalNode* BehaviorParser::Event_SingleContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}


size_t BehaviorParser::Event_SingleContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_Single;
}


std::any BehaviorParser::Event_SingleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_Single(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_SingleContext* BehaviorParser::event_Single() {
  Event_SingleContext *_localctx = _tracker.createInstance<Event_SingleContext>(_ctx, getState());
  enterRule(_localctx, 6, BehaviorParser::RuleEvent_Single);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(116);
    match(BehaviorParser::EVNT);
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(117);
      match(BehaviorParser::EVENT);
    }
    setState(120);
    match(BehaviorParser::WILL);
    setState(121);
    match(BehaviorParser::OCCUR);
    setState(122);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_LastingContext ------------------------------------------------------------------

BehaviorParser::Event_LastingContext::Event_LastingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::OCCUR() {
  return getToken(BehaviorParser::OCCUR, 0);
}

std::vector<BehaviorParser::ConditionContext *> BehaviorParser::Event_LastingContext::condition() {
  return getRuleContexts<BehaviorParser::ConditionContext>();
}

BehaviorParser::ConditionContext* BehaviorParser::Event_LastingContext::condition(size_t i) {
  return getRuleContext<BehaviorParser::ConditionContext>(i);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::END() {
  return getToken(BehaviorParser::END, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}

tree::TerminalNode* BehaviorParser::Event_LastingContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}


size_t BehaviorParser::Event_LastingContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_Lasting;
}


std::any BehaviorParser::Event_LastingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_Lasting(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_LastingContext* BehaviorParser::event_Lasting() {
  Event_LastingContext *_localctx = _tracker.createInstance<Event_LastingContext>(_ctx, getState());
  enterRule(_localctx, 8, BehaviorParser::RuleEvent_Lasting);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(125);
    match(BehaviorParser::EVNT);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(126);
      match(BehaviorParser::EVENT);
    }
    setState(129);
    match(BehaviorParser::WILL);
    setState(130);
    match(BehaviorParser::OCCUR);
    setState(131);
    condition();
    setState(132);
    match(BehaviorParser::AND);
    setState(133);
    match(BehaviorParser::END);
    setState(134);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

BehaviorParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Sub_conditionContext* BehaviorParser::ConditionContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}

std::vector<BehaviorParser::ConnectorContext *> BehaviorParser::ConditionContext::connector() {
  return getRuleContexts<BehaviorParser::ConnectorContext>();
}

BehaviorParser::ConnectorContext* BehaviorParser::ConditionContext::connector(size_t i) {
  return getRuleContext<BehaviorParser::ConnectorContext>(i);
}


size_t BehaviorParser::ConditionContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition;
}


std::any BehaviorParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ConditionContext* BehaviorParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(136);
    sub_condition();
    setState(140);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(137);
        connector(); 
      }
      setState(142);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConnectorContext ------------------------------------------------------------------

BehaviorParser::ConnectorContext::ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Or_ConnectorContext* BehaviorParser::ConnectorContext::or_Connector() {
  return getRuleContext<BehaviorParser::Or_ConnectorContext>(0);
}

BehaviorParser::And_ConnectorContext* BehaviorParser::ConnectorContext::and_Connector() {
  return getRuleContext<BehaviorParser::And_ConnectorContext>(0);
}


size_t BehaviorParser::ConnectorContext::getRuleIndex() const {
  return BehaviorParser::RuleConnector;
}


std::any BehaviorParser::ConnectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitConnector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ConnectorContext* BehaviorParser::connector() {
  ConnectorContext *_localctx = _tracker.createInstance<ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 12, BehaviorParser::RuleConnector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(143);
        or_Connector();
        break;
      }

      case BehaviorParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(144);
        and_Connector();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Or_ConnectorContext ------------------------------------------------------------------

BehaviorParser::Or_ConnectorContext::Or_ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Or_ConnectorContext::OR() {
  return getToken(BehaviorParser::OR, 0);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::Or_ConnectorContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}


size_t BehaviorParser::Or_ConnectorContext::getRuleIndex() const {
  return BehaviorParser::RuleOr_Connector;
}


std::any BehaviorParser::Or_ConnectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitOr_Connector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Or_ConnectorContext* BehaviorParser::or_Connector() {
  Or_ConnectorContext *_localctx = _tracker.createInstance<Or_ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 14, BehaviorParser::RuleOr_Connector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    match(BehaviorParser::OR);
    setState(148);
    sub_condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- And_ConnectorContext ------------------------------------------------------------------

BehaviorParser::And_ConnectorContext::And_ConnectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::And_ConnectorContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::And_ConnectorContext::sub_condition() {
  return getRuleContext<BehaviorParser::Sub_conditionContext>(0);
}


size_t BehaviorParser::And_ConnectorContext::getRuleIndex() const {
  return BehaviorParser::RuleAnd_Connector;
}


std::any BehaviorParser::And_ConnectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAnd_Connector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::And_ConnectorContext* BehaviorParser::and_Connector() {
  And_ConnectorContext *_localctx = _tracker.createInstance<And_ConnectorContext>(_ctx, getState());
  enterRule(_localctx, 16, BehaviorParser::RuleAnd_Connector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(BehaviorParser::AND);
    setState(151);
    sub_condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sub_conditionContext ------------------------------------------------------------------

BehaviorParser::Sub_conditionContext::Sub_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Condition_Time_Elapsed_From_EventContext* BehaviorParser::Sub_conditionContext::condition_Time_Elapsed_From_Event() {
  return getRuleContext<BehaviorParser::Condition_Time_Elapsed_From_EventContext>(0);
}

BehaviorParser::Condition_Event_OccurredContext* BehaviorParser::Sub_conditionContext::condition_Event_Occurred() {
  return getRuleContext<BehaviorParser::Condition_Event_OccurredContext>(0);
}

BehaviorParser::Condition_Event_OccurringContext* BehaviorParser::Sub_conditionContext::condition_Event_Occurring() {
  return getRuleContext<BehaviorParser::Condition_Event_OccurringContext>(0);
}

BehaviorParser::Condition_Event_One_TimeContext* BehaviorParser::Sub_conditionContext::condition_Event_One_Time() {
  return getRuleContext<BehaviorParser::Condition_Event_One_TimeContext>(0);
}


size_t BehaviorParser::Sub_conditionContext::getRuleIndex() const {
  return BehaviorParser::RuleSub_condition;
}


std::any BehaviorParser::Sub_conditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSub_condition(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Sub_conditionContext* BehaviorParser::sub_condition() {
  Sub_conditionContext *_localctx = _tracker.createInstance<Sub_conditionContext>(_ctx, getState());
  enterRule(_localctx, 18, BehaviorParser::RuleSub_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::AFTER: {
        enterOuterAlt(_localctx, 1);
        setState(153);
        condition_Time_Elapsed_From_Event();
        break;
      }

      case BehaviorParser::GIVEN: {
        enterOuterAlt(_localctx, 2);
        setState(154);
        condition_Event_Occurred();
        break;
      }

      case BehaviorParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(155);
        condition_Event_Occurring();
        break;
      }

      case BehaviorParser::WHEN: {
        enterOuterAlt(_localctx, 4);
        setState(156);
        condition_Event_One_Time();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Time_Elapsed_From_EventContext ------------------------------------------------------------------

BehaviorParser::Condition_Time_Elapsed_From_EventContext::Condition_Time_Elapsed_From_EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::AFTER() {
  return getToken(BehaviorParser::AFTER, 0);
}

BehaviorParser::Value_numberContext* BehaviorParser::Condition_Time_Elapsed_From_EventContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::SECONDS() {
  return getToken(BehaviorParser::SECONDS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::FROM() {
  return getToken(BehaviorParser::FROM, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Time_Elapsed_From_EventContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}


size_t BehaviorParser::Condition_Time_Elapsed_From_EventContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Time_Elapsed_From_Event;
}


std::any BehaviorParser::Condition_Time_Elapsed_From_EventContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Time_Elapsed_From_Event(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Time_Elapsed_From_EventContext* BehaviorParser::condition_Time_Elapsed_From_Event() {
  Condition_Time_Elapsed_From_EventContext *_localctx = _tracker.createInstance<Condition_Time_Elapsed_From_EventContext>(_ctx, getState());
  enterRule(_localctx, 20, BehaviorParser::RuleCondition_Time_Elapsed_From_Event);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(BehaviorParser::AFTER);
    setState(160);
    value_number();
    setState(161);
    match(BehaviorParser::SECONDS);
    setState(162);
    match(BehaviorParser::FROM);
    setState(164);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(163);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(166);
    match(BehaviorParser::EVNT);
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(167);
      match(BehaviorParser::EVENT);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_OccurredContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_OccurredContext::Condition_Event_OccurredContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::GIVEN() {
  return getToken(BehaviorParser::GIVEN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::HAS() {
  return getToken(BehaviorParser::HAS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::OCCURRED() {
  return getToken(BehaviorParser::OCCURRED, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::THE() {
  return getToken(BehaviorParser::THE, 0);
}


size_t BehaviorParser::Condition_Event_OccurredContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_Occurred;
}


std::any BehaviorParser::Condition_Event_OccurredContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_Occurred(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_OccurredContext* BehaviorParser::condition_Event_Occurred() {
  Condition_Event_OccurredContext *_localctx = _tracker.createInstance<Condition_Event_OccurredContext>(_ctx, getState());
  enterRule(_localctx, 22, BehaviorParser::RuleCondition_Event_Occurred);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    match(BehaviorParser::GIVEN);
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(171);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(174);
    match(BehaviorParser::EVNT);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(175);
      match(BehaviorParser::EVENT);
    }
    setState(178);
    match(BehaviorParser::HAS);
    setState(179);
    match(BehaviorParser::OCCURRED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_OccurringContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_OccurringContext::Condition_Event_OccurringContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::WHILE() {
  return getToken(BehaviorParser::WHILE, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::IS() {
  return getToken(BehaviorParser::IS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::OCCURRING() {
  return getToken(BehaviorParser::OCCURRING, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::THEN() {
  return getToken(BehaviorParser::THEN, 0);
}


size_t BehaviorParser::Condition_Event_OccurringContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_Occurring;
}


std::any BehaviorParser::Condition_Event_OccurringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_Occurring(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_OccurringContext* BehaviorParser::condition_Event_Occurring() {
  Condition_Event_OccurringContext *_localctx = _tracker.createInstance<Condition_Event_OccurringContext>(_ctx, getState());
  enterRule(_localctx, 24, BehaviorParser::RuleCondition_Event_Occurring);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(BehaviorParser::WHILE);
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THEN) {
      setState(182);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THEN)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(185);
    match(BehaviorParser::EVNT);
    setState(187);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(186);
      match(BehaviorParser::EVENT);
    }
    setState(189);
    match(BehaviorParser::IS);
    setState(190);
    match(BehaviorParser::OCCURRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_One_TimeContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_One_TimeContext::Condition_Event_One_TimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::WHEN() {
  return getToken(BehaviorParser::WHEN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::ENDS() {
  return getToken(BehaviorParser::ENDS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::STARTS() {
  return getToken(BehaviorParser::STARTS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_One_TimeContext::THEN() {
  return getToken(BehaviorParser::THEN, 0);
}


size_t BehaviorParser::Condition_Event_One_TimeContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_One_Time;
}


std::any BehaviorParser::Condition_Event_One_TimeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_One_Time(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_One_TimeContext* BehaviorParser::condition_Event_One_Time() {
  Condition_Event_One_TimeContext *_localctx = _tracker.createInstance<Condition_Event_One_TimeContext>(_ctx, getState());
  enterRule(_localctx, 26, BehaviorParser::RuleCondition_Event_One_Time);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(BehaviorParser::WHEN);
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THEN) {
      setState(193);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::AN

      || _la == BehaviorParser::THEN)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(196);
    match(BehaviorParser::EVNT);
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(197);
      match(BehaviorParser::EVENT);
    }
    setState(200);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::ENDS

    || _la == BehaviorParser::STARTS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_numberContext ------------------------------------------------------------------

BehaviorParser::Value_numberContext::Value_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Value_numberContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Value_numberContext::FLOAT() {
  return getToken(BehaviorParser::FLOAT, 0);
}

BehaviorParser::Number_randomContext* BehaviorParser::Value_numberContext::number_random() {
  return getRuleContext<BehaviorParser::Number_randomContext>(0);
}


size_t BehaviorParser::Value_numberContext::getRuleIndex() const {
  return BehaviorParser::RuleValue_number;
}


std::any BehaviorParser::Value_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitValue_number(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Value_numberContext* BehaviorParser::value_number() {
  Value_numberContext *_localctx = _tracker.createInstance<Value_numberContext>(_ctx, getState());
  enterRule(_localctx, 28, BehaviorParser::RuleValue_number);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(205);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(202);
        match(BehaviorParser::NUMBER);
        break;
      }

      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(203);
        match(BehaviorParser::FLOAT);
        break;
      }

      case BehaviorParser::AN: {
        enterOuterAlt(_localctx, 3);
        setState(204);
        number_random();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_randomContext ------------------------------------------------------------------

BehaviorParser::Number_randomContext::Number_randomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Random_floatContext* BehaviorParser::Number_randomContext::random_float() {
  return getRuleContext<BehaviorParser::Random_floatContext>(0);
}

BehaviorParser::Random_numberContext* BehaviorParser::Number_randomContext::random_number() {
  return getRuleContext<BehaviorParser::Random_numberContext>(0);
}


size_t BehaviorParser::Number_randomContext::getRuleIndex() const {
  return BehaviorParser::RuleNumber_random;
}


std::any BehaviorParser::Number_randomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitNumber_random(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Number_randomContext* BehaviorParser::number_random() {
  Number_randomContext *_localctx = _tracker.createInstance<Number_randomContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorParser::RuleNumber_random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(207);
      random_float();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(208);
      random_number();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Random_numberContext ------------------------------------------------------------------

BehaviorParser::Random_numberContext::Random_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Random_numberContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Random_numberContext::RANDOM() {
  return getToken(BehaviorParser::RANDOM, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Random_numberContext::NUMBER() {
  return getTokens(BehaviorParser::NUMBER);
}

tree::TerminalNode* BehaviorParser::Random_numberContext::NUMBER(size_t i) {
  return getToken(BehaviorParser::NUMBER, i);
}

tree::TerminalNode* BehaviorParser::Random_numberContext::TO() {
  return getToken(BehaviorParser::TO, 0);
}


size_t BehaviorParser::Random_numberContext::getRuleIndex() const {
  return BehaviorParser::RuleRandom_number;
}


std::any BehaviorParser::Random_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitRandom_number(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Random_numberContext* BehaviorParser::random_number() {
  Random_numberContext *_localctx = _tracker.createInstance<Random_numberContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorParser::RuleRandom_number);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(BehaviorParser::AN);
    setState(212);
    match(BehaviorParser::RANDOM);
    setState(213);
    match(BehaviorParser::NUMBER);
    setState(214);
    match(BehaviorParser::TO);
    setState(215);
    match(BehaviorParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Random_floatContext ------------------------------------------------------------------

BehaviorParser::Random_floatContext::Random_floatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Random_floatContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Random_floatContext::RANDOM() {
  return getToken(BehaviorParser::RANDOM, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Random_floatContext::FLOAT() {
  return getTokens(BehaviorParser::FLOAT);
}

tree::TerminalNode* BehaviorParser::Random_floatContext::FLOAT(size_t i) {
  return getToken(BehaviorParser::FLOAT, i);
}

tree::TerminalNode* BehaviorParser::Random_floatContext::TO() {
  return getToken(BehaviorParser::TO, 0);
}


size_t BehaviorParser::Random_floatContext::getRuleIndex() const {
  return BehaviorParser::RuleRandom_float;
}


std::any BehaviorParser::Random_floatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitRandom_float(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Random_floatContext* BehaviorParser::random_float() {
  Random_floatContext *_localctx = _tracker.createInstance<Random_floatContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorParser::RuleRandom_float);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(BehaviorParser::AN);
    setState(218);
    match(BehaviorParser::RANDOM);
    setState(219);
    match(BehaviorParser::FLOAT);
    setState(220);
    match(BehaviorParser::TO);
    setState(221);
    match(BehaviorParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectionContext ------------------------------------------------------------------

BehaviorParser::DirectionContext::DirectionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::DirContext* BehaviorParser::DirectionContext::dir() {
  return getRuleContext<BehaviorParser::DirContext>(0);
}

tree::TerminalNode* BehaviorParser::DirectionContext::WITHIN() {
  return getToken(BehaviorParser::WITHIN, 0);
}

tree::TerminalNode* BehaviorParser::DirectionContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::DirectionContext::METERS() {
  return getToken(BehaviorParser::METERS, 0);
}


size_t BehaviorParser::DirectionContext::getRuleIndex() const {
  return BehaviorParser::RuleDirection;
}


std::any BehaviorParser::DirectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDirection(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DirectionContext* BehaviorParser::direction() {
  DirectionContext *_localctx = _tracker.createInstance<DirectionContext>(_ctx, getState());
  enterRule(_localctx, 36, BehaviorParser::RuleDirection);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    dir();
    setState(224);
    match(BehaviorParser::WITHIN);
    setState(225);
    match(BehaviorParser::NUMBER);
    setState(226);
    match(BehaviorParser::METERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirContext ------------------------------------------------------------------

BehaviorParser::DirContext::DirContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Direction_ofContext* BehaviorParser::DirContext::direction_of() {
  return getRuleContext<BehaviorParser::Direction_ofContext>(0);
}

BehaviorParser::InfrontContext* BehaviorParser::DirContext::infront() {
  return getRuleContext<BehaviorParser::InfrontContext>(0);
}

BehaviorParser::BehindContext* BehaviorParser::DirContext::behind() {
  return getRuleContext<BehaviorParser::BehindContext>(0);
}

BehaviorParser::AroundContext* BehaviorParser::DirContext::around() {
  return getRuleContext<BehaviorParser::AroundContext>(0);
}


size_t BehaviorParser::DirContext::getRuleIndex() const {
  return BehaviorParser::RuleDir;
}


std::any BehaviorParser::DirContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDir(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DirContext* BehaviorParser::dir() {
  DirContext *_localctx = _tracker.createInstance<DirContext>(_ctx, getState());
  enterRule(_localctx, 38, BehaviorParser::RuleDir);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(232);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(228);
      direction_of();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(229);
      infront();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(230);
      behind();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(231);
      around();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Direction_ofContext ------------------------------------------------------------------

BehaviorParser::Direction_ofContext::Direction_ofContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::IN() {
  return getToken(BehaviorParser::IN, 0);
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::DIRECTION() {
  return getToken(BehaviorParser::DIRECTION, 0);
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::OF() {
  return getToken(BehaviorParser::OF, 0);
}

tree::TerminalNode* BehaviorParser::Direction_ofContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Direction_ofContext::getRuleIndex() const {
  return BehaviorParser::RuleDirection_of;
}


std::any BehaviorParser::Direction_ofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDirection_of(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Direction_ofContext* BehaviorParser::direction_of() {
  Direction_ofContext *_localctx = _tracker.createInstance<Direction_ofContext>(_ctx, getState());
  enterRule(_localctx, 40, BehaviorParser::RuleDirection_of);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(BehaviorParser::IN);
    setState(235);
    match(BehaviorParser::DIRECTION);
    setState(236);
    match(BehaviorParser::OF);
    setState(237);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InfrontContext ------------------------------------------------------------------

BehaviorParser::InfrontContext::InfrontContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::InfrontContext::IN() {
  return getToken(BehaviorParser::IN, 0);
}

tree::TerminalNode* BehaviorParser::InfrontContext::FRONT() {
  return getToken(BehaviorParser::FRONT, 0);
}


size_t BehaviorParser::InfrontContext::getRuleIndex() const {
  return BehaviorParser::RuleInfront;
}


std::any BehaviorParser::InfrontContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitInfront(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::InfrontContext* BehaviorParser::infront() {
  InfrontContext *_localctx = _tracker.createInstance<InfrontContext>(_ctx, getState());
  enterRule(_localctx, 42, BehaviorParser::RuleInfront);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(BehaviorParser::IN);
    setState(240);
    match(BehaviorParser::FRONT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BehindContext ------------------------------------------------------------------

BehaviorParser::BehindContext::BehindContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::BehindContext::BEHIND() {
  return getToken(BehaviorParser::BEHIND, 0);
}


size_t BehaviorParser::BehindContext::getRuleIndex() const {
  return BehaviorParser::RuleBehind;
}


std::any BehaviorParser::BehindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitBehind(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::BehindContext* BehaviorParser::behind() {
  BehindContext *_localctx = _tracker.createInstance<BehindContext>(_ctx, getState());
  enterRule(_localctx, 44, BehaviorParser::RuleBehind);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    match(BehaviorParser::BEHIND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AroundContext ------------------------------------------------------------------

BehaviorParser::AroundContext::AroundContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::AroundContext::AROUND() {
  return getToken(BehaviorParser::AROUND, 0);
}


size_t BehaviorParser::AroundContext::getRuleIndex() const {
  return BehaviorParser::RuleAround;
}


std::any BehaviorParser::AroundContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAround(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::AroundContext* BehaviorParser::around() {
  AroundContext *_localctx = _tracker.createInstance<AroundContext>(_ctx, getState());
  enterRule(_localctx, 46, BehaviorParser::RuleAround);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(BehaviorParser::AROUND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectContext ------------------------------------------------------------------

BehaviorParser::ObjectContext::ObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::ObjectContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::ObjectContext::OBSTACLE() {
  return getToken(BehaviorParser::OBSTACLE, 0);
}

tree::TerminalNode* BehaviorParser::ObjectContext::OBJECT() {
  return getToken(BehaviorParser::OBJECT, 0);
}


size_t BehaviorParser::ObjectContext::getRuleIndex() const {
  return BehaviorParser::RuleObject;
}


std::any BehaviorParser::ObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitObject(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ObjectContext* BehaviorParser::object() {
  ObjectContext *_localctx = _tracker.createInstance<ObjectContext>(_ctx, getState());
  enterRule(_localctx, 48, BehaviorParser::RuleObject);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(251);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(246);
      match(BehaviorParser::T__1);
      setState(247);
      match(BehaviorParser::PEDESTRIAN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(248);
      match(BehaviorParser::T__1);
      setState(249);
      match(BehaviorParser::OBSTACLE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(250);
      match(BehaviorParser::OBJECT);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ped_SelectorContext ------------------------------------------------------------------

BehaviorParser::Ped_SelectorContext::Ped_SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::SelectorContext* BehaviorParser::Ped_SelectorContext::selector() {
  return getRuleContext<BehaviorParser::SelectorContext>(0);
}

BehaviorParser::Id_listContext* BehaviorParser::Ped_SelectorContext::id_list() {
  return getRuleContext<BehaviorParser::Id_listContext>(0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::PEDESTRIANS() {
  return getToken(BehaviorParser::PEDESTRIANS, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::ARE() {
  return getToken(BehaviorParser::ARE, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::IS() {
  return getToken(BehaviorParser::IS, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::REQUIRED() {
  return getToken(BehaviorParser::REQUIRED, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

BehaviorParser::Selector_EveryoneContext* BehaviorParser::Ped_SelectorContext::selector_Everyone() {
  return getRuleContext<BehaviorParser::Selector_EveryoneContext>(0);
}


size_t BehaviorParser::Ped_SelectorContext::getRuleIndex() const {
  return BehaviorParser::RulePed_Selector;
}


std::any BehaviorParser::Ped_SelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitPed_Selector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Ped_SelectorContext* BehaviorParser::ped_Selector() {
  Ped_SelectorContext *_localctx = _tracker.createInstance<Ped_SelectorContext>(_ctx, getState());
  enterRule(_localctx, 50, BehaviorParser::RulePed_Selector);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(255);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::REQUIRED) {
        setState(253);
        match(BehaviorParser::REQUIRED);
        setState(254);
        match(BehaviorParser::COLON);
      }
      setState(257);
      selector();
      setState(258);
      _la = _input->LA(1);
      if (!(((((_la - 53) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 53)) & 2097155) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(259);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::ARE

      || _la == BehaviorParser::IS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(260);
        match(BehaviorParser::AN);
      }
      setState(263);
      id_list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::REQUIRED) {
        setState(265);
        match(BehaviorParser::REQUIRED);
        setState(266);
        match(BehaviorParser::COLON);
      }
      setState(269);
      selector_Everyone();
      setState(270);
      match(BehaviorParser::IS);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(271);
        match(BehaviorParser::AN);
      }
      setState(274);
      id_list();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectorContext ------------------------------------------------------------------

BehaviorParser::SelectorContext::SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Selector_PercentContext* BehaviorParser::SelectorContext::selector_Percent() {
  return getRuleContext<BehaviorParser::Selector_PercentContext>(0);
}

BehaviorParser::Selector_Exactly_N_RandomContext* BehaviorParser::SelectorContext::selector_Exactly_N_Random() {
  return getRuleContext<BehaviorParser::Selector_Exactly_N_RandomContext>(0);
}

BehaviorParser::Selector_EveryoneContext* BehaviorParser::SelectorContext::selector_Everyone() {
  return getRuleContext<BehaviorParser::Selector_EveryoneContext>(0);
}

BehaviorParser::Selector_AreaContext* BehaviorParser::SelectorContext::selector_Area() {
  return getRuleContext<BehaviorParser::Selector_AreaContext>(0);
}


size_t BehaviorParser::SelectorContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector;
}


std::any BehaviorParser::SelectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::SelectorContext* BehaviorParser::selector() {
  SelectorContext *_localctx = _tracker.createInstance<SelectorContext>(_ctx, getState());
  enterRule(_localctx, 52, BehaviorParser::RuleSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(278);
      selector_Percent();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(279);
      selector_Exactly_N_Random();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(280);
      selector_Everyone();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(281);
      selector_Area();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_PercentContext ------------------------------------------------------------------

BehaviorParser::Selector_PercentContext::Selector_PercentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Value_numberContext* BehaviorParser::Selector_PercentContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}

tree::TerminalNode* BehaviorParser::Selector_PercentContext::OF() {
  return getToken(BehaviorParser::OF, 0);
}


size_t BehaviorParser::Selector_PercentContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Percent;
}


std::any BehaviorParser::Selector_PercentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Percent(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_PercentContext* BehaviorParser::selector_Percent() {
  Selector_PercentContext *_localctx = _tracker.createInstance<Selector_PercentContext>(_ctx, getState());
  enterRule(_localctx, 54, BehaviorParser::RuleSelector_Percent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    value_number();
    setState(285);
    match(BehaviorParser::T__2);
    setState(286);
    match(BehaviorParser::OF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_Exactly_N_RandomContext ------------------------------------------------------------------

BehaviorParser::Selector_Exactly_N_RandomContext::Selector_Exactly_N_RandomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::EXACTLY() {
  return getToken(BehaviorParser::EXACTLY, 0);
}

BehaviorParser::Value_numberContext* BehaviorParser::Selector_Exactly_N_RandomContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}

tree::TerminalNode* BehaviorParser::Selector_Exactly_N_RandomContext::OF() {
  return getToken(BehaviorParser::OF, 0);
}


size_t BehaviorParser::Selector_Exactly_N_RandomContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Exactly_N_Random;
}


std::any BehaviorParser::Selector_Exactly_N_RandomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Exactly_N_Random(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_Exactly_N_RandomContext* BehaviorParser::selector_Exactly_N_Random() {
  Selector_Exactly_N_RandomContext *_localctx = _tracker.createInstance<Selector_Exactly_N_RandomContext>(_ctx, getState());
  enterRule(_localctx, 56, BehaviorParser::RuleSelector_Exactly_N_Random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(BehaviorParser::EXACTLY);
    setState(289);
    value_number();
    setState(290);
    match(BehaviorParser::OF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_EveryoneContext ------------------------------------------------------------------

BehaviorParser::Selector_EveryoneContext::Selector_EveryoneContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_EveryoneContext::EVERYONE() {
  return getToken(BehaviorParser::EVERYONE, 0);
}


size_t BehaviorParser::Selector_EveryoneContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Everyone;
}


std::any BehaviorParser::Selector_EveryoneContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Everyone(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_EveryoneContext* BehaviorParser::selector_Everyone() {
  Selector_EveryoneContext *_localctx = _tracker.createInstance<Selector_EveryoneContext>(_ctx, getState());
  enterRule(_localctx, 58, BehaviorParser::RuleSelector_Everyone);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(BehaviorParser::EVERYONE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_AreaContext ------------------------------------------------------------------

BehaviorParser::Selector_AreaContext::Selector_AreaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_AreaContext::EVERYONE() {
  return getToken(BehaviorParser::EVERYONE, 0);
}

tree::TerminalNode* BehaviorParser::Selector_AreaContext::IN() {
  return getToken(BehaviorParser::IN, 0);
}

tree::TerminalNode* BehaviorParser::Selector_AreaContext::LOC() {
  return getToken(BehaviorParser::LOC, 0);
}

tree::TerminalNode* BehaviorParser::Selector_AreaContext::IS() {
  return getToken(BehaviorParser::IS, 0);
}

tree::TerminalNode* BehaviorParser::Selector_AreaContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Selector_AreaContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Selector_AreaContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_Area;
}


std::any BehaviorParser::Selector_AreaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_Area(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_AreaContext* BehaviorParser::selector_Area() {
  Selector_AreaContext *_localctx = _tracker.createInstance<Selector_AreaContext>(_ctx, getState());
  enterRule(_localctx, 60, BehaviorParser::RuleSelector_Area);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(294);
    match(BehaviorParser::EVERYONE);
    setState(295);
    match(BehaviorParser::IN);
    setState(296);
    match(BehaviorParser::LOC);
    setState(297);
    match(BehaviorParser::IS);
    setState(298);
    match(BehaviorParser::AN);
    setState(299);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Id_listContext ------------------------------------------------------------------

BehaviorParser::Id_listContext::Id_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Id_listContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Id_listContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Id_listContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Id_listContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Id_listContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}


size_t BehaviorParser::Id_listContext::getRuleIndex() const {
  return BehaviorParser::RuleId_list;
}


std::any BehaviorParser::Id_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitId_list(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Id_listContext* BehaviorParser::id_list() {
  Id_listContext *_localctx = _tracker.createInstance<Id_listContext>(_ctx, getState());
  enterRule(_localctx, 62, BehaviorParser::RuleId_list);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301);
    match(BehaviorParser::ID);
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & 4611686018427388545) != 0)) {
      setState(303);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(302);
        match(BehaviorParser::COMMA);
      }
      setState(306);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(305);
        match(BehaviorParser::AND);
      }
      setState(309);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(308);
        match(BehaviorParser::AN);
      }
      setState(311);
      match(BehaviorParser::ID);
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionContext ------------------------------------------------------------------

BehaviorParser::ActionContext::ActionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Conditional_actionContext* BehaviorParser::ActionContext::conditional_action() {
  return getRuleContext<BehaviorParser::Conditional_actionContext>(0);
}

BehaviorParser::Un_conditional_actionContext* BehaviorParser::ActionContext::un_conditional_action() {
  return getRuleContext<BehaviorParser::Un_conditional_actionContext>(0);
}


size_t BehaviorParser::ActionContext::getRuleIndex() const {
  return BehaviorParser::RuleAction;
}


std::any BehaviorParser::ActionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::ActionContext* BehaviorParser::action() {
  ActionContext *_localctx = _tracker.createInstance<ActionContext>(_ctx, getState());
  enterRule(_localctx, 64, BehaviorParser::RuleAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(319);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(317);
      conditional_action();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(318);
      un_conditional_action();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Conditional_actionContext ------------------------------------------------------------------

BehaviorParser::Conditional_actionContext::Conditional_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Conditional_actionContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Conditional_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}

BehaviorParser::ConditionContext* BehaviorParser::Conditional_actionContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::Conditional_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleConditional_action;
}


std::any BehaviorParser::Conditional_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitConditional_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Conditional_actionContext* BehaviorParser::conditional_action() {
  Conditional_actionContext *_localctx = _tracker.createInstance<Conditional_actionContext>(_ctx, getState());
  enterRule(_localctx, 66, BehaviorParser::RuleConditional_action);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    match(BehaviorParser::AN);
    setState(322);
    match(BehaviorParser::ID);
    setState(323);
    match(BehaviorParser::WILL);
    setState(324);
    sub_action();
    setState(325);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Un_conditional_actionContext ------------------------------------------------------------------

BehaviorParser::Un_conditional_actionContext::Un_conditional_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Un_conditional_actionContext::ALWAYS() {
  return getToken(BehaviorParser::ALWAYS, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Un_conditional_actionContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}


size_t BehaviorParser::Un_conditional_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleUn_conditional_action;
}


std::any BehaviorParser::Un_conditional_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitUn_conditional_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Un_conditional_actionContext* BehaviorParser::un_conditional_action() {
  Un_conditional_actionContext *_localctx = _tracker.createInstance<Un_conditional_actionContext>(_ctx, getState());
  enterRule(_localctx, 68, BehaviorParser::RuleUn_conditional_action);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(327);
    match(BehaviorParser::AN);
    setState(328);
    match(BehaviorParser::ID);
    setState(329);
    match(BehaviorParser::WILL);
    setState(330);
    match(BehaviorParser::ALWAYS);
    setState(331);
    sub_action();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sub_actionContext ------------------------------------------------------------------

BehaviorParser::Sub_actionContext::Sub_actionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BehaviorParser::Action_atomContext *> BehaviorParser::Sub_actionContext::action_atom() {
  return getRuleContexts<BehaviorParser::Action_atomContext>();
}

BehaviorParser::Action_atomContext* BehaviorParser::Sub_actionContext::action_atom(size_t i) {
  return getRuleContext<BehaviorParser::Action_atomContext>(i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Sub_actionContext::THEN() {
  return getTokens(BehaviorParser::THEN);
}

tree::TerminalNode* BehaviorParser::Sub_actionContext::THEN(size_t i) {
  return getToken(BehaviorParser::THEN, i);
}


size_t BehaviorParser::Sub_actionContext::getRuleIndex() const {
  return BehaviorParser::RuleSub_action;
}


std::any BehaviorParser::Sub_actionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSub_action(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Sub_actionContext* BehaviorParser::sub_action() {
  Sub_actionContext *_localctx = _tracker.createInstance<Sub_actionContext>(_ctx, getState());
  enterRule(_localctx, 70, BehaviorParser::RuleSub_action);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    action_atom();
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::THEN) {
      setState(334);
      match(BehaviorParser::THEN);
      setState(335);
      action_atom();
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_atomContext ------------------------------------------------------------------

BehaviorParser::Action_atomContext::Action_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_atomContext::ACTION() {
  return getToken(BehaviorParser::ACTION, 0);
}

BehaviorParser::Action_StopContext* BehaviorParser::Action_atomContext::action_Stop() {
  return getRuleContext<BehaviorParser::Action_StopContext>(0);
}

BehaviorParser::Action_BeContext* BehaviorParser::Action_atomContext::action_Be() {
  return getRuleContext<BehaviorParser::Action_BeContext>(0);
}

BehaviorParser::Action_atom_Percent_Walk_SpeedContext* BehaviorParser::Action_atomContext::action_atom_Percent_Walk_Speed() {
  return getRuleContext<BehaviorParser::Action_atom_Percent_Walk_SpeedContext>(0);
}


size_t BehaviorParser::Action_atomContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_atom;
}


std::any BehaviorParser::Action_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_atom(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_atomContext* BehaviorParser::action_atom() {
  Action_atomContext *_localctx = _tracker.createInstance<Action_atomContext>(_ctx, getState());
  enterRule(_localctx, 72, BehaviorParser::RuleAction_atom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::ACTION: {
        enterOuterAlt(_localctx, 1);
        setState(341);
        match(BehaviorParser::ACTION);
        break;
      }

      case BehaviorParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(342);
        action_Stop();
        break;
      }

      case BehaviorParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(343);
        action_Be();
        break;
      }

      case BehaviorParser::T__4: {
        enterOuterAlt(_localctx, 4);
        setState(344);
        action_atom_Percent_Walk_Speed();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_StopContext ------------------------------------------------------------------

BehaviorParser::Action_StopContext::Action_StopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BehaviorParser::Action_StopContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_Stop;
}


std::any BehaviorParser::Action_StopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_Stop(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_StopContext* BehaviorParser::action_Stop() {
  Action_StopContext *_localctx = _tracker.createInstance<Action_StopContext>(_ctx, getState());
  enterRule(_localctx, 74, BehaviorParser::RuleAction_Stop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    match(BehaviorParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_atom_Percent_Walk_SpeedContext ------------------------------------------------------------------

BehaviorParser::Action_atom_Percent_Walk_SpeedContext::Action_atom_Percent_Walk_SpeedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Value_numberContext* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::THEIR() {
  return getToken(BehaviorParser::THEIR, 0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::NORMAL() {
  return getToken(BehaviorParser::NORMAL, 0);
}

tree::TerminalNode* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::SPEED() {
  return getToken(BehaviorParser::SPEED, 0);
}


size_t BehaviorParser::Action_atom_Percent_Walk_SpeedContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_atom_Percent_Walk_Speed;
}


std::any BehaviorParser::Action_atom_Percent_Walk_SpeedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_atom_Percent_Walk_Speed(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_atom_Percent_Walk_SpeedContext* BehaviorParser::action_atom_Percent_Walk_Speed() {
  Action_atom_Percent_Walk_SpeedContext *_localctx = _tracker.createInstance<Action_atom_Percent_Walk_SpeedContext>(_ctx, getState());
  enterRule(_localctx, 76, BehaviorParser::RuleAction_atom_Percent_Walk_Speed);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(349);
    match(BehaviorParser::T__4);
    setState(350);
    value_number();
    setState(351);
    match(BehaviorParser::T__5);
    setState(352);
    match(BehaviorParser::THEIR);
    setState(353);
    match(BehaviorParser::NORMAL);
    setState(354);
    match(BehaviorParser::SPEED);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_PushContext ------------------------------------------------------------------

BehaviorParser::Action_PushContext::Action_PushContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_PushContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Action_PushContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_Push;
}


std::any BehaviorParser::Action_PushContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_Push(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_PushContext* BehaviorParser::action_Push() {
  Action_PushContext *_localctx = _tracker.createInstance<Action_PushContext>(_ctx, getState());
  enterRule(_localctx, 78, BehaviorParser::RuleAction_Push);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(356);
    match(BehaviorParser::T__6);
    setState(357);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_BeContext ------------------------------------------------------------------

BehaviorParser::Action_BeContext::Action_BeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_BeContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}


size_t BehaviorParser::Action_BeContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_Be;
}


std::any BehaviorParser::Action_BeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_Be(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_BeContext* BehaviorParser::action_Be() {
  Action_BeContext *_localctx = _tracker.createInstance<Action_BeContext>(_ctx, getState());
  enterRule(_localctx, 80, BehaviorParser::RuleAction_Be);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(359);
    match(BehaviorParser::T__7);
    setState(360);
    match(BehaviorParser::STATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

BehaviorParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Decl_PedContext* BehaviorParser::DeclarationContext::decl_Ped() {
  return getRuleContext<BehaviorParser::Decl_PedContext>(0);
}

BehaviorParser::Decl_Ped_StateContext* BehaviorParser::DeclarationContext::decl_Ped_State() {
  return getRuleContext<BehaviorParser::Decl_Ped_StateContext>(0);
}

BehaviorParser::Decl_Env_StateContext* BehaviorParser::DeclarationContext::decl_Env_State() {
  return getRuleContext<BehaviorParser::Decl_Env_StateContext>(0);
}


size_t BehaviorParser::DeclarationContext::getRuleIndex() const {
  return BehaviorParser::RuleDeclaration;
}


std::any BehaviorParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DeclarationContext* BehaviorParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 82, BehaviorParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(362);
      decl_Ped();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(363);
      decl_Ped_State();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(364);
      decl_Env_State();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_PedContext ------------------------------------------------------------------

BehaviorParser::Decl_PedContext::Decl_PedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::CONSIDER() {
  return getToken(BehaviorParser::CONSIDER, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::ID() {
  return getTokens(BehaviorParser::ID);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::ID(size_t i) {
  return getToken(BehaviorParser::ID, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_PedContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
}


size_t BehaviorParser::Decl_PedContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Ped;
}


std::any BehaviorParser::Decl_PedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Ped(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_PedContext* BehaviorParser::decl_Ped() {
  Decl_PedContext *_localctx = _tracker.createInstance<Decl_PedContext>(_ctx, getState());
  enterRule(_localctx, 84, BehaviorParser::RuleDecl_Ped);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    match(BehaviorParser::CONSIDER);
    setState(369);
    match(BehaviorParser::AN);

    setState(370);
    match(BehaviorParser::ID);
    setState(383);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & 4611686018427388545) != 0)) {
      setState(372);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(371);
        match(BehaviorParser::COMMA);
      }
      setState(375);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(374);
        match(BehaviorParser::AND);
      }
      setState(378);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(377);
        match(BehaviorParser::AN);
      }
      setState(380);
      match(BehaviorParser::ID);
      setState(385);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_Ped_StateContext ------------------------------------------------------------------

BehaviorParser::Decl_Ped_StateContext::Decl_Ped_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::POSSIBLE() {
  return getToken(BehaviorParser::POSSIBLE, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::STATES() {
  return getToken(BehaviorParser::STATES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::ARE() {
  return getToken(BehaviorParser::ARE, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::STATE() {
  return getTokens(BehaviorParser::STATE);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::STATE(size_t i) {
  return getToken(BehaviorParser::STATE, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
}


size_t BehaviorParser::Decl_Ped_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Ped_State;
}


std::any BehaviorParser::Decl_Ped_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Ped_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Ped_StateContext* BehaviorParser::decl_Ped_State() {
  Decl_Ped_StateContext *_localctx = _tracker.createInstance<Decl_Ped_StateContext>(_ctx, getState());
  enterRule(_localctx, 86, BehaviorParser::RuleDecl_Ped_State);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(BehaviorParser::POSSIBLE);
    setState(387);
    match(BehaviorParser::PEDESTRIAN);
    setState(388);
    match(BehaviorParser::STATES);
    setState(389);
    match(BehaviorParser::ARE);

    setState(390);
    match(BehaviorParser::STATE);
    setState(400);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2117632) != 0)) {
      setState(392);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(391);
        match(BehaviorParser::COMMA);
      }
      setState(395);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(394);
        match(BehaviorParser::AND);
      }
      setState(397);
      match(BehaviorParser::STATE);
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_Env_StateContext ------------------------------------------------------------------

BehaviorParser::Decl_Env_StateContext::Decl_Env_StateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::POSSIBLE() {
  return getToken(BehaviorParser::POSSIBLE, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::ENVIRONMENT() {
  return getToken(BehaviorParser::ENVIRONMENT, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::STATES() {
  return getToken(BehaviorParser::STATES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::ARE() {
  return getToken(BehaviorParser::ARE, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::STATE() {
  return getTokens(BehaviorParser::STATE);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::STATE(size_t i) {
  return getToken(BehaviorParser::STATE, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::AND() {
  return getTokens(BehaviorParser::AND);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::AND(size_t i) {
  return getToken(BehaviorParser::AND, i);
}


size_t BehaviorParser::Decl_Env_StateContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Env_State;
}


std::any BehaviorParser::Decl_Env_StateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Env_State(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Env_StateContext* BehaviorParser::decl_Env_State() {
  Decl_Env_StateContext *_localctx = _tracker.createInstance<Decl_Env_StateContext>(_ctx, getState());
  enterRule(_localctx, 88, BehaviorParser::RuleDecl_Env_State);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    match(BehaviorParser::POSSIBLE);
    setState(404);
    match(BehaviorParser::ENVIRONMENT);
    setState(405);
    match(BehaviorParser::STATES);
    setState(406);
    match(BehaviorParser::ARE);

    setState(407);
    match(BehaviorParser::STATE);
    setState(417);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2117632) != 0)) {
      setState(409);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(408);
        match(BehaviorParser::COMMA);
      }
      setState(412);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(411);
        match(BehaviorParser::AND);
      }
      setState(414);
      match(BehaviorParser::STATE);
      setState(419);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void BehaviorParser::initialize() {
  ::antlr4::internal::call_once(behaviorParserOnceFlag, behaviorParserInitialize);
}
