#include "xml_writer.hpp"

XMLWriter::XMLWriter()
{
   this->currentElement = NULL; 
}

void XMLWriter::configure(CONFIG_MAP* configMap) 
{
    setParentElementName((*configMap)["parentElementName"]);
    setChildElementName((*configMap)["childElementName"]);
}

void XMLWriter::initializeOutputFile(std::string outputFilePath)
{
    openFile(outputFilePath);
    initializeXMLDeclaration("1.0", "utf-8");
    initializeParentElement();
}

void XMLWriter::appendFloatAttributeToCurrentElement(
    std::string key, FLOATING_NUMBER value, int* timestep)
{
    if(this->currentElement == NULL)
    {
        this->currentElement = this->document.allocate_node(
            rapidxml::node_element, 
            this->document.allocate_string(this->childElementName.c_str()));
        this->parentElement->append_node(this->currentElement);
    }
    
    if(this->currentElement->first_attribute(key.c_str()) == 0)          
    {
        appendChildElementAttribute(
            this->currentElement, key, std::to_string(value));
    }
    else                                            
    {
        generateChildElement(); 
        currentElement = currentElement->next_sibling();
        appendChildElementAttribute(
            this->currentElement, key, std::to_string(value));
    }
}

void XMLWriter::appendStringAttributeToCurrentElement(
    std::string key, std::string value, int* timestep)
{
    if(this->currentElement == NULL)
    {
        this->currentElement = this->document.allocate_node(
            rapidxml::node_element, 
            this->document.allocate_string(this->childElementName.c_str()));
        this->parentElement->append_node(this->currentElement);
    }
    
    if(this->currentElement->first_attribute(key.c_str()) == 0)          
    {
        appendChildElementAttribute(this->currentElement, key, value);
    }
    else                                            
    {
        generateChildElement(); 
        currentElement = currentElement->next_sibling();
        appendChildElementAttribute(this->currentElement, key, value);
    }
}

void XMLWriter::writeToDocument(Data* data)
{
    setNumChildElements(data->getPedestrianSet()->getNumPedestrians());
    initializeChildElements();
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void XMLWriter::writeDocumentContentsToFile()
{
    this->fileStream << this->document;
    this->fileStream.close();
    this->document.clear();
}

void XMLWriter::openFile(std::string fileName)
{
    this->fileStream.open(fileName);
}

void XMLWriter::setParentElementName(std::string parentElementName)
{
    this->parentElementName = parentElementName;
}

void XMLWriter::setChildElementName(std::string childElementName)
{
    this->childElementName = childElementName;
}

void XMLWriter::setNumChildElements(int numChildElements)
{
    this->numChildElements = numChildElements;
}

void XMLWriter::initializeXMLDeclaration(
    std::string versionNum, std::string encodingType)
{
    rapidxml::xml_node<>* declarationElement = this->document.allocate_node(
        rapidxml::node_declaration);
    declarationElement->append_attribute(
        this->document.allocate_attribute(
            "version", this->document.allocate_string(versionNum.c_str())));
    declarationElement->append_attribute(
        this->document.allocate_attribute(
            "encoding", this->document.allocate_string(encodingType.c_str())));
    this->document.append_node(declarationElement);
}

void XMLWriter::initializeParentElement()
{
    this->parentElement = this->document.allocate_node(
        rapidxml::node_element, 
        this->document.allocate_string(this->parentElementName.c_str()));
    this->document.append_node(parentElement);
}

void XMLWriter::generateChildElement()
{
    rapidxml::xml_node<>* traversalElement = this->document.allocate_node(
        rapidxml::node_element, 
        this->document.allocate_string(this->childElementName.c_str()));
    this->parentElement->append_node(traversalElement);
}

void XMLWriter::appendChildElementAttribute(
    rapidxml::xml_node<>* element, std::string key, std::string value)
{
    element->append_attribute(this->document.allocate_attribute(
        this->document.allocate_string(key.c_str()), 
        this->document.allocate_string(value.c_str())));
}

void XMLWriter::initializeChildElements()
{
    for(int i = 0; i < this->numChildElements; ++i)
    {
        generateChildElement();
    }
}