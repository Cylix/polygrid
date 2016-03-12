#include <polygrid/polygrid>
#include <vector>

template <typename T>
struct point { T x; T y; };

int main(void) {
  std::vector<point<int>> v1;
  polygrid::polygrid<10, 10> p1(v1);

  std::vector<point<float>> v2;
  polygrid::polygrid<10, 10> p2(v2);

  return 0;
}
