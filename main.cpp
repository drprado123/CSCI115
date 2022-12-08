#include <iostream>
#include <fstream>
#include <chrono>
#include "Sorting_Algos.cpp" //gives acess to sorting functions
#include "auxfunctions.cpp" //gives acess to auxilary/helper functions
using namespace std;
using namespace std :: chrono; //allows us to use commonplace chrono commands


const int numof = 5000; //declares our maximum array size during testing is a constant because it is used in many calculations

int* testfunc(void sort(int* arr, int size), int* testarray) //primary testing function takes in sorting algorithm was well as the test array to be used
{
  auto start = high_resolution_clock :: now();
  auto stop = high_resolution_clock :: now();
  auto duration  = duration_cast<microseconds>(stop-start);
  int* holder;
  int* averages = arrayfill((numof/100)+1,0);
  //declarations to be able to run clock functions as well as initialization of arrays
  for (int n = 100; n <= numof; n += 100) // loops through array grabbing an increasing size of array from the parent each time
      {
        cout << n << endl;
        holder = arrayget(testarray,n); //simply gets the first n values from testarray
        for (int i = 0;  i < 100; i++) //performs 100 tests for each datapoint
        {
          start = high_resolution_clock :: now();
          sort(holder, n);
          stop = high_resolution_clock :: now();
          duration = duration_cast<microseconds>(stop-start);
          averages[(n/100) - 1] = averages[(n/100) - 1] + int(duration.count())/(i+1); //averages all test values
        }
        delete[] holder;
      }
      return averages;
}
int* testfunc(void sort(int* arr, int left, int right), int* testarray) //alternate form of testfunc to accept the sorting algos with differnt parameters but processes are the same
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
        for (int i = 0;  i < 100; i++)
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
void place_csv(int* vals) //adds values into csv in trunkated manner (ie adds on to file)
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

void handler(int* arr) //runs entire test process for a given array
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
  
  //quickrand 
  average_vals = testfunc(quickrand,arr);
  place_csv(average_vals);
  delete[] average_vals;
  //heap
  average_vals = testfunc(heapsort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "heaport complete" << endl;
  
  //counting
  average_vals = testfunc(countSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "counting sort complete" << endl;
  
  //radix
  average_vals =testfunc(radixSort,arr);
  place_csv(average_vals);
  delete[] average_vals;
  cout << "radix complete" <<endl;
  

}

//This is the main where all tests and logging will be performed
int main()
{
  handler(generaterandarray(numof,10000)); //runs testing functions with randomized array
  cout << "random array testing complete" <<endl;
  handler(generateascending(numof)); //runs testing funtions with ascending array or pre sorted array
  cout << "descening array testing complete" <<endl;
  handler(generatedescending(numof));//runs testing functions with descending or reverse sorted array
  cout << "testing complete please see .csv file!" << endl;

  return  0;
}
