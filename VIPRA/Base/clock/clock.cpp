#include "clock.hpp"

Clock::Clock() {
  this->simulationElapsedMs = 0;
}

void
Clock::configure(const VIPRA::ConfigMap& config) {}

void
Clock::start() {
  this->realStartTime = std::chrono::system_clock::now();
}

void
Clock::stop() {
  this->realEndTime = std::chrono::system_clock::now();
}

void
Clock::printRealStartTime() {
  std::time_t time = std::chrono::system_clock::to_time_t(this->realStartTime);
  LJ::Info(simLogger, "computation started: {}", std::ctime(&time));
}

void
Clock::calculateRealElapsedSeconds() {
  this->realElapsedSeconds = this->realEndTime - this->realStartTime;
}

void
Clock::printRealDuration() {
  calculateRealElapsedSeconds();
  LJ::Info(simLogger, "elapsed time: {}s", this->realElapsedSeconds.count());
}

void
Clock::printRealEndTime() {
  std::time_t time = std::chrono::system_clock::to_time_t(this->realEndTime);
  LJ::Info(simLogger, "computation finished: {}", std::ctime(&time));
}

void
Clock::addSimulationTimeMs(VIPRA::delta_t seconds) {
  this->simulationElapsedMs += seconds * 1000;
}

void
Clock::printSimulationDuration() {
  LJ::Info(simLogger, "simulation duration: {:f}s", float(this->simulationElapsedMs) / 1000);
}