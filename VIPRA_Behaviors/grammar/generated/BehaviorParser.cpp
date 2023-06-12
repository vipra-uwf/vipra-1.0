
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
      "condition", "connector", "or_Connector", "and_Connector", "sub_condition", 
      "condition_Time_Elapsed_From_Event", "condition_Event_Occurred", "condition_Event_Occurring", 
      "value_numeric", "value_number", "value_float", "value_range", "value_random", 
      "random_number", "random_float", "float_range", "number_range", "direction", 
      "dir", "direction_of", "infront", "behind", "around", "object", "duration", 
      "ped_Selector", "selector", "selector_Percent", "selector_Exactly_N_Random", 
      "selector_Everyone", "id_list", "action", "conditional_action", "un_conditional_action", 
      "sub_action", "action_atom", "action_Stop", "action_atom_Percent_Walk_Speed", 
      "action_Be", "declaration", "decl_Loc", "decl_Ped_State", "decl_Env_State", 
      "decl_Loc_Area_Circle", "decl_Loc_Area_Rect", "decl_Loc_Point", "decl_Ped", 
      "point"
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
  	4,1,85,486,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,1,0,1,0,1,0,4,0,110,8,0,11,0,12,0,111,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,126,8,1,1,2,1,2,3,
  	2,130,8,2,1,3,1,3,1,3,3,3,135,8,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,144,
  	8,4,1,4,1,4,1,4,1,4,3,4,150,8,4,1,4,1,4,1,4,1,4,1,5,1,5,5,5,158,8,5,10,
  	5,12,5,161,9,5,1,6,1,6,3,6,165,8,6,1,7,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,
  	9,3,9,176,8,9,1,10,1,10,1,10,1,10,1,10,3,10,183,8,10,1,10,1,10,3,10,187,
  	8,10,1,11,1,11,3,11,191,8,11,1,11,1,11,3,11,195,8,11,1,11,1,11,1,11,1,
  	12,1,12,3,12,202,8,12,1,12,1,12,3,12,206,8,12,1,12,1,12,1,12,1,13,1,13,
  	1,13,1,13,3,13,215,8,13,1,14,1,14,1,15,1,15,1,16,1,16,3,16,223,8,16,1,
  	17,1,17,3,17,227,8,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,20,1,
  	20,1,20,1,20,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,23,1,23,1,
  	23,1,23,3,23,254,8,23,1,24,1,24,1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,
  	26,1,27,1,27,1,28,1,28,1,28,1,28,1,28,3,28,273,8,28,1,29,1,29,1,29,1,
  	29,1,30,1,30,3,30,281,8,30,1,30,1,30,1,30,1,30,3,30,287,8,30,1,30,1,30,
  	1,30,1,30,3,30,293,8,30,1,30,1,30,1,30,3,30,298,8,30,1,30,1,30,3,30,302,
  	8,30,1,31,1,31,1,31,3,31,307,8,31,1,32,1,32,1,32,3,32,312,8,32,1,33,1,
  	33,1,33,3,33,317,8,33,1,34,1,34,1,35,1,35,3,35,323,8,35,1,35,3,35,326,
  	8,35,1,35,3,35,329,8,35,1,35,5,35,332,8,35,10,35,12,35,335,9,35,1,36,
  	1,36,3,36,339,8,36,1,37,1,37,1,37,1,37,1,37,1,37,3,37,347,8,37,1,38,1,
  	38,1,38,1,38,1,38,1,38,1,39,1,39,1,39,5,39,358,8,39,10,39,12,39,361,9,
  	39,1,40,1,40,1,40,1,40,3,40,367,8,40,1,41,1,41,1,42,1,42,1,42,1,42,1,
  	42,1,42,1,42,1,43,1,43,1,43,1,44,1,44,1,44,1,44,3,44,385,8,44,1,45,1,
  	45,1,45,3,45,390,8,45,1,46,1,46,1,46,1,46,1,46,1,46,3,46,398,8,46,1,46,
  	3,46,401,8,46,1,46,5,46,404,8,46,10,46,12,46,407,9,46,1,47,1,47,1,47,
  	1,47,1,47,1,47,3,47,415,8,47,1,47,3,47,418,8,47,1,47,5,47,421,8,47,10,
  	47,12,47,424,9,47,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,48,1,
  	48,1,48,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,
  	49,1,49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,
  	51,1,51,3,51,466,8,51,1,51,3,51,469,8,51,1,51,3,51,472,8,51,1,51,5,51,
  	475,8,51,10,51,12,51,478,9,51,1,52,1,52,1,52,1,52,1,52,1,52,1,52,0,0,
  	53,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,
  	48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,
  	94,96,98,100,102,104,0,5,2,0,20,20,70,70,2,0,2,2,69,69,1,0,63,64,2,0,
  	57,58,83,83,2,0,23,23,46,46,494,0,106,1,0,0,0,2,125,1,0,0,0,4,129,1,0,
  	0,0,6,131,1,0,0,0,8,140,1,0,0,0,10,155,1,0,0,0,12,164,1,0,0,0,14,166,
  	1,0,0,0,16,169,1,0,0,0,18,175,1,0,0,0,20,177,1,0,0,0,22,188,1,0,0,0,24,
  	199,1,0,0,0,26,214,1,0,0,0,28,216,1,0,0,0,30,218,1,0,0,0,32,222,1,0,0,
  	0,34,226,1,0,0,0,36,228,1,0,0,0,38,232,1,0,0,0,40,236,1,0,0,0,42,240,
  	1,0,0,0,44,244,1,0,0,0,46,253,1,0,0,0,48,255,1,0,0,0,50,260,1,0,0,0,52,
  	263,1,0,0,0,54,265,1,0,0,0,56,272,1,0,0,0,58,274,1,0,0,0,60,301,1,0,0,
  	0,62,306,1,0,0,0,64,308,1,0,0,0,66,313,1,0,0,0,68,318,1,0,0,0,70,320,
  	1,0,0,0,72,338,1,0,0,0,74,340,1,0,0,0,76,348,1,0,0,0,78,354,1,0,0,0,80,
  	366,1,0,0,0,82,368,1,0,0,0,84,370,1,0,0,0,86,377,1,0,0,0,88,384,1,0,0,
  	0,90,389,1,0,0,0,92,391,1,0,0,0,94,408,1,0,0,0,96,425,1,0,0,0,98,437,
  	1,0,0,0,100,454,1,0,0,0,102,461,1,0,0,0,104,479,1,0,0,0,106,107,3,102,
  	51,0,107,109,5,1,0,0,108,110,3,2,1,0,109,108,1,0,0,0,110,111,1,0,0,0,
  	111,109,1,0,0,0,111,112,1,0,0,0,112,1,1,0,0,0,113,114,3,4,2,0,114,115,
  	5,1,0,0,115,126,1,0,0,0,116,117,3,88,44,0,117,118,5,1,0,0,118,126,1,0,
  	0,0,119,120,3,60,30,0,120,121,5,1,0,0,121,126,1,0,0,0,122,123,3,72,36,
  	0,123,124,5,1,0,0,124,126,1,0,0,0,125,113,1,0,0,0,125,116,1,0,0,0,125,
  	119,1,0,0,0,125,122,1,0,0,0,126,3,1,0,0,0,127,130,3,6,3,0,128,130,3,8,
  	4,0,129,127,1,0,0,0,129,128,1,0,0,0,130,5,1,0,0,0,131,132,7,0,0,0,132,
  	134,5,18,0,0,133,135,5,34,0,0,134,133,1,0,0,0,134,135,1,0,0,0,135,136,
  	1,0,0,0,136,137,5,80,0,0,137,138,5,52,0,0,138,139,3,10,5,0,139,7,1,0,
  	0,0,140,141,7,0,0,0,141,143,5,18,0,0,142,144,5,34,0,0,143,142,1,0,0,0,
  	143,144,1,0,0,0,144,145,1,0,0,0,145,146,5,80,0,0,146,147,5,52,0,0,147,
  	149,3,10,5,0,148,150,5,14,0,0,149,148,1,0,0,0,149,150,1,0,0,0,150,151,
  	1,0,0,0,151,152,5,22,0,0,152,153,5,31,0,0,153,154,3,10,5,0,154,9,1,0,
  	0,0,155,159,3,18,9,0,156,158,3,12,6,0,157,156,1,0,0,0,158,161,1,0,0,0,
  	159,157,1,0,0,0,159,160,1,0,0,0,160,11,1,0,0,0,161,159,1,0,0,0,162,165,
  	3,14,7,0,163,165,3,16,8,0,164,162,1,0,0,0,164,163,1,0,0,0,165,13,1,0,
  	0,0,166,167,5,56,0,0,167,168,3,18,9,0,168,15,1,0,0,0,169,170,5,22,0,0,
  	170,171,3,18,9,0,171,17,1,0,0,0,172,176,3,20,10,0,173,176,3,22,11,0,174,
  	176,3,24,12,0,175,172,1,0,0,0,175,173,1,0,0,0,175,174,1,0,0,0,176,19,
  	1,0,0,0,177,178,5,24,0,0,178,179,3,26,13,0,179,180,5,64,0,0,180,182,5,
  	39,0,0,181,183,7,0,0,0,182,181,1,0,0,0,182,183,1,0,0,0,183,184,1,0,0,
  	0,184,186,5,18,0,0,185,187,5,34,0,0,186,185,1,0,0,0,186,187,1,0,0,0,187,
  	21,1,0,0,0,188,190,5,42,0,0,189,191,7,0,0,0,190,189,1,0,0,0,190,191,1,
  	0,0,0,191,192,1,0,0,0,192,194,5,18,0,0,193,195,5,34,0,0,194,193,1,0,0,
  	0,194,195,1,0,0,0,195,196,1,0,0,0,196,197,5,43,0,0,197,198,5,53,0,0,198,
  	23,1,0,0,0,199,201,5,78,0,0,200,202,7,0,0,0,201,200,1,0,0,0,201,202,1,
  	0,0,0,202,203,1,0,0,0,203,205,5,18,0,0,204,206,5,34,0,0,205,204,1,0,0,
  	0,205,206,1,0,0,0,206,207,1,0,0,0,207,208,5,46,0,0,208,209,5,54,0,0,209,
  	25,1,0,0,0,210,215,3,28,14,0,211,215,3,30,15,0,212,215,3,32,16,0,213,
  	215,3,34,17,0,214,210,1,0,0,0,214,211,1,0,0,0,214,212,1,0,0,0,214,213,
  	1,0,0,0,215,27,1,0,0,0,216,217,5,84,0,0,217,29,1,0,0,0,218,219,5,85,0,
  	0,219,31,1,0,0,0,220,223,3,40,20,0,221,223,3,42,21,0,222,220,1,0,0,0,
  	222,221,1,0,0,0,223,33,1,0,0,0,224,227,3,38,19,0,225,227,3,36,18,0,226,
  	224,1,0,0,0,226,225,1,0,0,0,227,35,1,0,0,0,228,229,5,20,0,0,229,230,5,
  	61,0,0,230,231,3,42,21,0,231,37,1,0,0,0,232,233,5,20,0,0,233,234,5,61,
  	0,0,234,235,3,40,20,0,235,39,1,0,0,0,236,237,5,85,0,0,237,238,7,1,0,0,
  	238,239,5,85,0,0,239,41,1,0,0,0,240,241,5,84,0,0,241,242,7,1,0,0,242,
  	243,5,84,0,0,243,43,1,0,0,0,244,245,3,46,23,0,245,246,5,82,0,0,246,247,
  	5,84,0,0,247,248,5,49,0,0,248,45,1,0,0,0,249,254,3,48,24,0,250,254,3,
  	50,25,0,251,254,3,52,26,0,252,254,3,54,27,0,253,249,1,0,0,0,253,250,1,
  	0,0,0,253,251,1,0,0,0,253,252,1,0,0,0,254,47,1,0,0,0,255,256,5,44,0,0,
  	256,257,5,30,0,0,257,258,5,55,0,0,258,259,5,83,0,0,259,49,1,0,0,0,260,
  	261,5,44,0,0,261,262,5,40,0,0,262,51,1,0,0,0,263,264,5,27,0,0,264,53,
  	1,0,0,0,265,266,5,26,0,0,266,55,1,0,0,0,267,268,5,3,0,0,268,273,5,57,
  	0,0,269,270,5,3,0,0,270,273,5,51,0,0,271,273,5,19,0,0,272,267,1,0,0,0,
  	272,269,1,0,0,0,272,271,1,0,0,0,273,57,1,0,0,0,274,275,5,38,0,0,275,276,
  	3,26,13,0,276,277,7,2,0,0,277,59,1,0,0,0,278,279,5,62,0,0,279,281,5,15,
  	0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,282,1,0,0,0,282,283,3,62,31,0,
  	283,284,7,3,0,0,284,286,7,4,0,0,285,287,5,20,0,0,286,285,1,0,0,0,286,
  	287,1,0,0,0,287,288,1,0,0,0,288,289,3,70,35,0,289,302,1,0,0,0,290,291,
  	5,62,0,0,291,293,5,15,0,0,292,290,1,0,0,0,292,293,1,0,0,0,293,294,1,0,
  	0,0,294,295,3,68,34,0,295,297,5,46,0,0,296,298,5,20,0,0,297,296,1,0,0,
  	0,297,298,1,0,0,0,298,299,1,0,0,0,299,300,3,70,35,0,300,302,1,0,0,0,301,
  	280,1,0,0,0,301,292,1,0,0,0,302,61,1,0,0,0,303,307,3,64,32,0,304,307,
  	3,66,33,0,305,307,3,68,34,0,306,303,1,0,0,0,306,304,1,0,0,0,306,305,1,
  	0,0,0,307,63,1,0,0,0,308,309,3,28,14,0,309,311,5,4,0,0,310,312,5,55,0,
  	0,311,310,1,0,0,0,311,312,1,0,0,0,312,65,1,0,0,0,313,314,5,35,0,0,314,
  	316,3,28,14,0,315,317,5,55,0,0,316,315,1,0,0,0,316,317,1,0,0,0,317,67,
  	1,0,0,0,318,319,5,37,0,0,319,69,1,0,0,0,320,333,5,83,0,0,321,323,5,14,
  	0,0,322,321,1,0,0,0,322,323,1,0,0,0,323,325,1,0,0,0,324,326,5,22,0,0,
  	325,324,1,0,0,0,325,326,1,0,0,0,326,328,1,0,0,0,327,329,5,20,0,0,328,
  	327,1,0,0,0,328,329,1,0,0,0,329,330,1,0,0,0,330,332,5,83,0,0,331,322,
  	1,0,0,0,332,335,1,0,0,0,333,331,1,0,0,0,333,334,1,0,0,0,334,71,1,0,0,
  	0,335,333,1,0,0,0,336,339,3,74,37,0,337,339,3,76,38,0,338,336,1,0,0,0,
  	338,337,1,0,0,0,339,73,1,0,0,0,340,341,5,20,0,0,341,342,5,83,0,0,342,
  	343,5,80,0,0,343,344,3,78,39,0,344,346,3,10,5,0,345,347,3,58,29,0,346,
  	345,1,0,0,0,346,347,1,0,0,0,347,75,1,0,0,0,348,349,5,20,0,0,349,350,5,
  	83,0,0,350,351,5,80,0,0,351,352,5,25,0,0,352,353,3,78,39,0,353,77,1,0,
  	0,0,354,359,3,80,40,0,355,356,5,72,0,0,356,358,3,80,40,0,357,355,1,0,
  	0,0,358,361,1,0,0,0,359,357,1,0,0,0,359,360,1,0,0,0,360,79,1,0,0,0,361,
  	359,1,0,0,0,362,367,5,17,0,0,363,367,3,82,41,0,364,367,3,86,43,0,365,
  	367,3,84,42,0,366,362,1,0,0,0,366,363,1,0,0,0,366,364,1,0,0,0,366,365,
  	1,0,0,0,367,81,1,0,0,0,368,369,5,5,0,0,369,83,1,0,0,0,370,371,5,6,0,0,
  	371,372,3,26,13,0,372,373,5,7,0,0,373,374,5,73,0,0,374,375,5,50,0,0,375,
  	376,5,68,0,0,376,85,1,0,0,0,377,378,5,8,0,0,378,379,5,16,0,0,379,87,1,
  	0,0,0,380,385,3,90,45,0,381,385,3,92,46,0,382,385,3,94,47,0,383,385,3,
  	102,51,0,384,380,1,0,0,0,384,381,1,0,0,0,384,382,1,0,0,0,384,383,1,0,
  	0,0,385,89,1,0,0,0,386,390,3,96,48,0,387,390,3,100,50,0,388,390,3,98,
  	49,0,389,386,1,0,0,0,389,387,1,0,0,0,389,388,1,0,0,0,390,91,1,0,0,0,391,
  	392,5,59,0,0,392,393,5,57,0,0,393,394,5,66,0,0,394,395,5,23,0,0,395,405,
  	5,16,0,0,396,398,5,14,0,0,397,396,1,0,0,0,397,398,1,0,0,0,398,400,1,0,
  	0,0,399,401,5,22,0,0,400,399,1,0,0,0,400,401,1,0,0,0,401,402,1,0,0,0,
  	402,404,5,16,0,0,403,397,1,0,0,0,404,407,1,0,0,0,405,403,1,0,0,0,405,
  	406,1,0,0,0,406,93,1,0,0,0,407,405,1,0,0,0,408,409,5,59,0,0,409,410,5,
  	33,0,0,410,411,5,66,0,0,411,412,5,23,0,0,412,422,5,16,0,0,413,415,5,14,
  	0,0,414,413,1,0,0,0,414,415,1,0,0,0,415,417,1,0,0,0,416,418,5,22,0,0,
  	417,416,1,0,0,0,417,418,1,0,0,0,418,419,1,0,0,0,419,421,5,16,0,0,420,
  	414,1,0,0,0,421,424,1,0,0,0,422,420,1,0,0,0,422,423,1,0,0,0,423,95,1,
  	0,0,0,424,422,1,0,0,0,425,426,5,28,0,0,426,427,5,20,0,0,427,428,5,48,
  	0,0,428,429,5,83,0,0,429,430,5,21,0,0,430,431,3,104,52,0,431,432,5,81,
  	0,0,432,433,5,20,0,0,433,434,5,60,0,0,434,435,5,55,0,0,435,436,3,28,14,
  	0,436,97,1,0,0,0,437,438,5,28,0,0,438,439,5,20,0,0,439,440,5,48,0,0,440,
  	441,5,83,0,0,441,442,5,21,0,0,442,443,3,104,52,0,443,444,5,81,0,0,444,
  	445,5,20,0,0,445,446,5,47,0,0,446,447,5,55,0,0,447,448,3,28,14,0,448,
  	449,5,22,0,0,449,450,5,20,0,0,450,451,5,79,0,0,451,452,5,55,0,0,452,453,
  	3,28,14,0,453,99,1,0,0,0,454,455,5,28,0,0,455,456,5,20,0,0,456,457,5,
  	48,0,0,457,458,5,83,0,0,458,459,5,21,0,0,459,460,3,104,52,0,460,101,1,
  	0,0,0,461,462,5,28,0,0,462,463,5,20,0,0,463,476,5,83,0,0,464,466,5,14,
  	0,0,465,464,1,0,0,0,465,466,1,0,0,0,466,468,1,0,0,0,467,469,5,22,0,0,
  	468,467,1,0,0,0,468,469,1,0,0,0,469,471,1,0,0,0,470,472,5,20,0,0,471,
  	470,1,0,0,0,471,472,1,0,0,0,472,473,1,0,0,0,473,475,5,83,0,0,474,465,
  	1,0,0,0,475,478,1,0,0,0,476,474,1,0,0,0,476,477,1,0,0,0,477,103,1,0,0,
  	0,478,476,1,0,0,0,479,480,5,9,0,0,480,481,3,28,14,0,481,482,5,14,0,0,
  	482,483,3,28,14,0,483,484,5,10,0,0,484,105,1,0,0,0,48,111,125,129,134,
  	143,149,159,164,175,182,186,190,194,201,205,214,222,226,253,272,280,286,
  	292,297,301,306,311,316,322,325,328,333,338,346,359,366,384,389,397,400,
  	405,414,417,422,465,468,471,476
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
    setState(106);
    decl_Ped();
    setState(107);
    match(BehaviorParser::T__0);
    setState(109); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(108);
      statement();
      setState(111); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5188146942798987264) != 0) || _la == BehaviorParser::THE

    || _la == BehaviorParser::NUMBER);
   
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
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      event();
      setState(114);
      match(BehaviorParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      declaration();
      setState(117);
      match(BehaviorParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(119);
      ped_Selector();
      setState(120);
      match(BehaviorParser::T__0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(122);
      action();
      setState(123);
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
    setState(129);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(127);
      event_Single();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(128);
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
    setState(131);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(132);
    match(BehaviorParser::EVNT);
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(133);
      match(BehaviorParser::EVENT);
    }
    setState(136);
    match(BehaviorParser::WILL);
    setState(137);
    match(BehaviorParser::OCCUR);
    setState(138);
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

tree::TerminalNode* BehaviorParser::Event_LastingContext::COMMA() {
  return getToken(BehaviorParser::COMMA, 0);
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
    setState(140);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::AN

    || _la == BehaviorParser::THE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(141);
    match(BehaviorParser::EVNT);
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(142);
      match(BehaviorParser::EVENT);
    }
    setState(145);
    match(BehaviorParser::WILL);
    setState(146);
    match(BehaviorParser::OCCUR);
    setState(147);
    condition();
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::COMMA) {
      setState(148);
      match(BehaviorParser::COMMA);
    }
    setState(151);
    match(BehaviorParser::AND);
    setState(152);
    match(BehaviorParser::END);
    setState(153);
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
    setState(155);
    sub_condition();
    setState(159);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(156);
        connector(); 
      }
      setState(161);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
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
    setState(164);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(162);
        or_Connector();
        break;
      }

      case BehaviorParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(163);
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
    setState(166);
    match(BehaviorParser::OR);
    setState(167);
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
    setState(169);
    match(BehaviorParser::AND);
    setState(170);
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
  enterRule(_localctx, 18, BehaviorParser::RuleSub_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::AFTER: {
        enterOuterAlt(_localctx, 1);
        setState(172);
        condition_Time_Elapsed_From_Event();
        break;
      }

      case BehaviorParser::GIVEN: {
        enterOuterAlt(_localctx, 2);
        setState(173);
        condition_Event_Occurred();
        break;
      }

      case BehaviorParser::WHILE: {
        enterOuterAlt(_localctx, 3);
        setState(174);
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

BehaviorParser::Value_numericContext* BehaviorParser::Condition_Time_Elapsed_From_EventContext::value_numeric() {
  return getRuleContext<BehaviorParser::Value_numericContext>(0);
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
    setState(177);
    match(BehaviorParser::AFTER);
    setState(178);
    value_numeric();
    setState(179);
    match(BehaviorParser::SECONDS);
    setState(180);
    match(BehaviorParser::FROM);
    setState(182);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(181);
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
    setState(184);
    match(BehaviorParser::EVNT);
    setState(186);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(185);
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
    setState(188);
    match(BehaviorParser::GIVEN);
    setState(190);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(189);
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
    setState(192);
    match(BehaviorParser::EVNT);
    setState(194);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(193);
      match(BehaviorParser::EVENT);
    }
    setState(196);
    match(BehaviorParser::HAS);
    setState(197);
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
    setState(199);
    match(BehaviorParser::WHILE);
    setState(201);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::AN

    || _la == BehaviorParser::THE) {
      setState(200);
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
    setState(203);
    match(BehaviorParser::EVNT);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::EVENT) {
      setState(204);
      match(BehaviorParser::EVENT);
    }
    setState(207);
    match(BehaviorParser::IS);
    setState(208);
    match(BehaviorParser::OCCURRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_numericContext ------------------------------------------------------------------

BehaviorParser::Value_numericContext::Value_numericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Value_numberContext* BehaviorParser::Value_numericContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
}

BehaviorParser::Value_floatContext* BehaviorParser::Value_numericContext::value_float() {
  return getRuleContext<BehaviorParser::Value_floatContext>(0);
}

BehaviorParser::Value_rangeContext* BehaviorParser::Value_numericContext::value_range() {
  return getRuleContext<BehaviorParser::Value_rangeContext>(0);
}

BehaviorParser::Value_randomContext* BehaviorParser::Value_numericContext::value_random() {
  return getRuleContext<BehaviorParser::Value_randomContext>(0);
}


size_t BehaviorParser::Value_numericContext::getRuleIndex() const {
  return BehaviorParser::RuleValue_numeric;
}


std::any BehaviorParser::Value_numericContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitValue_numeric(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Value_numericContext* BehaviorParser::value_numeric() {
  Value_numericContext *_localctx = _tracker.createInstance<Value_numericContext>(_ctx, getState());
  enterRule(_localctx, 26, BehaviorParser::RuleValue_numeric);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(214);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(210);
      value_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      value_float();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(212);
      value_range();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(213);
      value_random();
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

//----------------- Value_numberContext ------------------------------------------------------------------

BehaviorParser::Value_numberContext::Value_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Value_numberContext::NUMBER() {
  return getToken(BehaviorParser::NUMBER, 0);
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
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(BehaviorParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_floatContext ------------------------------------------------------------------

BehaviorParser::Value_floatContext::Value_floatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Value_floatContext::FLOAT() {
  return getToken(BehaviorParser::FLOAT, 0);
}


size_t BehaviorParser::Value_floatContext::getRuleIndex() const {
  return BehaviorParser::RuleValue_float;
}


std::any BehaviorParser::Value_floatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitValue_float(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Value_floatContext* BehaviorParser::value_float() {
  Value_floatContext *_localctx = _tracker.createInstance<Value_floatContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorParser::RuleValue_float);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(BehaviorParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_rangeContext ------------------------------------------------------------------

BehaviorParser::Value_rangeContext::Value_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Float_rangeContext* BehaviorParser::Value_rangeContext::float_range() {
  return getRuleContext<BehaviorParser::Float_rangeContext>(0);
}

BehaviorParser::Number_rangeContext* BehaviorParser::Value_rangeContext::number_range() {
  return getRuleContext<BehaviorParser::Number_rangeContext>(0);
}


size_t BehaviorParser::Value_rangeContext::getRuleIndex() const {
  return BehaviorParser::RuleValue_range;
}


std::any BehaviorParser::Value_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitValue_range(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Value_rangeContext* BehaviorParser::value_range() {
  Value_rangeContext *_localctx = _tracker.createInstance<Value_rangeContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorParser::RuleValue_range);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        float_range();
        break;
      }

      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(221);
        number_range();
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

//----------------- Value_randomContext ------------------------------------------------------------------

BehaviorParser::Value_randomContext::Value_randomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Random_floatContext* BehaviorParser::Value_randomContext::random_float() {
  return getRuleContext<BehaviorParser::Random_floatContext>(0);
}

BehaviorParser::Random_numberContext* BehaviorParser::Value_randomContext::random_number() {
  return getRuleContext<BehaviorParser::Random_numberContext>(0);
}


size_t BehaviorParser::Value_randomContext::getRuleIndex() const {
  return BehaviorParser::RuleValue_random;
}


std::any BehaviorParser::Value_randomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitValue_random(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Value_randomContext* BehaviorParser::value_random() {
  Value_randomContext *_localctx = _tracker.createInstance<Value_randomContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorParser::RuleValue_random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(224);
      random_float();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(225);
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

BehaviorParser::Number_rangeContext* BehaviorParser::Random_numberContext::number_range() {
  return getRuleContext<BehaviorParser::Number_rangeContext>(0);
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
  enterRule(_localctx, 36, BehaviorParser::RuleRandom_number);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(BehaviorParser::AN);
    setState(229);
    match(BehaviorParser::RANDOM);
    setState(230);
    number_range();
   
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

BehaviorParser::Float_rangeContext* BehaviorParser::Random_floatContext::float_range() {
  return getRuleContext<BehaviorParser::Float_rangeContext>(0);
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
  enterRule(_localctx, 38, BehaviorParser::RuleRandom_float);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(BehaviorParser::AN);
    setState(233);
    match(BehaviorParser::RANDOM);
    setState(234);
    float_range();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Float_rangeContext ------------------------------------------------------------------

BehaviorParser::Float_rangeContext::Float_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Float_rangeContext::FLOAT() {
  return getTokens(BehaviorParser::FLOAT);
}

tree::TerminalNode* BehaviorParser::Float_rangeContext::FLOAT(size_t i) {
  return getToken(BehaviorParser::FLOAT, i);
}

tree::TerminalNode* BehaviorParser::Float_rangeContext::TO() {
  return getToken(BehaviorParser::TO, 0);
}


size_t BehaviorParser::Float_rangeContext::getRuleIndex() const {
  return BehaviorParser::RuleFloat_range;
}


std::any BehaviorParser::Float_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitFloat_range(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Float_rangeContext* BehaviorParser::float_range() {
  Float_rangeContext *_localctx = _tracker.createInstance<Float_rangeContext>(_ctx, getState());
  enterRule(_localctx, 40, BehaviorParser::RuleFloat_range);
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
    setState(236);
    match(BehaviorParser::FLOAT);
    setState(237);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__1 || _la == BehaviorParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(238);
    match(BehaviorParser::FLOAT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Number_rangeContext ------------------------------------------------------------------

BehaviorParser::Number_rangeContext::Number_rangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BehaviorParser::Number_rangeContext::NUMBER() {
  return getTokens(BehaviorParser::NUMBER);
}

tree::TerminalNode* BehaviorParser::Number_rangeContext::NUMBER(size_t i) {
  return getToken(BehaviorParser::NUMBER, i);
}

tree::TerminalNode* BehaviorParser::Number_rangeContext::TO() {
  return getToken(BehaviorParser::TO, 0);
}


size_t BehaviorParser::Number_rangeContext::getRuleIndex() const {
  return BehaviorParser::RuleNumber_range;
}


std::any BehaviorParser::Number_rangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitNumber_range(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Number_rangeContext* BehaviorParser::number_range() {
  Number_rangeContext *_localctx = _tracker.createInstance<Number_rangeContext>(_ctx, getState());
  enterRule(_localctx, 42, BehaviorParser::RuleNumber_range);
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
    setState(240);
    match(BehaviorParser::NUMBER);
    setState(241);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__1 || _la == BehaviorParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(242);
    match(BehaviorParser::NUMBER);
   
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
  enterRule(_localctx, 44, BehaviorParser::RuleDirection);

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
    dir();
    setState(245);
    match(BehaviorParser::WITHIN);
    setState(246);
    match(BehaviorParser::NUMBER);
    setState(247);
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
  enterRule(_localctx, 46, BehaviorParser::RuleDir);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(249);
      direction_of();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(250);
      infront();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(251);
      behind();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(252);
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
  enterRule(_localctx, 48, BehaviorParser::RuleDirection_of);

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
    match(BehaviorParser::IN);
    setState(256);
    match(BehaviorParser::DIRECTION);
    setState(257);
    match(BehaviorParser::OF);
    setState(258);
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
  enterRule(_localctx, 50, BehaviorParser::RuleInfront);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(BehaviorParser::IN);
    setState(261);
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
  enterRule(_localctx, 52, BehaviorParser::RuleBehind);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
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
  enterRule(_localctx, 54, BehaviorParser::RuleAround);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
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
  enterRule(_localctx, 56, BehaviorParser::RuleObject);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(272);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(267);
      match(BehaviorParser::T__2);
      setState(268);
      match(BehaviorParser::PEDESTRIAN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(269);
      match(BehaviorParser::T__2);
      setState(270);
      match(BehaviorParser::OBSTACLE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(271);
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

BehaviorParser::Value_numericContext* BehaviorParser::DurationContext::value_numeric() {
  return getRuleContext<BehaviorParser::Value_numericContext>(0);
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
  enterRule(_localctx, 58, BehaviorParser::RuleDuration);
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
    setState(274);
    match(BehaviorParser::FOR);
    setState(275);
    value_numeric();
    setState(276);
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
  enterRule(_localctx, 60, BehaviorParser::RulePed_Selector);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(301);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(280);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::REQUIRED) {
        setState(278);
        match(BehaviorParser::REQUIRED);
        setState(279);
        match(BehaviorParser::COLON);
      }
      setState(282);
      selector();
      setState(283);
      _la = _input->LA(1);
      if (!(((((_la - 57) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 57)) & 67108867) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(284);
      _la = _input->LA(1);
      if (!(_la == BehaviorParser::ARE

      || _la == BehaviorParser::IS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(286);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(285);
        match(BehaviorParser::AN);
      }
      setState(288);
      id_list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(292);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::REQUIRED) {
        setState(290);
        match(BehaviorParser::REQUIRED);
        setState(291);
        match(BehaviorParser::COLON);
      }
      setState(294);
      selector_Everyone();
      setState(295);
      match(BehaviorParser::IS);
      setState(297);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(296);
        match(BehaviorParser::AN);
      }
      setState(299);
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
  enterRule(_localctx, 62, BehaviorParser::RuleSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(306);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 1);
        setState(303);
        selector_Percent();
        break;
      }

      case BehaviorParser::EXACTLY: {
        enterOuterAlt(_localctx, 2);
        setState(304);
        selector_Exactly_N_Random();
        break;
      }

      case BehaviorParser::EVERYONE: {
        enterOuterAlt(_localctx, 3);
        setState(305);
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
  enterRule(_localctx, 64, BehaviorParser::RuleSelector_Percent);
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
    setState(308);
    value_number();
    setState(309);
    match(BehaviorParser::T__3);
    setState(311);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::OF) {
      setState(310);
      match(BehaviorParser::OF);
    }
   
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
  enterRule(_localctx, 66, BehaviorParser::RuleSelector_Exactly_N_Random);
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
    setState(313);
    match(BehaviorParser::EXACTLY);
    setState(314);
    value_number();
    setState(316);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::OF) {
      setState(315);
      match(BehaviorParser::OF);
    }
   
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
  enterRule(_localctx, 68, BehaviorParser::RuleSelector_Everyone);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
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
  enterRule(_localctx, 70, BehaviorParser::RuleId_list);
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
    setState(320);
    match(BehaviorParser::ID);
    setState(333);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5259264) != 0) || _la == BehaviorParser::ID) {
      setState(322);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(321);
        match(BehaviorParser::COMMA);
      }
      setState(325);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(324);
        match(BehaviorParser::AND);
      }
      setState(328);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(327);
        match(BehaviorParser::AN);
      }
      setState(330);
      match(BehaviorParser::ID);
      setState(335);
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
  enterRule(_localctx, 72, BehaviorParser::RuleAction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(338);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(336);
      conditional_action();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(337);
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
  enterRule(_localctx, 74, BehaviorParser::RuleConditional_action);
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
    setState(340);
    match(BehaviorParser::AN);
    setState(341);
    match(BehaviorParser::ID);
    setState(342);
    match(BehaviorParser::WILL);
    setState(343);
    sub_action();
    setState(344);
    condition();

    setState(346);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::FOR) {
      setState(345);
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
  enterRule(_localctx, 76, BehaviorParser::RuleUn_conditional_action);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    match(BehaviorParser::AN);
    setState(349);
    match(BehaviorParser::ID);
    setState(350);
    match(BehaviorParser::WILL);
    setState(351);
    match(BehaviorParser::ALWAYS);
    setState(352);
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
  enterRule(_localctx, 78, BehaviorParser::RuleSub_action);
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
    setState(354);
    action_atom();
    setState(359);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::THEN) {
      setState(355);
      match(BehaviorParser::THEN);
      setState(356);
      action_atom();
      setState(361);
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
  enterRule(_localctx, 80, BehaviorParser::RuleAction_atom);

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
    switch (_input->LA(1)) {
      case BehaviorParser::ACTION: {
        enterOuterAlt(_localctx, 1);
        setState(362);
        match(BehaviorParser::ACTION);
        break;
      }

      case BehaviorParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(363);
        action_Stop();
        break;
      }

      case BehaviorParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(364);
        action_Be();
        break;
      }

      case BehaviorParser::T__5: {
        enterOuterAlt(_localctx, 4);
        setState(365);
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
  enterRule(_localctx, 82, BehaviorParser::RuleAction_Stop);

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

BehaviorParser::Value_numericContext* BehaviorParser::Action_atom_Percent_Walk_SpeedContext::value_numeric() {
  return getRuleContext<BehaviorParser::Value_numericContext>(0);
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
  enterRule(_localctx, 84, BehaviorParser::RuleAction_atom_Percent_Walk_Speed);

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
    match(BehaviorParser::T__5);
    setState(371);
    value_numeric();
    setState(372);
    match(BehaviorParser::T__6);
    setState(373);
    match(BehaviorParser::THEIR);
    setState(374);
    match(BehaviorParser::NORMAL);
    setState(375);
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
  enterRule(_localctx, 86, BehaviorParser::RuleAction_Be);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(377);
    match(BehaviorParser::T__7);
    setState(378);
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
  enterRule(_localctx, 88, BehaviorParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(380);
      decl_Loc();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      decl_Ped_State();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(382);
      decl_Env_State();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(383);
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
  enterRule(_localctx, 90, BehaviorParser::RuleDecl_Loc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(389);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(386);
      decl_Loc_Area_Circle();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(387);
      decl_Loc_Point();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(388);
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
  enterRule(_localctx, 92, BehaviorParser::RuleDecl_Ped_State);
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
    setState(391);
    match(BehaviorParser::POSSIBLE);
    setState(392);
    match(BehaviorParser::PEDESTRIAN);
    setState(393);
    match(BehaviorParser::STATES);
    setState(394);
    match(BehaviorParser::ARE);

    setState(395);
    match(BehaviorParser::STATE);
    setState(405);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4276224) != 0)) {
      setState(397);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(396);
        match(BehaviorParser::COMMA);
      }
      setState(400);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(399);
        match(BehaviorParser::AND);
      }
      setState(402);
      match(BehaviorParser::STATE);
      setState(407);
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
  enterRule(_localctx, 94, BehaviorParser::RuleDecl_Env_State);
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
    setState(408);
    match(BehaviorParser::POSSIBLE);
    setState(409);
    match(BehaviorParser::ENVIRONMENT);
    setState(410);
    match(BehaviorParser::STATES);
    setState(411);
    match(BehaviorParser::ARE);

    setState(412);
    match(BehaviorParser::STATE);
    setState(422);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4276224) != 0)) {
      setState(414);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(413);
        match(BehaviorParser::COMMA);
      }
      setState(417);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(416);
        match(BehaviorParser::AND);
      }
      setState(419);
      match(BehaviorParser::STATE);
      setState(424);
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
  enterRule(_localctx, 96, BehaviorParser::RuleDecl_Loc_Area_Circle);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    match(BehaviorParser::CONSIDER);
    setState(426);
    match(BehaviorParser::AN);
    setState(427);
    match(BehaviorParser::LOCATION);
    setState(428);
    match(BehaviorParser::ID);
    setState(429);
    match(BehaviorParser::AT);
    setState(430);
    point();
    setState(431);
    match(BehaviorParser::WITH);
    setState(432);
    match(BehaviorParser::AN);
    setState(433);
    match(BehaviorParser::RADIUS);
    setState(434);
    match(BehaviorParser::OF);
    setState(435);
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
  enterRule(_localctx, 98, BehaviorParser::RuleDecl_Loc_Area_Rect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(437);
    match(BehaviorParser::CONSIDER);
    setState(438);
    match(BehaviorParser::AN);
    setState(439);
    match(BehaviorParser::LOCATION);
    setState(440);
    match(BehaviorParser::ID);
    setState(441);
    match(BehaviorParser::AT);
    setState(442);
    point();
    setState(443);
    match(BehaviorParser::WITH);
    setState(444);
    match(BehaviorParser::AN);
    setState(445);
    match(BehaviorParser::LENGTH);
    setState(446);
    match(BehaviorParser::OF);
    setState(447);
    value_number();
    setState(448);
    match(BehaviorParser::AND);
    setState(449);
    match(BehaviorParser::AN);
    setState(450);
    match(BehaviorParser::WIDTH);
    setState(451);
    match(BehaviorParser::OF);
    setState(452);
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
  enterRule(_localctx, 100, BehaviorParser::RuleDecl_Loc_Point);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    match(BehaviorParser::CONSIDER);
    setState(455);
    match(BehaviorParser::AN);
    setState(456);
    match(BehaviorParser::LOCATION);
    setState(457);
    match(BehaviorParser::ID);
    setState(458);
    match(BehaviorParser::AT);
    setState(459);
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
  enterRule(_localctx, 102, BehaviorParser::RuleDecl_Ped);
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
    setState(461);
    match(BehaviorParser::CONSIDER);
    setState(462);
    match(BehaviorParser::AN);

    setState(463);
    match(BehaviorParser::ID);
    setState(476);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 5259264) != 0) || _la == BehaviorParser::ID) {
      setState(465);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(464);
        match(BehaviorParser::COMMA);
      }
      setState(468);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AND) {
        setState(467);
        match(BehaviorParser::AND);
      }
      setState(471);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::AN) {
        setState(470);
        match(BehaviorParser::AN);
      }
      setState(473);
      match(BehaviorParser::ID);
      setState(478);
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
  enterRule(_localctx, 104, BehaviorParser::RulePoint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(BehaviorParser::T__8);
    setState(480);
    value_number();
    setState(481);
    match(BehaviorParser::COMMA);
    setState(482);
    value_number();
    setState(483);
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
