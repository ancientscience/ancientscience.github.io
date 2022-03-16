#include <set>

struct A
{
    A(int i) : _i(i) {}
    int get() const { return _i; }
private: 
    int _i;
};

bool operator < (const A & lhs, const A & rhs) 
{
    return lhs.get() < rhs.get();
}

int main()
{
    std::set<A> sa;

    sa.insert(A(10));
    sa.insert(A(8));
    sa.insert(A(18));

    sa.find(8);
}
