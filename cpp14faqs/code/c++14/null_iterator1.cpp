#include <vector>
#include <cassert>

int main()
{
    typedef std::vector<int> C;
    C::iterator ii1{}, ii2{};
    C::iterator ii4 = ii1;
    C::const_iterator cii{};
    assert ( ii1 == ii2 );
    assert ( ii1 == ii4 );

    assert (!(ii1 != ii2 ));

    assert ( (ii1 == cii ));
    assert ( (cii == ii1 ));
    assert (!(ii1 != cii ));
    assert (!(cii != ii1 ));
    assert (!(ii1 <  cii ));
    assert (!(cii <  ii1 ));
    assert ( (ii1 <= cii ));
    assert ( (cii <= ii1 ));
    assert (!(ii1 >  cii ));
    assert (!(cii >  ii1 ));
    assert ( (ii1 >= cii ));
    assert ( (cii >= ii1 ));
    assert (cii - ii1 == 0);
    assert (ii1 - cii == 0);
}
