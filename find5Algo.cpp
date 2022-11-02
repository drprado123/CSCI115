#include <iostream>
using namespace std;

bool hashcheck(int* hash, int val)
{

}
bool find5hash (int* vals, int size)
{
    int* hashing  = new int(6);
    int i = 0;
    while (i < size)
    {
        if (hashcheck(hashing,vals[i]) == true) return true;
        i++;
    }
}