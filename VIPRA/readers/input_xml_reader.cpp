#include "input_xml_reader.hpp"

ENTITY_SET InputXMLReader::getInputEntities()
{
    initializeTraversalElement();
   
	ENTITY_SET inputData;
	
	while(this->traversalElement != 0)
	{
		rapidxml::xml_attribute<>* elementAttribute = 
			this->traversalElement->first_attribute(); 	

        inputData.push_back(std::unordered_map<std::string, std::string>());
		
        while(elementAttribute != 0)
		{
			std::string key = elementAttribute->name();
            std::string value = elementAttribute->value();

            inputData[inputData.size() - 1][key] = value;

			elementAttribute = elementAttribute->next_attribute();
		}

		this->traversalElement = this->traversalElement->next_sibling();
	}

	return inputData;		
}

void InputXMLReader::configure(CONFIG_MAP* configMap)
{

}

void InputXMLReader::extractFileData(
    std::string fileName, CONFIG_MAP* configMap)
{
    openFile(fileName);
    readFile();
    this->rootElementName = (*configMap)["rootElementName"];
    parseXMLDocument();
}

void InputXMLReader::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void InputXMLReader::readFile()
{
    std::vector<char> buffer(
        (std::istreambuf_iterator<char>(this->fileStream)), 
        std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    this->fileContents = buffer;
	//std::cout << &buffer[0] << std::endl;
    this->fileStream.close();
}

void InputXMLReader::parseXMLDocument()
{
   this->document.parse<
   rapidxml::parse_declaration_node | 
   rapidxml::parse_no_data_nodes>(
       &this->fileContents[0]);
}

void InputXMLReader::initializeTraversalElement()
{
    this->rootElement = this->document.first_node(
        this->document.allocate_string(this->rootElementName.c_str()));

	this->traversalElement = this->rootElement->first_node(0);	
}