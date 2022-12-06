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
bool find5hash (int* vals, int size, int findme)
{
    int* hashing  = new int(findme);
    for (int i = 0; i < findme; i++)
    {
        hashing[i] = 0;
    }
    int i = 0;
    while (i < size)
    {
        if (vals[i] <= findme)
        {
            hashing[vals[i]]++;
            if (hashing[findme - vals[i]] >= 1) return true;
        }
        i++;
    }
    return false;
}

int main()
{
    int* arr = new int[2];
    arr[0] = 100;
    arr[1] = 0;
    cout << find5hash(arr,2,100);
    return 0;
}