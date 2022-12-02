#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "Sorting_Algos.cpp"
using namespace std;
using namespace std :: chrono;




//This is the main where all tests and logging will be performed
int main()
{
  
    int* random_arr = generaterandarray(100000,1000);
    //int* sorted_arr = generateascending(1000);
    //int* reverse_arr = generatedescending(1000);
    int* holder;
    int* averages = arrayfill(101,0);
    auto start = high_resolution_clock :: now();
    auto stop = high_resolution_clock :: now();
    auto duration  = duration_cast<microseconds>(stop-start);
      for (int n = 1000; n <= 100000; n += 1000)
    {
      cout << n << endl;
      holder = arrayget(random_arr,n);
      for (int i = 0;  i < 9; i++)
      {
        start = high_resolution_clock :: now();
        insertionSort(holder, n);
        stop = high_resolution_clock :: now();
        duration = duration_cast<microseconds>(stop-start);
        averages[(n/1000) - 1] = averages[(n/1000) - 1] + int(duration.count())/(i+1);
      }
      delete[] holder;
    }
    print(averages,100);
    // place averages into .csv
    //------------------------------------------------------------------------------------------
    
    averages = arrayfill(101,0);
    for (int n = 1000; n <= 100000; n += 1000)
    {
      cout << n << endl;
      holder = arrayget(random_arr,n);
      for (int i = 0;  i < 9; i++)
      {
        start = high_resolution_clock :: now();
        insertionSort(holder, n);
        stop = high_resolution_clock :: now();
        duration = duration_cast<microseconds>(stop-start);
        averages[(n/1000) - 1] = averages[(n/1000) - 1] + int(duration.count())/(i+1);
      }
      delete[] holder;
    }


  return 0;
}
