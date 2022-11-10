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

