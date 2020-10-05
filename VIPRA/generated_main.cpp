#include "readers/input_xml_reader.hpp"
#include "readers/FAKE_INCLUDE.hpp"
#include "readers/FAKE_INCLUDE.hpp"
#include "writers/xml_writer.hpp"

InputDataLoader* generateDataLoader(std::string type)
{
	if(type == "xml")
	{
		InputDataLoader* inputXMLReader = new InputDataLoader;
		return inputXMLReader;
	}
	else if(type == "json")
	{
		InputJSONReader* inputJSONReader = new InputJSONReader;
		return inputJSONReader;
	}
	else if(type == "plaintext")
	{
		InputPlainTextReader* plainTextReader = new InputPlainTextReader;
		return plainTextReader;
	}

	return nullptr;
}

OutputDataWriter* generateDataWriter(std::string type)
{
	if(type == "xml")
	{
		XMLWriter* xmlWriter = new XMLWriter;
		return xmlWriter;
	}

	return nullptr;
}

int main() {  return 0; }