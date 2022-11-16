#include <iostream>
using namespace std;

int Getmax(int arr[],int s)
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

void countingSort(int arr[], int s, int div)
{
    int output[s];
    int count[10] = {0};

    for (int i = 0; i < s; i++)
        {
        count[(arr[i]/div)% 10]++;
        }
    for (int i = 1; i <10; i++)
        {
            count[i] += count[i-1];
        }
    for (int i = s -1; i >= 0; i--)
        {
            output[count[(arr[i]/div)%10]-1] = arr[i];
            count[(arr[i]/div)%10]--;
            }
    for (int i =0; i < s; i ++)
        {
            arr[i]= output[i];
        }
}

void radixSort(int arr[], int s)
{
    int m = Getmax(arr, s);
    for(int div =1; m / div > 0; div *=10)
        {
           countingSort(arr, s,div); 
        }
}

int main()
{
    int s;
    cout << " Enter the size of array: "<<endl;
    cin >> s;

    int arr[s];

    cout << "Enter "<< s << " Random order"<< endl;
    for ( int i = 0; i < s;i++)
        {
            cin >> arr[i];
        }

    cout << endl << "Original: "<< endl;
    for (int i = 0; i < s; i++)
        {
        cout << arr[i] << " ";
    }

    radixSort(arr, s);
    cout << endl << " Sorted: " << endl;
    for (int i = 0; i < s; i++)
        {
            cout << arr[i] << " ";
        }
    return 0;
}