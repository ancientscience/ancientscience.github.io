#include <memory>
#include <iostream>
#include <vector>

int main()
{
    auto up_vec1 = std::make_unique<std::vector<int>>(2014, 2017);

    std::cout << "size of the first vector is : " << up_vec1->size() << std::endl;

    auto up_vec2 = std::make_unique<std::vector<int>>{2014, 2017};

    std::cout << "size of the second vector is : " << up_vec2->size() << std::endl;
}
