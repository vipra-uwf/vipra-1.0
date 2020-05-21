#include "xmlreader.hpp"

XMLReader::XMLReader()
{

}

/*XMLReader::XMLReader(std::string fileName)
{
    this->fileName = fileName;
}*/

void XMLReader::openFile(std::string fileName){
    this->fileName = fileName;
}

void XMLReader::setRootNodeName(std::string rootNodeName){
    this->rootNodeName = rootNodeName;
}

void XMLReader::setParseNodeName(std::string parseNodeName)
{
    this->parseNodeName = parseNodeName;
}


void XMLReader::writeData(Data* data)
{
    this->data = data;
    readCoordinatesFile();
    //parseCoordinatesDocument();
    //storeData();
}

void XMLReader::readCoordinatesFile()
{
    std::ifstream fileStream(this->fileName);
    std::vector<char> buffer((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    this->fileContents = buffer;
    std::cout << &this->fileContents[0] << std::endl;
}

void XMLReader::parseCoordinatesDocument()
{
   this->coordinateDocument.parse<rapidxml::parse_declaration_node | rapidxml::parse_no_data_nodes>(&this->fileContents[0]);
}

void XMLReader::storeData()//does both passengers and obstacles 
{   
    
    this->documentRootNode = coordinateDocument.first_node(rootNodeName.c_str());
    rapidxml::xml_node<>* node = this->documentRootNode->first_node(parseNodeName.c_str());

    while(node != 0)
    {
        setDataCoordinates(node);
        node = node->next_sibling();
    }
}

void XMLReader::setDataCoordinates(rapidxml::xml_node<>* node){

    double xCoordinate = std::stod(node->first_attribute("x")->value());
    double yCoordinate = std::stod(node->first_attribute("y")->value());

    if (parseNodeName == "pedestrian"){
        this->data->pushXPedestrianCoordinate(xCoordinate);
        this->data->pushYPedestrianCoordinate(yCoordinate);
    }else if (parseNodeName == "obstacle"){
        this->data->pushXObstacleCoordinate(xCoordinate);
        this->data->pushYObstacleCoordinate(yCoordinate);
    }
}

