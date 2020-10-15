#include "xml_writer.hpp"

XMLWriter::XMLWriter()
{
   this->currentNode = NULL; 
}

void XMLWriter::configure(CONFIG_MAP* configMap) 
{
    openFile((*configMap)["outputFilePath"]);
    setRootNodeName((*configMap)["rootElementName"]);
    // TODO change DataNodeName to ChildNodeName
    setDataNodeName((*configMap)["childElementName"]);
    initializeXMLDeclaration("1.0", "utf-8");
    initializeRootNode();
}

// void XMLWriter::configureXMLDocumentStructure(
//     std::string fileName, std::string rootElementName, 
//     std::string dataElementName, std::string versionNum, 
//     std::string encodingType)
// {
//     openFile(fileName);
//     setRootNodeName(rootElementName);
//     setDataNodeName(dataElementName);

//     initializeXMLDeclaration(versionNum, encodingType);
//     initializeRootNode();
// }

void XMLWriter::writeData(Data* data)
{
    setNumDataNodes(data->getPedestrianSet()->getNumPedestrians());
    initializeDataNodes();
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void XMLWriter::writeDocumentContents()
{
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void XMLWriter::writeFloatData(std::string key, FLOATING_NUMBER value)
{
    if(this->currentNode == NULL)
    {
        this->currentNode = this->document.allocate_node(
            rapidxml::node_element, 
            this->document.allocate_string(this->dataElementName.c_str()));
        this->rootElement->append_node(this->currentNode);
    }
    
    if(this->currentNode->first_attribute(key.c_str()) == 0)          
    {
        appendDataNodeAttribute(this->currentNode, key, std::to_string(value));
    }
    else                                            
    {
        generateDataNode(); 
        currentNode = currentNode->next_sibling();
        appendDataNodeAttribute(this->currentNode, key, std::to_string(value));
    }
}

void XMLWriter::writeStringData(std::string key, std::string value)
{
    if(this->currentNode == NULL)
    {
        this->currentNode = this->document.allocate_node(
            rapidxml::node_element, 
            this->document.allocate_string(this->dataElementName.c_str()));
        this->rootElement->append_node(this->currentNode);
    }
    
    if(this->currentNode->first_attribute(key.c_str()) == 0)          
    {
        appendDataNodeAttribute(this->currentNode, key, value);
    }
    else                                            
    {
        generateDataNode(); 
        currentNode = currentNode->next_sibling();
        appendDataNodeAttribute(this->currentNode, key, value);
    }
}

void XMLWriter::writeFloatCalmEntitySet(
    std::string key, std::vector<FLOATING_NUMBER> entitySet)
{
    int i = 0;

    for(rapidxml::xml_node<>* traversalElement = 
        this->rootElement->first_node(); 
    traversalElement; 
    traversalElement = traversalElement->next_sibling())
    {
        std::string data = std::to_string(entitySet[i]);
        traversalElement->append_attribute(
            this->document.allocate_attribute(
                this->document.allocate_string(key.c_str()), 
                this->document.allocate_string(data.c_str())));
        i++;
    }
}

void XMLWriter::writeStringCalmEntitySet(
    std::string key, std::vector<std::string> entitySet)
{
    int i = 0;

    for(rapidxml::xml_node<>* traversalElement = 
        this->rootElement->first_node(); 
    traversalElement; 
    traversalElement = traversalElement->next_sibling())
    {
        std::string data = entitySet[i];
        traversalElement->append_attribute(this->document.allocate_attribute(
            this->document.allocate_string(key.c_str()), 
            this->document.allocate_string(data.c_str())));
        i++;
    }
}

void XMLWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void XMLWriter::setRootNodeName(std::string rootElementName)
{
    this->rootElementName = rootElementName;
}

void XMLWriter::setDataNodeName(std::string dataElementName)
{
    this->dataElementName = dataElementName;
}

void XMLWriter::setNumDataNodes(int numDataNodes)
{
    this->numDataNodes = numDataNodes;
}

void XMLWriter::initializeXMLDeclaration(
    std::string versionNum, std::string encodingType)
{
    rapidxml::xml_node<>* declarationNode = this->document.allocate_node(
        rapidxml::node_declaration);
    declarationNode->append_attribute(
        this->document.allocate_attribute(
            "version", this->document.allocate_string(versionNum.c_str())));
    declarationNode->append_attribute(
        this->document.allocate_attribute(
            "encoding", this->document.allocate_string(encodingType.c_str())));
    this->document.append_node(declarationNode);
}

void XMLWriter::initializeRootNode()
{
    this->rootElement = this->document.allocate_node(
        rapidxml::node_element, 
        this->document.allocate_string(this->rootElementName.c_str()));
    this->document.append_node(rootElement);
}

void XMLWriter::generateDataNode()
{
    rapidxml::xml_node<>* traversalElement = this->document.allocate_node(
        rapidxml::node_element, 
        this->document.allocate_string(this->dataElementName.c_str()));
    this->rootElement->append_node(traversalElement);
}

void XMLWriter::appendDataNodeAttribute(
    rapidxml::xml_node<>* node, std::string key, std::string value)
{
    node->append_attribute(this->document.allocate_attribute(
        this->document.allocate_string(key.c_str()), 
        this->document.allocate_string(value.c_str())));
}

void XMLWriter::initializeDataNodes()
{
    for(int i = 0; i < this->numDataNodes; ++i)
    {
        generateDataNode();
    }
}






