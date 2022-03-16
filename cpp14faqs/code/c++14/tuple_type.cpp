#include <tuple>
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>

struct item 
{
    item(int i) : itemid(i) {}
    int itemid;
};

struct region 
{
    region(int i) : regionid(i) {}
    int regionid;
};

template<class Key, class Value>
    using map_t = 
        std::map<Key, Value, std::function<bool(const Key&, const Key&)>>;


int items_in_order(const map_t<item, int> & orderitemidtems) 
{ 
    return std::accumulate(orderitemidtems.begin(), orderitemidtems.end(), 0, 
        [](int acc, std::pair<item, int> const & p) { return acc + p.second; });}

int getregionid(const region & r)
{
    return r.regionid;
}

//std::tuple<region, std::map<item, int>> get_order()
auto get_order()
{
    map_t<item, int> orderitemidtems {
        [](const item & a, const item & b)
        { return a.itemid < b.itemid; }
    };

    orderitemidtems = {{1, 10}, {2, 20}, {3, 30}};

    return std::make_tuple(region(111), orderitemidtems);
}


int main()
{
    auto point = std::make_tuple(getregionid, items_in_order)(get_order());
}

