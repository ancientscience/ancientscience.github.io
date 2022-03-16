#include <utility>
#include <cassert>

int f(int) { return 0; }

double f(double) { return 0; }

int (*fp)(int);

int main()
{
  std::exchange(fp, &f);
  assert( fp != nullptr );
}
