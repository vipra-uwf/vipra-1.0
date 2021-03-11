// #include <iostream>

// #include "json_writer.hpp"

// #include "json/json.h"


// int main() {
//     JSONWriter* jsonWriter = new JSONWriter();

//     jsonWriter->appendFloatAttributeToCurrentElement("x", 20);
//     jsonWriter->appendFloatAttributeToCurrentElement("y", 40);
//     jsonWriter->appendFloatAttributeToCurrentElement("x", 60);
//     jsonWriter->appendFloatAttributeToCurrentElement("y", 80);

//     jsonWriter->writeDocumentContentsToFile();

//     std::cout << jsonWriter->document;
    
//     return 0;
// }