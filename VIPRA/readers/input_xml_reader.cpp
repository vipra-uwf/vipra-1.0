#include "input_xml_reader.hpp"

ENTITY_SET InputXMLReader::getInputEntities()
{
    initializeTraversalNodes();
   
	ENTITY_SET inputData;
	
	while(this->dataNode != 0)
	{
		rapidxml::xml_attribute<>* nodeAttribute = 
			this->dataNode->first_attribute(); 	

        inputData.push_back(std::unordered_map<std::string, std::string>());
		
        while(nodeAttribute != 0)
		{
			std::string key = nodeAttribute->name();
            std::string value = nodeAttribute->value();

            inputData[inputData.size() - 1][key] = value;

			nodeAttribute = nodeAttribute->next_attribute();
		}

		this->dataNode = this->dataNode->next_sibling();
	}

	return inputData;		
}

void InputXMLReader::extractFileData(
    std::string fileName, std::string rootNodeName)
{
    openFile(fileName);
    readFile();
    this->rootNodeName = rootNodeName;
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

void InputXMLReader::initializeTraversalNodes()
{
    this->rootNode = this->document.first_node(
        this->document.allocate_string(this->rootNodeName.c_str()));

	this->dataNode = this->rootNode->first_node(0);	
}