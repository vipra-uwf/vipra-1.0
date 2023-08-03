// NOLINTBEGIN
/*
**************************************************************************
In principle, this file is same as movement.cpp, however, it is based on dynamic
load balancing with a next available core getting the next task. Core 0 (Rank 0)
acts as the master co-ordinating the work distribution

USAGE: takes two arguments (the number of parameter combinations)
mpirun -n 100 ./movement_lb1 1331 file
****(file - tasks id) - one column of tasks id ( to generate this file, order
the tasks based on the time) This file is NOT  the output of BalanceLoad !!!
**************************************************************************/

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <mpi.h>
#include <spdlog/spdlog.h>

#include "configuration/configuration_reader.hpp"
#include "distributions/distributions.hpp"
#include "json/value.h"
#include "json/writer.h"
#include "main.hpp"
#include "randomization/random.hpp"

void master(int, char **);
void slave();

VIPRA::CONFIG::Map makeRandomConfig(const VIPRA::CONFIG::Map &,
                                    const VIPRA::CONFIG::Map &);
void               writeParameters(const std::string &, const Json::Value &);

int                id = 0;       // process rank
int                np;           // number of MPI processes
int                NUM = 15000;  // number of tasks to be processed  (given
uint64_t           seed = 13465;
VIPRA::pRNG_Engine engine{seed};
int                main(int argc, char **argv);

VIPRA::CONFIG::Map minConfig;
VIPRA::CONFIG::Map maxConfig;
VIPRA::CONFIG::Map simConfig;

//****************************************************************************80

int main(int argc, char *argv[])

//****************************************************************************80
{
  double wtime;

  MPI_Init(&argc, &argv);

  MPI_Comm_size(MPI_COMM_WORLD, &np);

  MPI_Comm_rank(MPI_COMM_WORLD, &id);

  NUM = atoi(argv[1]);

  wtime = MPI_Wtime();

  getInputFiles(argc, argv);
  simConfig = ConfigurationReader::getConfiguration(configFile);

  if (id == 0) {
    master(argc, argv);
  } else {
    slave();
  }

  wtime = MPI_Wtime() - wtime;
  spdlog::info("Process {} time = {}", id, wtime);

  MPI_Finalize();
  spdlog::info("Normal end of execution.");

  return 0;
}

void master(int argc, char **argv) {
  minConfig = ConfigurationReader::getConfiguration(minConfigFile);
  maxConfig = ConfigurationReader::getConfiguration(maxConfigFile);

  Json::FastWriter fastWriter;

  int        rank;
  int        p = 0;
  MPI_Status status;
  float      result[7];

  for (rank = 1; rank < np; ++rank) {
    auto jsonStr = fastWriter.write(makeRandomConfig(minConfig, maxConfig).getDoc());
    MPI_Send(jsonStr.c_str(),    /* message buffer */
             jsonStr.size(),     /* one data item */
             MPI_CHAR,           /* data item is an integer */
             rank,               /* destination process rank */
             1, MPI_COMM_WORLD); /* user chosen message tag */
    p++;
  }

  /*
   * Receive a result from any slave and dispatch a new work
   * request work requests have been exhausted.
   */
  while (p < NUM) {
    auto jsonStr = fastWriter.write(makeRandomConfig(minConfig, maxConfig).getDoc());
    MPI_Recv(&result,                  /* message buffer */
             1,                        /* one data item */
             MPI_INT,                  /* of type double real */
             MPI_ANY_SOURCE,           /* receive from any sender */
             MPI_ANY_TAG,              /* any type of message */
             MPI_COMM_WORLD, &status); /* received message info */
    MPI_Request req;
    MPI_Send(jsonStr.c_str(),    /* message buffer */
             jsonStr.size(),     /* one data item */
             MPI_CHAR,           /* data item is an integer */
             status.MPI_SOURCE,  /* destination process rank */
             1, MPI_COMM_WORLD); /* user chosen message tag */
    p++;
  }

  /*
   * Receive results for outstanding work requests.
   */
  for (rank = 1; rank < np; ++rank) {
    MPI_Recv(&result, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    MPI_Send(nullptr, 0, MPI_CHAR, status.MPI_SOURCE, 2, MPI_COMM_WORLD);
  }
}

void slave() {
  std::array<VIPRA::CONFIG::Map, 2> work;
  MPI::Status                       status;
  int                               result;

  int rank = 0;
  int workCnt = 0;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  Json::Value  root;
  Json::Reader reader;

  for (;;) {
    MPI::COMM_WORLD.Probe(0, MPI_ANY_TAG, status);
    int   l = status.Get_count(MPI::CHAR);
    char *buf = new char[l];
    MPI::COMM_WORLD.Recv(buf, l, MPI::CHAR, 0, MPI_ANY_TAG, status);

    if (status.Get_tag() == 2 || buf == nullptr) {
      return;
    }

    std::string bla1(buf, l);
    reader.parse(bla1, root);

    const std::string outputFile =
        "./output/r" + std::to_string(rank) + "w" + std::to_string(workCnt);

    parallel_main(simConfig, VIPRA::CONFIG::Map{root}, outputFile + ".json");

    writeParameters(outputFile + "_params.json", root);

    result = 1;
    ++workCnt;
    MPI_Send(&result, 1, MPI::INT, 0, 0, MPI_COMM_WORLD);
  }
}

VIPRA::CONFIG::Map makeRandomConfig(const VIPRA::CONFIG::Map &minModuleParams,
                                    const VIPRA::CONFIG::Map &maxModuleParams) {
  const auto &minDoc = minModuleParams.getDoc();
  const auto &maxDoc = maxModuleParams.getDoc();

  VIPRA::CONFIG::Map ret;

  for (const auto &module : minDoc.getMemberNames()) {
    for (const auto &val : minDoc[module].getMemberNames()) {
      const auto &valRef = minDoc[module][val];
      if (valRef.isNumeric()) {
        float                              min = minDoc[module][val].asFloat();
        float                              max = maxDoc[module][val].asFloat();
        VIPRA::uniform_distribution<float> distr{min, max};
        ret[module][val] = distr(engine);
      } else {
        ret[module][val] = valRef;
      }
    }
  }

  return ret;
}

/**
 * @brief Writes the timestep values JSON to the output file, and closes the file
 * 
 */
void writeParameters(const std::string &outputFilePath, const Json::Value &map) {
  std::ofstream fileStream;
  fileStream.open(outputFilePath, std::fstream::out | std::fstream::trunc);
  Json::FastWriter fastWriter;
  fileStream << fastWriter.write(map);
  fileStream.close();
}

// NOLINTEND