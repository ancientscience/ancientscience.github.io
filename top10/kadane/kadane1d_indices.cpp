#include <iostream>
#include <forward_list>
#include "kadane1d_indices.hpp"

template<typename ForwardIterator>
void printcontents(ForwardIterator start, 
                   ForwardIterator end)
{
    std::cout << "{";
    while(start != end)
    {
        std::cout << *start++ << " ";
    }
    std::cout << *start << "}" << std::endl; 
}

int main()
{
    std::tuple<int, int*, int*> sum_start_end;

    std::array<int, 8> a 
    {-2, -3, 4, -1, -2, 1, 5, -3};

    sum_start_end = 
      kadane1d(a.begin(), a.end());

    auto max_sum = std::get<0>(sum_start_end);

    auto start_index = 
        std::distance(std::begin(a), 
            std::get<1>(sum_start_end));

    auto end_index = 
        std::distance(std::begin(a), 
            std::get<2>(sum_start_end));

    std::cout << "<sum : " << max_sum << ","
     << " start index : " << start_index << ","
     << " end index : " << end_index << ">"
     << " \nMax subarray is : ";

    printcontents(std::get<1>(sum_start_end), 
                  std::get<2>(sum_start_end)); 

    std::vector<int> v 
    {-1, 4, -2, 5, -5, 2, -20, 6};

    typedef std::vector<int>::iterator vitr;
    std::tuple<int, vitr, vitr> 
      sum_start_end_v;

    sum_start_end_v = 
        kadane1d(v.begin(), v.end());

    max_sum = std::get<0>(sum_start_end_v);

    start_index = 
      std::distance(v.begin(), 
          std::get<1>(sum_start_end_v));
    
    end_index = std::distance(v.begin(), 
                std::get<2>(sum_start_end_v));

    std::cout << "<sum : " << max_sum << ","
     << " start index : " << start_index << ","
     << " end index : " << end_index << ">"
     << " \nMax subarray is : ";

    printcontents(std::get<1>(sum_start_end_v), 
                  std::get<2>(sum_start_end_v)); 


    std::forward_list<int> l 
    {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    typedef std::forward_list<int>::iterator 
        litr;
    std::tuple<int, litr, litr> sum_start_end_l;

    sum_start_end_l = 
        kadane1d(l.begin(), l.end());

    max_sum = std::get<0>(sum_start_end_l);
    
    start_index = std::distance(l.begin(), 
                  std::get<1>(sum_start_end_l));
    
    end_index = std::distance(l.begin(), 
                std::get<2>(sum_start_end_l));

    std::cout << "<sum : " << max_sum << ","
     << " start index : " << start_index << ","
     << " end index : " << end_index << ">"
     << " \nMax subarray is : ";
    printcontents(std::get<1>(sum_start_end_l), 
                  std::get<2>(sum_start_end_l)); 
}
