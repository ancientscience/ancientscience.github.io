#include <string>
#include <set>
#include <vector>

struct name_entry
{
    std::string family_name;
    std::string given_name;
};

/*
bool operator<(const name_entry& x, const name_entry& y)
{
    // lexicographical order on (family_name, given_name)
    if(x.family_name<y.family_name) return true;

    if(y.family_name<x.family_name) return false;

    return x.given_name<y.given_name;
}*/


struct comp_family_name
{
    bool operator()(const name_entry& x, const name_entry& y) const
    {
        return x.family_name<y.family_name;
    }

    bool operator()(const name_entry& x, const std::string& y) const
    {
        return x.family_name<y;
    }

    bool operator()(const std::string& x, const name_entry& y) const
    {
        return x<y.family_name;
    }

   // typedef void is_transparent;
};


int main()
{
    //std::set<name_entry> s;
    std::vector<name_entry> s;
    //std::set<name_entry, comp_family_name> names ;//{{"Kumar", "Chandra"}, {"Singh", "Neeru"}, {"Kumar", "Sunil"}, {"Kumar", "Arvind"}};
    //std::set<name_entry, std::less<name_entry>> names {{"Kumar", "Chandra"}, {"Singh", "Neeru"}, {"Kumar", "Sunil"}, {"Kumar", "Arvind"}};

//    names.equal_range(std::string("Kumar"), comp_family_name());
    //names.equal_range(std::string("Kumar"));
}
