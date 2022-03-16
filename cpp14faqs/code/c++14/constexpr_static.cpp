constexpr int first(int n) 
{
    static int value = n;         
    return value;
}

constexpr int uninit() 
{
    int a;                        
    return a;
}
