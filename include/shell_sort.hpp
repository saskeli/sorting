#pragma once

#include <iostream>

#include "util.hpp"

namespace srt {

namespace internal {
template <class IT>
void shell_sort_step(IT begin, IT end, size_t start, uint8_t step) {
  begin += start;
  for (IT inv = begin + step; inv < end; inv += step) {
    for (IT i = inv; i > begin; i -= step) {
      IT prev = i - step;
      if (*i < *prev) {
        auto tmp = *i;
        *i = *prev;
        *prev = tmp;
      } else {
        break;
      }
    }
  }
}
}  // namespace internal

template <class IT>
void shell_sort(IT begin, IT end) {
  for (auto p : internal::primes) {
    if (p > 1) {
#pragma omp parallel for
      for (size_t i = 0; i < p; ++i) {
        internal::shell_sort_step(begin, end, i, p);
      }
    } else {
      for (IT inv = begin + 1; inv < end; ++inv) {
        for (IT i = inv; i > begin; --i) {
          IT prev = i - 1;
          if (*i < *prev) {
            auto tmp = *i;
            *i = *prev;
            *prev = tmp;
          } else {
            break;
          }
        }
      }
    }
  }
}
}  // namespace srt
