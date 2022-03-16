#include <memory>
#include <cassert>

struct A
{
  A() : b(false) { }
  A(int, double&, char&&, void*) : b(true) { }
  bool b;
};

int main()
{
    int i = 0;
    double d = 0.0;
    char c = 0;

    std::unique_ptr<A> a = std::make_unique<A>(i, d, std::move(c), nullptr);

    assert( a != nullptr );
    assert( a->b );

    a = std::make_unique<A>();
    assert( a != nullptr );
    assert( !a->b );
}
