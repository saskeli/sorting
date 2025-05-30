#pragma once

namespace srt {
template <class IT>
void insertion_sort(IT begin, IT end) {
  IT inv = begin;
  ++inv;
  for (; inv != end; ++inv) {
    for (IT i = inv; i != begin; --i) {
        IT o = i;
        --o;
        if (*i < *o) {
            std::swap(*i, *o);
        } else {
            break;
        }
    }
  }
}
}  // namespace str
