template<typename T>
struct Circle 
{
    T radius;
 
    using value_type = T;
 
    Circle(T r) : radius(r) {}
    Circle(const Circle& c) : radius(c.radius) {}
};

template<typename T=double>
constexpr T pi = T(3.1415926535897932385);
 
auto area = []( auto c ) 
{
    using T = typename decltype(c)::value_type;
    return pi<T> * c.radius * c.radius;
};
