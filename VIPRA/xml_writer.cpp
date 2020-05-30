#include "xml_writer.hpp"

XMLWriter::XMLWriter()
{

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

void XMLWriter::initializeXMLDeclaration(std::string version, std::string versionNum, std::string encoding, std::string encodingType)
{
    rapidxml::xml_node<>* declarationNode = this->document.allocate_node(rapidxml::node_declaration);
    declarationNode->append_attribute(this->document.allocate_attribute(version.c_str(), versionNum.c_str()));
    declarationNode->append_attribute(this->document.allocate_attribute(encoding.c_str(), encodingType.c_str()));
    this->document.append_node(declarationNode);
}

void XMLWriter::initializeRootNode()
{
    this->rootNode = this->document.allocate_node(rapidxml::node_element, this->rootNodeName.c_str());
    this->document.append_node(rootNode);
}

void XMLWriter::generateDataNode()
{
    this->dataNode = this->document.allocate_node(rapidxml::node_element, "pedestrian");
    this->rootNode->append_node(dataNode);
}

void XMLWriter::appendDataNodeAttribute(std::string key, std::string value)
{
    this->dataNode->append_attribute(this->document.allocate_attribute(key.c_str(), value.c_str()));
}

void XMLWriter::initializeDataNodes()
{
    for(int i = 0; i < this->numDataNodes; ++i)
    {
        generateDataNode();
    }
}

void XMLWriter::writeVectorDataToNodes(std::string key, std::vector<std::string> valuesVector)
{
   this->dataNode = this->rootNode->first_node(this->dataNodeName.c_str());

   for(int i = 0; i < this->numDataNodes; ++i)
   {
       appendDataNodeAttribute(key, valuesVector[i]);
       this->dataNode = this->dataNode->next_sibling();
   }
}

void XMLWriter::writeData(Data* data)
{
    openFile("pedestrian_data.xml");
    setRootNodeName("pedestrian-set");
    setDataNodeName("pedestrian");

    
    initializeXMLDeclaration("version", "1.0", "encoding", "utf-8");
    initializeRootNode();

    // generateDataNode();
    // appendDataNodeAttribute("x", "5.5");
    // appendDataNodeAttribute("y", "2.5");

    std::vector<std::string> xTest;
    std::vector<std::string> yTest;

    xTest.push_back("5.5");
    yTest.push_back("2.1");

    xTest.push_back("8.3");
    yTest.push_back("9.9");

    xTest.push_back("4.1");
    yTest.push_back("7.6");

    xTest.push_back("1.9");
    yTest.push_back("3.7");

    setNumDataNodes(xTest.size());
    initializeDataNodes();

    writeVectorDataToNodes("x", xTest);
    writeVectorDataToNodes("y", yTest);
    
    
    // std::string xml_as_string;
    // rapidxml::print(std::back_inserter(xml_as_string), this->document, 0);

    this->fileStream << this->document;

    this->fileStream.close();
    this->document.clear();

}