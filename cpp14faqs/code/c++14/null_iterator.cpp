#include <vector>

struct A 
{
    A() {}
    virtual std::vector<int>::const_iterator begin()
    {
        return {};
    }

    virtual std::vector<int>::const_iterator end()
    {
        return {};
    }
};

struct B : A 
{
    explicit B(std::vector<int> & _v) : v(_v) {}

    virtual std::vector<int>::const_iterator begin()
    {
        return v.begin();
    }

    virtual std::vector<int>::const_iterator end()
    {
        return v.end();
    }

    std::vector<int> v;
};

/*
const A& ar = get_an_A(...);
for (int x : ar)
do_something(x);

do_something_else(ar);
*/

int main()
{
    std::vector<int> v {1, 2, 3};

    A * a = new B(v);
}
