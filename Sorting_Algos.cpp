//file containing all sorting algorithms required
#include <iostream>
#include "auxfunctions.cpp"
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
// bubble sort
void bubbleSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
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
    int i = high;
    for (int j = high; j> low; j--)
    {
        if (arr[j] > pivot)
        {
            swap(arr,i--,j);
        }
    }
    swap(arr,i,low);
    return(i);
}
void quicksort(int* arr, int low, int high) //quicksort using first element as partition
{
    if (low < high)
    {
        int q = partition(arr,low,high);
        quicksort(arr,low,q-1);
        quicksort(arr,q+1,high);
    }
}
int partitionrand(int* arr, int low, int high) //partitions using random element as partition - using first partition as subroutine
{
    int pivot = low + rand() % (high - low);
    swap(arr,pivot,low);
    return partition(arr,low,high);
}

void quickrand(int* arr, int low, int high) //quicksort using a random element
{
    if (low < high)
    {
        int q = partitionrand(arr,low,high);
        quickrand(arr,low,q-1);
        quickrand(arr,q+1,high);
    }
}


//functions for heapsort -------------------------------
void heapify(int* arr, int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;


    if (left < size && arr[left] > arr[largest]) largest = left;
    if (right < size && arr[right] > arr[largest]) largest = right;
    if (largest != root)
    {
        swap(arr,root,largest);

        heapify(arr,size,largest);
    }

}
void heapsort(int* arr, int size)
{
    for (int  i = size/2-1; i >=0; i--) heapify(arr,size,i);
    for (int i = size - 1; i >=0; i--) 
    {
        swap(arr,0,i);
        heapify(arr,i,0);
    }
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

