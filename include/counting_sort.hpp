#pragma once

#include <iostream>
#include <vector>

namespace srt {
template <class IT, class T>
void counting_sort(IT begin, IT end, T min, T max) {
  std::vector<uint64_t> counts(max - min + 1);
  for (IT i = begin; i != end; ++i) {
    auto v = *i - min;
    if (v >= counts.size()) {
      exit(1);
    }
    ++counts[*i - min];
  }
  --counts[0];
  for (size_t i = 1; i < counts.size(); ++i) {
    counts[i] += counts[i - 1];
  }
  auto trg = counts;
  size_t i = counts[counts.size() - 1];
  while (i) {
    T v = *(begin + i);
    uint64_t idx = trg[v - min];
    if (idx >= i) {
      --i;
    } else {
      idx = counts[v - min];
      std::swap(*(begin + idx), *(begin + i));
      --counts[v - min];
    }
  }
}

template <class IT>
void counting_sort(IT begin, IT end) {
  IT i = begin;
  auto min = *i;
  auto max = *i;
  ++i;
  for (; i != end; ++i) {
    auto v = *i;
    min = std::min(min, v);
    max = std::max(max, v);
  }
  counting_sort(begin, end, min, max);
}
}  // namespace srt
