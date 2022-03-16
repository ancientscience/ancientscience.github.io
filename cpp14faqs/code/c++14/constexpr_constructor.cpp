int x;                              

struct A 
{
    constexpr A(bool b) : m(b?42:x) { }
    int m;
};

constexpr int v = A(true).m;        
                                    
constexpr int w = A(false).m;       
