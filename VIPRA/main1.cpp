#include "readers/input_xml_reader.hpp"

InputDataLoader* generateDataLoader(std::string type)
{
	if(type == "xml")
	{
		InputXMLReader* inputXMLReader = new InputXMLReader;
		return inputXMLReader;
	}
	else if(type == "json")
	{
		InputJSONReader* inputJSONReader = new InputJSONReader;
		return inputJSONReader;
	}
}

InputDataLoader* generateDataLoader()
{
	InputXMLReader* inputXMLReader = new InputXMLReader;
	return inputXMLReader;
}

int main() {  return 0; }