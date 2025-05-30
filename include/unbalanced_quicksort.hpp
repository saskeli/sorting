#pragma once

#include "counting_sort.hpp"
#include "insertion_sort.hpp"

namespace srt {
namespace internal {

template <class IT, class T>
IT partition(IT begin, IT end, const T pivot, T& a_max, T& b_min) {
  --end;
  while (begin != end) {
    T e = *end;
    T b = *begin;
    if (b < pivot) {
      a_max = std::max(b, a_max);
      ++begin;
    } else if (e >= pivot) {
      b_min = std::min(e, b_min);
      --end;
    } else {
      std::swap(*end, *begin);
      a_max = std::max(e, a_max);
      b_min = std::min(b, b_min);
      ++begin;
    }
  }
  return end;
}
template <class IT, class T>
void unbalanced_quicksort(IT begin, IT end, T min, T max, size_t depth = 0) {
  const decltype(end - begin) i_s_limit = 10;
  const T c_s_limit = 10000;
  if (min == max) {
    return;
  }
  if (end - begin < i_s_limit) {
    return insertion_sort(begin, end);
  }
  if (max - min < c_s_limit) {
    return counting_sort(begin, end, min, max);
  }
  T pivot = min / 2 + max / 2 + 1;
  T a_max = min;
  T b_min = max;
  IT mid = partition(begin, end, pivot, a_max, b_min);
  unbalanced_quicksort(begin, mid, min, a_max, depth + 1);
  unbalanced_quicksort(mid, end, b_min, max, depth + 1);
}
}  // namespace internal

template <class IT>
void unbalanced_quicksort(IT begin, IT end) {
  if (begin == end) {
    return;
  }
  IT i = begin;
  auto min = *i;
  auto max = *i;
  ++i;
  for (; i != end; ++i) {
    auto v = *i;
    min = std::min(min, v);
    max = std::max(max, v);
  }
  internal::unbalanced_quicksort(begin, end, min, max);
}

}  // namespace srt
