#include <utility>
#include <cassert>

struct DefaultConstructible
{
    DefaultConstructible(int i = 0) : value(i) { }
    int value;
};

struct From { };

struct To 
{
    int value = 0;

    To() = default;
    To(const To&) = default;
    To(const From&) = delete;

    To& operator=(const From&) 
    { 
        value = 1; return *this; 
    }

    To& operator=(From&&) 
    { 
        value = 2; return *this; 
    }
};


int main()
{
    DefaultConstructible x = 1;

    auto old = std::exchange(x, {});

    assert( x.value == 0 );
    assert( old.value == 1 );

    To t;
    From f;

    auto prev = std::exchange(t, f);

    assert( t.value == 1 );
    assert( prev.value == 0 );

    prev = std::exchange(t, From{});

    assert( t.value == 2 );
    assert( prev.value == 1 );
}
