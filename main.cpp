#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "Sorting_Algos.cpp"
using namespace std;
using namespace std :: chrono;


const int numof = 100000;

int* testfunc(void sort(int* arr, int size), int* testarray)
{
  auto start = high_resolution_clock :: now();
  auto stop = high_resolution_clock :: now();
  auto duration  = duration_cast<microseconds>(stop-start);
  int* holder;
  int* averages = arrayfill((numof/100)+1,0);
  for (int n = 100; n <= numof; n += 100)
      {
        cout << n << endl;
        holder = arrayget(testarray,n);
        for (int i = 0;  i < 9; i++)
        {
          start = high_resolution_clock :: now();
          sort(holder, n);
          stop = high_resolution_clock :: now();
          duration = duration_cast<microseconds>(stop-start);
          averages[(n/100) - 1] = averages[(n/100) - 1] + int(duration.count())/(i+1);
        }
        delete[] holder;
      }
      cout << "amde it" << endl;
      return averages;

}
int* testfunc(void sort(int* arr, int left, int right), int* testarray)
{
  auto start = high_resolution_clock :: now();
  auto stop = high_resolution_clock :: now();
  auto duration  = duration_cast<microseconds>(stop-start);
  int* holder;
  int* averages = arrayfill((numof/100)+1,0);
  for (int n = 100; n <= numof; n += 100)
      {
        cout << n << endl;
        holder = arrayget(testarray,n);
        for (int i = 0;  i < 9; i++)
        {
          start = high_resolution_clock :: now();
          sort(holder, 0,n-1);
          stop = high_resolution_clock :: now();
          duration = duration_cast<microseconds>(stop-start);
          averages[(n/100) - 1] = averages[(n/100) - 1] + int(duration.count())/(i+1);
        }
        delete[] holder;
      }
      return averages;

}
void place_csv(int* vals)
{
  ofstream file;
  file.open("data.csv", std::ios::app);
  for (int i = 0; i < (numof/100)+1; i++)
  {
    file << vals[i] <<", ";
  } 
  file << endl;
  file.close();

}

void handler(int* arr)
{
  int* average_vals;
  //Insertion
  average_vals = testfunc(insertionSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  //Selection
  average_vals = testfunc(selectionsort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  
  //Bubble
  average_vals = testfunc(bubbleSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "bubble complete" << endl;
  
  //Merge
  average_vals = testfunc(mergeSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "ms complete" << endl;
  //quick
  average_vals = testfunc(quicksort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "qs complete" << endl;
  
  //heap
  average_vals = testfunc(heapsort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "heaport complete" << endl;
  
  //counting
  average_vals = testfunc(countingSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  
  //radix
  average_vals =testfunc(radixSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  

}

//This is the main where all tests and logging will be performed
int main()
{
  handler(generaterandarray(numof,10000));
  handler(generateascending(numof));
  handler(generatedescending(numof));
  return  0;
}
