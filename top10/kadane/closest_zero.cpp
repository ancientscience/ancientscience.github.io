#include <utility>
#include <algorithm>
#include <tuple>
#include <iostream>

typedef std::pair<int, size_t> ValueIndexPair;

std::vector<int> i
findSubArraySumZero(std::vector<int> & a)
{
    typedef std::tuple<int, size_t, size_t> 
        ValStartEndIndices;

    size_t len = a.size();
    std::vector<ValueIndexPair> prefixa(len);
       
    prefixa[0] = ValueIndexPair(a[0], 0);
   
    for(size_t i = 1; i < len; ++i)
    prefixa[i] = 
    ValueIndexPair(
     prefixa[i - 1].first + a[i], i);

    std::cout << 
    "Printing Prefix Array with Value and"
    " Original Index" 
    << std::endl;

    for(ValueIndexPair vip : prefixa)
    std::cout << vip.first << ":" 
              << vip.second << " ";
    std::cout << std::endl; 

    int start_prefix = prefixa[0].first;
    int end_prefix = prefixa[len - 1].first;

    std::sort(prefixa.begin(), prefixa.end(), 
      [](ValueIndexPair f, ValueIndexPair s) 
      {
          return f.first < s.first;
      }
    );

    std::cout 
    << "Printing Value Sorted Prefix Array" 
    << std::endl;

    for(ValueIndexPair vip : prefixa)
    std::cout << vip.first << ":" 
              << vip.second << " ";
    std::cout << std::endl; 

    std::vector<ValStartEndIndices> 
        pairwisediff_vec(len - 1);
    for(size_t i = 0; i < len - 1; ++i)
    {
        pairwisediff_vec[i] = 
        std::make_tuple(
        prefixa[i + 1].first - prefixa[i].first,
        prefixa[i].second, 
        prefixa[i + 1].second);
    }

    std::cout << 
    "Printing Pairwise Value Differences with"
    " original indices" 
    << std::endl;

    for(ValStartEndIndices vsei : 
        pairwisediff_vec)
    std::cout << "("
              << std::get<0>(vsei) << ":" 
              << std::get<1>(vsei) << ":"
              << std::get<2>(vsei) << ") ";
    std::cout << std::endl;    

    std::vector<ValStartEndIndices>::iterator 
    itr = 
    std::min_element(
        pairwisediff_vec.begin(), 
        pairwisediff_vec.end(),      
      [](ValStartEndIndices f, 
         ValStartEndIndices s)
      {
          return std::abs(std::get<0>(f)) 
                 < std::abs(std::get<0>(s));
      }
    );
     
    ValStartEndIndices closest_indices = *itr;
   
    std::vector<int> vcandidates(3);
 
    vcandidates[0] = 
     std::abs(std::get<0>(closest_indices));
    vcandidates[1] = 
     std::abs(start_prefix); // a[0]
    vcandidates[2] = 
     std::abs(end_prefix); // a[0..n - 1]

    int close_zero = *std::min_element(
     vcandidates.begin(), vcandidates.end());

    std::vector<int> vsumzero;

    size_t start_index, end_index = 0;

    if(close_zero == vcandidates[1])
    {
        vsumzero.push_back(a[0]);
    }
    else if(close_zero == vcandidates[2])
    {
        vsumzero = a;
    }
    else // close_zero == vcandidates[0])
    {
        std::pair<size_t, size_t> se = 
        std::minmax(std::get<1>(
              closest_indices), 
              std::get<2>(closest_indices));

        vsumzero.assign(a.begin() + 
                        se.first + 1,
              a.begin() + se.second + 1);
    }

    return vsumzero;
}

int main()
{
    std::vector<int> v 
    { 8, -3, 2, 1, -4, 10, -5 };
 
    std::vector<int> vclosest_sum_zero = 
       findSubArraySumZero(v);

    std::cout << "Subarray with sum closest"
     "to zero is" << std::endl;
    for(int e : vclosest_sum_zero)
    std::cout << e << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    v = {-3,2,4,-6,-8,10,11};
    vclosest_sum_zero = findSubArraySumZero(v);

    std::cout << "Subarray with sum closest to"
     " zero is" << std::endl;
    for(int e : vclosest_sum_zero)
    std::cout << e << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    v = {10, -2, -7};
    vclosest_sum_zero = findSubArraySumZero(v);

    std::cout << "Subarray with sum closest to"
     " zero is" << std::endl;
    for(int e : vclosest_sum_zero)
    std::cout << e << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}
