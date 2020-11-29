#include <iostream>

#include "readers/input_json_reader.hpp"

// g++ testmain.cpp readers/input_json_reader.cpp readers/jsoncpp.cpp

int main()
{
    InputJSONReader inputJSONReader; 
    CONFIG_MAP configMap;
    
    inputJSONReader.extractFileData("input_data/TEST_entity_set.json", &configMap);
    ENTITY_SET jsonEntitySet = inputJSONReader.getInputEntities();

    std::cout << "finished" << std::endl;

    // std::cout << jsonEntitySet[0]["type"] << std::endl;

    // for(int i = 0; jsonEntitySet.size(); ++i) 
    // {
    //     std::cout << jsonEntitySet[i]
    // }

    return 0;
}