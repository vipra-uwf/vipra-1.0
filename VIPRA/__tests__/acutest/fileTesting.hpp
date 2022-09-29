
#include "acutest.h"

#include <algorithm>
#include <fstream>
#include <string>

[[nodiscard]] bool
TEST_FILE_CONTENT(std::string filepath, std::string expected, bool removeSpaces) {
  std::ifstream t(filepath);
  std::string   fileContent((std::istreambuf_iterator<char>(t)),
                          std::istreambuf_iterator<char>());
  if (removeSpaces) {
    fileContent.erase(std::remove_if(fileContent.begin(),
                                     fileContent.end(),
                                     [](char chr) { return std::iswspace(chr); }),
                      fileContent.end());
  }
  t.close();
  return (expected.compare(fileContent) == 0);
}