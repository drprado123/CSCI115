#include <iostream>
#include "Sorting_Algos.cpp"
using namespace std;

bool hashcheck(int* hash, int val)
{
    if (val % 5 <= 0 && val <= 5)
    {
        hash[val]++;
    }
    if (hash[0] >= 1 && hash[5] >= 1) return true;
    if (hash[1] >= 1 && hash[4] >=1) return true;
    if (hash[2] >=1 && hash[3]>=1) return true;
    else return false;

}
bool find5hash (int* vals, int size)
{
    int* hashing  = new int(6);
    for (int i = 0; i < 6; i++)
    {
        hashing[i] = 0;
    }
    int i = 0;
    while (i < size)
    {
        if (vals[i] % 5 <= 0 && vals[i] <= 5)
        {
            hashing[vals[i]]++;
        }
        if (hashing[0] >= 1 && hashing[5] >= 1) return true;
        if (hashing[1] >= 1 && hashing[4] >=1) return true;
        if (hashing[2] >=1 && hashing[3]>=1) return true;
        i++;
    }
    return false;
}

int main()
{
    return 0;
}