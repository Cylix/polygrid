#include <polygrid/polygrid.hpp>
#include <vector>

template <typename T>
struct point { T x; T y; };

int main(void) {
  std::vector<point<int>> v;
  polygrid::polygrid<10, 10> p(v);

  return 0;
}
