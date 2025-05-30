#include <algorithm>
#include <cstdint>
#include <vector>

#include "include/unbalanced_quicksort.hpp"
#include "include/util.hpp"

int main() {
  std::vector<uint64_t> a_vec(1000000);
  srt::internal::populate_random(a_vec);
  auto b_vec = a_vec;
  srt::unbalanced_quicksort(a_vec.begin(), a_vec.end());
  std::sort(b_vec.begin(), b_vec.end());
  for (size_t i = 0; i < b_vec.size(); ++i) {
    if (a_vec[i] != b_vec[i]) {
      std::cout << i << ": " << a_vec[i] << " <-> " << b_vec[i] << std::endl;
    }
  }
  return 0;
}
