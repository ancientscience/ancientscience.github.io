#include <utility>
#include <cassert>
#include <string>

int main()
{
    {
        int v = 12;
        assert ( std::exchange ( v, 23 ) == 12 );
        assert ( v == 23 );
        assert ( std::exchange ( v, 67.2 ) == 23 );
        assert ( v == 67 );

        assert ((std::exchange<int, float> ( v, {} )) == 67 );
        assert ( v == 0 );
    }

    {
        bool b = false;
        assert ( !std::exchange ( b, true ));
        assert ( b );
    }

    {
        const std::string s1 ( "Hi Mom!" );
        const std::string s2 ( "Yo Dad!" );
    
        std::string s3 = s1; 

        assert ( std::exchange ( s3, s2 ) == s1 );
        assert ( s3 == s2 );

        assert ( std::exchange ( s3, "Hi Mom!" ) == s2 );
        assert ( s3 == s1 );

        s3 = s2; 

        assert ( std::exchange ( s3, {} ) == s2 );
        assert ( s3.size () == 0 );
        s3 = s2; 

        assert ( std::exchange ( s3, "" ) == s2 );
        assert ( s3.size () == 0 );
    }

    {
        const unsigned val = 4;
        int i = 1;
        auto prev = std::exchange(i, val);

        static_assert( std::is_same<decltype(prev), int>::value, "return type" );
        assert( i == 4 );
        assert( prev == 1 );

        prev = std::exchange(i, 3);

        assert( i == 3 );
        assert( prev == 4 );
    }
}
