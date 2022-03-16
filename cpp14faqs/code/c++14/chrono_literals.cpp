#include <chrono>
#include <type_traits>

int main()
{
    using namespace std::chrono_literals;

    auto a = 10h;
    auto b = 2min;
    auto c = 20s;
    auto d = 10ms;
    auto e = 20us;
    auto f = 5ns;

    static_assert(std::is_same<decltype(a), std::chrono::hours>::value, "");
    static_assert(std::is_same<decltype(b), std::chrono::minutes>::value, "");
    static_assert(std::is_same<decltype(c), std::chrono::seconds>::value, "");
    static_assert(std::is_same<decltype(d), std::chrono::milliseconds>::value, "");
    static_assert(std::is_same<decltype(e), std::chrono::microseconds>::value, "");
    static_assert(std::is_same<decltype(f), std::chrono::nanoseconds>::value, "");
}
