#include <iostream>
using namespace std;

//contains all basic auxilary functions used during testing and building of primary functions

void swap(int *a, int *b) //swaps two values within an array
{
	int t = *a;
	*a = *b;
	*b = t;
}
//functions to use for testing values----------------------------
int* generaterandarray(int size, int maxval) //generates an array of size size with the biggest possible value being maxval
{
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % maxval;
    }
    return arr;
}
int* generateascending(int size) //generates an ascending array of size size
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i;
    }
    return arr;
}
int* generatedescending(int size) //generates descending array of size size
{
    int* arr = new int[size];
    for (int i = size; i >= 0; i--)
    {
        arr[size-i] = i;
    }
    return arr;
}
void print(int* arr, int n) //prints n elements of array
{
    for (int i  = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int* arrayget(int* arr, int n) //gets the first n values of an array
{
    int* temp = new int[n];
    for (int i = 0; i <n; i++)
    {
        temp[i] = arr[i];
    }
    return temp;
}

int* arrayfill(int size, int number)// generates an array of size size fileld with number
{
    int* temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = number;
    }
    return temp;
}

int Getmax(int arr[],int s) //returns the value inside of an array
{
    int max = arr[0];
    for( int i = 1; i <s; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
    return max;
}
