Link to Report google doc 

https://docs.google.com/document/d/18-KkeTORB--wVVNpSIgF5bsRqedNDj5bJCDA2_8rI90/edit?usp=sharing

Link to Google Slides

https://docs.google.com/presentation/d/1x0LrWqRDC9IbqJLpr862WMjG8SaDJEuvYwamZngfAqU/edit?usp=sharing


Using this code is very simple. Simply running the main with a file named "data.csv" in the same directory will reproduce all of our results. 

For a functional breakdown though
the handler function is the primary usage tool here as it is programmed to receive an array and then using that array run all necessary tests on each sorting algorithm
the internal functions of the hanlder functions can be used outside of it though if an isolated test need be ran
to do so one would call testfunc and insert their soring algorithm as a parameter as well as the array they wish to use during the process
then the values that returns are the average times for each array size --  in this way the handler simply facilitates the calling of testfunc over and over
place_csv simply manages the fstream do the data.csv file. 

It is important though that all files be loaded in the same directory as they rely on eachother for incluces/imports

For usage of the find5 function, one simply inserts an array, its size and a value to be searched for and bool value will be returned. Important to note that this function does NOT work with negative numbers
