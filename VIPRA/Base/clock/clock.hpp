#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

#include <spdlog/spdlog.h>

#include <definitions/config_map.hpp>
#include <definitions/type_definitions.hpp>

namespace VIPRA {
using nano = std::chrono::nanoseconds;
using milli = std::chrono::milliseconds;
using seconds = std::chrono::seconds;

/**
 * @brief Clock to time execution time
 * 
 * @tparam TimeT : time scale
 * @tparam ClockT : type of clock to use
 */
template <typename TimeT = seconds, typename ClockT = std::chrono::steady_clock>
class Clock {
 public:
  /**
   * @brief Returns the current time
   * 
   * @return TimeT 
   */
  inline TimeT now() { return ClockT::now(); }

  /**
   * @brief Starts the timer
   * 
   */
  inline void start() { _start = ClockT::now(); }

  /**
   * @brief Stops the timer and returns the time since it was started
   * 
   * @return TimeT 
   */
  [[nodiscard]] inline TimeT stop() {
    return std::chrono::duration_cast<TimeT>(ClockT::now() - _start);
  }

  static constexpr TimeT zero = TimeT::zero();

 private:
  std::chrono::time_point<ClockT> _start;
};
}  // namespace VIPRA

/**
 * @brief Formatter for time in spdlog
 * 
 * @tparam  : 
 */
template <>
struct fmt::v9::formatter<VIPRA::seconds> {
  static constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    return ctx.end();
  }

  template <typename FormatContext>
  auto format(VIPRA::seconds input, FormatContext& ctx) -> decltype(ctx.out()) {
    auto hours = std::chrono::duration_cast<std::chrono::hours>(input);
    input -= hours;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(input);
    input -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(input);
    input -= seconds;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(input);

    return format_to(ctx.out(), "{}h:{}m:{}s", hours.count(), minutes.count(),
                     seconds.count(), milliseconds.count());
  }
};

/**
 * @brief Formatter for time in spdlog
 * 
 * @tparam  : 
 */
template <>
struct fmt::v9::formatter<VIPRA::milli> {
  static constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    return ctx.end();
  }

  template <typename FormatContext>
  auto format(VIPRA::milli input, FormatContext& ctx) -> decltype(ctx.out()) {
    auto hours = std::chrono::duration_cast<std::chrono::hours>(input);
    input -= hours;
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(input);
    input -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(input);
    input -= seconds;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(input);

    return format_to(ctx.out(), "{}h:{}m:{}s:{}ms", hours.count(), minutes.count(),
                     seconds.count(), milliseconds.count());
  }
};

/**
 * @brief Formatter for time in spdlog
 * 
 * @tparam  : 
 */
template <>
struct fmt::v9::formatter<VIPRA::nano> {
  static constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    return ctx.end();
  }

  template <typename FormatContext>
  auto format(VIPRA::milli input, FormatContext& ctx) -> decltype(ctx.out()) {
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(input);
    input -= minutes;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(input);
    input -= seconds;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(input);
    input -= milliseconds;
    auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(input);

    return format_to(ctx.out(), "{}m:{}s:{}ms:{}ns", minutes.count(), seconds.count(),
                     milliseconds.count(), nanoseconds.count());
  }
};

#endif