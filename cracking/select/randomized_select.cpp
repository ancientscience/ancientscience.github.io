#include <utility>
#include <cassert>
#include <cstdlib>

int partition(int a[], int l, int r)
{
    int p = a[r];
    int i = l - 1;

    for(int j = l; j <= r - 1; j++)
    {
        if(a[j] <= p)
        {
            i = i + 1;
            std::swap(a[i], a[j]);
        }
    } 

    std::swap(a[i + 1], a[r]);

    return i + 1;
}


int randomized_partition(int a[], int l, int r)
{
    int i = l + std::rand() % (r - l + 1);
    std::swap(a[r], a[i]);
    return partition(a, l, r);
}


int randomized_select(int a[], int l, int r, 
                      size_t k)
{
    int p, pdist;
    if(l < r)
    {
        p = randomized_partition(a, l, r);

        pdist = p - l + 1;
        
        if(k == pdist) // pivot is the element
            return a[p];
        else if(k < pdist)
            return randomized_select(
                       a, l, p - 1, k);
        else // k > pdist
            return randomized_select(
                       a, p + 1, r, k - pdist);
    }
}


int main()
{
    int a[] = {8, 1, 6, 4, 0, 3, 9, 5};

    int sixth_min = 
        randomized_select(a, 0, 7, 6);

    assert(sixth_min = 8);
}
