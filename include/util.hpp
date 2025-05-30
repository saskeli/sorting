#pragma once

#include <array>
#include <cstdint>
#include <random>

namespace srt::internal {
std::array primes = {
    uint32_t(583087), uint32_t(291547), uint32_t(145777), uint32_t(72893),
    uint32_t(36947),  uint32_t(18481),  uint32_t(9241),   uint32_t(4621),
    uint32_t(2311),   uint32_t(1259),   uint32_t(631),    uint32_t(317),
    uint32_t(163),    uint32_t(83),     uint32_t(43),     uint32_t(23),
    uint32_t(13),     uint32_t(7),      uint32_t(5),      uint32_t(3),
    uint32_t(2),      uint32_t(1)};

template <class V_T>
void populate_random(V_T& vec, uint64_t seed = 0) {
  std::random_device r;
  std::mt19937 gen(seed ? seed : r());
  std::uniform_int_distribution<uint64_t> uniform_dist;
  for (size_t i = 0; i < vec.size(); ++i) {
    vec[i] = uniform_dist(gen);
  }
}
}  // namespace srt::internal
