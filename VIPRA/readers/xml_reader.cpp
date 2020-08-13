#include "xml_reader.hpp"

std::unordered_map<
	std::string, std::vector<FLOATING_NUMBER>> XMLReader::getFloatInputData()
{
	initializeRootNode();
	initializeDataNode();
   
	std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> inputData;
	
	while(this->dataNode != 0)
	{
		rapidxml::xml_attribute<>* nodeAttribute = 
			this->dataNode->first_attribute(); 	
		
		while(nodeAttribute != 0)
		{
			std::string key = nodeAttribute->name();
			FLOATING_NUMBER value = std::stod(nodeAttribute->value());	
			inputData[key].push_back(value);
			
			nodeAttribute = nodeAttribute->next_attribute();
		}

		this->dataNode = this->dataNode->next_sibling();
	}

	return inputData;		
}

void XMLReader::extractFileData(
    std::string fileName, std::string rootNodeName)
{
    openFile(fileName);
    readFile();
    setRootNodeName(rootNodeName);
    parseXMLDocument();
}

void XMLReader::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void XMLReader::readFile()
{
    std::vector<char> buffer(
        (std::istreambuf_iterator<char>(this->fileStream)), 
        std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    this->fileContents = buffer;
	//std::cout << &buffer[0] << std::endl;
    this->fileStream.close();
}

void XMLReader::setRootNodeName(std::string rootNodeName)
{
    this->rootNodeName = rootNodeName;
}

void XMLReader::parseXMLDocument()
{
   this->document.parse<
   rapidxml::parse_declaration_node | 
   rapidxml::parse_no_data_nodes>(
       &this->fileContents[0]);
}

void XMLReader::initializeRootNode()
{
    this->rootNode = this->document.first_node(
        this->document.allocate_string(this->rootNodeName.c_str()));
}

void XMLReader::initializeDataNode()
{
	this->dataNode = this->rootNode->first_node(0);	
}