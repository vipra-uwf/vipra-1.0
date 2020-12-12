#include <string>
#include <unordered_map>
#include <vector>

typedef float FLOATING_NUMBER;
typedef std::unordered_map<std::string, std::string> CONFIG_MAP;
typedef std::vector<std::unordered_map<std::string, std::string>> ENTITY_SET;
//typedef std::unordered_map<std::string, std::unordered_map<std::string, std::string>> SIM_OPTIONS/CONFIG;
typedef std::unordered_map<std::string, FLOATING_NUMBER> SIM_PARAMS;