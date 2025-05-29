#pragma once

#include <array>
#include <cstdint>
#include <random>

namespace srt::internal {
std::array primes = {
    uint8_t(251), uint8_t(241), uint8_t(239), uint8_t(233), uint8_t(229),
    uint8_t(227), uint8_t(223), uint8_t(211), uint8_t(199), uint8_t(197),
    uint8_t(193), uint8_t(191), uint8_t(181), uint8_t(179), uint8_t(173),
    uint8_t(167), uint8_t(163), uint8_t(157), uint8_t(151), uint8_t(149),
    uint8_t(139), uint8_t(137), uint8_t(131), uint8_t(127), uint8_t(113),
    uint8_t(109), uint8_t(107), uint8_t(103), uint8_t(101), uint8_t(97),
    uint8_t(89),  uint8_t(83),  uint8_t(79),  uint8_t(73),  uint8_t(71),
    uint8_t(67),  uint8_t(61),  uint8_t(59),  uint8_t(53),  uint8_t(47),
    uint8_t(43),  uint8_t(41),  uint8_t(37),  uint8_t(31),  uint8_t(29),
    uint8_t(23),  uint8_t(19),  uint8_t(17),  uint8_t(13),  uint8_t(11),
    uint8_t(7),   uint8_t(5),   uint8_t(3),   uint8_t(2),   uint8_t(1)};

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
