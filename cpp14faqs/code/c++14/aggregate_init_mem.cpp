#include <iostream>

struct Univ
{
    std::string name;
    int rank;
    int i;
    std::string city = "unknown";
    char c = city[rank];
};

int main()
{
    Univ u = {"Columbia", 3};

    std::cout << u.name << ' ' << u.rank 
              << ' ' << u.i << ' ' 
              << u.city << ' ' << u.c << '\n';
}

