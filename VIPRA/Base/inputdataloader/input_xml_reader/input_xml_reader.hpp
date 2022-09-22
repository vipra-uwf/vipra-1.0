#ifndef INPUT_XML_READER_HPP
#define INPUT_XML_READER_HPP

#include "../input_data_loader.hpp"
#include "../rapidxml/rapidxml.hpp"

class InputXMLReader : public InputDataLoader {
 private:
  std::ifstream            fileStream;
  std::vector<char>        fileContents;
  std::string              parentElementName;
  std::string              dataElementName;
  rapidxml::xml_document<> document;
  rapidxml::xml_node<>*    parentElement;
  rapidxml::xml_node<>*    traversalElement;

  void openFile(std::string fileName);
  void readFile();
  void initializeTraversalElement();
  void parseXMLDocument();

 public:
  ENTITY_SET getInputEntities() override;
  void       configure(const CONFIG_MAP& configMap) override;
  void       extractFileData(std::string       fileName,
                             const CONFIG_MAP& configMap) override;
};

#endif
