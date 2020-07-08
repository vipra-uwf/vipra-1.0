#include "xml_reader.hpp"
#include <utility>

XMLReader::XMLReader()
{
    this->rootNode = NULL;
    this->dataNode = NULL;
    this->numEntities = 0;
}

void XMLReader::storeData(Data* data)
{
    extractFileData("./input_data/a320_144_pedestrians.xml", "pedestrian-set", "pedestrian");
    std::vector<Dimensions> pedestrianCoordinates;
    std::vector<FLOATING_NUMBER> pedestrianCoordinatesX = getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> pedestrianCoordinatesY = getFloatDataSet("y");

    for(int i = 0; i < this->numEntities; ++i)
    {
        pedestrianCoordinates.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    pedestrianCoordinatesX.at(i), 
                    pedestrianCoordinatesY.at(i)
                }
            }
        );
    }
    
    data->getPedestrianSet()->setPedestrianCoordinates(pedestrianCoordinates);
    data->getPedestrianSet()->setMasses(getFloatDataSet("mass"));
    data->getPedestrianSet()->setReactionTimes(getFloatDataSet("reaction_time"));
    data->getPedestrianSet()->setDesiredSpeeds(getFloatDataSet("desired_speed"));
    data->getPedestrianSet()->setNumPedestrians(this->numEntities);
    data->getPedestrianSet()->initializeValues();
    
    extractFileData("./input_data/a320_144_obstacles.xml", "obstacle-set", "obstacle");
    std::vector<Dimensions> obstacleCoordinates;
    std::vector<FLOATING_NUMBER> obstacleCoordinatesX = getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> obstacleCoordinatesY = getFloatDataSet("y");

    for(int i = 0; i < this->numEntities; ++i)
    {
        obstacleCoordinates.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    obstacleCoordinatesX.at(i),
                    obstacleCoordinatesY.at(i)
                }
            }
        );
    }

    data->getObstacleSet()->setObstacleCoordinates(obstacleCoordinates);
    data->getObstacleSet()->setNumObstacles(this->numEntities);
	

	openFile("./input_data/simulation_params.xml");
	data->setHashMapData(getHashMapDataSet("parameters"));	
}

void XMLReader::extractFileData(std::string fileName, std::string rootElement, std::string parseElement)
{
    openFile(fileName);
    readFile();
    setRootElement(rootElement);
    setParseElement(parseElement);
    parseXMLDocument();
}

void XMLReader::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void XMLReader::readFile()
{
    std::vector<char> buffer((std::istreambuf_iterator<char>(this->fileStream)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    this->fileContents = buffer;
	//std::cout << &buffer[0] << std::endl;
    this->fileStream.close();
}

void XMLReader::setRootElement(std::string rootElement)
{
    this->rootElement = rootElement;
}

void XMLReader::setParseElement(std::string parseElement)
{
    this->parseElement = parseElement;
}

void XMLReader::parseXMLDocument()
{
   this->document.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&this->fileContents[0]);
}

void XMLReader::initializeRootNode()
{
    this->rootNode = this->document.first_node(this->document.allocate_string(this->rootElement.c_str()));
}

void XMLReader::initializeDataNode()
{
    this->dataNode = this->rootNode->first_node(this->document.allocate_string(this->parseElement.c_str()));
}

FLOATING_NUMBER XMLReader::getFloatValue(rapidxml::xml_node<>* node, std::string attribute)
{
    return std::stod(node->first_attribute(attribute.c_str())->value());
}

std::string XMLReader::getStringValue(rapidxml::xml_node<>* node, std::string attribute)
{
    return node->first_attribute(attribute.c_str())->value();
}

std::vector<FLOATING_NUMBER> XMLReader::getFloatDataSet(std::string attribute)
{
    std::vector<FLOATING_NUMBER> dataSet;

    initializeRootNode();
    initializeDataNode();

    this->numEntities = 0;

    while(this->dataNode != 0)
    {   
        FLOATING_NUMBER value = getFloatValue(this->dataNode, attribute);
        dataSet.push_back(value);
        this->dataNode = this->dataNode->next_sibling();
        this->numEntities++;
    }

    return dataSet;
}

std::vector<std::string> XMLReader::getStringDataSet(std::string attribute)
{
    std::vector<std::string> dataSet;

    initializeRootNode();
    initializeDataNode();
    
    this->numEntities = 0;
   
    while(this->dataNode != 0)
    {   
        std::string value = getStringValue(this->dataNode, attribute);
        dataSet.push_back(value);
        this->dataNode = this->dataNode->next_sibling();
        this->numEntities++;
    }

    return dataSet;
}


std::unordered_map<std::string, FLOATING_NUMBER> XMLReader::getHashMapDataSet(std::string parent_node)
{
	readFile();
	parseXMLDocument();
	
	this->rootNode = this->document.first_node(parent_node.c_str());
    this->dataNode = this->rootNode->first_node();	
	
	std::unordered_map<std::string, FLOATING_NUMBER> hashMapData;

	while(this->dataNode != 0)
	{
		std::string key = this->dataNode->name();
		FLOATING_NUMBER value = std::stod(
				this->dataNode->first_attribute()->value()); 

		hashMapData[key] = value;

		this->dataNode = this->dataNode->next_sibling();
	}

	return hashMapData;
}
