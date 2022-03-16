#include <type_traits>
#include <utility>

template<class Fn>
//typename std::result_of<Fn(int)>::type f(Fn& t);
//typename std::result_of<Fn(int)>::type f(Fn& t);
decltype(std::declval<Fn>()(std::declval<int>())) f(Fn & t);

template<class T, class U>
int f(U u);

struct S {};

int main() {
  f<S>(0);
}
