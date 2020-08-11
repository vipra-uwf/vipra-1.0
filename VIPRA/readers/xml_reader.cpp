#include "xml_reader.hpp"
#include <utility>

XMLReader::XMLReader()
{
    //this->rootNode = NULL;
    //this->dataNode = NULL;
    this->numDataNodes = 0;
}
std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> XMLReader::getInputData()
{
	initializeRootNode();
	initializeDataNode();
   
	std::unordered_map<std::string, std::vector<FLOATING_NUMBER>> inputData;
	
	while(this->dataNode != 0)
	{
		rapidxml::xml_attribute<>* nodeAttribute = this->dataNode->first_attribute(); 	
		
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

/*void XMLReader::storeData(Data* data)
{
    extractFileData(
        "./input_data/a320_144_pedestrians.xml", 
        "pedestrian-set", 
        "pedestrian");
    std::vector<Dimensions> pedestrianCoordinates;
    std::vector<FLOATING_NUMBER> pedestrianCoordinatesX = getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> pedestrianCoordinatesY = getFloatDataSet("y");

    for(int i = 0; i < this->numDataNodes; ++i)
    {
        pedestrianCoordinates.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    pedestrianCoordinatesX[i], 
                    pedestrianCoordinatesY[i]
                }
            }
        );
    }
    
    data->getPedestrianSet()->setPedestrianCoordinates(pedestrianCoordinates);
    data->getPedestrianSet()->setMasses(getFloatDataSet("mass"));
    data->getPedestrianSet()->setReactionTimes(
        getFloatDataSet("reaction_time"));
    data->getPedestrianSet()->setDesiredSpeeds(
        getFloatDataSet("desired_speed"));
    data->getPedestrianSet()->setNumPedestrians(this->numDataNodes);
    data->getPedestrianSet()->initializeValues();
    
    extractFileData(
        "./input_data/a320_144_obstacles.xml",
        "obstacle-set", 
        "obstacle");
    std::vector<Dimensions> obstacleCoordinates;
    std::vector<FLOATING_NUMBER> obstacleCoordinatesX = getFloatDataSet("x");
    std::vector<FLOATING_NUMBER> obstacleCoordinatesY = getFloatDataSet("y");

    for(int i = 0; i < this->numDataNodes; ++i)
    {
        obstacleCoordinates.push_back(
            Dimensions {
                std::vector<FLOATING_NUMBER> {
                    obstacleCoordinatesX[i],
                    obstacleCoordinatesY[i]
                }
            }
        );
    }

    data->getObstacleSet()->setObstacleCoordinates(obstacleCoordinates);
    data->getObstacleSet()->setNumObstacles(this->numDataNodes);
	

	openFile("./input_data/simulation_params.xml");
	data->setSimulationParams(getSimulationParams("parameters"));	
}
*/
void XMLReader::extractFileData(
    std::string fileName, std::string rootNodeName)
{
    openFile(fileName);
    readFile();
    setRootNodeName(rootNodeName);
    //setDataNodeName(dataNodeName);
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

void XMLReader::setDataNodeName(std::string dataNodeName)
{
    this->dataNodeName = dataNodeName;
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
    //this->dataNode = this->rootNode->first_node(
        //this->document.allocate_string(this->dataNodeName.c_str()));
}

FLOATING_NUMBER XMLReader::getFloatValue(
    rapidxml::xml_node<>* node, std::string attribute)
{
    return std::stod(node->first_attribute(attribute.c_str())->value());
}

std::string XMLReader::getStringValue(
    rapidxml::xml_node<>* node, std::string attribute)
{
    return node->first_attribute(attribute.c_str())->value();
}

std::vector<FLOATING_NUMBER> XMLReader::getFloatDataSet(std::string attribute)
{
    std::vector<FLOATING_NUMBER> dataSet;

    initializeRootNode();
    initializeDataNode();

    this->numDataNodes = 0;

    while(this->dataNode != 0)
    {   
        FLOATING_NUMBER value = getFloatValue(this->dataNode, attribute);
        dataSet.push_back(value);
        this->dataNode = this->dataNode->next_sibling();
        this->numDataNodes++;
    }

    return dataSet;
}

std::vector<std::string> XMLReader::getStringDataSet(std::string attribute)
{
    std::vector<std::string> dataSet;

    initializeRootNode();
    initializeDataNode();
    
    this->numDataNodes = 0;
   
    while(this->dataNode != 0)
    {   
        std::string value = getStringValue(this->dataNode, attribute);
        dataSet.push_back(value);
        this->dataNode = this->dataNode->next_sibling();
        this->numDataNodes++;
    }

    return dataSet;
}


std::unordered_map<std::string, FLOATING_NUMBER> XMLReader::getSimulationParams(
    std::string parentNode)
{
	readFile();
	parseXMLDocument();
	
	this->rootNode = this->document.first_node(parentNode.c_str());
    this->dataNode = this->rootNode->first_node();	
	
	std::unordered_map<std::string, FLOATING_NUMBER> simulationParams;

	while(this->dataNode != 0)
	{
		std::string key = this->dataNode->name();
		FLOATING_NUMBER value = std::stod(
				this->dataNode->first_attribute()->value()); 

		simulationParams[key] = value;

		this->dataNode = this->dataNode->next_sibling();
	}

	return simulationParams;
}
