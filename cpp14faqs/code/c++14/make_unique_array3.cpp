#include <memory>
#include <cassert>

struct A
{
    A() : b(true) { }
    A(int) : b(false) { }
    bool b;
};


int main()
{
  std::unique_ptr<A[]> a = std::make_unique<A[]>(3);
  assert( a != nullptr );
  assert( a[0].b && a[1].b && a[2].b );
}

