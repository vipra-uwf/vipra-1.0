
#include <math.h>
#include <mpi.h>
#include <mpi/mpi.h>
#include <cstdint>

#include "arguments/arguments.hpp"
#include "configuration/config.hpp"
#include "configuration/configuration_reader.hpp"
#include "definitions/type_definitions.hpp"
#include "parameter_sweep/parameter_sweep.hpp"
#include "randomization/random.hpp"

void simulationMain(const std::string&, VIPRA::Args&, VIPRA::Config&, VIPRA::Config&);
void writeParameters(const std::string&, const std::vector<char>&);
void writeParameters(const std::string&, const VIPRA::Config&);

int threads = 0;
int id = 0;

void assignWork(VIPRA::cnt totalSimRuns, const VIPRA::Config& params,
                VIPRA::pRNG_Engine& engine) {
  MPI_Status status;
  float      result = 0;
  VIPRA::cnt simCnt = 0;

  for (int rank = 1; rank < threads; ++rank) {
    auto paramsStr = VIPRA::ParameterSweep::randomizeParams(params, engine).dump();
    MPI_Send(paramsStr.c_str(), static_cast<int>(paramsStr.length()), MPI_CHAR, rank, 1,
             MPI_COMM_WORLD);
    ++simCnt;
  }

  while (simCnt < totalSimRuns) {
    auto paramsStr = VIPRA::ParameterSweep::randomizeParams(params, engine).dump();
    MPI_Recv(&result, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    MPI_Send(paramsStr.c_str(), static_cast<int>(paramsStr.length()), MPI_CHAR,
             status.MPI_SOURCE, 1, MPI_COMM_WORLD);
    ++simCnt;
  }
}

void joinWorkers() {
  MPI_Status status;
  float      result = 0;

  for (int rank = 1; rank < threads; ++rank) {
    MPI_Recv(&result, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    MPI_Send(nullptr, 0, MPI_CHAR, status.MPI_SOURCE, 2, MPI_COMM_WORLD);
  }
}

void master(VIPRA::Args& args) {
  VIPRA::pRNG_Engine engine{};

  VIPRA::Config config =
      VIPRA::ConfigurationReader::getConfiguration(args.get<std::string>("config"));
  VIPRA::Params params =
      VIPRA::ConfigurationReader::getConfiguration(args.get<std::string>("params"));

  engine.reseed(config["seed"].get<uint64_t>());

  auto totalSimRuns = args.get<VIPRA::cnt>("simulations");
  assignWork(totalSimRuns, params, engine);
  joinWorkers();
}

void worker(VIPRA::Args& args) {
  std::vector<char> data;
  MPI_Status        status;
  int               result = 0;
  int               workCnt = 0;
  int               dataLength = 0;
  int               rank = 0;
  std::string       outputFile;

  VIPRA::Config config =
      VIPRA::ConfigurationReader::getConfiguration(args.get<std::string>("config"));

  VIPRA::Params params;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  for (;;) {
    MPI_Probe(0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    MPI_Get_count(&status, MPI_CHAR, &dataLength);

    data.resize(dataLength + 1);
    MPI_Recv(data.data(), dataLength, MPI_CHAR, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    data[data.size() - 1] = '\0';

    if (status.MPI_TAG == 2) {
      return;
    }

    params = nlohmann::json::parse(data.data());
    std::string id = "r" + std::to_string(rank) + "w" + std::to_string(workCnt);

    simulationMain(id, args, config, params);

    writeParameters("./params" + id + "_params.json", data);

    result = 1;
    ++workCnt;
    MPI_Send(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }
}

void single(VIPRA::Args& args) {
  VIPRA::pRNG_Engine engine{};
  VIPRA::cnt         totalSimRuns = args.get<uint64_t>("simulations");

  VIPRA::Config config =
      VIPRA::ConfigurationReader::getConfiguration(args.get<std::string>("config"));
  VIPRA::Params params =
      VIPRA::ConfigurationReader::getConfiguration(args.get<std::string>("params"));
  engine.reseed(config["seed"].get<uint64_t>());

  for (int i = 0; i < totalSimRuns; ++i) {
    auto currParams = VIPRA::ParameterSweep::randomizeParams(params, engine);
    writeParameters("./params/r1w" + std::to_string(i), currParams);
    simulationMain("r1w" + std::to_string(i), args, config, currParams);
  }
}

void writeParameters(const std::string& outputFile, const std::vector<char>& data) {
  std::ofstream fileStream;
  fileStream.open(outputFile, std::fstream::out | std::fstream::trunc);
  fileStream << data.data();
  fileStream.close();
}
void writeParameters(const std::string& outputFile, const VIPRA::Config& config) {
  std::ofstream fileStream;
  fileStream.open(outputFile, std::fstream::out | std::fstream::trunc);
  fileStream << config.dump();
  fileStream.close();
}

int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &threads);
  MPI_Comm_rank(MPI_COMM_WORLD, &id);

  VIPRA::Args args;
  args.parse(argc, argv);

  if (threads < 2) {
    single(args);
    MPI_Finalize();
    return 0;
  }

  if (id == 0) {
    master(args);
  } else {
    worker(args);
  }

  MPI_Finalize();
}
