#include "xml_writer.hpp"

void XMLWriter::configureXMLDocumentStructure(std::string fileName, std::string rootNodeName, std::string dataNodeName, std::string versionNum, std::string encodingType)
{
    openFile(fileName);
    setRootNodeName(rootNodeName);
    setDataNodeName(dataNodeName);

    initializeXMLDeclaration(versionNum, encodingType);
    initializeRootNode();
}

void XMLWriter::writeData(Data* data)
{
    //TODO use PedestrianSet.getNumPedestrians() -- first must set it in the XMLReader 
    setNumDataNodes(data->getPedestrianSet()->getXCoordinates()->size());
    initializeDataNodes();

    writeFloatDataSet("x", *data->getPedestrianSet()->getXCoordinates());
    writeFloatDataSet("y", *data->getPedestrianSet()->getYCoordinates());
    writeStringDataSet("type", *data->getPedestrianSet()->getTypes()); 

    this->fileStream << this->document;

    this->fileStream.close();
    this->document.clear();
}

void XMLWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void XMLWriter::setRootNodeName(std::string rootNodeName)
{
    this->rootNodeName = rootNodeName;
}

void XMLWriter::setDataNodeName(std::string dataNodeName)
{
    this->dataNodeName = dataNodeName;
}

void XMLWriter::setNumDataNodes(int numDataNodes)
{
    this->numDataNodes = numDataNodes;
}

void XMLWriter::initializeXMLDeclaration(std::string versionNum, std::string encodingType)
{
    rapidxml::xml_node<>* declarationNode = this->document.allocate_node(rapidxml::node_declaration);
    declarationNode->append_attribute(this->document.allocate_attribute("version", this->document.allocate_string(versionNum.c_str())));
    declarationNode->append_attribute(this->document.allocate_attribute("encoding", this->document.allocate_string(encodingType.c_str())));
    this->document.append_node(declarationNode);
}

void XMLWriter::initializeRootNode()
{
    this->rootNode = this->document.allocate_node(rapidxml::node_element, this->document.allocate_string(this->rootNodeName.c_str()));
    this->document.append_node(rootNode);
}

void XMLWriter::generateDataNode()
{
    rapidxml::xml_node<>* dataNode = this->document.allocate_node(rapidxml::node_element, this->document.allocate_string(this->dataNodeName.c_str()));
    this->rootNode->append_node(dataNode);
}

void XMLWriter::appendDataNodeAttribute(rapidxml::xml_node<>* node, std::string key, std::string value)
{
    node->append_attribute(this->document.allocate_attribute(this->document.allocate_string(key.c_str()), this->document.allocate_string(value.c_str())));
}

void XMLWriter::initializeDataNodes()
{
    for(int i = 0; i < this->numDataNodes; ++i)
    {
        generateDataNode();
    }
}

void XMLWriter::writeFloatDataSet(std::string key, std::vector<FLOATING_NUMBER> dataSet)
{
    int i = 0;

    for(rapidxml::xml_node<>* dataNode = this->rootNode->first_node(); dataNode; dataNode = dataNode->next_sibling())
    {
        std::string data = std::to_string(dataSet[i]);
        dataNode->append_attribute(this->document.allocate_attribute(document.allocate_string(key.c_str()), document.allocate_string(data.c_str())));
        i++;
    }
}

void XMLWriter::writeStringDataSet(std::string key, std::vector<std::string> dataSet)
{
    int i = 0;

    for(rapidxml::xml_node<>* dataNode = this->rootNode->first_node(); dataNode; dataNode = dataNode->next_sibling())
    {
        std::string data = dataSet[i];
        dataNode->append_attribute(this->document.allocate_attribute(document.allocate_string(key.c_str()), document.allocate_string(data.c_str())));
        i++;
    }
}

void XMLWriter::writeFloatData(std::string, FLOATING_NUMBER)
{
    //will we have multiple file streams open?
}

void XMLWriter::writeStringData(std::string, std::string)
{
    
}


