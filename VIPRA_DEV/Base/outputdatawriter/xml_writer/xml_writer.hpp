#ifndef XML_WRITER_HPP
#define XML_WRITER_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

#include "../output_data_writer.hpp"
#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_print.hpp"

class XMLWriter: public OutputDataWriter
{
    private:
        Data* data;
        std::ofstream fileStream;
        std::string parentElementName;
        std::string childElementName;
        int numChildElements;
        rapidxml::xml_document<> document;
        rapidxml::xml_node<>* parentElement;
        rapidxml::xml_node<>* currentElement;

        void openFile(std::string fileName);

        void initializeXMLDeclaration(
            std::string versionNum, std::string encodingType);
        void initializeParentElement();
        void initializeChildElements();

        void generateChildElement();
        void appendChildElementAttribute(
            rapidxml::xml_node<>* element, std::string key, std::string value);
        
        void setData(Data* initialData);
        void setParentElementName(std::string parentElementName);
        void setChildElementName(std::string dataElementName);
        void setNumChildElements(int numChildElements);
              
    public:
        XMLWriter();
        virtual void configure(CONFIG_MAP* configMap);
        virtual void initializeOutputFile(std::string outputFilePath);
        virtual void addFloatValue(
            std::string key, FLOATING_NUMBER value);
        virtual void addStringValue(
            std::string key, std::string value);
        virtual void writeDocumentContentsToFile();
        virtual void writeToDocument(Data* data);
};

#endif
