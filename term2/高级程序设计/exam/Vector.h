#include <vector>
using namespace std;

typedef int (*map_func)(int);
typedef bool (*filter_func)(int);

class Vector {
public:
  Vector(const vector<int> &vec) : vec_(vec) {}

  Vector filter(filter_func f) const;
  Vector map(map_func f) const;
  Vector &for_each(map_func f);

  void output() const;

private:
  vector<int> vec_;
};
