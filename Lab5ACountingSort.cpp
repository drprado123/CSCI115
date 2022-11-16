#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{
    int *sorted = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++)
        {
            count =0;
            
    for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                count += 1;
            }
        }
            sorted[count]= arr[i];
        }
    for (int i =0; i < n;i++ )
        {
            arr[i] = sorted[i];
        }
}


void print(int arr[], int n)
{
    for(int i =0; i < n; i++)
        {
            cout << arr[i]<< " ";
        }
    cout << endl;
}

int main() {
int arr[] = {11,56,1,15,24};
    int n = 5;

    cout << "old array";
    print (arr,n);

    countSort(arr,n);
    cout << "sorted array: ";
    print(arr, n);

    return 0;
}