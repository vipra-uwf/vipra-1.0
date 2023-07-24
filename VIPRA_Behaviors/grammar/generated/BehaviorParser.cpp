
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
      "program", "statement", "event", "event_attribute", "event_name", 
      "event_start", "event_end", "condition", "connector", "or_Connector", 
      "and_Connector", "sub_condition", "condition_Time_Elapsed_From_Event", 
      "condition_Event_Occurred", "condition_Event_Occurring", "condition_Event_Starting", 
      "condition_Event_Ending", "condition_Spatial", "condition_Attribute", 
      "value_numeric", "value_number", "value_float", "value_range", "value_random", 
      "random_number", "random_float", "float_range", "number_range", "value_coord", 
      "duration", "attribute", "attr_value", "ped_Selector", "selector_attribute", 
      "selector_type", "selector_selector", "selector_from", "selector_required", 
      "selector", "selector_Percent", "selector_Exactly_N_Random", "selector_Everyone", 
      "group", "id_list", "action", "action_attribute", "action_stimulus", 
      "action_response", "action_duration", "action_target", "sub_action", 
      "action_atom", "set_atom", "scale_atom", "target", "self", "nearest_type", 
      "declaration", "decl_Loc", "decl_Ped_State", "decl_Env_State", "decl_Loc_Area_Circle", 
      "decl_Loc_Area_Rect", "decl_Loc_Point", "decl_Ped"
    },
    std::vector<std::string>{
      "", "'.'", "'-'", "'{'", "'}'", "'%'", "'('", "')'", "", "", "", "','", 
      "':'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "COMMENT", "LINE_COMMENT", "WS", "COMMA", 
      "COLON", "STATE_VAL", "EVNT", "AN", "AT", "ADD", "AND", "ARE", "AFTER", 
      "ALWAYS", "AROUND", "ACTION", "BEHIND", "CONSIDER", "DECIMAL", "DIRECTION", 
      "DURATION", "END", "ENDS", "ENVIRONMENT", "EVENT", "EXACTLY", "EVERY", 
      "EVERYONE", "ENDING", "FOR", "FROM", "FRONT", "FASTER", "GIVEN", "GOAL", 
      "GROUP", "HAS", "IN", "INTEGER", "IS", "IF", "LENGTH", "LOCATION", 
      "MAX", "METERS", "NAME", "NEAREST", "NORMAL", "OBSTACLE", "OCCUR", 
      "OCCURRED", "OCCURRING", "OF", "ON", "OR", "PEDESTRIAN", "PEDESTRIANS", 
      "POSSIBLE", "POSITION", "RADIUS", "RANDOM", "REQUIRED", "RESPONSE", 
      "SCALE", "SELF", "SELECT", "SELECTOR", "SET", "SECOND", "SECONDS", 
      "STATUS", "STARTING", "SLOWER", "STATES", "START", "STATE", "STARTS", 
      "SPEED", "SUBTRACT", "STIMULUS", "TARGET", "TO", "THE", "THAT", "THEN", 
      "THEIR", "THERES", "TYPES", "TYPE", "UNCONDITIONALLY", "VALUE", "VELOCITY", 
      "WHEN", "WHILE", "WIDTH", "WILL", "WITH", "WITHIN", "ID", "NUMBER", 
      "FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,108,501,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,7,
  	63,2,64,7,64,1,0,1,0,1,0,4,0,134,8,0,11,0,12,0,135,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,150,8,1,1,2,1,2,1,2,5,2,155,8,2,10,
  	2,12,2,158,9,2,1,3,1,3,1,3,3,3,163,8,3,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,
  	5,1,6,1,6,1,6,1,6,1,7,1,7,5,7,179,8,7,10,7,12,7,182,9,7,1,8,1,8,3,8,186,
  	8,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,3,11,200,
  	8,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,15,
  	1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,18,3,18,226,8,18,
  	1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,3,19,236,8,19,1,20,1,20,1,21,
  	1,21,1,22,1,22,3,22,244,8,22,1,23,1,23,3,23,248,8,23,1,24,1,24,1,24,1,
  	25,1,25,1,25,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,
  	28,1,28,1,28,3,28,270,8,28,3,28,272,8,28,1,28,1,28,1,29,1,29,1,29,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,30,1,30,1,30,3,30,288,8,30,1,31,1,31,1,31,
  	3,31,293,8,31,1,32,1,32,1,32,5,32,298,8,32,10,32,12,32,301,9,32,1,33,
  	1,33,1,33,1,33,3,33,307,8,33,1,34,1,34,1,34,1,34,1,35,1,35,1,35,1,35,
  	1,36,1,36,1,36,1,36,1,37,1,37,1,38,1,38,1,38,3,38,326,8,38,1,39,1,39,
  	1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,43,1,43,3,43,339,8,43,1,43,5,43,
  	342,8,43,10,43,12,43,345,9,43,1,44,1,44,1,44,1,44,1,44,1,44,5,44,353,
  	8,44,10,44,12,44,356,9,44,1,45,1,45,1,45,1,45,3,45,362,8,45,1,46,1,46,
  	1,46,1,46,1,47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,49,1,49,1,49,1,49,
  	1,50,1,50,1,50,5,50,383,8,50,10,50,12,50,386,9,50,1,51,1,51,3,51,390,
  	8,51,1,52,1,52,3,52,394,8,52,1,52,1,52,1,52,1,52,1,53,1,53,3,53,402,8,
  	53,1,53,1,53,1,53,1,54,1,54,3,54,409,8,54,1,55,1,55,1,56,1,56,1,56,1,
  	57,1,57,1,57,1,57,3,57,420,8,57,1,58,1,58,1,58,3,58,425,8,58,1,59,1,59,
  	1,59,1,59,1,59,3,59,432,8,59,1,59,5,59,435,8,59,10,59,12,59,438,9,59,
  	1,60,1,60,1,60,1,60,1,60,3,60,445,8,60,1,60,5,60,448,8,60,10,60,12,60,
  	451,9,60,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,1,61,
  	1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,1,62,
  	1,62,1,62,1,62,1,63,1,63,1,63,1,63,1,63,1,63,1,63,1,64,1,64,1,64,1,64,
  	3,64,493,8,64,1,64,5,64,496,8,64,10,64,12,64,499,9,64,1,64,0,0,65,0,2,
  	4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
  	52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,
  	98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,0,3,2,
  	0,2,2,89,89,1,0,76,77,2,0,63,64,106,106,494,0,130,1,0,0,0,2,149,1,0,0,
  	0,4,151,1,0,0,0,6,162,1,0,0,0,8,164,1,0,0,0,10,168,1,0,0,0,12,172,1,0,
  	0,0,14,176,1,0,0,0,16,185,1,0,0,0,18,187,1,0,0,0,20,190,1,0,0,0,22,199,
  	1,0,0,0,24,201,1,0,0,0,26,206,1,0,0,0,28,210,1,0,0,0,30,213,1,0,0,0,32,
  	216,1,0,0,0,34,219,1,0,0,0,36,225,1,0,0,0,38,235,1,0,0,0,40,237,1,0,0,
  	0,42,239,1,0,0,0,44,243,1,0,0,0,46,247,1,0,0,0,48,249,1,0,0,0,50,252,
  	1,0,0,0,52,255,1,0,0,0,54,259,1,0,0,0,56,263,1,0,0,0,58,275,1,0,0,0,60,
  	287,1,0,0,0,62,292,1,0,0,0,64,294,1,0,0,0,66,306,1,0,0,0,68,308,1,0,0,
  	0,70,312,1,0,0,0,72,316,1,0,0,0,74,320,1,0,0,0,76,325,1,0,0,0,78,327,
  	1,0,0,0,80,330,1,0,0,0,82,332,1,0,0,0,84,334,1,0,0,0,86,336,1,0,0,0,88,
  	346,1,0,0,0,90,361,1,0,0,0,92,363,1,0,0,0,94,367,1,0,0,0,96,371,1,0,0,
  	0,98,375,1,0,0,0,100,379,1,0,0,0,102,389,1,0,0,0,104,391,1,0,0,0,106,
  	399,1,0,0,0,108,408,1,0,0,0,110,410,1,0,0,0,112,412,1,0,0,0,114,419,1,
  	0,0,0,116,424,1,0,0,0,118,426,1,0,0,0,120,439,1,0,0,0,122,452,1,0,0,0,
  	124,464,1,0,0,0,126,481,1,0,0,0,128,488,1,0,0,0,130,131,3,128,64,0,131,
  	133,5,1,0,0,132,134,3,2,1,0,133,132,1,0,0,0,134,135,1,0,0,0,135,133,1,
  	0,0,0,135,136,1,0,0,0,136,1,1,0,0,0,137,138,3,4,2,0,138,139,5,1,0,0,139,
  	150,1,0,0,0,140,141,3,114,57,0,141,142,5,1,0,0,142,150,1,0,0,0,143,144,
  	3,64,32,0,144,145,5,1,0,0,145,150,1,0,0,0,146,147,3,88,44,0,147,148,5,
  	1,0,0,148,150,1,0,0,0,149,137,1,0,0,0,149,140,1,0,0,0,149,143,1,0,0,0,
  	149,146,1,0,0,0,150,3,1,0,0,0,151,152,5,32,0,0,152,156,5,12,0,0,153,155,
  	3,6,3,0,154,153,1,0,0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,157,1,0,0,
  	0,157,5,1,0,0,0,158,156,1,0,0,0,159,163,3,8,4,0,160,163,3,10,5,0,161,
  	163,3,12,6,0,162,159,1,0,0,0,162,160,1,0,0,0,162,161,1,0,0,0,163,7,1,
  	0,0,0,164,165,5,53,0,0,165,166,5,12,0,0,166,167,5,106,0,0,167,9,1,0,0,
  	0,168,169,5,82,0,0,169,170,5,12,0,0,170,171,3,14,7,0,171,11,1,0,0,0,172,
  	173,5,29,0,0,173,174,5,12,0,0,174,175,3,14,7,0,175,13,1,0,0,0,176,180,
  	3,22,11,0,177,179,3,16,8,0,178,177,1,0,0,0,179,182,1,0,0,0,180,178,1,
  	0,0,0,180,181,1,0,0,0,181,15,1,0,0,0,182,180,1,0,0,0,183,186,3,18,9,0,
  	184,186,3,20,10,0,185,183,1,0,0,0,185,184,1,0,0,0,186,17,1,0,0,0,187,
  	188,5,62,0,0,188,189,3,22,11,0,189,19,1,0,0,0,190,191,5,18,0,0,191,192,
  	3,22,11,0,192,21,1,0,0,0,193,200,3,24,12,0,194,200,3,26,13,0,195,200,
  	3,28,14,0,196,200,3,30,15,0,197,200,3,32,16,0,198,200,3,34,17,0,199,193,
  	1,0,0,0,199,194,1,0,0,0,199,195,1,0,0,0,199,196,1,0,0,0,199,197,1,0,0,
  	0,199,198,1,0,0,0,200,23,1,0,0,0,201,202,3,38,19,0,202,203,5,77,0,0,203,
  	204,5,38,0,0,204,205,5,14,0,0,205,25,1,0,0,0,206,207,5,14,0,0,207,208,
  	5,44,0,0,208,209,5,58,0,0,209,27,1,0,0,0,210,211,5,14,0,0,211,212,5,59,
  	0,0,212,29,1,0,0,0,213,214,5,14,0,0,214,215,5,79,0,0,215,31,1,0,0,0,216,
  	217,5,14,0,0,217,218,5,36,0,0,218,33,1,0,0,0,219,220,5,88,0,0,220,221,
  	5,105,0,0,221,222,3,38,19,0,222,223,5,52,0,0,223,35,1,0,0,0,224,226,5,
  	88,0,0,225,224,1,0,0,0,225,226,1,0,0,0,226,227,1,0,0,0,227,228,3,60,30,
  	0,228,229,5,47,0,0,229,230,3,62,31,0,230,37,1,0,0,0,231,236,3,40,20,0,
  	232,236,3,42,21,0,233,236,3,44,22,0,234,236,3,46,23,0,235,231,1,0,0,0,
  	235,232,1,0,0,0,235,233,1,0,0,0,235,234,1,0,0,0,236,39,1,0,0,0,237,238,
  	5,107,0,0,238,41,1,0,0,0,239,240,5,108,0,0,240,43,1,0,0,0,241,244,3,52,
  	26,0,242,244,3,54,27,0,243,241,1,0,0,0,243,242,1,0,0,0,244,45,1,0,0,0,
  	245,248,3,50,25,0,246,248,3,48,24,0,247,245,1,0,0,0,247,246,1,0,0,0,248,
  	47,1,0,0,0,249,250,5,68,0,0,250,251,3,54,27,0,251,49,1,0,0,0,252,253,
  	5,68,0,0,253,254,3,52,26,0,254,51,1,0,0,0,255,256,5,108,0,0,256,257,7,
  	0,0,0,257,258,5,108,0,0,258,53,1,0,0,0,259,260,5,107,0,0,260,261,7,0,
  	0,0,261,262,5,107,0,0,262,55,1,0,0,0,263,264,5,3,0,0,264,271,3,38,19,
  	0,265,266,5,11,0,0,266,269,3,38,19,0,267,268,5,11,0,0,268,270,3,38,19,
  	0,269,267,1,0,0,0,269,270,1,0,0,0,270,272,1,0,0,0,271,265,1,0,0,0,271,
  	272,1,0,0,0,272,273,1,0,0,0,273,274,5,4,0,0,274,57,1,0,0,0,275,276,3,
  	38,19,0,276,277,7,1,0,0,277,59,1,0,0,0,278,288,5,66,0,0,279,288,5,99,
  	0,0,280,288,5,42,0,0,281,288,5,83,0,0,282,288,5,50,0,0,283,288,5,78,0,
  	0,284,285,5,51,0,0,285,288,5,85,0,0,286,288,1,0,0,0,287,278,1,0,0,0,287,
  	279,1,0,0,0,287,280,1,0,0,0,287,281,1,0,0,0,287,282,1,0,0,0,287,283,1,
  	0,0,0,287,284,1,0,0,0,287,286,1,0,0,0,288,61,1,0,0,0,289,293,3,38,19,
  	0,290,293,3,56,28,0,291,293,5,13,0,0,292,289,1,0,0,0,292,290,1,0,0,0,
  	292,291,1,0,0,0,293,63,1,0,0,0,294,295,5,74,0,0,295,299,5,12,0,0,296,
  	298,3,66,33,0,297,296,1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,300,
  	1,0,0,0,300,65,1,0,0,0,301,299,1,0,0,0,302,307,3,68,34,0,303,307,3,70,
  	35,0,304,307,3,72,36,0,305,307,3,74,37,0,306,302,1,0,0,0,306,303,1,0,
  	0,0,306,304,1,0,0,0,306,305,1,0,0,0,307,67,1,0,0,0,308,309,5,96,0,0,309,
  	310,5,12,0,0,310,311,3,86,43,0,311,69,1,0,0,0,312,313,5,73,0,0,313,314,
  	5,12,0,0,314,315,3,76,38,0,315,71,1,0,0,0,316,317,5,38,0,0,317,318,5,
  	12,0,0,318,319,3,84,42,0,319,73,1,0,0,0,320,321,5,69,0,0,321,75,1,0,0,
  	0,322,326,3,78,39,0,323,326,3,80,40,0,324,326,3,82,41,0,325,322,1,0,0,
  	0,325,323,1,0,0,0,325,324,1,0,0,0,326,77,1,0,0,0,327,328,3,40,20,0,328,
  	329,5,5,0,0,329,79,1,0,0,0,330,331,3,40,20,0,331,81,1,0,0,0,332,333,5,
  	35,0,0,333,83,1,0,0,0,334,335,7,2,0,0,335,85,1,0,0,0,336,343,5,106,0,
  	0,337,339,5,11,0,0,338,337,1,0,0,0,338,339,1,0,0,0,339,340,1,0,0,0,340,
  	342,5,106,0,0,341,338,1,0,0,0,342,345,1,0,0,0,343,341,1,0,0,0,343,344,
  	1,0,0,0,344,87,1,0,0,0,345,343,1,0,0,0,346,347,5,23,0,0,347,348,5,6,0,
  	0,348,349,5,106,0,0,349,350,5,7,0,0,350,354,5,12,0,0,351,353,3,90,45,
  	0,352,351,1,0,0,0,353,356,1,0,0,0,354,352,1,0,0,0,354,355,1,0,0,0,355,
  	89,1,0,0,0,356,354,1,0,0,0,357,362,3,94,47,0,358,362,3,92,46,0,359,362,
  	3,96,48,0,360,362,3,98,49,0,361,357,1,0,0,0,361,358,1,0,0,0,361,359,1,
  	0,0,0,361,360,1,0,0,0,362,91,1,0,0,0,363,364,5,87,0,0,364,365,5,12,0,
  	0,365,366,3,14,7,0,366,93,1,0,0,0,367,368,5,70,0,0,368,369,5,12,0,0,369,
  	370,3,100,50,0,370,95,1,0,0,0,371,372,5,28,0,0,372,373,5,12,0,0,373,374,
  	3,58,29,0,374,97,1,0,0,0,375,376,5,88,0,0,376,377,5,12,0,0,377,378,3,
  	108,54,0,378,99,1,0,0,0,379,384,3,102,51,0,380,381,5,11,0,0,381,383,3,
  	102,51,0,382,380,1,0,0,0,383,386,1,0,0,0,384,382,1,0,0,0,384,385,1,0,
  	0,0,385,101,1,0,0,0,386,384,1,0,0,0,387,390,3,104,52,0,388,390,3,106,
  	53,0,389,387,1,0,0,0,389,388,1,0,0,0,390,103,1,0,0,0,391,393,5,75,0,0,
  	392,394,5,88,0,0,393,392,1,0,0,0,393,394,1,0,0,0,394,395,1,0,0,0,395,
  	396,3,60,30,0,396,397,5,89,0,0,397,398,3,62,31,0,398,105,1,0,0,0,399,
  	401,5,71,0,0,400,402,5,88,0,0,401,400,1,0,0,0,401,402,1,0,0,0,402,403,
  	1,0,0,0,403,404,3,60,30,0,404,405,3,62,31,0,405,107,1,0,0,0,406,409,3,
  	110,55,0,407,409,3,112,56,0,408,406,1,0,0,0,408,407,1,0,0,0,409,109,1,
  	0,0,0,410,411,5,72,0,0,411,111,1,0,0,0,412,413,5,54,0,0,413,414,5,106,
  	0,0,414,113,1,0,0,0,415,420,3,116,58,0,416,420,3,118,59,0,417,420,3,120,
  	60,0,418,420,3,128,64,0,419,415,1,0,0,0,419,416,1,0,0,0,419,417,1,0,0,
  	0,419,418,1,0,0,0,420,115,1,0,0,0,421,425,3,122,61,0,422,425,3,126,63,
  	0,423,425,3,124,62,0,424,421,1,0,0,0,424,422,1,0,0,0,424,423,1,0,0,0,
  	425,117,1,0,0,0,426,427,5,63,0,0,427,428,5,81,0,0,428,429,5,12,0,0,429,
  	436,5,13,0,0,430,432,5,11,0,0,431,430,1,0,0,0,431,432,1,0,0,0,432,433,
  	1,0,0,0,433,435,5,13,0,0,434,431,1,0,0,0,435,438,1,0,0,0,436,434,1,0,
  	0,0,436,437,1,0,0,0,437,119,1,0,0,0,438,436,1,0,0,0,439,440,5,31,0,0,
  	440,441,5,81,0,0,441,442,5,12,0,0,442,449,5,13,0,0,443,445,5,11,0,0,444,
  	443,1,0,0,0,444,445,1,0,0,0,445,446,1,0,0,0,446,448,5,13,0,0,447,444,
  	1,0,0,0,448,451,1,0,0,0,449,447,1,0,0,0,449,450,1,0,0,0,450,121,1,0,0,
  	0,451,449,1,0,0,0,452,453,5,25,0,0,453,454,5,15,0,0,454,455,5,50,0,0,
  	455,456,5,106,0,0,456,457,5,16,0,0,457,458,3,56,28,0,458,459,5,104,0,
  	0,459,460,5,15,0,0,460,461,5,67,0,0,461,462,5,60,0,0,462,463,3,38,19,
  	0,463,123,1,0,0,0,464,465,5,25,0,0,465,466,5,15,0,0,466,467,5,50,0,0,
  	467,468,5,106,0,0,468,469,5,16,0,0,469,470,3,56,28,0,470,471,5,104,0,
  	0,471,472,5,15,0,0,472,473,5,49,0,0,473,474,5,60,0,0,474,475,3,38,19,
  	0,475,476,5,18,0,0,476,477,5,15,0,0,477,478,5,102,0,0,478,479,5,60,0,
  	0,479,480,3,38,19,0,480,125,1,0,0,0,481,482,5,25,0,0,482,483,5,15,0,0,
  	483,484,5,50,0,0,484,485,5,106,0,0,485,486,5,16,0,0,486,487,3,56,28,0,
  	487,127,1,0,0,0,488,489,5,95,0,0,489,490,5,12,0,0,490,497,5,106,0,0,491,
  	493,5,11,0,0,492,491,1,0,0,0,492,493,1,0,0,0,493,494,1,0,0,0,494,496,
  	5,106,0,0,495,492,1,0,0,0,496,499,1,0,0,0,497,495,1,0,0,0,497,498,1,0,
  	0,0,498,129,1,0,0,0,499,497,1,0,0,0,35,135,149,156,162,180,185,199,225,
  	235,243,247,269,271,287,292,299,306,325,338,343,354,361,384,389,393,401,
  	408,419,424,431,436,444,449,492,497
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
    setState(130);
    decl_Ped();
    setState(131);
    match(BehaviorParser::T__0);
    setState(133); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(132);
      statement();
      setState(135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & -9223372030370381824) != 0) || _la == BehaviorParser::SELECTOR

    || _la == BehaviorParser::TYPES);
   
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
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::EVENT: {
        enterOuterAlt(_localctx, 1);
        setState(137);
        event();
        setState(138);
        match(BehaviorParser::T__0);
        break;
      }

      case BehaviorParser::CONSIDER:
      case BehaviorParser::ENVIRONMENT:
      case BehaviorParser::PEDESTRIAN:
      case BehaviorParser::TYPES: {
        enterOuterAlt(_localctx, 2);
        setState(140);
        declaration();
        setState(141);
        match(BehaviorParser::T__0);
        break;
      }

      case BehaviorParser::SELECTOR: {
        enterOuterAlt(_localctx, 3);
        setState(143);
        ped_Selector();
        setState(144);
        match(BehaviorParser::T__0);
        break;
      }

      case BehaviorParser::ACTION: {
        enterOuterAlt(_localctx, 4);
        setState(146);
        action();
        setState(147);
        match(BehaviorParser::T__0);
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

//----------------- EventContext ------------------------------------------------------------------

BehaviorParser::EventContext::EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::EventContext::EVENT() {
  return getToken(BehaviorParser::EVENT, 0);
}

tree::TerminalNode* BehaviorParser::EventContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

std::vector<BehaviorParser::Event_attributeContext *> BehaviorParser::EventContext::event_attribute() {
  return getRuleContexts<BehaviorParser::Event_attributeContext>();
}

BehaviorParser::Event_attributeContext* BehaviorParser::EventContext::event_attribute(size_t i) {
  return getRuleContext<BehaviorParser::Event_attributeContext>(i);
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
    setState(151);
    match(BehaviorParser::EVENT);
    setState(152);
    match(BehaviorParser::COLON);
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & 9007199271518209) != 0)) {
      setState(153);
      event_attribute();
      setState(158);
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

//----------------- Event_attributeContext ------------------------------------------------------------------

BehaviorParser::Event_attributeContext::Event_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Event_nameContext* BehaviorParser::Event_attributeContext::event_name() {
  return getRuleContext<BehaviorParser::Event_nameContext>(0);
}

BehaviorParser::Event_startContext* BehaviorParser::Event_attributeContext::event_start() {
  return getRuleContext<BehaviorParser::Event_startContext>(0);
}

BehaviorParser::Event_endContext* BehaviorParser::Event_attributeContext::event_end() {
  return getRuleContext<BehaviorParser::Event_endContext>(0);
}


size_t BehaviorParser::Event_attributeContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_attribute;
}


std::any BehaviorParser::Event_attributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_attribute(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_attributeContext* BehaviorParser::event_attribute() {
  Event_attributeContext *_localctx = _tracker.createInstance<Event_attributeContext>(_ctx, getState());
  enterRule(_localctx, 6, BehaviorParser::RuleEvent_attribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(159);
        event_name();
        break;
      }

      case BehaviorParser::START: {
        enterOuterAlt(_localctx, 2);
        setState(160);
        event_start();
        break;
      }

      case BehaviorParser::END: {
        enterOuterAlt(_localctx, 3);
        setState(161);
        event_end();
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

//----------------- Event_nameContext ------------------------------------------------------------------

BehaviorParser::Event_nameContext::Event_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_nameContext::NAME() {
  return getToken(BehaviorParser::NAME, 0);
}

tree::TerminalNode* BehaviorParser::Event_nameContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

tree::TerminalNode* BehaviorParser::Event_nameContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Event_nameContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_name;
}


std::any BehaviorParser::Event_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_name(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_nameContext* BehaviorParser::event_name() {
  Event_nameContext *_localctx = _tracker.createInstance<Event_nameContext>(_ctx, getState());
  enterRule(_localctx, 8, BehaviorParser::RuleEvent_name);

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
    match(BehaviorParser::NAME);
    setState(165);
    match(BehaviorParser::COLON);
    setState(166);
    match(BehaviorParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_startContext ------------------------------------------------------------------

BehaviorParser::Event_startContext::Event_startContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_startContext::START() {
  return getToken(BehaviorParser::START, 0);
}

tree::TerminalNode* BehaviorParser::Event_startContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Event_startContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::Event_startContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_start;
}


std::any BehaviorParser::Event_startContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_start(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_startContext* BehaviorParser::event_start() {
  Event_startContext *_localctx = _tracker.createInstance<Event_startContext>(_ctx, getState());
  enterRule(_localctx, 10, BehaviorParser::RuleEvent_start);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(BehaviorParser::START);
    setState(169);
    match(BehaviorParser::COLON);
    setState(170);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Event_endContext ------------------------------------------------------------------

BehaviorParser::Event_endContext::Event_endContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Event_endContext::END() {
  return getToken(BehaviorParser::END, 0);
}

tree::TerminalNode* BehaviorParser::Event_endContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Event_endContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::Event_endContext::getRuleIndex() const {
  return BehaviorParser::RuleEvent_end;
}


std::any BehaviorParser::Event_endContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitEvent_end(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Event_endContext* BehaviorParser::event_end() {
  Event_endContext *_localctx = _tracker.createInstance<Event_endContext>(_ctx, getState());
  enterRule(_localctx, 12, BehaviorParser::RuleEvent_end);

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
    match(BehaviorParser::END);
    setState(173);
    match(BehaviorParser::COLON);
    setState(174);
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
  enterRule(_localctx, 14, BehaviorParser::RuleCondition);
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
    setState(176);
    sub_condition();
    setState(180);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::AND

    || _la == BehaviorParser::OR) {
      setState(177);
      connector();
      setState(182);
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
  enterRule(_localctx, 16, BehaviorParser::RuleConnector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::OR: {
        enterOuterAlt(_localctx, 1);
        setState(183);
        or_Connector();
        break;
      }

      case BehaviorParser::AND: {
        enterOuterAlt(_localctx, 2);
        setState(184);
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
  enterRule(_localctx, 18, BehaviorParser::RuleOr_Connector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    match(BehaviorParser::OR);
    setState(188);
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
  enterRule(_localctx, 20, BehaviorParser::RuleAnd_Connector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(BehaviorParser::AND);
    setState(191);
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

BehaviorParser::Condition_Event_StartingContext* BehaviorParser::Sub_conditionContext::condition_Event_Starting() {
  return getRuleContext<BehaviorParser::Condition_Event_StartingContext>(0);
}

BehaviorParser::Condition_Event_EndingContext* BehaviorParser::Sub_conditionContext::condition_Event_Ending() {
  return getRuleContext<BehaviorParser::Condition_Event_EndingContext>(0);
}

BehaviorParser::Condition_SpatialContext* BehaviorParser::Sub_conditionContext::condition_Spatial() {
  return getRuleContext<BehaviorParser::Condition_SpatialContext>(0);
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
  enterRule(_localctx, 22, BehaviorParser::RuleSub_condition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      condition_Time_Elapsed_From_Event();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(194);
      condition_Event_Occurred();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(195);
      condition_Event_Occurring();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(196);
      condition_Event_Starting();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(197);
      condition_Event_Ending();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(198);
      condition_Spatial();
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

//----------------- Condition_Time_Elapsed_From_EventContext ------------------------------------------------------------------

BehaviorParser::Condition_Time_Elapsed_From_EventContext::Condition_Time_Elapsed_From_EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 24, BehaviorParser::RuleCondition_Time_Elapsed_From_Event);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    value_numeric();
    setState(202);
    match(BehaviorParser::SECONDS);
    setState(203);
    match(BehaviorParser::FROM);
    setState(204);
    match(BehaviorParser::EVNT);
   
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

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::HAS() {
  return getToken(BehaviorParser::HAS, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurredContext::OCCURRED() {
  return getToken(BehaviorParser::OCCURRED, 0);
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
  enterRule(_localctx, 26, BehaviorParser::RuleCondition_Event_Occurred);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(BehaviorParser::EVNT);
    setState(207);
    match(BehaviorParser::HAS);
    setState(208);
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

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_OccurringContext::OCCURRING() {
  return getToken(BehaviorParser::OCCURRING, 0);
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
  enterRule(_localctx, 28, BehaviorParser::RuleCondition_Event_Occurring);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(BehaviorParser::EVNT);
    setState(211);
    match(BehaviorParser::OCCURRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_StartingContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_StartingContext::Condition_Event_StartingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_StartingContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_StartingContext::STARTING() {
  return getToken(BehaviorParser::STARTING, 0);
}


size_t BehaviorParser::Condition_Event_StartingContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_Starting;
}


std::any BehaviorParser::Condition_Event_StartingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_Starting(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_StartingContext* BehaviorParser::condition_Event_Starting() {
  Condition_Event_StartingContext *_localctx = _tracker.createInstance<Condition_Event_StartingContext>(_ctx, getState());
  enterRule(_localctx, 30, BehaviorParser::RuleCondition_Event_Starting);

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
    match(BehaviorParser::EVNT);
    setState(214);
    match(BehaviorParser::STARTING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_Event_EndingContext ------------------------------------------------------------------

BehaviorParser::Condition_Event_EndingContext::Condition_Event_EndingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_Event_EndingContext::EVNT() {
  return getToken(BehaviorParser::EVNT, 0);
}

tree::TerminalNode* BehaviorParser::Condition_Event_EndingContext::ENDING() {
  return getToken(BehaviorParser::ENDING, 0);
}


size_t BehaviorParser::Condition_Event_EndingContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Event_Ending;
}


std::any BehaviorParser::Condition_Event_EndingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Event_Ending(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_Event_EndingContext* BehaviorParser::condition_Event_Ending() {
  Condition_Event_EndingContext *_localctx = _tracker.createInstance<Condition_Event_EndingContext>(_ctx, getState());
  enterRule(_localctx, 32, BehaviorParser::RuleCondition_Event_Ending);

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
    match(BehaviorParser::EVNT);
    setState(217);
    match(BehaviorParser::ENDING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_SpatialContext ------------------------------------------------------------------

BehaviorParser::Condition_SpatialContext::Condition_SpatialContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Condition_SpatialContext::TARGET() {
  return getToken(BehaviorParser::TARGET, 0);
}

tree::TerminalNode* BehaviorParser::Condition_SpatialContext::WITHIN() {
  return getToken(BehaviorParser::WITHIN, 0);
}

BehaviorParser::Value_numericContext* BehaviorParser::Condition_SpatialContext::value_numeric() {
  return getRuleContext<BehaviorParser::Value_numericContext>(0);
}

tree::TerminalNode* BehaviorParser::Condition_SpatialContext::METERS() {
  return getToken(BehaviorParser::METERS, 0);
}


size_t BehaviorParser::Condition_SpatialContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Spatial;
}


std::any BehaviorParser::Condition_SpatialContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Spatial(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_SpatialContext* BehaviorParser::condition_Spatial() {
  Condition_SpatialContext *_localctx = _tracker.createInstance<Condition_SpatialContext>(_ctx, getState());
  enterRule(_localctx, 34, BehaviorParser::RuleCondition_Spatial);

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
    match(BehaviorParser::TARGET);
    setState(220);
    match(BehaviorParser::WITHIN);
    setState(221);
    value_numeric();
    setState(222);
    match(BehaviorParser::METERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Condition_AttributeContext ------------------------------------------------------------------

BehaviorParser::Condition_AttributeContext::Condition_AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::AttributeContext* BehaviorParser::Condition_AttributeContext::attribute() {
  return getRuleContext<BehaviorParser::AttributeContext>(0);
}

tree::TerminalNode* BehaviorParser::Condition_AttributeContext::IS() {
  return getToken(BehaviorParser::IS, 0);
}

BehaviorParser::Attr_valueContext* BehaviorParser::Condition_AttributeContext::attr_value() {
  return getRuleContext<BehaviorParser::Attr_valueContext>(0);
}

tree::TerminalNode* BehaviorParser::Condition_AttributeContext::TARGET() {
  return getToken(BehaviorParser::TARGET, 0);
}


size_t BehaviorParser::Condition_AttributeContext::getRuleIndex() const {
  return BehaviorParser::RuleCondition_Attribute;
}


std::any BehaviorParser::Condition_AttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitCondition_Attribute(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Condition_AttributeContext* BehaviorParser::condition_Attribute() {
  Condition_AttributeContext *_localctx = _tracker.createInstance<Condition_AttributeContext>(_ctx, getState());
  enterRule(_localctx, 36, BehaviorParser::RuleCondition_Attribute);
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
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::TARGET) {
      setState(224);
      match(BehaviorParser::TARGET);
    }
    setState(227);
    attribute();
    setState(228);
    match(BehaviorParser::IS);
    setState(229);
    attr_value();
   
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
  enterRule(_localctx, 38, BehaviorParser::RuleValue_numeric);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(235);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(231);
      value_number();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      value_float();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(233);
      value_range();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(234);
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
  enterRule(_localctx, 40, BehaviorParser::RuleValue_number);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
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
  enterRule(_localctx, 42, BehaviorParser::RuleValue_float);

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
  enterRule(_localctx, 44, BehaviorParser::RuleValue_range);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(241);
        float_range();
        break;
      }

      case BehaviorParser::NUMBER: {
        enterOuterAlt(_localctx, 2);
        setState(242);
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
  enterRule(_localctx, 46, BehaviorParser::RuleValue_random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(247);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(245);
      random_float();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(246);
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
  enterRule(_localctx, 48, BehaviorParser::RuleRandom_number);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(BehaviorParser::RANDOM);
    setState(250);
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
  enterRule(_localctx, 50, BehaviorParser::RuleRandom_float);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(BehaviorParser::RANDOM);
    setState(253);
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
  enterRule(_localctx, 52, BehaviorParser::RuleFloat_range);
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
    match(BehaviorParser::FLOAT);
    setState(256);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__1 || _la == BehaviorParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(257);
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
  enterRule(_localctx, 54, BehaviorParser::RuleNumber_range);
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
    setState(259);
    match(BehaviorParser::NUMBER);
    setState(260);
    _la = _input->LA(1);
    if (!(_la == BehaviorParser::T__1 || _la == BehaviorParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(261);
    match(BehaviorParser::NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Value_coordContext ------------------------------------------------------------------

BehaviorParser::Value_coordContext::Value_coordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BehaviorParser::Value_numericContext *> BehaviorParser::Value_coordContext::value_numeric() {
  return getRuleContexts<BehaviorParser::Value_numericContext>();
}

BehaviorParser::Value_numericContext* BehaviorParser::Value_coordContext::value_numeric(size_t i) {
  return getRuleContext<BehaviorParser::Value_numericContext>(i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Value_coordContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Value_coordContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
}


size_t BehaviorParser::Value_coordContext::getRuleIndex() const {
  return BehaviorParser::RuleValue_coord;
}


std::any BehaviorParser::Value_coordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitValue_coord(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Value_coordContext* BehaviorParser::value_coord() {
  Value_coordContext *_localctx = _tracker.createInstance<Value_coordContext>(_ctx, getState());
  enterRule(_localctx, 56, BehaviorParser::RuleValue_coord);
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
    setState(263);
    match(BehaviorParser::T__2);
    setState(264);
    value_numeric();
    setState(271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::COMMA) {
      setState(265);
      match(BehaviorParser::COMMA);
      setState(266);
      value_numeric();
      setState(269);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(267);
        match(BehaviorParser::COMMA);
        setState(268);
        value_numeric();
      }
    }
    setState(273);
    match(BehaviorParser::T__3);
   
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

//----------------- AttributeContext ------------------------------------------------------------------

BehaviorParser::AttributeContext::AttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::AttributeContext::POSITION() {
  return getToken(BehaviorParser::POSITION, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::VELOCITY() {
  return getToken(BehaviorParser::VELOCITY, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::GOAL() {
  return getToken(BehaviorParser::GOAL, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::STATE() {
  return getToken(BehaviorParser::STATE, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::LOCATION() {
  return getToken(BehaviorParser::LOCATION, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::STATUS() {
  return getToken(BehaviorParser::STATUS, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::MAX() {
  return getToken(BehaviorParser::MAX, 0);
}

tree::TerminalNode* BehaviorParser::AttributeContext::SPEED() {
  return getToken(BehaviorParser::SPEED, 0);
}


size_t BehaviorParser::AttributeContext::getRuleIndex() const {
  return BehaviorParser::RuleAttribute;
}


std::any BehaviorParser::AttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAttribute(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::AttributeContext* BehaviorParser::attribute() {
  AttributeContext *_localctx = _tracker.createInstance<AttributeContext>(_ctx, getState());
  enterRule(_localctx, 60, BehaviorParser::RuleAttribute);

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
      case BehaviorParser::POSITION: {
        enterOuterAlt(_localctx, 1);
        setState(278);
        match(BehaviorParser::POSITION);
        break;
      }

      case BehaviorParser::VELOCITY: {
        enterOuterAlt(_localctx, 2);
        setState(279);
        match(BehaviorParser::VELOCITY);
        break;
      }

      case BehaviorParser::GOAL: {
        enterOuterAlt(_localctx, 3);
        setState(280);
        match(BehaviorParser::GOAL);
        break;
      }

      case BehaviorParser::STATE: {
        enterOuterAlt(_localctx, 4);
        setState(281);
        match(BehaviorParser::STATE);
        break;
      }

      case BehaviorParser::LOCATION: {
        enterOuterAlt(_localctx, 5);
        setState(282);
        match(BehaviorParser::LOCATION);
        break;
      }

      case BehaviorParser::STATUS: {
        enterOuterAlt(_localctx, 6);
        setState(283);
        match(BehaviorParser::STATUS);
        break;
      }

      case BehaviorParser::MAX: {
        enterOuterAlt(_localctx, 7);
        setState(284);
        match(BehaviorParser::MAX);
        setState(285);
        match(BehaviorParser::SPEED);
        break;
      }

      case BehaviorParser::T__2:
      case BehaviorParser::STATE_VAL:
      case BehaviorParser::IS:
      case BehaviorParser::RANDOM:
      case BehaviorParser::TO:
      case BehaviorParser::NUMBER:
      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 8);

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

//----------------- Attr_valueContext ------------------------------------------------------------------

BehaviorParser::Attr_valueContext::Attr_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Value_numericContext* BehaviorParser::Attr_valueContext::value_numeric() {
  return getRuleContext<BehaviorParser::Value_numericContext>(0);
}

BehaviorParser::Value_coordContext* BehaviorParser::Attr_valueContext::value_coord() {
  return getRuleContext<BehaviorParser::Value_coordContext>(0);
}

tree::TerminalNode* BehaviorParser::Attr_valueContext::STATE_VAL() {
  return getToken(BehaviorParser::STATE_VAL, 0);
}


size_t BehaviorParser::Attr_valueContext::getRuleIndex() const {
  return BehaviorParser::RuleAttr_value;
}


std::any BehaviorParser::Attr_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAttr_value(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Attr_valueContext* BehaviorParser::attr_value() {
  Attr_valueContext *_localctx = _tracker.createInstance<Attr_valueContext>(_ctx, getState());
  enterRule(_localctx, 62, BehaviorParser::RuleAttr_value);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(292);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::RANDOM:
      case BehaviorParser::NUMBER:
      case BehaviorParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(289);
        value_numeric();
        break;
      }

      case BehaviorParser::T__2: {
        enterOuterAlt(_localctx, 2);
        setState(290);
        value_coord();
        break;
      }

      case BehaviorParser::STATE_VAL: {
        enterOuterAlt(_localctx, 3);
        setState(291);
        match(BehaviorParser::STATE_VAL);
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

//----------------- Ped_SelectorContext ------------------------------------------------------------------

BehaviorParser::Ped_SelectorContext::Ped_SelectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::SELECTOR() {
  return getToken(BehaviorParser::SELECTOR, 0);
}

tree::TerminalNode* BehaviorParser::Ped_SelectorContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

std::vector<BehaviorParser::Selector_attributeContext *> BehaviorParser::Ped_SelectorContext::selector_attribute() {
  return getRuleContexts<BehaviorParser::Selector_attributeContext>();
}

BehaviorParser::Selector_attributeContext* BehaviorParser::Ped_SelectorContext::selector_attribute(size_t i) {
  return getRuleContext<BehaviorParser::Selector_attributeContext>(i);
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
  enterRule(_localctx, 64, BehaviorParser::RulePed_Selector);
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
    setState(294);
    match(BehaviorParser::SELECTOR);
    setState(295);
    match(BehaviorParser::COLON);
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 38) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 38)) & 288230412658933761) != 0)) {
      setState(296);
      selector_attribute();
      setState(301);
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

//----------------- Selector_attributeContext ------------------------------------------------------------------

BehaviorParser::Selector_attributeContext::Selector_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Selector_typeContext* BehaviorParser::Selector_attributeContext::selector_type() {
  return getRuleContext<BehaviorParser::Selector_typeContext>(0);
}

BehaviorParser::Selector_selectorContext* BehaviorParser::Selector_attributeContext::selector_selector() {
  return getRuleContext<BehaviorParser::Selector_selectorContext>(0);
}

BehaviorParser::Selector_fromContext* BehaviorParser::Selector_attributeContext::selector_from() {
  return getRuleContext<BehaviorParser::Selector_fromContext>(0);
}

BehaviorParser::Selector_requiredContext* BehaviorParser::Selector_attributeContext::selector_required() {
  return getRuleContext<BehaviorParser::Selector_requiredContext>(0);
}


size_t BehaviorParser::Selector_attributeContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_attribute;
}


std::any BehaviorParser::Selector_attributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_attribute(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_attributeContext* BehaviorParser::selector_attribute() {
  Selector_attributeContext *_localctx = _tracker.createInstance<Selector_attributeContext>(_ctx, getState());
  enterRule(_localctx, 66, BehaviorParser::RuleSelector_attribute);

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
      case BehaviorParser::TYPE: {
        enterOuterAlt(_localctx, 1);
        setState(302);
        selector_type();
        break;
      }

      case BehaviorParser::SELECT: {
        enterOuterAlt(_localctx, 2);
        setState(303);
        selector_selector();
        break;
      }

      case BehaviorParser::FROM: {
        enterOuterAlt(_localctx, 3);
        setState(304);
        selector_from();
        break;
      }

      case BehaviorParser::REQUIRED: {
        enterOuterAlt(_localctx, 4);
        setState(305);
        selector_required();
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

//----------------- Selector_typeContext ------------------------------------------------------------------

BehaviorParser::Selector_typeContext::Selector_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_typeContext::TYPE() {
  return getToken(BehaviorParser::TYPE, 0);
}

tree::TerminalNode* BehaviorParser::Selector_typeContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::Id_listContext* BehaviorParser::Selector_typeContext::id_list() {
  return getRuleContext<BehaviorParser::Id_listContext>(0);
}


size_t BehaviorParser::Selector_typeContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_type;
}


std::any BehaviorParser::Selector_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_type(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_typeContext* BehaviorParser::selector_type() {
  Selector_typeContext *_localctx = _tracker.createInstance<Selector_typeContext>(_ctx, getState());
  enterRule(_localctx, 68, BehaviorParser::RuleSelector_type);

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
    match(BehaviorParser::TYPE);
    setState(309);
    match(BehaviorParser::COLON);
    setState(310);
    id_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_selectorContext ------------------------------------------------------------------

BehaviorParser::Selector_selectorContext::Selector_selectorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_selectorContext::SELECT() {
  return getToken(BehaviorParser::SELECT, 0);
}

tree::TerminalNode* BehaviorParser::Selector_selectorContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::SelectorContext* BehaviorParser::Selector_selectorContext::selector() {
  return getRuleContext<BehaviorParser::SelectorContext>(0);
}


size_t BehaviorParser::Selector_selectorContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_selector;
}


std::any BehaviorParser::Selector_selectorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_selector(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_selectorContext* BehaviorParser::selector_selector() {
  Selector_selectorContext *_localctx = _tracker.createInstance<Selector_selectorContext>(_ctx, getState());
  enterRule(_localctx, 70, BehaviorParser::RuleSelector_selector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(BehaviorParser::SELECT);
    setState(313);
    match(BehaviorParser::COLON);
    setState(314);
    selector();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_fromContext ------------------------------------------------------------------

BehaviorParser::Selector_fromContext::Selector_fromContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_fromContext::FROM() {
  return getToken(BehaviorParser::FROM, 0);
}

tree::TerminalNode* BehaviorParser::Selector_fromContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::GroupContext* BehaviorParser::Selector_fromContext::group() {
  return getRuleContext<BehaviorParser::GroupContext>(0);
}


size_t BehaviorParser::Selector_fromContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_from;
}


std::any BehaviorParser::Selector_fromContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_from(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_fromContext* BehaviorParser::selector_from() {
  Selector_fromContext *_localctx = _tracker.createInstance<Selector_fromContext>(_ctx, getState());
  enterRule(_localctx, 72, BehaviorParser::RuleSelector_from);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(BehaviorParser::FROM);
    setState(317);
    match(BehaviorParser::COLON);
    setState(318);
    group();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Selector_requiredContext ------------------------------------------------------------------

BehaviorParser::Selector_requiredContext::Selector_requiredContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Selector_requiredContext::REQUIRED() {
  return getToken(BehaviorParser::REQUIRED, 0);
}


size_t BehaviorParser::Selector_requiredContext::getRuleIndex() const {
  return BehaviorParser::RuleSelector_required;
}


std::any BehaviorParser::Selector_requiredContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelector_required(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Selector_requiredContext* BehaviorParser::selector_required() {
  Selector_requiredContext *_localctx = _tracker.createInstance<Selector_requiredContext>(_ctx, getState());
  enterRule(_localctx, 74, BehaviorParser::RuleSelector_required);

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
    match(BehaviorParser::REQUIRED);
   
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
  enterRule(_localctx, 76, BehaviorParser::RuleSelector);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(322);
      selector_Percent();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(323);
      selector_Exactly_N_Random();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(324);
      selector_Everyone();
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
  enterRule(_localctx, 78, BehaviorParser::RuleSelector_Percent);

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
    value_number();
    setState(328);
    match(BehaviorParser::T__4);
   
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

BehaviorParser::Value_numberContext* BehaviorParser::Selector_Exactly_N_RandomContext::value_number() {
  return getRuleContext<BehaviorParser::Value_numberContext>(0);
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
  enterRule(_localctx, 80, BehaviorParser::RuleSelector_Exactly_N_Random);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    value_number();
   
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
  enterRule(_localctx, 82, BehaviorParser::RuleSelector_Everyone);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(BehaviorParser::EVERYONE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GroupContext ------------------------------------------------------------------

BehaviorParser::GroupContext::GroupContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::GroupContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::GroupContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::GroupContext::PEDESTRIANS() {
  return getToken(BehaviorParser::PEDESTRIANS, 0);
}


size_t BehaviorParser::GroupContext::getRuleIndex() const {
  return BehaviorParser::RuleGroup;
}


std::any BehaviorParser::GroupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitGroup(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::GroupContext* BehaviorParser::group() {
  GroupContext *_localctx = _tracker.createInstance<GroupContext>(_ctx, getState());
  enterRule(_localctx, 84, BehaviorParser::RuleGroup);
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
    setState(334);
    _la = _input->LA(1);
    if (!(((((_la - 63) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 63)) & 8796093022211) != 0))) {
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
  enterRule(_localctx, 86, BehaviorParser::RuleId_list);
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
    setState(336);
    match(BehaviorParser::ID);
    setState(343);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA || _la == BehaviorParser::ID) {
      setState(338);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(337);
        match(BehaviorParser::COMMA);
      }
      setState(340);
      match(BehaviorParser::ID);
      setState(345);
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

tree::TerminalNode* BehaviorParser::ActionContext::ACTION() {
  return getToken(BehaviorParser::ACTION, 0);
}

tree::TerminalNode* BehaviorParser::ActionContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}

tree::TerminalNode* BehaviorParser::ActionContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

std::vector<BehaviorParser::Action_attributeContext *> BehaviorParser::ActionContext::action_attribute() {
  return getRuleContexts<BehaviorParser::Action_attributeContext>();
}

BehaviorParser::Action_attributeContext* BehaviorParser::ActionContext::action_attribute(size_t i) {
  return getRuleContext<BehaviorParser::Action_attributeContext>(i);
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
  enterRule(_localctx, 88, BehaviorParser::RuleAction);
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
    setState(346);
    match(BehaviorParser::ACTION);
    setState(347);
    match(BehaviorParser::T__5);
    setState(348);
    match(BehaviorParser::ID);
    setState(349);
    match(BehaviorParser::T__6);
    setState(350);
    match(BehaviorParser::COLON);
    setState(354);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 28) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 28)) & 1729386654956781569) != 0)) {
      setState(351);
      action_attribute();
      setState(356);
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

//----------------- Action_attributeContext ------------------------------------------------------------------

BehaviorParser::Action_attributeContext::Action_attributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Action_responseContext* BehaviorParser::Action_attributeContext::action_response() {
  return getRuleContext<BehaviorParser::Action_responseContext>(0);
}

BehaviorParser::Action_stimulusContext* BehaviorParser::Action_attributeContext::action_stimulus() {
  return getRuleContext<BehaviorParser::Action_stimulusContext>(0);
}

BehaviorParser::Action_durationContext* BehaviorParser::Action_attributeContext::action_duration() {
  return getRuleContext<BehaviorParser::Action_durationContext>(0);
}

BehaviorParser::Action_targetContext* BehaviorParser::Action_attributeContext::action_target() {
  return getRuleContext<BehaviorParser::Action_targetContext>(0);
}


size_t BehaviorParser::Action_attributeContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_attribute;
}


std::any BehaviorParser::Action_attributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_attribute(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_attributeContext* BehaviorParser::action_attribute() {
  Action_attributeContext *_localctx = _tracker.createInstance<Action_attributeContext>(_ctx, getState());
  enterRule(_localctx, 90, BehaviorParser::RuleAction_attribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(361);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::RESPONSE: {
        enterOuterAlt(_localctx, 1);
        setState(357);
        action_response();
        break;
      }

      case BehaviorParser::STIMULUS: {
        enterOuterAlt(_localctx, 2);
        setState(358);
        action_stimulus();
        break;
      }

      case BehaviorParser::DURATION: {
        enterOuterAlt(_localctx, 3);
        setState(359);
        action_duration();
        break;
      }

      case BehaviorParser::TARGET: {
        enterOuterAlt(_localctx, 4);
        setState(360);
        action_target();
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

//----------------- Action_stimulusContext ------------------------------------------------------------------

BehaviorParser::Action_stimulusContext::Action_stimulusContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_stimulusContext::STIMULUS() {
  return getToken(BehaviorParser::STIMULUS, 0);
}

tree::TerminalNode* BehaviorParser::Action_stimulusContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::ConditionContext* BehaviorParser::Action_stimulusContext::condition() {
  return getRuleContext<BehaviorParser::ConditionContext>(0);
}


size_t BehaviorParser::Action_stimulusContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_stimulus;
}


std::any BehaviorParser::Action_stimulusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_stimulus(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_stimulusContext* BehaviorParser::action_stimulus() {
  Action_stimulusContext *_localctx = _tracker.createInstance<Action_stimulusContext>(_ctx, getState());
  enterRule(_localctx, 92, BehaviorParser::RuleAction_stimulus);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    match(BehaviorParser::STIMULUS);
    setState(364);
    match(BehaviorParser::COLON);
    setState(365);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_responseContext ------------------------------------------------------------------

BehaviorParser::Action_responseContext::Action_responseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_responseContext::RESPONSE() {
  return getToken(BehaviorParser::RESPONSE, 0);
}

tree::TerminalNode* BehaviorParser::Action_responseContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::Sub_actionContext* BehaviorParser::Action_responseContext::sub_action() {
  return getRuleContext<BehaviorParser::Sub_actionContext>(0);
}


size_t BehaviorParser::Action_responseContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_response;
}


std::any BehaviorParser::Action_responseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_response(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_responseContext* BehaviorParser::action_response() {
  Action_responseContext *_localctx = _tracker.createInstance<Action_responseContext>(_ctx, getState());
  enterRule(_localctx, 94, BehaviorParser::RuleAction_response);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(BehaviorParser::RESPONSE);
    setState(368);
    match(BehaviorParser::COLON);
    setState(369);
    sub_action();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_durationContext ------------------------------------------------------------------

BehaviorParser::Action_durationContext::Action_durationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_durationContext::DURATION() {
  return getToken(BehaviorParser::DURATION, 0);
}

tree::TerminalNode* BehaviorParser::Action_durationContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::DurationContext* BehaviorParser::Action_durationContext::duration() {
  return getRuleContext<BehaviorParser::DurationContext>(0);
}


size_t BehaviorParser::Action_durationContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_duration;
}


std::any BehaviorParser::Action_durationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_duration(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_durationContext* BehaviorParser::action_duration() {
  Action_durationContext *_localctx = _tracker.createInstance<Action_durationContext>(_ctx, getState());
  enterRule(_localctx, 96, BehaviorParser::RuleAction_duration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(BehaviorParser::DURATION);
    setState(372);
    match(BehaviorParser::COLON);
    setState(373);
    duration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Action_targetContext ------------------------------------------------------------------

BehaviorParser::Action_targetContext::Action_targetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Action_targetContext::TARGET() {
  return getToken(BehaviorParser::TARGET, 0);
}

tree::TerminalNode* BehaviorParser::Action_targetContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

BehaviorParser::TargetContext* BehaviorParser::Action_targetContext::target() {
  return getRuleContext<BehaviorParser::TargetContext>(0);
}


size_t BehaviorParser::Action_targetContext::getRuleIndex() const {
  return BehaviorParser::RuleAction_target;
}


std::any BehaviorParser::Action_targetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitAction_target(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Action_targetContext* BehaviorParser::action_target() {
  Action_targetContext *_localctx = _tracker.createInstance<Action_targetContext>(_ctx, getState());
  enterRule(_localctx, 98, BehaviorParser::RuleAction_target);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    match(BehaviorParser::TARGET);
    setState(376);
    match(BehaviorParser::COLON);
    setState(377);
    target();
   
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

std::vector<tree::TerminalNode *> BehaviorParser::Sub_actionContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Sub_actionContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
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
  enterRule(_localctx, 100, BehaviorParser::RuleSub_action);
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
    setState(379);
    action_atom();
    setState(384);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA) {
      setState(380);
      match(BehaviorParser::COMMA);
      setState(381);
      action_atom();
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

//----------------- Action_atomContext ------------------------------------------------------------------

BehaviorParser::Action_atomContext::Action_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::Set_atomContext* BehaviorParser::Action_atomContext::set_atom() {
  return getRuleContext<BehaviorParser::Set_atomContext>(0);
}

BehaviorParser::Scale_atomContext* BehaviorParser::Action_atomContext::scale_atom() {
  return getRuleContext<BehaviorParser::Scale_atomContext>(0);
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
  enterRule(_localctx, 102, BehaviorParser::RuleAction_atom);

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
    switch (_input->LA(1)) {
      case BehaviorParser::SET: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        set_atom();
        break;
      }

      case BehaviorParser::SCALE: {
        enterOuterAlt(_localctx, 2);
        setState(388);
        scale_atom();
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

//----------------- Set_atomContext ------------------------------------------------------------------

BehaviorParser::Set_atomContext::Set_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Set_atomContext::SET() {
  return getToken(BehaviorParser::SET, 0);
}

BehaviorParser::AttributeContext* BehaviorParser::Set_atomContext::attribute() {
  return getRuleContext<BehaviorParser::AttributeContext>(0);
}

tree::TerminalNode* BehaviorParser::Set_atomContext::TO() {
  return getToken(BehaviorParser::TO, 0);
}

BehaviorParser::Attr_valueContext* BehaviorParser::Set_atomContext::attr_value() {
  return getRuleContext<BehaviorParser::Attr_valueContext>(0);
}

tree::TerminalNode* BehaviorParser::Set_atomContext::TARGET() {
  return getToken(BehaviorParser::TARGET, 0);
}


size_t BehaviorParser::Set_atomContext::getRuleIndex() const {
  return BehaviorParser::RuleSet_atom;
}


std::any BehaviorParser::Set_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSet_atom(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Set_atomContext* BehaviorParser::set_atom() {
  Set_atomContext *_localctx = _tracker.createInstance<Set_atomContext>(_ctx, getState());
  enterRule(_localctx, 104, BehaviorParser::RuleSet_atom);
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
    match(BehaviorParser::SET);
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::TARGET) {
      setState(392);
      match(BehaviorParser::TARGET);
    }
    setState(395);
    attribute();
    setState(396);
    match(BehaviorParser::TO);
    setState(397);
    attr_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scale_atomContext ------------------------------------------------------------------

BehaviorParser::Scale_atomContext::Scale_atomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Scale_atomContext::SCALE() {
  return getToken(BehaviorParser::SCALE, 0);
}

BehaviorParser::AttributeContext* BehaviorParser::Scale_atomContext::attribute() {
  return getRuleContext<BehaviorParser::AttributeContext>(0);
}

BehaviorParser::Attr_valueContext* BehaviorParser::Scale_atomContext::attr_value() {
  return getRuleContext<BehaviorParser::Attr_valueContext>(0);
}

tree::TerminalNode* BehaviorParser::Scale_atomContext::TARGET() {
  return getToken(BehaviorParser::TARGET, 0);
}


size_t BehaviorParser::Scale_atomContext::getRuleIndex() const {
  return BehaviorParser::RuleScale_atom;
}


std::any BehaviorParser::Scale_atomContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitScale_atom(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Scale_atomContext* BehaviorParser::scale_atom() {
  Scale_atomContext *_localctx = _tracker.createInstance<Scale_atomContext>(_ctx, getState());
  enterRule(_localctx, 106, BehaviorParser::RuleScale_atom);
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
    setState(399);
    match(BehaviorParser::SCALE);
    setState(401);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BehaviorParser::TARGET) {
      setState(400);
      match(BehaviorParser::TARGET);
    }
    setState(403);
    attribute();
    setState(404);
    attr_value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

BehaviorParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BehaviorParser::SelfContext* BehaviorParser::TargetContext::self() {
  return getRuleContext<BehaviorParser::SelfContext>(0);
}

BehaviorParser::Nearest_typeContext* BehaviorParser::TargetContext::nearest_type() {
  return getRuleContext<BehaviorParser::Nearest_typeContext>(0);
}


size_t BehaviorParser::TargetContext::getRuleIndex() const {
  return BehaviorParser::RuleTarget;
}


std::any BehaviorParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::TargetContext* BehaviorParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 108, BehaviorParser::RuleTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(408);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::SELF: {
        enterOuterAlt(_localctx, 1);
        setState(406);
        self();
        break;
      }

      case BehaviorParser::NEAREST: {
        enterOuterAlt(_localctx, 2);
        setState(407);
        nearest_type();
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

//----------------- SelfContext ------------------------------------------------------------------

BehaviorParser::SelfContext::SelfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::SelfContext::SELF() {
  return getToken(BehaviorParser::SELF, 0);
}


size_t BehaviorParser::SelfContext::getRuleIndex() const {
  return BehaviorParser::RuleSelf;
}


std::any BehaviorParser::SelfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitSelf(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::SelfContext* BehaviorParser::self() {
  SelfContext *_localctx = _tracker.createInstance<SelfContext>(_ctx, getState());
  enterRule(_localctx, 110, BehaviorParser::RuleSelf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    match(BehaviorParser::SELF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Nearest_typeContext ------------------------------------------------------------------

BehaviorParser::Nearest_typeContext::Nearest_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BehaviorParser::Nearest_typeContext::NEAREST() {
  return getToken(BehaviorParser::NEAREST, 0);
}

tree::TerminalNode* BehaviorParser::Nearest_typeContext::ID() {
  return getToken(BehaviorParser::ID, 0);
}


size_t BehaviorParser::Nearest_typeContext::getRuleIndex() const {
  return BehaviorParser::RuleNearest_type;
}


std::any BehaviorParser::Nearest_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BehaviorVisitor*>(visitor))
    return parserVisitor->visitNearest_type(this);
  else
    return visitor->visitChildren(this);
}

BehaviorParser::Nearest_typeContext* BehaviorParser::nearest_type() {
  Nearest_typeContext *_localctx = _tracker.createInstance<Nearest_typeContext>(_ctx, getState());
  enterRule(_localctx, 112, BehaviorParser::RuleNearest_type);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(BehaviorParser::NEAREST);
    setState(413);
    match(BehaviorParser::ID);
   
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
  enterRule(_localctx, 114, BehaviorParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(419);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BehaviorParser::CONSIDER: {
        enterOuterAlt(_localctx, 1);
        setState(415);
        decl_Loc();
        break;
      }

      case BehaviorParser::PEDESTRIAN: {
        enterOuterAlt(_localctx, 2);
        setState(416);
        decl_Ped_State();
        break;
      }

      case BehaviorParser::ENVIRONMENT: {
        enterOuterAlt(_localctx, 3);
        setState(417);
        decl_Env_State();
        break;
      }

      case BehaviorParser::TYPES: {
        enterOuterAlt(_localctx, 4);
        setState(418);
        decl_Ped();
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
  enterRule(_localctx, 116, BehaviorParser::RuleDecl_Loc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(421);
      decl_Loc_Area_Circle();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(422);
      decl_Loc_Point();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(423);
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

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::PEDESTRIAN() {
  return getToken(BehaviorParser::PEDESTRIAN, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::STATES() {
  return getToken(BehaviorParser::STATES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::STATE_VAL() {
  return getTokens(BehaviorParser::STATE_VAL);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::STATE_VAL(size_t i) {
  return getToken(BehaviorParser::STATE_VAL, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Ped_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Ped_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
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
  enterRule(_localctx, 118, BehaviorParser::RuleDecl_Ped_State);
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
    setState(426);
    match(BehaviorParser::PEDESTRIAN);
    setState(427);
    match(BehaviorParser::STATES);
    setState(428);
    match(BehaviorParser::COLON);
    setState(429);
    match(BehaviorParser::STATE_VAL);
    setState(436);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA

    || _la == BehaviorParser::STATE_VAL) {
      setState(431);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(430);
        match(BehaviorParser::COMMA);
      }
      setState(433);
      match(BehaviorParser::STATE_VAL);
      setState(438);
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

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::ENVIRONMENT() {
  return getToken(BehaviorParser::ENVIRONMENT, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::STATES() {
  return getToken(BehaviorParser::STATES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::STATE_VAL() {
  return getTokens(BehaviorParser::STATE_VAL);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::STATE_VAL(size_t i) {
  return getToken(BehaviorParser::STATE_VAL, i);
}

std::vector<tree::TerminalNode *> BehaviorParser::Decl_Env_StateContext::COMMA() {
  return getTokens(BehaviorParser::COMMA);
}

tree::TerminalNode* BehaviorParser::Decl_Env_StateContext::COMMA(size_t i) {
  return getToken(BehaviorParser::COMMA, i);
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
  enterRule(_localctx, 120, BehaviorParser::RuleDecl_Env_State);
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
    setState(439);
    match(BehaviorParser::ENVIRONMENT);
    setState(440);
    match(BehaviorParser::STATES);
    setState(441);
    match(BehaviorParser::COLON);

    setState(442);
    match(BehaviorParser::STATE_VAL);
    setState(449);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA

    || _la == BehaviorParser::STATE_VAL) {
      setState(444);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(443);
        match(BehaviorParser::COMMA);
      }
      setState(446);
      match(BehaviorParser::STATE_VAL);
      setState(451);
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

BehaviorParser::Value_coordContext* BehaviorParser::Decl_Loc_Area_CircleContext::value_coord() {
  return getRuleContext<BehaviorParser::Value_coordContext>(0);
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

BehaviorParser::Value_numericContext* BehaviorParser::Decl_Loc_Area_CircleContext::value_numeric() {
  return getRuleContext<BehaviorParser::Value_numericContext>(0);
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
  enterRule(_localctx, 122, BehaviorParser::RuleDecl_Loc_Area_Circle);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    match(BehaviorParser::CONSIDER);
    setState(453);
    match(BehaviorParser::AN);
    setState(454);
    match(BehaviorParser::LOCATION);
    setState(455);
    match(BehaviorParser::ID);
    setState(456);
    match(BehaviorParser::AT);
    setState(457);
    value_coord();
    setState(458);
    match(BehaviorParser::WITH);
    setState(459);
    match(BehaviorParser::AN);
    setState(460);
    match(BehaviorParser::RADIUS);
    setState(461);
    match(BehaviorParser::OF);
    setState(462);
    value_numeric();
   
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

BehaviorParser::Value_coordContext* BehaviorParser::Decl_Loc_Area_RectContext::value_coord() {
  return getRuleContext<BehaviorParser::Value_coordContext>(0);
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

std::vector<BehaviorParser::Value_numericContext *> BehaviorParser::Decl_Loc_Area_RectContext::value_numeric() {
  return getRuleContexts<BehaviorParser::Value_numericContext>();
}

BehaviorParser::Value_numericContext* BehaviorParser::Decl_Loc_Area_RectContext::value_numeric(size_t i) {
  return getRuleContext<BehaviorParser::Value_numericContext>(i);
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
  enterRule(_localctx, 124, BehaviorParser::RuleDecl_Loc_Area_Rect);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(464);
    match(BehaviorParser::CONSIDER);
    setState(465);
    match(BehaviorParser::AN);
    setState(466);
    match(BehaviorParser::LOCATION);
    setState(467);
    match(BehaviorParser::ID);
    setState(468);
    match(BehaviorParser::AT);
    setState(469);
    value_coord();
    setState(470);
    match(BehaviorParser::WITH);
    setState(471);
    match(BehaviorParser::AN);
    setState(472);
    match(BehaviorParser::LENGTH);
    setState(473);
    match(BehaviorParser::OF);
    setState(474);
    value_numeric();
    setState(475);
    match(BehaviorParser::AND);
    setState(476);
    match(BehaviorParser::AN);
    setState(477);
    match(BehaviorParser::WIDTH);
    setState(478);
    match(BehaviorParser::OF);
    setState(479);
    value_numeric();
   
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

BehaviorParser::Value_coordContext* BehaviorParser::Decl_Loc_PointContext::value_coord() {
  return getRuleContext<BehaviorParser::Value_coordContext>(0);
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
  enterRule(_localctx, 126, BehaviorParser::RuleDecl_Loc_Point);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(481);
    match(BehaviorParser::CONSIDER);
    setState(482);
    match(BehaviorParser::AN);
    setState(483);
    match(BehaviorParser::LOCATION);
    setState(484);
    match(BehaviorParser::ID);
    setState(485);
    match(BehaviorParser::AT);
    setState(486);
    value_coord();
   
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

tree::TerminalNode* BehaviorParser::Decl_PedContext::TYPES() {
  return getToken(BehaviorParser::TYPES, 0);
}

tree::TerminalNode* BehaviorParser::Decl_PedContext::COLON() {
  return getToken(BehaviorParser::COLON, 0);
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
  enterRule(_localctx, 128, BehaviorParser::RuleDecl_Ped);
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
    setState(488);
    match(BehaviorParser::TYPES);
    setState(489);
    match(BehaviorParser::COLON);
    setState(490);
    match(BehaviorParser::ID);
    setState(497);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BehaviorParser::COMMA || _la == BehaviorParser::ID) {
      setState(492);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BehaviorParser::COMMA) {
        setState(491);
        match(BehaviorParser::COMMA);
      }
      setState(494);
      match(BehaviorParser::ID);
      setState(499);
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
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  behaviorParserInitialize();
#else
  ::antlr4::internal::call_once(behaviorParserOnceFlag, behaviorParserInitialize);
#endif
}
