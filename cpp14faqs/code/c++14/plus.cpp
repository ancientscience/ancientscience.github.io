#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
#include <string>
#include <vector>

int main() 
{
    std::vector<const char *> v {"3", "2", "1"};

    std::set<std::string, std::greater<>> s {"a", "aaa", "aa"};

    std::vector<std::string> dest;

    std::transform(v.begin(), v.end(), s.begin(), 
        std::back_inserter(dest), std::plus<>());

    for (const auto& elem : dest) 
    {
        std::cout << elem << std::endl;
    }
}
