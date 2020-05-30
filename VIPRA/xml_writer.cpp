#include "xml_writer.hpp"

XMLWriter::XMLWriter()
{
    this->xTest.push_back("5.5");
    this->yTest.push_back("2.1");

    this->xTest.push_back("8.3");
    this->yTest.push_back("9.9");

    this->xTest.push_back("4.1");
    this->yTest.push_back("7.6");

    this->xTest.push_back("1.9");
    this->yTest.push_back("3.7");
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
    rapidxml::xml_node<>* dataNode = this->document.allocate_node(rapidxml::node_element, "pedestrian");
    this->rootNode->append_node(dataNode);
    this->dataNodes.push_back(dataNode);
    
    // appendDataNodeAttribute(dataNode, "z", "10");
}

void XMLWriter::appendDataNodeAttribute(rapidxml::xml_node<>* node, std::string key, std::string value)
{
    node->append_attribute(this->document.allocate_attribute(key.c_str(), value.c_str()));
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

   int i = 0; 

    for(rapidxml::xml_node<>* child = this->rootNode->first_node(); child; child = child->next_sibling())
    {
        // std::cout << child->parent()->name() << std::endl;
        // std::cout << child->name() << std::endl;
        // std::cout << child << std::endl;


        // child->append_attribute(this->document.allocate_attribute(key.c_str(), valuesVector[i].c_str()));


        

        child->append_attribute(this->document.allocate_attribute(key.c_str(), document.allocate_string(valuesVector[i].c_str())));


        //child->append_attribute(rapidxml::xml_attribute("x" , "12"));

        i++;
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

    setNumDataNodes(this->xTest.size());
    initializeDataNodes();


    writeVectorDataToNodes("x", this->xTest);
    writeVectorDataToNodes("y", this->yTest);


    // writeVectorDataToNodes("x", this->xTest);
    // writeVectorDataToNodes("y", this->yTest);

    // rapidxml::xml_node<>* currentNode = this->rootNode->first_node(0);
    // std::cout << currentNode->name() << std::endl;





    // appendDataNodeAttribute(this->dataNodes[1], "x", this->xTest[1]);

    // generateDataNode();
    // appendDataNodeAttribute("x", "5.5");
    // appendDataNodeAttribute("y", "2.5");


   
    // std::string xml_as_string;
    // rapidxml::print(std::back_inserter(xml_as_string), this->document, 0);

    //PROBABLY NEED TO WIPE dataNodes (vector)

    this->fileStream << this->document;

    this->fileStream.close();
    this->document.clear();

}