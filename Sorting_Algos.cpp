#include <iostream>
using namespace std;

// merge sort
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1];
    int r[n2];
    for (int i = 0; i < n1; i++){
        l[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++){
        r[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2){
        if (l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// insertion sort
void insertionSort(int arr[], int n){
    int key, j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i;
        while (j > 0 && arr[j - 1] > key){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

//selection sort

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void selectionsort(int array[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		swap(array[min], array[i]);
		
	}
}


//functions for quicksort----------------------------------------------------------
void swap (int* arr, int a, int b)//swaps two values within an array
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
int partition(int* arr, int low, int high) //partitions using first element
{
    int pivot = arr[low];
    int i = high +1;
    for (int j = high; j>= 0; j--)
    {
        if (arr[j] > pivot)
        {
            i--;
            swap(arr,i,j);
        }
    }
    swap(arr,i-1,low);
    return(i-1);
}
void quicksort(int* arr, int low, int high) //quicksort using first element as partition
{
    int q = partition(arr,low,high);
    quicksort(arr,low,q-1);
    quicksort(arr,q+1,high);
}
int partitionrand(int* arr, int low, int high) //partitions using random element as partition - using first partition as subroutine
{
    int pivot = arr[rand() % high];
    swap(arr,pivot,low);
    return partition(arr,low,high);
}

void quickrand(int* arr, int low, int high) //quicksort using a random element
{
    int q = partitionrand(arr,low,high);
    quickrand(arr,low,q-1);
    quickrand(arr,q+1,high);
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
int* generatedescenging(int size) //generates descending array of size size
{
    int* arr = new int[size];
    for (int i = size; i >= 0; i--)
    {
        arr[i] = i;
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