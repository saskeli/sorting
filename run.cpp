#include <cstdint>
#include <vector>

#include "include/util.hpp"
#include "include/shell_sort.hpp"

int main() {
  std::vector<uint64_t> a_vec(1000000);
  srt::internal::populate_random(a_vec);
  std::cout << *(a_vec.end() - 1) << std::endl;
  srt::shell_sort(a_vec.begin(), a_vec.end());
  std::cout << *(a_vec.end() - 1) << std::endl;
  return 0;
}
