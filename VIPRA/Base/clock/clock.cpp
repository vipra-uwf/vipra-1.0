#include "clock.hpp"

Clock::Clock() {
  this->simulationElapsedMs = 0;
}

void Clock::configure(const VIPRA::CONFIG::Map&) {}

void Clock::start() {
  this->realStartTime = std::chrono::system_clock::now();
}

void Clock::stop() {
  this->realEndTime = std::chrono::system_clock::now();
}

void Clock::printRealStartTime() {
  std::time_t time = std::chrono::system_clock::to_time_t(this->realStartTime);
  spdlog::info("Computation Started: {}", std::ctime(&time));
}

void Clock::calculateRealElapsedSeconds() {
  this->realElapsedSeconds = this->realEndTime - this->realStartTime;
}

void Clock::printRealDuration() {
  calculateRealElapsedSeconds();
  spdlog::info("Elapsed Time: {}s", this->realElapsedSeconds.count());
}

void Clock::printRealEndTime() {
  std::time_t time = std::chrono::system_clock::to_time_t(this->realEndTime);
  spdlog::info("Computation Finished: {}", std::ctime(&time));
}

void Clock::addSimulationTimeMs(VIPRA::delta_t seconds) {
  this->simulationElapsedMs += seconds * 1000;
}

void Clock::printSimulationDuration() const {
  spdlog::info("Simulation Duration: {:f}s", static_cast<float>(this->simulationElapsedMs) / 1000);
}