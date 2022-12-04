#include <iostream>
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
        if (hashcheck(hashing,vals[i]) == true) return true;
        i++;
    }
    return false;
}