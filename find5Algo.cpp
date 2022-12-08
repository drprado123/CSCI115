#include <iostream>
#include "Sorting_Algos.cpp"
using namespace std;

bool find5hash (int* vals, int size, int findme) //To use insert array, size of array and value you wish to search for
{
    int* hashing  = new int(findme);
    for (int i = 0; i < findme; i++)
    {
        hashing[i] = 0;
    }
    int i = 0;
    while (i < size) //loops through given array vals
    {
        if (vals[i] <= findme) //checks whether the val can be placed into hash table
        {
            hashing[vals[i]]++; //incerements hash value
            if (hashing[findme - vals[i]] >= 1) return true; //uses subtraction to search for pair value to add to findme
            //returns bool true if a pair to add to finme is found
        }
        i++;
    }
    return false; //returns a bool false value if pair to add up to findme is not found
}

int main()
{
    //simple testcase
    int* arr = new int[2];
    arr[0] = 100;
    arr[1] = 0;
    cout << find5hash(arr,2,100);
    return 0;
}