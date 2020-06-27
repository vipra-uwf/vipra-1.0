#include "xml_reader.hpp"

XMLReader::XMLReader()
{
    //TODO these nulls may not matter -- trying to figure out "segfault"
    this->rootNode = NULL;
    this->dataNode = NULL;
    this->numEntities = 0;
}

void XMLReader::storeData(Data* data)
{
<<<<<<< HEAD
//TODO fix xmlreader to work with the new dimension functions.
    extractFileData("./input_data/a320_144_pedestrians.xml", "pedestrian-set", "pedestrian");
    // data->getPedestrianSet()->setMassesKg(getFloatDataSet("massKg"));
    //data->getPedestrianSet()->setXCoordinates(getFloatDataSet("x"));
    //data->getPedestrianSet()->setYCoordinates(getFloatDataSet("y"));
    data->getPedestrianSet()->setMassesKg(getFloatDataSet("mass"));
=======
    // TODO maybe have extractFileData and getFloatDataSet be the virtual methods instead of storeData
    // why should the reader store the data? -- Alex 
    extractFileData("./input_data/a320_144_pedestrians.xml", "pedestrian-set", "pedestrian");
    data->getPedestrianSet()->setCoordinatesX(getFloatDataSet("x"));
    data->getPedestrianSet()->setCoordinatesY(getFloatDataSet("y"));
    data->getPedestrianSet()->setMasses(getFloatDataSet("mass"));
    data->getPedestrianSet()->setReactionTimes(getFloatDataSet("reaction_time"));
    data->getPedestrianSet()->setDesiredSpeeds(getFloatDataSet("desired_speed"));
>>>>>>> 980aa09babde6e99c8da3b98baae72c7d853f1e1
    data->getPedestrianSet()->setNumPedestrians(this->numEntities);
    data->getPedestrianSet()->initializeValues();

    extractFileData("./input_data/a320_144_obstacles.xml", "obstacle-set", "obstacle");
    //data->getObstacleSet()->setXCoordinates(getFloatDataSet("x"));
    //data->getObstacleSet()->setYCoordinates(getFloatDataSet("y")); 
    data->getObstacleSet()->setNumObstacles(this->numEntities);
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

    // std::cout << "\nRoot Node: " << this->rootNode << "            (" << this->rootElement << ")" << std::endl;

    this->numEntities = 0;

    while(this->dataNode != 0)
    {   
        // std::cout << "Data Node[" << this->numEntities << "]: " << this->dataNode << "           (" << this->parseElement << ")" << "            Parent: " << this->dataNode->parent() << std::endl; 
        
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

    // std::cout << "\nRoot Node: " << this->rootNode << "            (" << this->rootElement << ")" << std::endl;
    
    this->numEntities = 0;
   
    while(this->dataNode != 0)
    {   
        // std::cout << "Data Node[" << this->numEntities << "]: " << this->dataNode << "           (" << this->parseElement << ")" << "            Parent: " << this->dataNode->parent() << std::endl; 
        
        std::string value = getStringValue(this->dataNode, attribute);

        dataSet.push_back(value);

        this->dataNode = this->dataNode->next_sibling();

        this->numEntities++;

    }

    return dataSet;
}