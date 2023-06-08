
// Generated from Behavior.g4 by ANTLR 4.13.0


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
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
BehaviorParserStaticData *behaviorParserStaticData = nullptr;

void behaviorParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (behaviorParserStaticData != nullptr) {
    return;
  }
#else
  assert(behaviorParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<BehaviorParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "event", "event_Single", "event_Lasting", 
      "event_Individual", "condition", "connector", "or_Connector", "and_Connector", 
      "sub_condition", "condition_Time_Elapsed_From_Event", "condition_Event_Occurred", 
      "condition_Event_Occurring", "value_number", "number_random", "random_number", 
      "random_float", "direction", "dir", "direction_of", "infront", "behind", 
      "around", "object", "duration", "ped_Selector", "selector", "selector_Percent", 
      "selector_Exactly_N_Random", "selector_Everyone", "id_list", "action", 
      "conditional_action", "un_conditional_action", "sub_action", "action_atom", 
      "action_Stop", "action_atom_Percent_Walk_Speed", "action_Be", "declaration", 
      "decl_Loc", "decl_Ped_State", "decl_Env_State", "decl_Loc_Area_Circle", 
      "decl_Loc_Area_Rect", "decl_Loc_Point", "decl_Ped", "point"
    },
    std::vector<std::string>{
      "", "'.'", "'-'", "'+'", "'%'", "'@stop'", "'@walk'", "'x'", "'@be set to'", 
      "'('", "')'", "", "", "", "','", "':'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "COMMENT", "LINE_COMMENT", 
      "WS", "COMMA", "COLON", "STATE", "ACTION", "EVNT", "OBJECT", "AN", 
      "AT", "AND", "ARE", "AFTER", "ALWAYS", "AROUND", "BEHIND", "CONSIDER", 
      "DECIMAL", "DIRECTION", "END", "ENDS", "ENVIRONMENT", "EVENT", "EXACTLY", 
      "EVERY", "EVERYONE", "FOR", "FROM", "FRONT", "FASTER", "GIVEN", "HAS", 
      "IN", "INTEGER", "IS", "LENGTH", "LOCATION", "METERS", "NORMAL", "OBSTACLE", 
      "OCCUR", "OCCURRED", "OCCURRING", "OF", "OR", "PEDESTRIAN", "PEDESTRIANS", 
      "POSSIBLE", "RADIUS", "RANDOM", "REQUIRED", "SECOND", "SECONDS", "SLOWER", 
      "STATES", "STARTS", "SPEED", "TO", "THE", "THAT", "THEN", "THEIR", 
      "THERES", "TYPES", "VALUE", "WHEN", "WHILE", "WIDTH", "WILL", "WITH", 
      "WITHIN", "ID", "NUMBER", "FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,85,465,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,1,0,1,
  	0,1,0,4,0,102,8,0,11,0,12,0,103,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,3,1,118,8,1,1,2,1,2,3,2,122,8,2,1,3,1,3,1,3,3,3,127,8,3,1,3,
  	1,3,1,3,1,3,1,4,1,4,1,4,3,4,136,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,6,1,6,5,6,153,8,6,10,6,12,6,156,9,6,1,7,1,7,3,7,160,
  	8,7,1,8,1,8,1,8,1,9,1,9,1,9,1,10,1,10,1,10,3,10,171,8,10,1,11,1,11,1,
  	11,1,11,3,11,177,8,11,1,11,1,11,3,11,181,8,11,1,12,1,12,3,12,185,8,12,
  	1,12,1,12,3,12,189,8,12,1,12,1,12,1,12,1,13,1,13,3,13,196,8,13,1,13,1,
  	13,3,13,200,8,13,1,13,1,13,1,13,1,14,1,14,1,14,3,14,208,8,14,1,15,1,15,
  	3,15,212,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,3,19,235,8,19,1,20,
  	1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,24,
  	1,24,1,24,3,24,254,8,24,1,25,1,25,1,25,1,25,1,26,1,26,3,26,262,8,26,1,
  	26,1,26,1,26,1,26,3,26,268,8,26,1,26,1,26,1,26,1,26,3,26,274,8,26,1,26,
  	1,26,1,26,3,26,279,8,26,1,26,1,26,3,26,283,8,26,1,27,1,27,1,27,3,27,288,
  	8,27,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,1,30,1,31,1,31,3,31,
  	302,8,31,1,31,3,31,305,8,31,1,31,3,31,308,8,31,1,31,5,31,311,8,31,10,
  	31,12,31,314,9,31,1,32,1,32,3,32,318,8,32,1,33,1,33,1,33,1,33,1,33,1,
  	33,3,33,326,8,33,1,34,1,34,1,34,1,34,1,34,1,34,1,35,1,35,1,35,5,35,337,
  	8,35,10,35,12,35,340,9,35,1,36,1,36,1,36,1,36,3,36,346,8,36,1,37,1,37,
  	1,38,1,38,1,38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,1,40,1,40,1,40,1,40,
  	3,40,364,8,40,1,41,1,41,1,41,3,41,369,8,41,1,42,1,42,1,42,1,42,1,42,1,
  	42,3,42,377,8,42,1,42,3,42,380,8,42,1,42,5,42,383,8,42,10,42,12,42,386,
  	9,42,1,43,1,43,1,43,1,43,1,43,1,43,3,43,394,8,43,1,43,3,43,397,8,43,1,
  	43,5,43,400,8,43,10,43,12,43,403,9,43,1,44,1,44,1,44,1,44,1,44,1,44,1,
  	44,1,44,1,44,1,44,1,44,1,44,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,
  	45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,46,1,
  	46,1,46,1,47,1,47,1,47,1,47,3,47,445,8,47,1,47,3,47,448,8,47,1,47,3,47,
  	451,8,47,1,47,5,47,454,8,47,10,47,12,47,457,9,47,1,48,1,48,1,48,1,48,
  	1,48,1,48,1,48,0,0,49,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,
  	36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,
  	82,84,86,88,90,92,94,96,0,5,2,0,20,20,70,70,2,0,2,2,69,69,1,0,63,64,2,
  	0,57,58,83,83,2,0,23,23,46,46,472,0,98,1,0,0,0,2,117,1,0,0,0,4,121,1,
  	0,0,0,6,123,1,0,0,0,8,132,1,0,0,0,10,144,1,0,0,0,12,150,1,0,0,0,14,159,
  	1,0,0,0,16,161,1,0,0,0,18,164,1,0,0,0,20,170,1,0,0,0,22,172,1,0,0,0,24,
  	182,1,0,0,0,26,193,1,0,0,0,28,207,1,0,0,0,30,211,1,0,0,0,32,213,1,0,0,
  	0,34,219,1,0,0,0,36,225,1,0,0,0,38,234,1,0,0,0,40,236,1,0,0,0,42,241,
  	1,0,0,0,44,244,1,0,0,0,46,246,1,0,0,0,48,253,1,0,0,0,50,255,1,0,0,0,52,
  	282,1,0,0,0,54,287,1,0,0,0,56,289,1,0,0,0,58,293,1,0,0,0,60,297,1,0,0,
  	0,62,299,1,0,0,0,64,317,1,0,0,0,66,319,1,0,0,0,68,327,1,0,0,0,70,333,
  	1,0,0,0,72,345,1,0,0,0,74,347,1,0,0,0,76,349,1,0,0,0,78,356,1,0,0,0,80,
  	363,1,0,0,0,82,368,1,0,0,0,84,370,1,0,0,0,86,387,1,0,0,0,88,404,1,0,0,
  	0,90,416,1,0,0,0,92,433,1,0,0,0,94,440,1,0,0,0,96,458,1,0,0,0,98,99,3,
  	94,47,0,99,101,5,1,0,0,100,102,3,2,1,0,101,100,1,0,0,0,102,103,1,0,0,
  	0,103,101,1,0,0,0,103,104,1,0,0,0,104,1,1,0,0,0,105,106,3,4,2,0,106,107,
  	5,1,0,0,107,118,1,0,0,0,108,109,3,80,40,0,109,110,5,1,0,0,110,118,1,0,
  	0,0,111,112,3,52,26,0,112,113,5,1,0,0,113,118,1,0,0,0,114,115,3,64,32,
  	0,115,116,5,1,0,0,116,118,1,0,0,0,117,105,1,0,0,0,117,108,1,0,0,0,117,
  	111,1,0,0,0,117,114,1,0,0,0,118,3,1,0,0,0,119,122,3,6,3,0,120,122,3,8,
  	4,0,121,119,1,0,0,0,121,120,1,0,0,0,122,5,1,0,0,0,123,124,7,0,0,0,124,
  	126,5,18,0,0,125,127,5,34,0,0,126,125,1,0,0,0,126,127,1,0,0,0,127,128,
  	1,0,0,0,128,129,5,80,0,0,129,130,5,52,0,0,130,131,3,12,6,0,131,7,1,0,
  	0,0,132,133,7,0,0,0,133,135,5,18,0,0,134,136,5,34,0,0,135,134,1,0,0,0,
  	135,136,1,0,0,0,136,137,1,0,0,0,137,138,5,80,0,0,138,139,5,52,0,0,139,
  	140,3,12,6,0,140,141,5,22,0,0,141,142,5,31,0,0,142,143,3,12,6,0,143,9,
  	1,0,0,0,144,145,5,20,0,0,145,146,5,83,0,0,146,147,5,80,0,0,147,148,5,
  	18,0,0,148,149,3,12,6,0,149,11,1,0,0,0,150,154,3,20,10,0,151,153,3,14,
  	7,0,152,151,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,1,0,0,0,155,
  	13,1,0,0,0,156,154,1,0,0,0,157,160,3,16,8,0,158,160,3,18,9,0,159,157,
  	1,0,0,0,159,158,1,0,0,0,160,15,1,0,0,0,161,162,5,56,0,0,162,163,3,20,
  	10,0,163,17,1,0,0,0,164,165,5,22,0,0,165,166,3,20,10,0,166,19,1,0,0,0,
  	167,171,3,22,11,0,168,171,3,24,12,0,169,171,3,26,13,0,170,167,1,0,0,0,
  	170,168,1,0,0,0,170,169,1,0,0,0,171,21,1,0,0,0,172,173,5,24,0,0,173,174,
  	3,50,25,0,174,176,5,39,0,0,175,177,7,0,0,0,176,175,1,0,0,0,176,177,1,
  	0,0,0,177,178,1,0,0,0,178,180,5,18,0,0,179,181,5,34,0,0,180,179,1,0,0,
  	0,180,181,1,0,0,0,181,23,1,0,0,0,182,184,5,42,0,0,183,185,7,0,0,0,184,
  	183,1,0,0,0,184,185,1,0,0,0,185,186,1,0,0,0,186,188,5,18,0,0,187,189,
  	5,34,0,0,188,187,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,0,190,191,5,43,
  	0,0,191,192,5,53,0,0,192,25,1,0,0,0,193,195,5,78,0,0,194,196,7,0,0,0,
  	195,194,1,0,0,0,195,196,1,0,0,0,196,197,1,0,0,0,197,199,5,18,0,0,198,
  	200,5,34,0,0,199,198,1,0,0,0,199,200,1,0,0,0,200,201,1,0,0,0,201,202,
  	5,46,0,0,202,203,5,54,0,0,203,27,1,0,0,0,204,208,3,30,15,0,205,208,5,
  	84,0,0,206,208,5,85,0,0,207,204,1,0,0,0,207,205,1,0,0,0,207,206,1,0,0,
  	0,208,29,1,0,0,0,209,212,3,34,17,0,210,212,3,32,16,0,211,209,1,0,0,0,
  	211,210,1,0,0,0,212,31,1,0,0,0,213,214,5,20,0,0,214,215,5,61,0,0,215,
  	216,5,84,0,0,216,217,7,1,0,0,217,218,5,84,0,0,218,33,1,0,0,0,219,220,
  	5,20,0,0,220,221,5,61,0,0,221,222,5,85,0,0,222,223,7,1,0,0,223,224,5,
  	85,0,0,224,35,1,0,0,0,225,226,3,38,19,0,226,227,5,82,0,0,227,228,5,84,
  	0,0,228,229,5,49,0,0,229,37,1,0,0,0,230,235,3,40,20,0,231,235,3,42,21,
  	0,232,235,3,44,22,0,233,235,3,46,23,0,234,230,1,0,0,0,234,231,1,0,0,0,
  	234,232,1,0,0,0,234,233,1,0,0,0,235,39,1,0,0,0,236,237,5,44,0,0,237,238,
  	5,30,0,0,238,239,5,55,0,0,239,240,5,83,0,0,240,41,1,0,0,0,241,242,5,44,
  	0,0,242,243,5,40,0,0,243,43,1,0,0,0,244,245,5,27,0,0,245,45,1,0,0,0,246,
  	247,5,26,0,0,247,47,1,0,0,0,248,249,5,3,0,0,249,254,5,57,0,0,250,251,
  	5,3,0,0,251,254,5,51,0,0,252,254,5,19,0,0,253,248,1,0,0,0,253,250,1,0,
  	0,0,253,252,1,0,0,0,254,49,1,0,0,0,255,256,5,38,0,0,256,257,3,28,14,0,
  	257,258,7,2,0,0,258,51,1,0,0,0,259,260,5,62,0,0,260,262,5,15,0,0,261,
  	259,1,0,0,0,261,262,1,0,0,0,262,263,1,0,0,0,263,264,3,54,27,0,264,265,
  	7,3,0,0,265,267,7,4,0,0,266,268,5,20,0,0,267,266,1,0,0,0,267,268,1,0,
  	0,0,268,269,1,0,0,0,269,270,3,62,31,0,270,283,1,0,0,0,271,272,5,62,0,
  	0,272,274,5,15,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,275,1,0,0,0,275,
  	276,3,60,30,0,276,278,5,46,0,0,277,279,5,20,0,0,278,277,1,0,0,0,278,279,
  	1,0,0,0,279,280,1,0,0,0,280,281,3,62,31,0,281,283,1,0,0,0,282,261,1,0,
  	0,0,282,273,1,0,0,0,283,53,1,0,0,0,284,288,3,56,28,0,285,288,3,58,29,
  	0,286,288,3,60,30,0,287,284,1,0,0,0,287,285,1,0,0,0,287,286,1,0,0,0,288,
  	55,1,0,0,0,289,290,3,28,14,0,290,291,5,4,0,0,291,292,5,55,0,0,292,57,
  	1,0,0,0,293,294,5,35,0,0,294,295,3,28,14,0,295,296,5,55,0,0,296,59,1,
  	0,0,0,297,298,5,37,0,0,298,61,1,0,0,0,299,312,5,83,0,0,300,302,5,14,0,
  	0,301,300,1,0,0,0,301,302,1,0,0,0,302,304,1,0,0,0,303,305,5,22,0,0,304,
  	303,1,0,0,0,304,305,1,0,0,0,305,307,1,0,0,0,306,308,5,20,0,0,307,306,
  	1,0,0,0,307,308,1,0,0,0,308,309,1,0,0,0,309,311,5,83,0,0,310,301,1,0,
  	0,0,311,314,1,0,0,0,312,310,1,0,0,0,312,313,1,0,0,0,313,63,1,0,0,0,314,
  	312,1,0,0,0,315,318,3,66,33,0,316,318,3,68,34,0,317,315,1,0,0,0,317,316,
  	1,0,0,0,318,65,1,0,0,0,319,320,5,20,0,0,320,321,5,83,0,0,321,322,5,80,
  	0,0,322,323,3,70,35,0,323,325,3,12,6,0,324,326,3,50,25,0,325,324,1,0,
  	0,0,325,326,1,0,0,0,326,67,1,0,0,0,327,328,5,20,0,0,328,329,5,83,0,0,
  	329,330,5,80,0,0,330,331,5,25,0,0,331,332,3,70,35,0,332,69,1,0,0,0,333,
  	338,3,72,36,0,334,335,5,72,0,0,335,337,3,72,36,0,336,334,1,0,0,0,337,
  	340,1,0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,71,1,0,0,0,340,338,1,
  	0,0,0,341,346,5,17,0,0,342,346,3,74,37,0,343,346,3,78,39,0,344,346,3,
  	76,38,0,345,341,1,0,0,0,345,342,1,0,0,0,345,343,1,0,0,0,345,344,1,0,0,
  	0,346,73,1,0,0,0,347,348,5,5,0,0,348,75,1,0,0,0,349,350,5,6,0,0,350,351,
  	3,28,14,0,351,352,5,7,0,0,352,353,5,73,0,0,353,354,5,50,0,0,354,355,5,
  	68,0,0,355,77,1,0,0,0,356,357,5,8,0,0,357,358,5,16,0,0,358,79,1,0,0,0,
  	359,364,3,82,41,0,360,364,3,84,42,0,361,364,3,86,43,0,362,364,3,94,47,
  	0,363,359,1,0,0,0,363,360,1,0,0,0,363,361,1,0,0,0,363,362,1,0,0,0,364,
  	81,1,0,0,0,365,369,3,88,44,0,366,369,3,92,46,0,367,369,3,90,45,0,368,
  	365,1,0,0,0,368,366,1,0,0,0,368,367,1,0,0,0,369,83,1,0,0,0,370,371,5,
  	59,0,0,371,372,5,57,0,0,372,373,5,66,0,0,373,374,5,23,0,0,374,384,5,16,
  	0,0,375,377,5,14,0,0,376,375,1,0,0,0,376,377,1,0,0,0,377,379,1,0,0,0,
  	378,380,5,22,0,0,379,378,1,0,0,0,379,380,1,0,0,0,380,381,1,0,0,0,381,
  	383,5,16,0,0,382,376,1,0,0,0,383,386,1,0,0,0,384,382,1,0,0,0,384,385,
  	1,0,0,0,385,85,1,0,0,0,386,384,1,0,0,0,387,388,5,59,0,0,388,389,5,33,
  	0,0,389,390,5,66,0,0,390,391,5,23,0,0,391,401,5,16,0,0,392,394,5,14,0,
  	0,393,392,1,0,0,0,393,394,1,0,0,0,394,396,1,0,0,0,395,397,5,22,0,0,396,
  	395,1,0,0,0,396,397,1,0,0,0,397,398,1,0,0,0,398,400,5,16,0,0,399,393,
  	1,0,0,0,400,403,1,0,0,0,401,399,1,0,0,0,401,402,1,0,0,0,402,87,1,0,0,
  	0,403,401,1,0,0,0,404,405,5,28,0,0,405,406,5,20,0,0,406,407,5,48,0,0,
  	407,408,5,83,0,0,408,409,5,21,0,0,409,410,3,96,48,0,410,411,5,81,0,0,
  	411,412,5,20,0,0,412,413,5,60,0,0,413,414,5,55,0,0,414,415,3,28,14,0,
  	415,89,1,0,0,0,416,417,5,28,0,0,417,418,5,20,0,0,418,419,5,48,0,0,419,
  	420,5,83,0,0,420,421,5,21,0,0,421,422,3,96,48,0,422,423,5,81,0,0,423,
  	424,5,20,0,0,424,425,5,47,0,0,425,426,5,55,0,0,426,427,3,28,14,0,427,
  	428,5,22,0,0,428,429,5,20,0,0,429,430,5,79,0,0,430,431,5,55,0,0,431,432,
  	3,28,14,0,432,91,1,0,0,0,433,434,5,28,0,0,434,435,5,20,0,0,435,436,5,
  	48,0,0,436,437,5,83,0,0,437,438,5,21,0,0,438,439,3,96,48,0,439,93,1,0,
  	0,0,440,441,5,28,0,0,441,442,5,20,0,0,442,455,5,83,0,0,443,445,5,14,0,
  	0,444,443,1,0,0,0,444,445,1,0,0,0,445,447,1,0,0,0,446,448,5,22,0,0,447,
  	446,1,0,0,0,447,448,1,0,0,0,448,450,1,0,0,0,449,451,5,20,0,0,450,449,
  	1,0,0,0,450,451,1,0,0,0,451,452,1,0,0,0,452,454,5,83,0,0,453,444,1,0,
  	0,0,454,457,1,0,0,0,455,453,1,0,0,0,455,456,1,0,0,0,456,95,1,0,0,0,457,
  	455,1,0,0,0,458,459,5,9,0,0,459,460,3,28,14,0,460,461,5,14,0,0,461,462,
  	3,28,14,0,462,463,5,10,0,0,463,97,1,0,0,0,44,103,117,121,126,135,154,
  	159,170,176,180,184,188,195,199,207,211,234,253,261,267,273,278,282,287,
  	301,304,307,312,317,325,338,345,363,368,376,379,384,393,396,401,444,447,
  	450,455
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
    setState(98);
    decl_Ped();
    setState(99);
    match(BehaviorParser::T__0);
    setState(101); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(100);
      statement();
      setState(103); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5188146942798987264) != 0) || ((((_la - 70) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 70)) & 49153) != 0));
   
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
    setState(117);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(105);
      event();
      setState(106);
      match(BehaviorParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(108);
      declaration();
      setState(109);
      match(BehaviorParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(111);
      ped_Selector();
      setState(112);
      match(BehaviorParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(114);
      action();
      setState(115);
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
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(119);
      event_Single();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
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
    setState(123);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(124);
    match(BehaviorParser::EVNT);
    setState(126);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(125);
      match(BehaviorParser::EVENT);
    }
    setState(128);
    match(BehaviorParser::WILL);
    setState(129);
    match(BehaviorParser::OCCUR);
    setState(130);
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
    setState(132);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(133);
    match(BehaviorParser::EVNT);
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(134);
      match(BehaviorParser::EVENT);
    }
    setState(137);
    match(BehaviorParser::WILL);
    setState(138);
    match(BehaviorParser::OCCUR);
    setState(139);
    condition();
    setState(140);
    match(BehaviorParser::AND);
    setState(141);
    match(BehaviorParser::END);
    setState(142);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_IndividualContext ------------------------------------------------------------------

BehaviorParser::Event_IndividualContext::Event_IndividualContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_IndividualContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Event_IndividualContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Event_IndividualContext::WILL() {
  return getToken(BehaviorParser::WILL, 0);
}

tree::TerminalNode* BehaviorParser::Event_IndividualContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Event_IndividualContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::Event_IndividualContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_Individual;
}


std::any BehaviorParser::Event_IndividualContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_Individual(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_IndividualContext* BehaviorParser::event_Individual() {
  Event_IndividualContext *_localctx = _tracker.createInstance<Event_IndividualContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorParser::RuleEvent_Individual);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(BehaviorParser::AN);
    setState(145);
    match(BehaviorParser::ID);
    setState(146);
    match(BehaviorParser::WILL);
    setState(147);
    match(BehaviorParser::EVNT);
    setState(148);
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
  enterRule(_localctx, 12, BehaviorParser::RuleCondition);

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
    setState(150);
    sub_condition();
    setState(154);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(151);
        connector(); 
      }
      setState(156);
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
  enterRule(_localctx, 14, BehaviorParser::RuleConnector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(159);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(157);
        or_Connector();
        break;
      }

      case BehaviorParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(158);
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
  enterRule(_localctx, 16, BehaviorParser::RuleOr_Connector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    match(BehaviorParser::OR);
    setState(162);
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
  enterRule(_localctx, 18, BehaviorParser::RuleAnd_Connector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(BehaviorParser::AND);
    setState(165);
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
  enterRule(_localctx, 20, BehaviorParser::RuleSub_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(170);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::AFTER: {
        enterOuterAlt(_localctx, 1);
        setState(167);
        condition_Time_Elapsed_From_Event();
        break;
      }

      case BehaviorParser::GIVEN: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        condition_Event_Occurred();
        break;
      }

      case BehaviorParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(169);
        condition_Event_Occurring();
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

BehaviorParser::DurationContext* BehaviorParser::Condition_Time_Elapsed_From_EventContext::duration() {
  return getRuleContext<BehaviorParser::DurationContext>(0);
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
  enterRule(_localctx, 22, BehaviorParser::RuleCondition_Time_Elapsed_From_Event);
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
    setState(172);
    match(BehaviorParser::AFTER);
    setState(173);
    duration();
    setState(174);
    match(BehaviorParser::FROM);
    setState(176);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(175);
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
    setState(178);
    match(BehaviorParser::EVNT);
    setState(180);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(179);
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
  enterRule(_localctx, 24, BehaviorParser::RuleCondition_Event_Occurred);
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
    setState(182);
    match(BehaviorParser::GIVEN);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(183);
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
    setState(186);
    match(BehaviorParser::EVNT);
    setState(188);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(187);
      match(BehaviorParser::EVENT);
    }
    setState(190);
    match(BehaviorParser::HAS);
    setState(191);
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

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::THE() {
  return getToken(BehaviorParser::THE, 0);
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
  enterRule(_localctx, 26, BehaviorParser::RuleCondition_Event_Occurring);
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
    setState(193);
    match(BehaviorParser::WHILE);
    setState(195);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(194);
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
    setState(197);
    match(BehaviorParser::EVNT);
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(198);
      match(BehaviorParser::EVENT);
    }
    setState(201);
    match(BehaviorParser::IS);
    setState(202);
    match(BehaviorParser::OCCURRING);
   
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

BehaviorParser::Number_randomContext* BehaviorParser::Value_numberContext::number_random() {
  return getRuleContext<BehaviorParser::Number_randomContext>(0);
}

tree::TerminalNode* BehaviorParser::Value_numberContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
}

tree::TerminalNode* BehaviorParser::Value_numberContext::FLOAT() {
  return getToken(BehaviorParser::FLOAT, 0);
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
    setState(207);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::AN: {
        enterOuterAlt(_localctx, 1);
        setState(204);
        number_random();
        break;
      }

      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(205);
        match(BehaviorParser::NUMBER);
        break;
      }

      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(206);
        match(BehaviorParser::FLOAT);
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
    setState(211);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(209);
      random_float();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(210);
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
    setState(213);
    match(BehaviorParser::AN);
    setState(214);
    match(BehaviorParser::RANDOM);
    setState(215);
    match(BehaviorParser::NUMBER);
    setState(216);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__1 || _la == BehaviorParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(217);
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
    setState(219);
    match(BehaviorParser::AN);
    setState(220);
    match(BehaviorParser::RANDOM);
    setState(221);
    match(BehaviorParser::FLOAT);
    setState(222);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__1 || _la == BehaviorParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(223);
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
    setState(225);
    dir();
    setState(226);
    match(BehaviorParser::WITHIN);
    setState(227);
    match(BehaviorParser::NUMBER);
    setState(228);
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
    setState(234);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(230);
      direction_of();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(231);
      infront();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(232);
      behind();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(233);
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
    setState(236);
    match(BehaviorParser::IN);
    setState(237);
    match(BehaviorParser::DIRECTION);
    setState(238);
    match(BehaviorParser::OF);
    setState(239);
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
    setState(241);
    match(BehaviorParser::IN);
    setState(242);
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
    setState(244);
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
    setState(246);
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
    setState(253);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(248);
      match(BehaviorParser::T__2);
      setState(249);
      match(BehaviorParser::PEDESTRIAN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(250);
      match(BehaviorParser::T__2);
      setState(251);
      match(BehaviorParser::OBSTACLE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(252);
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

//----------------- DurationContext ------------------------------------------------------------------

BehaviorParser::DurationContext::DurationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::DurationContext::FOR() {
  return getToken(BehaviorParser::FOR, 0);
}

BehaviorParser::Value_numberContext* BehaviorParser::DurationContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}

tree::TerminalNode* BehaviorParser::DurationContext::SECONDS() {
  return getToken(BehaviorParser::SECONDS, 0);
}

tree::TerminalNode* BehaviorParser::DurationContext::SECOND() {
  return getToken(BehaviorParser::SECOND, 0);
}


size_t BehaviorParser::DurationContext::getRuleIndex() const {
  return BehaviorParser::RuleDuration;
}


std::any BehaviorParser::DurationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDuration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::DurationContext* BehaviorParser::duration() {
  DurationContext *_localctx = _tracker.createInstance<DurationContext>(_ctx, getState());
  enterRule(_localctx, 50, BehaviorParser::RuleDuration);
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
    setState(255);
    match(BehaviorParser::FOR);
    setState(256);
    value_number();
    setState(257);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::SECOND

    || _la == BehaviorParser::SECONDS)) {
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
  enterRule(_localctx, 52, BehaviorParser::RulePed_Selector);
  size_t _la = 0;

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(261);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::REQUIRED) {
        setState(259);
        match(BehaviorParser::REQUIRED);
        setState(260);
        match(BehaviorParser::COLON);
      }
      setState(263);
      selector();
      setState(264);
      _la = _input->LA(1);
      if (!(((((_la - 57) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 57)) & 67108867) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(265);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::ARE

      || _la == BehaviorParser::IS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(267);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(266);
        match(BehaviorParser::AN);
      }
      setState(269);
      id_list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::REQUIRED) {
        setState(271);
        match(BehaviorParser::REQUIRED);
        setState(272);
        match(BehaviorParser::COLON);
      }
      setState(275);
      selector_Everyone();
      setState(276);
      match(BehaviorParser::IS);
      setState(278);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(277);
        match(BehaviorParser::AN);
      }
      setState(280);
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
  enterRule(_localctx, 54, BehaviorParser::RuleSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(287);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::AN:
      case BehaviorParser::NUMBER:
      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(284);
        selector_Percent();
        break;
      }

      case BehaviorParser::EXACTLY: {
        enterOuterAlt(_localctx, 2);
        setState(285);
        selector_Exactly_N_Random();
        break;
      }

      case BehaviorParser::EVERYONE: {
        enterOuterAlt(_localctx, 3);
        setState(286);
        selector_Everyone();
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
  enterRule(_localctx, 56, BehaviorParser::RuleSelector_Percent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    value_number();
    setState(290);
    match(BehaviorParser::T__3);
    setState(291);
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
  enterRule(_localctx, 58, BehaviorParser::RuleSelector_Exactly_N_Random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    match(BehaviorParser::EXACTLY);
    setState(294);
    value_number();
    setState(295);
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
  enterRule(_localctx, 60, BehaviorParser::RuleSelector_Everyone);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(BehaviorParser::EVERYONE);
   
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
    setState(299);
    match(BehaviorParser::ID);
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5259264) != 0) || _la == BehaviorParser::ID) {
      setState(301);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(300);
        match(BehaviorParser::COMMA);
      }
      setState(304);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(303);
        match(BehaviorParser::AND);
      }
      setState(307);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(306);
        match(BehaviorParser::AN);
      }
      setState(309);
      match(BehaviorParser::ID);
      setState(314);
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
    setState(317);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(315);
      conditional_action();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(316);
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

BehaviorParser::DurationContext* BehaviorParser::Conditional_actionContext::duration() {
  return getRuleContext<BehaviorParser::DurationContext>(0);
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
    setState(319);
    match(BehaviorParser::AN);
    setState(320);
    match(BehaviorParser::ID);
    setState(321);
    match(BehaviorParser::WILL);
    setState(322);
    sub_action();
    setState(323);
    condition();

    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::FOR) {
      setState(324);
      duration();
    }
   
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

      case BehaviorParser::T__4: {
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

      case BehaviorParser::T__5: {
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
    match(BehaviorParser::T__4);
   
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
    match(BehaviorParser::T__5);
    setState(350);
    value_number();
    setState(351);
    match(BehaviorParser::T__6);
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
  enterRule(_localctx, 78, BehaviorParser::RuleAction_Be);

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
    match(BehaviorParser::T__7);
    setState(357);
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

BehaviorParser::Decl_LocContext* BehaviorParser::DeclarationContext::decl_Loc() {
  return getRuleContext<BehaviorParser::Decl_LocContext>(0);
}

BehaviorParser::Decl_Ped_StateContext* BehaviorParser::DeclarationContext::decl_Ped_State() {
  return getRuleContext<BehaviorParser::Decl_Ped_StateContext>(0);
}

BehaviorParser::Decl_Env_StateContext* BehaviorParser::DeclarationContext::decl_Env_State() {
  return getRuleContext<BehaviorParser::Decl_Env_StateContext>(0);
}

BehaviorParser::Decl_PedContext* BehaviorParser::DeclarationContext::decl_Ped() {
  return getRuleContext<BehaviorParser::Decl_PedContext>(0);
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
  enterRule(_localctx, 80, BehaviorParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(363);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(359);
      decl_Loc();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(360);
      decl_Ped_State();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(361);
      decl_Env_State();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(362);
      decl_Ped();
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

//----------------- Decl_LocContext ------------------------------------------------------------------

BehaviorParser::Decl_LocContext::Decl_LocContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Decl_Loc_Area_CircleContext* BehaviorParser::Decl_LocContext::decl_Loc_Area_Circle() {
  return getRuleContext<BehaviorParser::Decl_Loc_Area_CircleContext>(0);
}

BehaviorParser::Decl_Loc_PointContext* BehaviorParser::Decl_LocContext::decl_Loc_Point() {
  return getRuleContext<BehaviorParser::Decl_Loc_PointContext>(0);
}

BehaviorParser::Decl_Loc_Area_RectContext* BehaviorParser::Decl_LocContext::decl_Loc_Area_Rect() {
  return getRuleContext<BehaviorParser::Decl_Loc_Area_RectContext>(0);
}


size_t BehaviorParser::Decl_LocContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Loc;
}


std::any BehaviorParser::Decl_LocContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Loc(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_LocContext* BehaviorParser::decl_Loc() {
  Decl_LocContext *_localctx = _tracker.createInstance<Decl_LocContext>(_ctx, getState());
  enterRule(_localctx, 82, BehaviorParser::RuleDecl_Loc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(368);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(365);
      decl_Loc_Area_Circle();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(366);
      decl_Loc_Point();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(367);
      decl_Loc_Area_Rect();
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
  enterRule(_localctx, 84, BehaviorParser::RuleDecl_Ped_State);
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
    setState(370);
    match(BehaviorParser::POSSIBLE);
    setState(371);
    match(BehaviorParser::PEDESTRIAN);
    setState(372);
    match(BehaviorParser::STATES);
    setState(373);
    match(BehaviorParser::ARE);

    setState(374);
    match(BehaviorParser::STATE);
    setState(384);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4276224) != 0)) {
      setState(376);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(375);
        match(BehaviorParser::COMMA);
      }
      setState(379);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(378);
        match(BehaviorParser::AND);
      }
      setState(381);
      match(BehaviorParser::STATE);
      setState(386);
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
  enterRule(_localctx, 86, BehaviorParser::RuleDecl_Env_State);
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
    setState(387);
    match(BehaviorParser::POSSIBLE);
    setState(388);
    match(BehaviorParser::ENVIRONMENT);
    setState(389);
    match(BehaviorParser::STATES);
    setState(390);
    match(BehaviorParser::ARE);

    setState(391);
    match(BehaviorParser::STATE);
    setState(401);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4276224) != 0)) {
      setState(393);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(392);
        match(BehaviorParser::COMMA);
      }
      setState(396);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(395);
        match(BehaviorParser::AND);
      }
      setState(398);
      match(BehaviorParser::STATE);
      setState(403);
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

//----------------- Decl_Loc_Area_CircleContext ------------------------------------------------------------------

BehaviorParser::Decl_Loc_Area_CircleContext::Decl_Loc_Area_CircleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::CONSIDER() {
  return getToken(BehaviorParser::CONSIDER, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Loc_Area_CircleContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::LOCATION() {
  return getToken(BehaviorParser::LOCATION, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::AT() {
  return getToken(BehaviorParser::AT, 0);
}

BehaviorParser::PointContext* BehaviorParser::Decl_Loc_Area_CircleContext::point() {
  return getRuleContext<BehaviorParser::PointContext>(0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::WITH() {
  return getToken(BehaviorParser::WITH, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::RADIUS() {
  return getToken(BehaviorParser::RADIUS, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_CircleContext::OF() {
  return getToken(BehaviorParser::OF, 0);
}

BehaviorParser::Value_numberContext* BehaviorParser::Decl_Loc_Area_CircleContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}


size_t BehaviorParser::Decl_Loc_Area_CircleContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Loc_Area_Circle;
}


std::any BehaviorParser::Decl_Loc_Area_CircleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Loc_Area_Circle(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Loc_Area_CircleContext* BehaviorParser::decl_Loc_Area_Circle() {
  Decl_Loc_Area_CircleContext *_localctx = _tracker.createInstance<Decl_Loc_Area_CircleContext>(_ctx, getState());
  enterRule(_localctx, 88, BehaviorParser::RuleDecl_Loc_Area_Circle);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    match(BehaviorParser::CONSIDER);
    setState(405);
    match(BehaviorParser::AN);
    setState(406);
    match(BehaviorParser::LOCATION);
    setState(407);
    match(BehaviorParser::ID);
    setState(408);
    match(BehaviorParser::AT);
    setState(409);
    point();
    setState(410);
    match(BehaviorParser::WITH);
    setState(411);
    match(BehaviorParser::AN);
    setState(412);
    match(BehaviorParser::RADIUS);
    setState(413);
    match(BehaviorParser::OF);
    setState(414);
    value_number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_Loc_Area_RectContext ------------------------------------------------------------------

BehaviorParser::Decl_Loc_Area_RectContext::Decl_Loc_Area_RectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::CONSIDER() {
  return getToken(BehaviorParser::CONSIDER, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Loc_Area_RectContext::AN() {
  return getTokens(BehaviorParser::AN);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::AN(size_t i) {
  return getToken(BehaviorParser::AN, i);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::LOCATION() {
  return getToken(BehaviorParser::LOCATION, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::AT() {
  return getToken(BehaviorParser::AT, 0);
}

BehaviorParser::PointContext* BehaviorParser::Decl_Loc_Area_RectContext::point() {
  return getRuleContext<BehaviorParser::PointContext>(0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::WITH() {
  return getToken(BehaviorParser::WITH, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::LENGTH() {
  return getToken(BehaviorParser::LENGTH, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Loc_Area_RectContext::OF() {
  return getTokens(BehaviorParser::OF);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::OF(size_t i) {
  return getToken(BehaviorParser::OF, i);
}

std::vector<BehaviorParser::Value_numberContext *> BehaviorParser::Decl_Loc_Area_RectContext::value_number() {
  return getRuleContexts<BehaviorParser::Value_numberContext>();
}

BehaviorParser::Value_numberContext* BehaviorParser::Decl_Loc_Area_RectContext::value_number(size_t i) {
  return getRuleContext<BehaviorParser::Value_numberContext>(i);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::AND() {
  return getToken(BehaviorParser::AND, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_Area_RectContext::WIDTH() {
  return getToken(BehaviorParser::WIDTH, 0);
}


size_t BehaviorParser::Decl_Loc_Area_RectContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Loc_Area_Rect;
}


std::any BehaviorParser::Decl_Loc_Area_RectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Loc_Area_Rect(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Loc_Area_RectContext* BehaviorParser::decl_Loc_Area_Rect() {
  Decl_Loc_Area_RectContext *_localctx = _tracker.createInstance<Decl_Loc_Area_RectContext>(_ctx, getState());
  enterRule(_localctx, 90, BehaviorParser::RuleDecl_Loc_Area_Rect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(BehaviorParser::CONSIDER);
    setState(417);
    match(BehaviorParser::AN);
    setState(418);
    match(BehaviorParser::LOCATION);
    setState(419);
    match(BehaviorParser::ID);
    setState(420);
    match(BehaviorParser::AT);
    setState(421);
    point();
    setState(422);
    match(BehaviorParser::WITH);
    setState(423);
    match(BehaviorParser::AN);
    setState(424);
    match(BehaviorParser::LENGTH);
    setState(425);
    match(BehaviorParser::OF);
    setState(426);
    value_number();
    setState(427);
    match(BehaviorParser::AND);
    setState(428);
    match(BehaviorParser::AN);
    setState(429);
    match(BehaviorParser::WIDTH);
    setState(430);
    match(BehaviorParser::OF);
    setState(431);
    value_number();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Decl_Loc_PointContext ------------------------------------------------------------------

BehaviorParser::Decl_Loc_PointContext::Decl_Loc_PointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Decl_Loc_PointContext::CONSIDER() {
  return getToken(BehaviorParser::CONSIDER, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_PointContext::AN() {
  return getToken(BehaviorParser::AN, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_PointContext::LOCATION() {
  return getToken(BehaviorParser::LOCATION, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_PointContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Loc_PointContext::AT() {
  return getToken(BehaviorParser::AT, 0);
}

BehaviorParser::PointContext* BehaviorParser::Decl_Loc_PointContext::point() {
  return getRuleContext<BehaviorParser::PointContext>(0);
}


size_t BehaviorParser::Decl_Loc_PointContext::getRuleIndex() const {
  return BehaviorParser::RuleDecl_Loc_Point;
}


std::any BehaviorParser::Decl_Loc_PointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitDecl_Loc_Point(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Decl_Loc_PointContext* BehaviorParser::decl_Loc_Point() {
  Decl_Loc_PointContext *_localctx = _tracker.createInstance<Decl_Loc_PointContext>(_ctx, getState());
  enterRule(_localctx, 92, BehaviorParser::RuleDecl_Loc_Point);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(BehaviorParser::CONSIDER);
    setState(434);
    match(BehaviorParser::AN);
    setState(435);
    match(BehaviorParser::LOCATION);
    setState(436);
    match(BehaviorParser::ID);
    setState(437);
    match(BehaviorParser::AT);
    setState(438);
    point();
   
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
  enterRule(_localctx, 94, BehaviorParser::RuleDecl_Ped);
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
    setState(440);
    match(BehaviorParser::CONSIDER);
    setState(441);
    match(BehaviorParser::AN);

    setState(442);
    match(BehaviorParser::ID);
    setState(455);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5259264) != 0) || _la == BehaviorParser::ID) {
      setState(444);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(443);
        match(BehaviorParser::COMMA);
      }
      setState(447);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(446);
        match(BehaviorParser::AND);
      }
      setState(450);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(449);
        match(BehaviorParser::AN);
      }
      setState(452);
      match(BehaviorParser::ID);
      setState(457);
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

//----------------- PointContext ------------------------------------------------------------------

BehaviorParser::PointContext::PointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BehaviorParser::Value_numberContext *> BehaviorParser::PointContext::value_number() {
  return getRuleContexts<BehaviorParser::Value_numberContext>();
}

BehaviorParser::Value_numberContext* BehaviorParser::PointContext::value_number(size_t i) {
  return getRuleContext<BehaviorParser::Value_numberContext>(i);
}

tree::TerminalNode* BehaviorParser::PointContext::COMMA() {
  return getToken(BehaviorParser::COMMA, 0);
}


size_t BehaviorParser::PointContext::getRuleIndex() const {
  return BehaviorParser::RulePoint;
}


std::any BehaviorParser::PointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitPoint(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::PointContext* BehaviorParser::point() {
  PointContext *_localctx = _tracker.createInstance<PointContext>(_ctx, getState());
  enterRule(_localctx, 96, BehaviorParser::RulePoint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(458);
    match(BehaviorParser::T__8);
    setState(459);
    value_number();
    setState(460);
    match(BehaviorParser::COMMA);
    setState(461);
    value_number();
    setState(462);
    match(BehaviorParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void BehaviorParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  behaviorParserInitialize();
#else
  ::antlr4::internal::call_once(behaviorParserOnceFlag, behaviorParserInitialize);
#endif
}
