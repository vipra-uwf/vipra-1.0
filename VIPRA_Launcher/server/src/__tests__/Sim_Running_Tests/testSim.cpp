
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
//   [`${configDir}/sim.config`, paramsFile, pedestrianFile, mapFile, outputFile]

struct Args {
  std::string configDir;
  std::string paramsFile;
  std::string pedFile;
  std::string mapFile;
  std::string outputFile;
};

Args
getArgs(int argc, const char** argv) {
  if (argc == 6) {
    return Args{argv[1], argv[2], argv[3], argv[4], argv[5]};
  } else {
    throw std::runtime_error("Incorrect Number of Arguments");
  }
}

int
main(int argc, const char** argv) {
  printf("STARTING TEST SIMULATION\n");
  const Args    args{getArgs(argc, argv)};
  std::ofstream file;
  file.open(args.outputFile);
  if (file.is_open()) {
    printf("WRITING TO OUTPUT\n");
    file << "This Is A Test Output.\n";
    file.close();
    printf("DONE\n");
    return 0;
  } else {
    std::cerr << "UNABLE TO OPEN OUTPUT FILE\n";
    return -1;
  }
}