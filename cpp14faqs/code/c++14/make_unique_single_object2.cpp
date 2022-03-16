#include <memory>
#include <string>
#include <cassert>

int main()
{
    std::unique_ptr<int> p1 = std::make_unique<int>(100);
    assert ( *p1 == 100 );

    p1 = std::make_unique<int> ();
    assert ( *p1 == 0 );
    

    std::unique_ptr<std::string> p2 = std::make_unique<std::string> ( "Chandra" );
    assert ( *p2 == "Chandra" );

    p2 = std::make_unique<std::string> ();
    assert ( *p2 == "" );

    p2 = std::make_unique<std::string> ( 10, 'c' );
    assert ( *p2 == "cccccccccc" );
}
